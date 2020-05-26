#include <iostream>
#include <math.h>
#include <random>
#include <vector>
#include <time.h>
#include <algorithm>

#include "cloth.h"
#include "collision/plane.h"
#include "collision/sphere.h"

using namespace std;

Cloth::Cloth(double width, double height, int num_width_points,
             int num_height_points, float thickness) {
  this->width = width;
  this->height = height;
  this->num_width_points = num_width_points;
  this->num_height_points = num_height_points;
  this->thickness = thickness;

  buildGrid();
  buildClothMesh();
}

Cloth::~Cloth() {
  point_masses.clear();
  springs.clear();

  if (clothMesh) {
    delete clothMesh;
  }
}

void Cloth::buildGrid() {
//   // TODO (Part 1): Build a grid of masses and springs.
  Vector3D pm2d[num_height_points][num_width_points];

  double w_interval = width/ (double)num_width_points;
  double h_interval = height/ (double)num_height_points;
  double a = -1/1000;
  double b = 1/1000;


  for(int i = 0; i < num_height_points; i++){
    for (int j = 0; j < num_width_points; j++){


      int index = i * num_width_points + j;
      if(orientation == HORIZONTAL){ 
        pm2d[i][j].y = 1;
        pm2d[i][j].x = w_interval * (double)(j+1);
        pm2d[i][j].z = h_interval * (double)(i+1);

        bool pin = 0;;
        for(int x = 0; x < pinned.size(); x++){
          if(i == pinned[x][0] && j == pinned[x][1]){
            pin = true;
          }
        }
        point_masses.push_back(PointMass(pm2d[i][j],pin));
      }

      else if(orientation == VERTICAL)
      {
        srand(time(NULL));
        double r1 = rand() % 10 * (b - a) + a;
        pm2d[i][j].z = r1;
        pm2d[i][j].x = w_interval * (double)(j+1);
        pm2d[i][j].y = h_interval * (double)(i+1);

        bool pin = 0;;
        for(int x = 0; x < pinned.size(); x++){
          if(i == pinned[x][0] && j == pinned[x][1]){
            pin = true;
          }
        }
        point_masses.push_back(PointMass(pm2d[i][j],pin));
      }
    }
  }

  //stored in row major order
  for(int i = 0; i < num_height_points; i++){
    for(int j = 0; j < num_height_points; j++){
      int index = i * num_width_points + j;
      PointMass * ptr  = &point_masses[index];

        //STRUCTURAL CONSTRAINTS
        if(j > 0 ){
          springs.push_back(Spring(ptr, ptr - 1, STRUCTURAL));
        }
        if( i > 0){
          springs.push_back(Spring(ptr, ptr - num_width_points, STRUCTURAL));
        }
        //BENDING CONSTRAINTS
        if( j > 1){
          springs.push_back(Spring(ptr, ptr  - 2, BENDING));
        }
        if( i > 1 ){
          springs.push_back(Spring(ptr, ptr  - (2 * num_width_points ), BENDING));
        } 
        //SHEARING CONSTRAINTS
        if( i > 0 && j < num_width_points - 1 ){
          springs.push_back(Spring(ptr, ptr - num_width_points + 1, SHEARING));
        }
        if( i > 0 && j > 0){
          springs.push_back(Spring(ptr, ptr - num_width_points - 1 , SHEARING));
        }    
    }
  }
}

