#include "Quaternion.h"

using namespace MATH;

Quaternion::Quaternion() {
	q.w = 1.0f;
	q.x = 0.0f;
	q.y = 0.0f;
	q.z = 0.0f;
	

};

Quaternion::Quaternion(float w_, Vec3 v_) {
	q.w = w_;
	q.x = v_.x;
	q.y = v_.y;
	q.z = v_.z;
	
};

Quaternion::Quaternion(float x_, float y_, float z_, float w_) {
	d = w_;
	v.x = x_;
	v.y = y_;
	v.z = z_;
};


void Quaternion::set(Vec3 v_) {
	v.x = v_.x;
	v.y = v_.y;
	v.z = v_.z;
}

Quaternion Quaternion::operator + (const Quaternion& otherQuat) {
	return Quaternion(d + otherQuat.d, v + otherQuat.v);
};

Quaternion Quaternion::operator - (const Quaternion& otherQuat) {
	return Quaternion(d - otherQuat.d, v - otherQuat.v);
};

Quaternion Quaternion::operator * (const Quaternion& otherQuat) {

	Vec3 ijk(d * otherQuat.v + otherQuat.d * v + v.crossV3(otherQuat.v)); 
	Vec3 ijk_result((d * otherQuat.v) + (otherQuat.d * v) + v.crossV3(otherQuat.v));
	return Quaternion((d * otherQuat.d) - (v.dotV3(otherQuat.v)), ijk_result);
};

Vec3 Quaternion::Rotate(Vec3 axis, float angleInDegrees) {
	float radians = angleInDegrees;
	Vec3 axisNormalized = axis.normalizeV3();
	d = cos(radians / 2);
	Vec3 imaginary = axisNormalized * (sin(radians / 2));
	return (imaginary);

	Quaternion result((axis.x * sin(0.5f * radians)), (axis.y * sin(0.5f * radians)), (axis.z * sin(0.5f * radians)), (cos(0.5f * radians)));
	return Vec3((axis.x * sin(0.5f * radians)), (axis.y * sin(0.5f * radians)), (axis.z * sin(0.5f * radians)));
};


Quaternion Quaternion::Normalize() {
	float mag = Mag();
	Quaternion temp;
	temp.d = d / mag;
	temp.v.x = v.x / mag;
	temp.v.y = v.y / mag;
	temp.v.z = v.z / mag;
	return temp;
};

float Quaternion::Mag()
{
	return sqrt((v.x * v.x)  + (v.y * v.y) + (v.z * v.z) + (d * d));
}

Quaternion Quaternion::Conjugate()
{
	return Quaternion(-v.x, -v.y, -v.z, d);
}

Quaternion Quaternion::Inverse()
{
	Quaternion input(v.x, v.y, v.z, d);
	Quaternion p = input.Conjugate();
	float m = input.Mag() * input.Mag();
	return Quaternion(p.v.x / m, p.v.y / m, p.v.z / m, p.d / m);
}
