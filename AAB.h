#ifndef AAB_H
#define AAB_H

#include "Plane.h"
#include <math.h>
using namespace MATH;

using namespace std;

class AAB
{
public:
	float rx, ry, rz;
	Plane box[6];

	AAB(float width, float height, float depth);
	AAB();

};

#endif