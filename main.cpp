
#include <iostream>

#include "Vector.h"
#include "Ray.h"
#include "Plane.h"
#include "Sphere.h"
#include "Collider.h"
#include "AAB.h"
#include "Quaternion.h"

int main(int argc, char* args[])
{

	// ASSIGNMENT 1 -------------- // 

	cout << "ASSIGNMENT 1 OUTPUT: " << endl;
	cout << "" << endl;
	cout << "" << endl;

	Vec3 v(2, 2, 1);
	Vec3 u(4, 2, 1);

	cout << "v = (" << v.x << "," << v.y << "," << v.z << ")" << endl;
	cout << "u = (" << u.x << "," << u.y << "," << u.z << ")" << endl;

	// Magnitude

	float vMag = v.magV3();
	cout << "Magnitude of v = " << vMag << endl;

	// Normalize
	Vec3 vN = v.normalizeV3();
	cout << "Normalized Vec v = (" << vN.x << "), (" << vN.y << "), (" << vN.z << ")" << endl;

	// Dot product v.u

	float vDotU = v.dotV3(u);
	cout << "Dot product of Vec3 v and Vec3 u = " << vDotU << endl;

	// Cross product Vec3 u x Vec3 v

	Vec3 uCrossV = u.crossV3(v);
	cout << "Cross product of Vec3 u x Vec3 v = (" << uCrossV.x << "), (" << uCrossV.y << "), (" << uCrossV.z << ")" << endl;

	// // // // // // // // // -----------------

	Vec4 v4(0, 0, 0, 1);
	Vec4 u4(0, 0, 0, 1);

	// Magnitude of Vec4
	float vMag4 = v4.magV4();
	cout << "Magnitude of v4 = " << vMag4 << endl;

	// Normalize Vec4

	Vec4 nVec4 = v4.normalizeV4();
	cout << "Normalized Vec4 v4 = (" << nVec4.x << "), (" << nVec4.y << "), (" << nVec4.z << "), (" << nVec4.w << ")" << endl;

	// Dot Vec4
	float V4dotU4 = v4.dotV4(u4);
	cout << "Dot product of Vec4 v4 . Vec4 u4= " << V4dotU4 << endl;

	// ASSIGNMENT 1 ENDS ----------- // 


	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "ASSIGNMENT 2 OUTPUT: " << endl;
	cout << "" << endl;
	cout << "" << endl;

	// ASSIGNMENT 2 STARTS ---------// 

	Ray ray(Vec3(1.0f, 0.0f, 1.0f), Vec3(3.0f, 2.0f, 1.0f));
	cout << "Ray: \n" << endl;
	cout << "Ray Start: (" << ray.start.x << "," << ray.start.y << "," << ray.start.z << ")" << endl;
	printf("\n");
	//Ray Dir
	cout << "Ray Dir: (" << ray.dir.x << "," << ray.dir.y << "," << ray.dir.z << ")" << endl;
	printf("\n");

	Plane plane(2.0f, 1.0f, 0.0f, -4.0f);
	plane.print();
	printf("\n");

	Vec3 inter = plane.intersectPoint(ray);
	cout << "Intersection point: " << "(" << inter.x << "," << inter.y << "," << inter.z << ")" << endl; 


	// ASSIGNMENT 2 ENDS -----------//

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// ASSIGNMENT 3 STARTS ---------// 

	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "ASSIGNMENT 3 OUTPUT: " << endl;
	cout << "" << endl;
	cout << "" << endl;

	Vec3 rStart(2.0f, -1.0f, -1.0f);
	Vec3 rDir(0.0f, 2.0f, 3.0f);
	Sphere sphere(Vec3(0.0f, 0.0f, 0.0f), 5.0f);
	AAB cube(20.0f, 10.0f, 10.0f);
	Ray ray2(rStart, rDir);

	

	if (Collider::RaySphereCollisionDetected(ray2, sphere) == true)
	{
		Vec3 rpCol = (Collider::RaySphereCollisionPoint(ray2, sphere));
		cout << "\n RAY - SPHERE COLLISION: " << endl;
		cout << "Value of intersection: " << "(" << rpCol.x << "," << rpCol.y << "," << rpCol.z << ")" <<endl;
	}
	
	cout << "\n RAY - BOX COLLISION: " << endl;

	Vec3 intersection = Collider::RayAABCollisionPoint(ray2, cube);
	cout << " Value of intersection: " << "(" << intersection.x << "," << intersection.y << "," << intersection.z << ")" << endl; 

	// ASSIGNMENT 3 ENDS -----------//

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// ASSIGNMENT 4 STARTS ---------// 

	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "ASSIGNMENT 4 OUTPUT: " << endl;
	cout << "" << endl;
	cout << "" << endl;

	Quaternion quat1(1.0f, 2.0f, 2.0f, 3.0f);
	Quaternion quat2(2.0f, 1.0f, 2.0f, 5.0f);

	cout << "\n q1: " << "(" << quat1.v.x << "," << quat1.v.y << "," << quat1.v.z << "," << quat1.d << ")" << endl;
	cout << "\n q2: " << "(" << quat2.v.x << "," << quat2.v.y << "," << quat2.v.z << "," << quat2.d << ")" << endl;

	Quaternion result = quat1 * quat2;
	cout << "\n q1 * q2: " << "(" << result.q.x << "," << result.q.y << "," << result.q.z << "," << result.q.w << ")" << endl;

	Quaternion resultAdd = quat1 + quat2;
	cout << "\n q1 + q2: " << "(" << resultAdd.q.x << "," << resultAdd.q.y << "," << resultAdd.q.z << "," << resultAdd.q.w << ")" << endl;

	Quaternion resultSub = quat1 - quat2;
	cout << "\n q1 - q2: " << "(" << resultSub.q.x << "," << resultSub.q.y << "," << resultSub.q.z << "," << resultSub.q.w << ")" << endl;

	cout << "\n q1 conjugate: " << "(" << quat1.Conjugate().v.x << "," << quat1.Conjugate().v.y << "," << quat1.Conjugate().v.z << "," << quat1.Conjugate().d << ")" << endl;

	cout << "\n q1 magnitude: " << quat1.Mag() << endl;

	cout << "\n q1 inverse: " << "(" << quat1.Inverse().v.x << "," << quat1.Inverse().v.y << "," << quat1.Inverse().v.z << "," << quat1.Inverse().d << ")" << endl;

	cout << "\n q1 normalized: " << "(" << quat1.Normalize().v.x << "," << quat1.Normalize().v.y << "," << quat1.Normalize().v.z << "," << quat1.Normalize().d << ")" << endl;

	Quaternion quat3(1.0f, 1.0f, 1.0f, 0.0f);
	float angle = 90.0f;
	Vec3 Vec(1.0f, 0.0f, 0.0f);
	Vec3 rotation = quat3.Rotate(Vec, angle);
	cout << "\n rotated vector = " << "(" << rotation.x << "," << rotation.y << "," << rotation.z << "," << rotation.z << ")" << endl;

	return 0;



	// ASSIGNMENT 4 ENDS -----------//


}	
