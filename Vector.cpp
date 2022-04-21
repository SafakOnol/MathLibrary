#include "Vector.h"

using namespace MATH;
/////////////////////////Vec3/////////////////////////
Vec3::Vec3() {
	x = 0;
	y = 0;
	z = 0;
}

Vec3::Vec3(float x_, float y_, float z_) {
	x = x_;
	y = y_;
	z = z_;
}

float Vec3::magV3() {
	double mag = sqrt((x * x) + (y * y) + (z * z));
	return mag;
}

float MATH::Vec3::dotV3(const Vec3 otherVec) { return (x * otherVec.x + y * otherVec.y + z * otherVec.z); }

float MATH::Vec3::distanceV3(const Vec3& a, const Vec3& b) 
{
	Vec3 r = a - b;
	float d = r.magV3();
	return d; 
}

Vec3 Vec3::normalizeV3() 
{
	Vec3 n;
	float temp = magV3();
	n.x = x / temp;
	n.y = y / temp;
	n.z = z / temp;
	return n;
}



Vec3 Vec3::lerpV3(const Vec3& v1, const Vec3& v2, float t) 
{ 
	return (v1 + t * (v2 - v1)); 
}

Vec3 Vec3::crossV3(const Vec3 otherVec) {
	Vec3 crossVec3;
	crossVec3.x = y * otherVec.z - z * otherVec.y;
	crossVec3.y = z * otherVec.x - x * otherVec.z;
	crossVec3.z = x * otherVec.y - y * otherVec.x;
	return crossVec3;
}

//Operators Vec3
Vec3 Vec3::operator +(const Vec3& v) const { return Vec3(x + v.x, y + v.y, z + v.z); }

Vec3 Vec3::operator -(const Vec3& v) const { return Vec3(x - v.x, y - v.y, z - v.z); }

Vec3 Vec3::operator *(const float v) const { return Vec3(x * v, y * v, z * v); }

Vec3& Vec3::operator +=(const Vec3& v) {
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

Vec3& Vec3::operator -=(const Vec3& v) {
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

Vec3& Vec3::operator *=(const float s) {
	x *= s;
	y *= s;
	z *= s;
	return *this;
}

/////////////////////////Vec4/////////////////////////
Vec4::Vec4() {
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

Vec4::Vec4(float x_, float y_, float z_, float d_) {
	x = x_;
	y = y_;
	z = z_;
	w = d_;
}

Vec4::Vec4(const Vec4& v) {
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}

float Vec4::magV4() {
	double mag = sqrt((x * x) + (y * y) + (z * z) + (w * w));
	return mag;
}

float Vec4::dotV4(Vec4 otherVec) {
	float Dot4D(otherVec.x + y * otherVec.y + z * otherVec.z + w);
	return Dot4D;
}




Vec4 Vec4::normalizeV4() {

	Vec4 n4;
	double temp = magV4();
	n4.x = x / temp;
	n4.y = y / temp;
	n4.z = z / temp;
	n4.w = w / temp;
	return n4;	
}


//Operators Vec4
Vec4 Vec4::operator+(const Vec4& v) const { return Vec4(x + v.x, y + v.y, z + v.z, w + v.w); }

Vec4 Vec4::operator -(const Vec4& v) const { return Vec4(x - v.x, y - v.y, z - v.z, w - v.w); }

Vec4 Vec4::operator *(const float v) const { return Vec4(x * v, y * v, z * v, w * v); }

Vec4& Vec4::operator +=(const Vec4& v) {
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
	return *this;
}

Vec4& MATH::Vec4::operator -=(const Vec4& v) {
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;
	return *this;
}

Vec4& MATH::Vec4::operator *=(const float s) {
	x *= s;
	y *= s;
	z *= s;
	w *= s;
	return *this;
}