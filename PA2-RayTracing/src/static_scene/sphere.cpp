#include "sphere.h"

#include <cmath>

#include  "../bsdf.h"
#include "../misc/sphere_drawing.h"

namespace CGL { namespace StaticScene {

bool Sphere::test(const Ray& r, double& t1, double& t2) const {

  // Part 1, Task 4:
  // Implement ray - sphere intersection test.
  // Return true if there are intersections and writing the
  // smaller of the two intersection times in t1 and the larger in t2.
        double disc,tm1,tm2,tc,d,t1c;
        Vector3D L = o-r.o;
        tc = dot(L,r.d);
        d=sqrt((dot(L,L)-(tc*tc)));

          if((d*d)>r2){
          return false;


        }
        t1c=sqrt(r2-(d*d));
        tm1 = tc - t1c;
        tm2 = tc + t1c;

          if(tm1<tm2){
            t1=tm1;
            t2=tm2;
          }

          else{
            t1=tm2;    
            t2=tm1;
          }

  return true;
}

bool Sphere::intersect(const Ray& r) const {

  // Part 1, Task 4:
  // Implement ray - sphere intersection.
  // Note that you might want to use the the Sphere::test helper here.
      double t1,t2;
      bool inter=test(r,t1,t2);

      if(inter){
      Vector3D Point = r.o + r.d * t1;
      r.max_t = t1;
      return true;
      }

  return false;

}

bool Sphere::intersect(const Ray& r, Intersection *i) const {

  // Part 1, Task 4:
  // Implement ray - sphere intersection.
  // Note again that you might want to use the the Sphere::test helper here.
  // When an intersection takes place, the Intersection data should be updated
  // correspondingly.
      double t1,t2;
      bool inter=test(r,t1,t2);

      if(inter){
      Vector3D Point = r.o + r.d * t1;
      r.max_t = t1;

    Vector3D N=(Point-o)/sqrt(r2);

    i->t = t1; //replace this with your value of t
    i->primitive = this;
     //replace this with your value of normal at the point of intersection
    i->n = N;
    i->bsdf = get_bsdf();

      return true;
      }

  return false;
}

void Sphere::draw(const Color& c) const {
  Misc::draw_sphere_opengl(o, r, c);
}

void Sphere::drawOutline(const Color& c) const {
    //Misc::draw_sphere_opengl(o, r, c);
}


} // namespace StaticScene
} // namespace CGL
