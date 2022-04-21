#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <math.h>
#include "Mat3.h"


using namespace std;

class Vec3
{
public:
	float x, y, z;

	Vec3();
	Vec3(float x_, float y_, float z_);

	void add(Vec3 otherVec);

	void subtract(Vec3 otherVec);

	void scalarMultiplication(float s);

	float mag();

	Vec3 normalize();

	float dot(Vec3 otherVec);

	Vec3 cross(Vec3 otherVec);

	void lerp(Vec3 otherVec, float t);

	void rotateZ(float angle);

	Vec3 operator + (const Vec3& v) const;

	Vec3 operator - (const Vec3& v)const;

	Vec3 operator * (const float v)const;

};

#endif