#pragma once
#include "Sphere.h"
#include "Ray.h"
#include "AAB.h"
#include "Vector.h"
#include "VMath.h"

class Collider
{
public:


	static bool RaySphereCollisionDetected(Ray ray, Sphere sphere);
	static Vec3 RaySphereCollisionPoint(Ray ray, Sphere sphere);
	static void quadraticEquation(Ray ray, Sphere sphere);
	static Vec3 RayAABCollisionPoint(Ray& ray, const AAB& box);
	static bool isInside(const AAB& box, Vec3 p);



};

