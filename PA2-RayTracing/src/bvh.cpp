#include "bvh.h"

#include "CGL/CGL.h"
#include "static_scene/triangle.h"

#include <iostream>
#include <stack>

using namespace std;

namespace CGL { namespace StaticScene {

BVHAccel::BVHAccel(const std::vector<Primitive *> &_primitives,
                   size_t max_leaf_size) {

  root = construct_bvh(_primitives, max_leaf_size);
}

BVHAccel::~BVHAccel() {
  if (root) delete root;
}

BBox BVHAccel::get_bbox() const {
  return root->bb;
}

void BVHAccel::draw(BVHNode *node, const Color& c) const {
  if (node->isLeaf()) {
    for (Primitive *p : *(node->prims))
      p->draw(c);
  } else {
    draw(node->l, c);
    draw(node->r, c);
  }
}

void BVHAccel::drawOutline(BVHNode *node, const Color& c) const {
  if (node->isLeaf()) {
    for (Primitive *p : *(node->prims))
      p->drawOutline(c);
  } else {
    drawOutline(node->l, c);
    drawOutline(node->r, c);
  }
}

BVHNode *BVHAccel::construct_bvh(const std::vector<Primitive*>& prims, size_t max_leaf_size) {
  // Part 2, Task 1:
  // Construct a BVH from the given vector of primitives and maximum leaf
  // size configuration. The starter code build a BVH aggregate with a
  // single leaf node (which is also the root) that encloses all the
  // primitives.

  BBox centroid_box, bbox;

 vector<Primitive*>pleft = vector<Primitive *>();
 vector<Primitive*>pright = vector<Primitive *>();

for (Primitive *p : prims) {

    BBox bb = p->get_bbox();
    bbox.expand(bb);
    Vector3D c = bb.centroid();
    centroid_box.expand(c);
    //cout<<"s1"<<endl;
}

  BVHNode *node = new BVHNode(bbox);

  if(prims.empty()){
  root=NULL;
  return node;
  }

  if(prims.size() <= max_leaf_size){

    node->prims = new vector<Primitive *>(prims);
    //cout<<"s2"<<endl;
    return node;
  }

  else{

    double x1=bbox.extent.x;
    double y1=bbox.extent.y;
    double z1=bbox.extent.z;
    int max1 = 0;

    if(x1>y1 && x1>z1){
      max1=0;
    }

    else if(y1>x1 && y1>z1){
      max1=1;
    }

    else if(z1>x1 && z1>y1){

      max1=2;
    }

    for(Primitive *p : prims) {

      //cout << "Max1: "<< max1 << endl;
      if (p->get_bbox().centroid()[max1] <= centroid_box.centroid()[max1]) {

        pleft.push_back(p);
        //cout<<"s4"<<endl;
      }
      else {
        pright.push_back(p);
        //cout<<"s5"<<endl;
      }
    }

    // if(pright.empty() ){

    //   node->l=construct_bvh(pleft,max_leaf_size);
    //   cout<<"r1"<<endl;
    //   return node;
    // }

    // else if(pleft.empty()){

    //   node->r=construct_bvh(pright,max_leaf_size);
    //   cout<<"r2"<<endl;
    //   return node;
    // }

    if(max_leaf_size>prims.size()){
      //cout<<"hello"<<endl;
      node->r=NULL;
      node->l=NULL;
      return node;
    }

    node->r=construct_bvh(pright,max_leaf_size);
    node->l=construct_bvh(pleft,max_leaf_size);
    //cout<<"r3"<<endl;
    return node;   
    
  } 
}

bool BVHAccel::intersect(const Ray& ray, BVHNode *node) const {
  // Part 2, task 3: replace this.
  // Take note that this function has a short-circuit that the
  // Intersection version cannot, since it returns as soon as it finds
  // a hit, it doesn't actually have to find the closest hit.
//cout<<"p0"<<endl;

  double t0=0;
  double t1=0;
  bool hit1 = false;
  bool hit2 = false;

if(node->bb.intersect(ray,t0,t1)==0){ 

//cout<<"p1"<<endl;
return false;
}
if(t0>ray.max_t || t1<ray.min_t){

//cout<<"p2"<<endl;
return false;
}

if(node->isLeaf()){

    //cout<<"p3"<<endl;

    for (Primitive *p : *(node->prims)) {
    total_isects++;

      if (p->intersect(ray)){
      //cout<<"p3"<<endl;
      return true;
      }
    }
}
    //}
else{
hit1 = intersect(ray,node->r);
//cout<<"h1"<<endl;

hit2 = intersect(ray,node->l);
//cout<<"h2"<<endl;

  if(hit1==1 || hit2==1){
  //cout<<"p4"<<endl;
  return true;
  } 
}

return false;
}

bool BVHAccel::intersect(const Ray& ray, Intersection* i, BVHNode *node) const {
  // Part 2, task 3: replace this
//cout<<"p0"<<endl;

  double t0=0;
  double t1=0;
  bool hit1 = false;
  bool hit2 = false;

if(node->bb.intersect(ray,t0,t1)==0){ 

//cout<<"p1"<<endl;
return false;
}
if(t0>ray.max_t || t1<ray.min_t){

//cout<<"p2"<<endl;
return false;
}

if(node->isLeaf()){

    //cout<<"p3"<<endl;

    for (Primitive *p : *(node->prims)) {
    total_isects++;

      if (p->intersect(ray,i)){
      //cout<<"p3"<<endl;
      return true;
      }
    }
}
    //}
else{
hit1 = intersect(ray,i,node->r);
//cout<<"h1"<<endl;

hit2 = intersect(ray,i,node->l);
//cout<<"h2"<<endl;

return hit1 || hit2;

}
return false;
}

}  // namespace StaticScene
}  // namespace CGL
