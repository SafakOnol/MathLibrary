#ifndef RAY_H
#define RAY_H

#include "Vector.h"
#include <math.h>
using namespace MATH;

using namespace std;

class Ray
{
public:
	//Class variables
	Vec3 start;
	Vec3 dir;

	//Constructor
	//Ray();
	Ray(Vec3 start_, Vec3 dir_);

	//Method to calculate the position
	Vec3 currentPosition(float t);

};

#endif