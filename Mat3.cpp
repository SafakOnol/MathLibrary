#include "Mat3.h"

Mat3::Mat3()
{
	// matrix constructor
	// set matrix entries to the identity matrix
	setIdentity(); 
	
}

void Mat3::setIdentity()
{
	// setIdentity member function
	// set matrix entries to the identity matrix
	for (int i = 0; i < 9; ++i)
	{
		m[i] += 1;
	}
}

void Mat3::rotateZ(float angle)
{
	// rotateZ member function
	// set matrix entries to the rotation matrix

	// cos(angle) -sin(angle) m[2]
	// sin(angle)  cos(angle) m[5]
	// m[6]        m[7]		  m[8]
	for (int i = 0; i < 9; ++i)
	{
		if (i == 0)
		{
		m[i] = cos(angle);
		}
		else if (i == 1)
		{
		m[i] = -1 * sin(angle);
		}
		else if (i == 3)
		{
		m[i] = sin(angle);
		}
		else if (i == 4)
		{
		m[i] = cos(angle);
		}
	}
}

void Mat3::scale(float x, float y, float z)
{
	// scale member function
	// set matrix entries to the scale matrix

	// x 0 0 
	// 0 y 0
	// 0 0 z
	for (int i = 0; i < 9; ++i)
	{
		if (i == 0)
		{
			m[i] = x;
		}
		else if (i == 4)
		{
			m[i] = y;
		}
		else if (i == 8)
		{
			m[i] = z;
		}
		else
		{
			m[i] = 0;
		}
	}
}

void Mat3::transpose()
{
	// transpose member function
	// set matrix entries to the transpose matrix

	// 0 1 2	 0 3 6 -- m[0] m[1] m[2]    m_0 m_3 m_6
	// 3 4 5 - > 1 4 7 -- m[3] m[4] m[5] -> m_1 m_4 m_7
	// 6 7 8	 2 5 8 -- m[6] m[7] m[8]    m_2 m_5 m_8

	float m_1 = m[1];
	float m_2 = m[2];
	float m_3 = m[3];
	float m_5 = m[5];
	float m_6 = m[6];
	float m_7 = m[7];

	for (int i = 0; i < 9; ++i)
	{
		if (i == 1)
		{
			m[i] = m_3;
		}
		else if (i == 3)
		{
			m[i] = m_1;
		}
		else if (i == 2)
		{
			m[i] = m_6;
		}
		else if (i == 6)
		{
			m[i] = m_2;
		}
		else if (i == 5)
		{
			m[i] = m_7;
		}
		else if (i == 7)
		{
			m[i] = m_5;
		}
	}
}

float Mat3::det()
{
	// determinant member function
	// calculate the determinant of a matrix
	float det_;
	det_ = m[0] * (m[4] * m[8] - m[5] * m[7]) - m[1] * (m[3] * m[8] - m[5] * m[6]) + m[2] * (m[3] * m[7] - m[4] * m[6]);
	return det_;
}

void Mat3::inverse()
{
	// inverse member function
	// calculate the inverse matrix

	int a = m[0];
	int b = m[1];
	int c = m[2];
	int d = m[3];
	int e = m[4];
	int f = m[5];
	int g = m[6];
	int h = m[7];
	int i = m[8];

	m[0] = ((e * i) - (f * h));
	m[1] = ((c * h) - (b * i));
	m[2] = ((b * f) - (c * e));
	m[3] = ((f * g) - (d * i));
	m[4] = ((a * i) - (c * g));
	m[5] = ((c * d) - (a * f));
	m[6] = ((d * h) - (e * g));
	m[7] = ((b * g) - (a * h));
	m[8] = ((a * e) - (b * d));
}

//Mat3 Mat3::operator*(Mat3 otherMat)
//{
//	// multiplication member function
//	// calculate and return the result of the multiplication of two matrices
//	Mat3 mat3_;
//	for (int i = 0; i < 3; ++i)
//	{
//		for (int j = 0; j < 3; ++j)
//		{
//			mat3_.m[i * 3 + j] = (m[0 * 3 + j] * otherMat.m[i * 3 + 0]) + (m[1 * 3 + j] * otherMat.m[i * 3 + 1]) + (m[2 * 3 + j] * otherMat.m[i * 3 + 2]);
//		}
//	}
//	return mat3_;
//}
//
//Vec3 Mat3::operator*(Vec3 vector)
//{
//	// matrix and vector multiplication member function
//	// calculate and return the result of the multiplication of a matrix and a vector
//	Vec3 vec3_;
//	vec3_.x = vector.x * m[0] + vector.y * m[3] + vector.z * m[6];
//	vec3_.y = vector.x * m[1] + vector.y * m[4] + vector.z * m[7];
//	vec3_.z = vector.x * m[2] + vector.z * m[5] + vector.z * m[8];
//	return vec3_;
//}