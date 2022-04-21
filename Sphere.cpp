#include "Sphere.h"

using namespace MATH;

Sphere::Sphere()
{
	position.x = 1.0f;
	position.y = 1.0f;
	position.z = 1.0f;
	radius = 1.0f;
}

Sphere::Sphere(Vec3 position_, float radius_)
{
	position.x = position_.x;
	position.y = position_.y;
	position.z = position_.z;
	radius = radius_;
}
Sphere::~Sphere()
{
}