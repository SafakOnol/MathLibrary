#ifndef QUATERNION_H
#define QUATERNION_H

#include "Vector.h"
//#include "VMath.h"
#include "Mat3.h"
#include "Ray.h"
#include "Sphere.h"
#include "Plane.h"
#include <math.h>
using namespace MATH;

using namespace std;

class Quaternion
{
public:
	//Class variables
	Vec4 q; //x,y,z,w mode

	Vec3 v;//x,y,z
	float w, d;

	//Constructor
	Quaternion();
	Quaternion(float x_, float y_, float z_, float w_);
	Quaternion(float w_, Vec3 v_);
	void set(Vec3 v);


	Quaternion operator * (const Quaternion& otherQuat);
	Quaternion operator + (const Quaternion& otherQuat);
	Quaternion operator - (const Quaternion& otherQuat);

	Vec3 Rotate(Vec3 axis, float angleInDegrees);
	// Return the magnitude of the Quaternion using Pythagoras’s theorem
	float Mag();

	// Normalize the Quaternion by dividing it by it’s magnitude +
	Quaternion Normalize();

	// Reverse sign on the imaginary part of the quaternion (x, y, z)+
	Quaternion Conjugate();

	// Invert the quaternion+
	Quaternion Inverse();

	// Rotate a vector using this quaternion
	Vec3 Rotate(Vec3 vec);



};

#endif