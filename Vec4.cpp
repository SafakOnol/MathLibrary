#include "Vec4.h"


Vec4::Vec4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 1;
}

Vec4::Vec4(float _x, float _y, float _z, float _w)
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}

float Vec4::Mag()
{
	double mag = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w, 2));
	return mag;
}

Vec4 Vec4::Normalize() {

	Vec4 normalizedVec4(x, y, z, w);
	float temp = Mag();
	x = x / temp;
	y = y / temp;
	z = z / temp;
	w = w / temp;
	return normalizedVec4;
}

float Vec4::Dot(Vec4 b4)
{
	float dot4 = ((b4.x * x), (b4.y * y), (b4.z * z), (b4.w * w));
	return dot4;
}

Vec4 Vec4::operator + (const Vec4& v) const
{
	return Vec4(x + v.x, y + v.y, z + v.z, w + v.w);
}

Vec4 Vec4::operator - (const Vec4& v) const
{
	return Vec4(x - v.x, y - v.y, z - v.z, w - v.w);
}

Vec4 Vec4::operator * (const float f) const
{
	return Vec4(x * f, y * f, z * f, w * f);
}
