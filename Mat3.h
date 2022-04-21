#ifndef MAT3_H
#define MAT3_H

#include<iostream>
#include <math.h>
#include "Vector.h"

using namespace std;

class Mat3
{
public:

	float m[9];

	Mat3();

	void setIdentity();

	void rotateZ(float angle);

	void scale(float x, float y, float z);

	void transpose();

	float det();

	void inverse();

	//Mat3 operator*(Mat3 otherMat);

	//Vec3 operator*(Vec3 vector);

	// add other operators??


};

#endif