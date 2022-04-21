#ifndef SPHERE_H
#define SPHERE_H

#include "Vector.h"
using namespace MATH;

class Sphere
{
public:
	Vec3 position;
	float radius;

	Sphere();
	Sphere(Vec3 position_, float radius_);
	~Sphere();
};

#endif
