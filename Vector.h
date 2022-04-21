#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <string> 
#include <math.h>

using namespace std;
namespace MATH {

//#ifndef VERY_SMALL
//#define VERY_SMALL 1.0e-7f
//#endif
//
//#ifndef VERY_CLOSE_TO_ONE 
//#define	VERY_CLOSE_TO_ONE 0.9999f
//#endif
//#ifndef M_PI
//#define M_PI 3.14159265358979323846f
//#endif
//
//#ifndef DEGREES_TO_RADIANS
//#define DEGREES_TO_RADIANS (M_PI / 180.0f)
//#endif	
//
//#ifndef RADIANS_TO_DEGREES
//#define RADIANS_TO_DEGREES (180.0f / M_PI)
//#endif


	struct Vec3 {
		float  x, y, z;

		Vec3();
		Vec3(float x_, float y_, float z_);

		inline void set(float x_, float y_, float z_) { x = x_; y = y_; z = z_; }

		inline Vec3(const Vec3& v) { set(v.x, v.y, v.z); }

		//float
		float magV3();
		float dotV3(const Vec3 otherVec);
		float distanceV3(const Vec3& a, const Vec3& b); 

		//Vec
		Vec3 crossV3(const Vec3 otherVec);
		Vec3 normalizeV3();
		Vec3 lerpV3(const Vec3& v1, const Vec3& v2, float t);

		//Operators
		inline const float operator [] (int index) const { return *(&x + index); }

		inline float& operator [] (int index) { return *(&x + index); }
		///////////////////////////////////////////////
		//=
		Vec3 operator = (const float v) const;

		//+
		Vec3 operator + (const Vec3& v) const;

		//- 
		Vec3 operator - (const Vec3& v) const;

		//*
		Vec3 operator * (const float s) const;

		//-
		const Vec3 operator - () const { return Vec3(-x, -y, -z); }

		//* #2
		inline friend Vec3 operator * (const float s, const Vec3& v) { return v * s; }

//		inline const Vec3 operator / (const float s) const {
//#ifdef _DEBUG  
//			if (fabs(s) < VERY_SMALL) {
//				string errorMsg = __FILE__ + __LINE__;
//				throw errorMsg.append(": Divide by nearly zero! ");
//			}
//#endif
//			float r = 1.0f / s;
//			return *this * r;
//		}

		//+=
		Vec3& operator += (const Vec3& v);

		//-=
		Vec3& operator -= (const Vec3& v);

		//*=
		Vec3& operator *= (const float s);

		//conversion operators
		/*inline operator const float* () const { return static_cast<const float*>(&x); }
		inline operator float* () { return static_cast<float*>(&x); }*/
	};


	struct Vec4 {
		float  x, y, z, w;

		Vec4();
		Vec4(float x_, float y_, float z_, float d_);
		Vec4(const Vec4& v);


		float magV4();
		float dotV4(Vec4 otherVec);

		Vec4 normalizeV4();
		Vec4 crossV4(Vec4 otherVec);


		inline Vec4(const Vec3& v, const float w_) {
			x = v.x;
			y = v.y;
			z = v.z;
			w = w_;
		}

		inline Vec4(const Vec3& v) {
			x = v.x;
			y = v.y;
			z = v.z;
			w = 1.0f;
		}

		//Operators
		inline const float operator [] (int index) const { return *(&x + index); }

		inline float& operator [] (int index) { return *(&x + index); }
		///////////////////////////////////////////////
		//=
		Vec4 operator = (const float v)const;

		//+
		Vec4 operator + (const Vec4& v) const;

		//-						  
		Vec4 operator - (const Vec4& v) const;

		//*
		Vec4 operator * (const float s) const;

		//-
		Vec4 operator - () const { return Vec4(-x, -y, -z, -w); }

		////* #2
		//inline friend Vec4 operator * (const float s, const Vec4& v);

		///////////////////////////////////////////////

		//+=
		Vec4& operator += (const Vec4& v);

		//-=
		Vec4& operator -= (const Vec4& v);

		//*=
		Vec4& operator *= (const float s);

		////* friend
		//friend Vec4 operator * (const float s, const Vec4& v);


//		inline Vec4 operator / (const float s) const {
//#ifdef DEBUG  /// If in debug mode let's worry about divide by zero or nearly zero!!! 
//			if (std::fabs(s) < VERY_SMALL) {
//				std::string errorMsg = __FILE__ + __LINE__;
//				throw errorMsg.append(": Divide by nearly zero! ");
//			}
//#endif
//			float r = 1.0f / s;
//			return *this * r;
//		}

//		inline Vec4& operator /= (const float s) {
//#ifdef _DEBUG  /// If in debug mode let's worry about divide by zero or nearly zero!!! 
//			if (std::fabs(s) < VERY_SMALL) {
//				std::string errorMsg = __FILE__ + __LINE__;
//				throw errorMsg.append(": Divide by nearly zero! ");
//			}
//#endif //DEBUG
//
//			float r = 1.0f / s;
//			*this *= r;
//			return *this;
//		}

		inline void print(const char* comment = nullptr) {
			if (comment) printf("%s\n", comment);
			printf("%1.8f %1.8f %1.8f %1.8f\n", x, y, z, w);
		}

		//conversion operators 
		inline operator const float* () const { return static_cast<const float*>(&x); }
		inline operator float* () { return static_cast<float*>(&x); }
	};
}
#endif