void Cloth::simulate(double frames_per_sec, double simulation_steps, ClothParameters *cp,
                     vector<Vector3D> external_accelerations,
                     vector<CollisionObject *> *collision_objects) {
  
  double mass = width * height * cp->density / num_width_points / num_height_points;
  double delta_t = 1.0f / frames_per_sec / simulation_steps;

  // TODO (Part 2): Compute total force acting on each point mass.
  Vector3D total_force;

  for( int i = 0; i < external_accelerations.size(); i++){
    total_force = total_force + (external_accelerations[i] * mass);

    for(PointMass &pm: point_masses){
      pm.forces =  total_force;
    }
  }

  double dnorm;
  Vector3D fforce;

  for(Spring &sp: springs){
    Vector3D difference = (sp.pm_b -> position) - (sp.pm_a -> position);
    dnorm = difference.norm();
    difference = difference/difference.norm();

    if(cp->enable_structural_constraints == 0 && cp->enable_shearing_constraints == 0 && cp->enable_bending_constraints == 0){
      continue;
    }

    if(cp->enable_structural_constraints && sp.spring_type == STRUCTURAL){
      fforce = (dnorm - sp.rest_length) * cp -> ks * difference;
      sp.pm_a -> forces = (sp.pm_a -> forces) + fforce;
      sp.pm_b -> forces = (sp.pm_b -> forces) - fforce;
    }

    else if(cp->enable_shearing_constraints && sp.spring_type == SHEARING){
      fforce = (dnorm - sp.rest_length) * cp -> ks * difference;
      sp.pm_a -> forces = (sp.pm_a -> forces) + fforce;
      sp.pm_b -> forces = (sp.pm_b -> forces) - fforce;
    }

    else if(cp->enable_bending_constraints && sp.spring_type == BENDING){
      fforce = (dnorm - sp.rest_length) * cp -> ks * difference;
      sp.pm_a -> forces = (sp.pm_a -> forces) + fforce;
      sp.pm_b -> forces = (sp.pm_b -> forces) - fforce;
    }
  }

  //TODO (Part 2): Use Verlet integration to compute new point mass positions
  for(PointMass& pm: point_masses){
    
    if(pm.pinned){
      continue;
    }

    else{
      Vector3D npos = pm.position + (1 - ( (cp->damping)/100 ) ) * (pm.position - pm.last_position) + (pm.forces/mass) * pow(delta_t,2);
      pm.last_position = pm.position;
      pm.position = npos;
    }
  }

  // TODO (Part 4): Handle self-collisions.
  // This won't do anything until you complete Part 4.
  build_spatial_map();
  for (PointMass &pm : point_masses) {
    self_collide(pm, simulation_steps);
  }

  // TODO (Part 3): Handle collisions with other primitives.
  // This won't do anything until you complete Part 3.
  for (PointMass &pm : point_masses) {
    for (CollisionObject *co : *collision_objects) {
      co->collide(pm);
    }
  }
  // TODO (Part 2): Constrain the changes to be such that the spring does not change
  // in length more than 10% per timestep [Provot 1995].
  // for(Spring& sp: springs){

  for(Spring& sp: springs){

    double cal_pos = (sp.pm_a->position - sp.pm_b->position).norm();
    double greater = 1.1 * sp.rest_length; 

    if(cal_pos > greater){
      double differential = (sp.pm_a -> position - sp.pm_b -> position).norm() - greater;

      if ((sp.pm_a -> pinned == 0) && (sp.pm_b -> pinned == 0)){
      Vector3D a = sp.pm_b -> position - sp.pm_a -> position;
      Vector3D b = -a;
      sp.pm_a -> position = sp.pm_a -> position + (a/a.norm() * (differential / 2.0));
      sp.pm_b -> position = sp.pm_b -> position + (b/b.norm() * (differential / 2.0));
      }

      if ((sp.pm_a -> pinned == 1) && (sp.pm_b -> pinned == 0)){
        Vector3D direction = sp.pm_a -> position - sp.pm_b -> position;
        direction = direction/direction.norm() * differential;
        sp.pm_b -> position = sp.pm_b -> position + direction;
      }

      if ((sp.pm_a -> pinned == 0) && (sp.pm_b -> pinned == 1)){
        Vector3D direction = sp.pm_b -> position - sp.pm_a -> position;
        direction = direction/direction.norm() * differential;
        sp.pm_a -> position = sp.pm_a -> position + direction;
      }
    }
  }
}

void Cloth::build_spatial_map() {
  for (const auto &entry : map) {
    delete(entry.second);
  }
  map.clear();

  // TODO (Part 4): Build a spatial map out of all of the point masses.

}

void Cloth::self_collide(PointMass &pm, double simulation_steps) {
  // TODO (Part 4): Handle self-collision for a given point mass.

}

float Cloth::hash_position(Vector3D pos) {
  // TODO (Part 4): Hash a 3D position into a unique float identifier that represents
  // membership in some uniquely identified 3D box volume.

  return 0.f;
}

///////////////////////////////////////////////////////
/// YOU DO NOT NEED TO REFER TO ANY CODE BELOW THIS ///
///////////////////////////////////////////////////////

