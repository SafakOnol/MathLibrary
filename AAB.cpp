#include "AAB.h"
using namespace std;

AAB::AAB() {

	// First three planes go through the origin
	box[0].plane.x = 1;
	box[0].plane.y = 0;
	box[0].plane.z = 0;
	box[0].plane.w = 0;

	box[1].plane.x = 0;
	box[1].plane.y = 1;
	box[1].plane.z = 0;
	box[1].plane.w = 0;

	box[2].plane.x = 0;
	box[2].plane.y = 0;
	box[2].plane.z = 1;
	box[2].plane.w = 0;
	// Last three planes are a distance away from origin (1, 1, and 1)
	box[3].plane.x = 1;
	box[3].plane.y = 0;
	box[3].plane.z = 0;
	box[3].plane.w = -1;

	box[4].plane.x = 0;
	box[4].plane.y = 1;
	box[4].plane.z = 0;
	box[4].plane.w = -1;

	box[5].plane.x = 0;
	box[5].plane.y = 0;
	box[5].plane.z = 1;
	box[5].plane.w = -1;
}

AAB::AAB(float width, float height, float depth) {
	rx = width;
	ry = height;
	rz = depth;
	// First three planes go through the origin
	box[0].plane.x = 1;
	box[0].plane.y = 0;
	box[0].plane.z = 0;
	box[0].plane.w = 0;// d=-N.P =-N.O 

	box[1].plane.x = 0;
	box[1].plane.y = 1;
	box[1].plane.z = 0;
	box[1].plane.w = 0;// d=-N.P =-N.O 

	box[2].plane.x = 0;
	box[2].plane.y = 0;
	box[2].plane.z = 1;
	box[2].plane.w = 0;// d=-N.P=0  why? because p=origine (0,0,0)
// // Last three planes are a distance away from 
	//origin (width, height, and depth)
	// x=rx
	//1 * x + 0 * y + 0 * z - rx = 0
	box[3].plane.x = 1;
	box[3].plane.y = 0;
	box[3].plane.z = 0;
	box[3].plane.w = -rx; //d=-N.P , p(rx,0,0)
	// y=ry
	box[4].plane.x = 0;
	box[4].plane.y = 1;
	box[4].plane.z = 0;
	box[4].plane.w = -ry;//d=-N.P , p(ry,0,0)
	//z=rz
	box[5].plane.x = 0;
	box[5].plane.y = 0;
	box[5].plane.z = 1;
	box[5].plane.w = -rz;//d=-N.P , p(rz,0,0)
}
