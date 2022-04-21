#ifndef PLANE_H
#define PLANE_H
#include <cmath>
#include <iostream>
#include "Vector.h"
#include "Ray.h"

namespace  MATH {
	struct Plane : public Vec4 { 
		
		//Vec4
		Vec4 plane;

		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;
		float d = 0.0f;

		//Vec3
		Vec3 intersectPoint(Ray ray);
		
		Plane();
		Plane(float x_, float y_, float z_, float d_);
		Plane(Vec3 normal, Vec3 p);
		Plane(Vec3 normal, float _d);
		Plane(const Vec3& v0, const Vec3& v1, const Vec3& v2);
		void set(float x, float y, float z, float d);
		void print();
	};
}
#endif
