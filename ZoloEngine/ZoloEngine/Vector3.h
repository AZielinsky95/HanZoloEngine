#pragma once
#include <math.h>
#include <cstdio>

class Vector3{
private:


public:
	float x, y, z;

	Vector3(){ x = y = z = 0.0f; }

	Vector3(const Vector3 &obj)
	{
		x = obj.x;
		y = obj.y;
		z = obj.z;
	};

	inline Vector3(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	static inline Vector3 CalcCrossProduct(const Vector3& v1, const Vector3& v2)
	{
		float newX, newY, newZ;
		newX = (v1.y * v2.z) - (v1.z * v2.y);
		newY = (v1.z * v2.x) - (v1.x * v2.z);
		newZ = (v1.x * v2.y) - (v1.y * v2.x);

		return Vector3(newX, newY, newZ);
	}

	inline const Vector3 operator - (const Vector3& v)
	{
		return Vector3(x - v.x, y - v.y, z - v.z);
	}

	inline const Vector3 operator + (const Vector3& v)
	{
		return Vector3(x + v.x, y + v.y, z + v.z);
	}

	inline const Vector3 operator * (const float s)
	{
		return Vector3(s*x, s*y, s*z);
	}

	inline const Vector3 operator * (const Vector3& v)
	{
		return Vector3(v.x*x, v.y*y, v.z*z);
	}

	inline const Vector3 operator / (const float s)
	{
		return Vector3(x / s, y / s, z / s);
	}

	inline const Vector3 operator += (const Vector3& v)
	{
		return Vector3(x += v.x, y += v.y, z += v.z);
	}

	inline Vector3 operator = (const Vector3& v)
	{
		return Vector3(x = v.x, y = v.y, z = v.z);
	}

	inline bool operator == (const Vector3& v)
	{
		return(x == v.x && y == v.y && z == v.z);
	}

	inline bool operator != (const Vector3& v)
	{
		return(x != v.x && y != v.y && z != v.z);
	}

	inline const Vector3 operator -= (const Vector3& v)
	{
		return Vector3(x -= v.x, y -= v.y, z -= v.z);
	}

	inline const Vector3 operator *= (const Vector3& v)
	{
		return Vector3(x *= v.x, y *= v.y, z *= v.z);
	}

	inline float GetMag()
	{
		return sqrt(x * x + y * y + z * z);
	}

	inline Vector3 Normalize()
	{
		return *this / GetMag();
	}

	inline static float DotProduct(Vector3 ths, Vector3 other)
	{
		return (ths.x * other.x) + (ths.y * other.y) + (ths.z  * other.z);
	}

	inline void PrintToConsole()
	{
		printf("x: %f, y: %f, z: %z", x, y, z);
	}


};

