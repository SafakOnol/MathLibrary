#include "Vec3.h"


Vec3::Vec3()
{
	x = 0;
	y = 0;
	z = 0;
}

Vec3::Vec3(float x_, float y_, float z_)
{
	x = x_;
	y = y_;
	z = z_;
}

void Vec3::add(Vec3 otherVec)
{
	x += otherVec.x;
	y += otherVec.y;
	z += otherVec.z;
}

void Vec3::subtract(Vec3 otherVec)
{
	x -= otherVec.x;
	y -= otherVec.y;
	z -= otherVec.z;
}

void Vec3::scalarMultiplication(float s)
{
	x *= s;
	y *= s;
	z *= s;
}

float Vec3::mag()
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

Vec3 Vec3::normalize()
{
	Vec3 n;
	float temp = mag();
	n.x = x / temp;
	n.y = y / temp;
	n.z = z / temp;
	return n;
}

float Vec3::dot(Vec3 otherVec)
{
	return x * otherVec.x + y * otherVec.y + z * otherVec.z;
}

Vec3 Vec3::cross(Vec3 otherVec)
{
	Vec3 crossVec3;
	crossVec3.x = y * otherVec.z - z * otherVec.y;
	crossVec3.y = z * otherVec.x - x * otherVec.z;
	crossVec3.z = x * otherVec.y - y * otherVec.x;
	return crossVec3;
}

void Vec3::lerp(Vec3 otherVec, float t)
{
	x = (1 - t) * x + (t * otherVec.x);
	x = (1 - t) * y + (t * otherVec.y);
	x = (1 - t) * z + (t * otherVec.z);
}

void Vec3::rotateZ(float angle)
{
	float temp = x;
	x = temp * cos(angle) - y * sin(angle);
	y = temp * sin(angle) + y * cos(angle);
}

Vec3 Vec3::operator + (const Vec3& v) const
{
	return Vec3(x + v.x, y + v.y, z + v.z);
}

Vec3 Vec3::operator - (const Vec3& v) const
{
	return Vec3(x - v.x, y - v.y, z - v.z);
}

Vec3 Vec3::operator * (const float v) const
{
	return Vec3(x * v, y * v, z * v);
}