void Cloth::reset() {
  PointMass *pm = &point_masses[0];
  for (int i = 0; i < point_masses.size(); i++) {
    pm->position = pm->start_position;
    pm->last_position = pm->start_position;
    pm++;
  }
}

void Cloth::buildClothMesh() {
  if (point_masses.size() == 0) return;

  ClothMesh *clothMesh = new ClothMesh();
  vector<Triangle *> triangles;

  // Create vector of triangles
  for (int y = 0; y < num_height_points - 1; y++) {
    for (int x = 0; x < num_width_points - 1; x++) {
      PointMass *pm = &point_masses[y * num_width_points + x];
      // Both triangles defined by vertices in counter-clockwise orientation
      triangles.push_back(new Triangle(pm, pm + num_width_points, pm + 1));
      triangles.push_back(new Triangle(pm + 1, pm + num_width_points,
                                       pm + num_width_points + 1));
    }
  }

  // For each triangle in row-order, create 3 edges and 3 internal halfedges
  for (int i = 0; i < triangles.size(); i++) {
    Triangle *t = triangles[i];

    // Allocate new halfedges on heap
    Halfedge *h1 = new Halfedge();
    Halfedge *h2 = new Halfedge();
    Halfedge *h3 = new Halfedge();

    // Allocate new edges on heap
    Edge *e1 = new Edge();
    Edge *e2 = new Edge();
    Edge *e3 = new Edge();

    // Assign a halfedge pointer to the triangle
    t->halfedge = h1;

    // Assign halfedge pointers to point masses
    t->pm1->halfedge = h1;
    t->pm2->halfedge = h2;
    t->pm3->halfedge = h3;

    // Update all halfedge pointers
    h1->edge = e1;
    h1->next = h2;
    h1->pm = t->pm1;
    h1->triangle = t;

    h2->edge = e2;
    h2->next = h3;
    h2->pm = t->pm2;
    h2->triangle = t;

    h3->edge = e3;
    h3->next = h1;
    h3->pm = t->pm3;
    h3->triangle = t;
  }

  // Go back through the cloth mesh and link triangles together using halfedge
  // twin pointers

  // Convenient variables for math
  int num_height_tris = (num_height_points - 1) * 2;
  int num_width_tris = (num_width_points - 1) * 2;

  bool topLeft = true;
  for (int i = 0; i < triangles.size(); i++) {
    Triangle *t = triangles[i];

    if (topLeft) {
      // Get left triangle, if it exists
      if (i % num_width_tris != 0) { // Not a left-most triangle
        Triangle *temp = triangles[i - 1];
        t->pm1->halfedge->twin = temp->pm3->halfedge;
      } else {
        t->pm1->halfedge->twin = nullptr;
      }

      // Get triangle above, if it exists
      if (i >= num_width_tris) { // Not a top-most triangle
        Triangle *temp = triangles[i - num_width_tris + 1];
        t->pm3->halfedge->twin = temp->pm2->halfedge;
      } else {
        t->pm3->halfedge->twin = nullptr;
      }

      // Get triangle to bottom right; guaranteed to exist
      Triangle *temp = triangles[i + 1];
      t->pm2->halfedge->twin = temp->pm1->halfedge;
    } else {
      // Get right triangle, if it exists
      if (i % num_width_tris != num_width_tris - 1) { // Not a right-most triangle
        Triangle *temp = triangles[i + 1];
        t->pm3->halfedge->twin = temp->pm1->halfedge;
      } else {
        t->pm3->halfedge->twin = nullptr;
      }

      // Get triangle below, if it exists
      if (i + num_width_tris - 1 < 1.0f * num_width_tris * num_height_tris / 2.0f) { // Not a bottom-most triangle
        Triangle *temp = triangles[i + num_width_tris - 1];
        t->pm2->halfedge->twin = temp->pm3->halfedge;
      } else {
        t->pm2->halfedge->twin = nullptr;
      }

      // Get triangle to top left; guaranteed to exist
      Triangle *temp = triangles[i - 1];
      t->pm1->halfedge->twin = temp->pm2->halfedge;
    }

    topLeft = !topLeft;
  }

  clothMesh->triangles = triangles;
  this->clothMesh = clothMesh;
}
