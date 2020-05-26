#include "triangle.h"
#include "CGL/CGL.h"
#include "GL/glew.h"
#include <math.h>

namespace CGL { namespace StaticScene {

Triangle::Triangle(const Mesh* mesh, size_t v1, size_t v2, size_t v3) :
    mesh(mesh), v1(v1), v2(v2), v3(v3) { }

BBox Triangle::get_bbox() const {

  Vector3D p1(mesh->positions[v1]), p2(mesh->positions[v2]), p3(mesh->positions[v3]);
  BBox bb(p1);
  bb.expand(p2);
  bb.expand(p3);
  return bb;

}

bool Triangle::intersect(const Ray& r) const {

  // Part 1, Task 3: implement ray-triangle intersection
  Vector3D p1(mesh->positions[v1]), p2(mesh->positions[v2]), p3(mesh->positions[v3]);

   //calculate t
  /*
    Vector3D edge1, edge2, h, s, q, IPoint;
    float a,f,u,v;

    edge1 = p2 - p1;
    edge2 = p3 - p1;

    h = cross(r.d,edge2);
    a = dot(edge1,h);
   
    f = 1/a;
    s = r.o - p1;
    u = f * dot(s,h);

    q = cross(s,edge1);
    v = f * dot(r.d,q);

    // At this stage we can compute t to find out where the intersection point is on the line.
    float t = f * dot(edge2,q);
     // ray intersection
        IPoint = r.o + r.d * t; 

  if (t>=r.min_t && t<=r.max_t) { // if there is an intersection, the if condition should be true
    r.max_t = t; //replace this with your value of t
    return true;
  }
*/
  return false;
}


bool Triangle::intersect(const Ray& r, Intersection *isect) const {

  // Part 1, Task 3:
  // implement ray-triangle intersection. When an intersection takes
  // place, the Intersection data should be updated accordingly

  Vector3D p1(mesh->positions[v1]), p2(mesh->positions[v2]), p3(mesh->positions[v3]);
  Vector3D n1(mesh->normals[v1]), n2(mesh->normals[v2]), n3(mesh->normals[v3]);


  //finding t
   Vector3D edge1, edge2, h, s, q, IPoint;
    float a,f,u,v;

    edge1 = p2 - p1;
    edge2 = p3 - p1;

    h = cross(r.d,edge2);
    a = dot(edge1,h);
   
    f = 1/a;
    s = r.o - p1;
    u = f * dot(s,h);

    q = cross(s,edge1);
    v = f * dot(r.d,q);

    // At this stage we can compute t to find out where the intersection point is on the line.
    float t = f * dot(edge2,q);

     // ray intersection
    IPoint = r.o + r.d * t; 


  Vector3D v1 = p2 - p1;
  Vector3D v2 = p3- p1;
  Vector3D S = r.o - p1;

  Vector3D S1=cross(r.d,v2);
  Vector3D S2=cross(S,v1);

  double coef=1.0/dot(S1,v1);
  //double t=coef*dot(S2,v2);

  double b1=coef*dot(S1,S);
  double a1=coef*dot(S2,r.d);
  //float w=1-u-v;

  // float d00 = dotProduct(v0, v0);
  // float d01 = dotProduct(v0, v1);
  // float d11 = dotProduct(v1, v1);
  // float d20 = dotProduct(v2, v0);
  // float d21 = dotProduct(v2, v1);

  // float invDenom = 1.0 / (d00 * d11 - d01 * d01);
  // alpha = (d11 * d20 - d01 * d21) * invDenom;
  // beta = (d00 * d21 - d01 * d20) * invDenom;
  // gamma = 1.0f - alpha - beta;

  // float w=1-u-v;

  // float np1=(u*n1.x)+(v*n1.y)+(w*n1.z);
  // float np2=(u*n2.x)+(v*n2.y)+(w*n2.z);
  // float np3=(u*n3.x)+(v*n3.y)+(w*n3.z);

  //if (t>=r.min_t && t<=r.max_t) { // if there is an intersection, the if condition should be true
  if((b1>=0 && b1<=1) && (a1>=0 && a1<=1) && (b1+a1<=1) && t>=r.min_t && t<=r.max_t){

    r.max_t=t;

    Vector3D N=((1-b1-a1)*n1)+(b1*n2)+(a1*n3);

    isect->t = t; //replace this with your value of t
    isect->primitive = this;
    isect->n = N;   //replace this with your value of normal at the point of intersection
    isect->bsdf = get_bsdf();

    return true;
  }

  return false;
}

void Triangle::draw(const Color& c) const {
  glColor4f(c.r, c.g, c.b, c.a);
  glBegin(GL_TRIANGLES);
  glVertex3d(mesh->positions[v1].x,
             mesh->positions[v1].y,
             mesh->positions[v1].z);
  glVertex3d(mesh->positions[v2].x,
             mesh->positions[v2].y,
             mesh->positions[v2].z);
  glVertex3d(mesh->positions[v3].x,
             mesh->positions[v3].y,
             mesh->positions[v3].z);
  glEnd();
}

void Triangle::drawOutline(const Color& c) const {
  glColor4f(c.r, c.g, c.b, c.a);
  glBegin(GL_LINE_LOOP);
  glVertex3d(mesh->positions[v1].x,
             mesh->positions[v1].y,
             mesh->positions[v1].z);
  glVertex3d(mesh->positions[v2].x,
             mesh->positions[v2].y,
             mesh->positions[v2].z);
  glVertex3d(mesh->positions[v3].x,
             mesh->positions[v3].y,
             mesh->positions[v3].z);
  glEnd();
}


} // namespace StaticScene
}// namespace CGL