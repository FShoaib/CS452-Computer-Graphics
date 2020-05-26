#include <nanogui/nanogui.h>

#include "../clothMesh.h"
#include "../misc/sphere_drawing.h"
#include "sphere.h"

using namespace nanogui;
using namespace CGL;

void Sphere::collide(PointMass &pm) {
  // TODO (Part 3): Handle collisions with spheres.
	Vector3D tp = (pm.position - origin);

	if (tp.norm() < radius ){
		tp.normalize();
		//Vector3D tangent_point = (tp * radius + origin - pm.last_position) + pm.last_position;
		pm.position = (tp * radius + origin - pm.last_position) * (1.0 - friction) + pm.last_position ;
	}
}

void Sphere::render(GLShader &shader) {
  // We decrease the radius here so flat triangles don't behave strangely
  // and intersect with the sphere when rendered
  Misc::draw_sphere(shader, origin, radius * 0.92);
}
