#ifndef VEC4_H
#define VEC4_H
#include <iostream>
#include <math.h>
#include "Mat3.h"


using namespace std;

class Vec4
{
public:
	float x, y, z, w;
	
	Vec4();
	Vec4(float x_, float y_, float z_, float w_);

	float Mag();

	Vec4 Normalize();

	float Dot(const Vec4 otherVec);

	Vec4 operator + (const Vec4& v) const;

	Vec4 operator - (const Vec4& v)const;

	Vec4 operator * (const float f)const;
	
};

#endif
