#pragma once
#include <cstdio>
#include <math.h>
//#include "Vector4.h"

class Matrix4x4
{
private:
	float m[16];
public:

	Matrix4x4(){ LoadIndentity(); }

	Matrix4x4(const Matrix4x4 &obj)
	{
		m[0] = obj.m[0];
		m[1] = obj.m[1];
		m[2] = obj.m[2];
		m[3] = obj.m[3];
		m[4] = obj.m[4];
		m[5] = obj.m[5];
		m[6] = obj.m[6];
		m[7] = obj.m[7];
		m[8] = obj.m[8];
		m[9] = obj.m[9];
		m[10] = obj.m[10];
		m[11] = obj.m[11];
		m[12] = obj.m[12];
		m[13] = obj.m[13];
		m[14] = obj.m[14];
		m[15] = obj.m[15];
	}

	// Matrix 4x4 Constructor
	inline Matrix4x4(float m0, float m1, float m2, float m3,
		float m4, float m5, float m6, float m7,
		float m8, float m9, float m10, float m11,
		float m12, float m13, float m14, float m15)
	{
		m[0] = m0;
		m[1] = m1;
		m[2] = m2;
		m[3] = m3;
		m[4] = m4;
		m[5] = m5;
		m[6] = m6;
		m[7] = m7;
		m[8] = m8;
		m[9] = m9;
		m[10] = m10;
		m[11] = m11;
		m[12] = m12;
		m[13] = m13;
		m[14] = m14;
		m[15] = m15;
	}

	//Load Identity Matrix
	inline void LoadIndentity()
	{
		m[0] = 1.0f; m[4] = 0.0f; m[8] = 0.0f;  m[12] = 0.0f;
		m[1] = 0.0f; m[5] = 1.0f; m[9] = 0.0f;  m[13] = 0.0f;
		m[2] = 0.0f; m[6] = 0.0f; m[10] = 1.0f; m[14] = 0.0f;
		m[3] = 0.0f; m[7] = 0.0f; m[11] = 0.0f; m[15] = 1.0f;
	}


	//4x4 + 4x4
	inline const Matrix4x4 operator + (Matrix4x4& other)
	{
		return Matrix4x4(m[0] + other.m[0], m[4] + other.m[4], m[8] + other.m[8], m[12] + other.m[12],
			m[1] + other.m[1], m[5] + other.m[5], m[9] + other.m[9], m[13] + other.m[13],
			m[2] + other.m[2], m[6] + other.m[6], m[10] + other.m[10], m[14] + other.m[14],
			m[3] + other.m[3], m[7] + other.m[7], m[11] + other.m[11], m[15] + other.m[15]);
	}

	//4x4 - 4x4
	inline const Matrix4x4 operator - (Matrix4x4& other)
	{
		return Matrix4x4(m[0] - other.m[0], m[4] - other.m[4], m[8] - other.m[8], m[12] - other.m[12],
			m[1] - other.m[1], m[5] - other.m[5], m[9] - other.m[9], m[13] - other.m[13],
			m[2] - other.m[2], m[6] - other.m[6], m[10] - other.m[10], m[14] - other.m[14],
			m[3] - other.m[3], m[7] - other.m[7], m[11] - other.m[11], m[15] - other.m[15]);
	}

	//4x4 = 4x4
	inline const Matrix4x4 operator = (Matrix4x4& other)
	{
		return Matrix4x4(m[0] = other.m[0], m[4] = other.m[4], m[8] = other.m[8], m[12] = other.m[12],
			m[1] = other.m[1], m[5] = other.m[5], m[9] = other.m[9], m[13] = other.m[13],
			m[2] = other.m[2], m[6] = other.m[6], m[10] = other.m[10], m[14] = other.m[14],
			m[3] = other.m[3], m[7] = other.m[7], m[11] = other.m[11], m[15] = other.m[15]);
	}

	//4x4 == 4x4
	inline bool operator == (Matrix4x4& other)
	{
		return (m[0] == other.m[0]&& m[4] == other.m[4]&& m[8] == other.m[8]&& m[12] == other.m[12]&&
			m[1] == other.m[1]&& m[5] == other.m[5]&& m[9] == other.m[9]&& m[13] == other.m[13]&&
			m[2] == other.m[2]&& m[6] == other.m[6]&& m[10] == other.m[10]&& m[14] == other.m[14]&&
			m[3] == other.m[3]&& m[7] == other.m[7]&& m[11] == other.m[11]&& m[15] == other.m[15]);
	}

	inline bool operator != (Matrix4x4& other)
	{
		return (m[0] != other.m[0]&& m[4] != other.m[4]&& m[8] != other.m[8]&& m[12] != other.m[12]&&
			m[1] != other.m[1]&& m[5] != other.m[5]&& m[9] != other.m[9]&& m[13] != other.m[13]&&
			m[2] != other.m[2]&& m[6] != other.m[6]&& m[10] != other.m[10]&& m[14] != other.m[14]&&
			m[3] != other.m[3]&& m[7] != other.m[7]&& m[11] != other.m[11]&& m[15] != other.m[15]);
	}

	//4x4 * 4x4
	inline const Matrix4x4 operator * (double other)
	{
		return Matrix4x4(m[0] * other, m[4] * other, m[8] * other, m[12] * other,
			m[1] * other, m[5] * other, m[9] * other, m[13] * other,
			m[2] * other, m[6] * other, m[10] * other, m[14] * other,
			m[3] * other, m[7] * other, m[11] * other, m[15] * other);
	}

	//Transpose 4x4
	inline Matrix4x4 Transpose()
	{
		return Matrix4x4(m[0], m[1], m[2], m[3],
			m[4], m[5], m[6], m[7],
			m[8], m[9], m[10], m[11],
			m[12], m[13], m[14], m[15]);
	}

	//Transformations

	inline Matrix4x4 BuildScalingMatrix(float Sx, float Sy, float Sz)
	{
		return Matrix4x4(Sx, 0.0f, 0.0f, 0.0f, 0.0f, Sy, 0.0f, 0.0f, 0.0f, 0.0f, Sz, 0.0f, 0.0f, 0.0f, 0.0f, 1);
	}

	inline Matrix4x4 BuildTranslationMatrix(float x, float y, float z)
	{
		return Matrix4x4(0.0f, 0.0f, 0.0f, x, 0.0f, 0.0f, 0.0f, y, 0.0f, 0.0f, 0.0f, z, 0.0f, 0.0f, 0.0f, 0.0f);

	}

	inline Matrix4x4 BuildRotationX(float angle)
	{

		return Matrix4x4(1, 0, 0, 0,
			0, cos(angle), -sin(angle), 0,
			0, sin(angle), cos(angle), 0,
			0, 0, 0, 1);

	}

	inline Matrix4x4 BuildRotationY(float angle)
	{

		return Matrix4x4(cos(angle), 0, sin(angle), 0,
			0, 1, 0, 0,
			-sin(angle), 0, cos(angle), 0,
			0, 0, 0, 1);

	}

	inline Matrix4x4 BuildRotationZ(float angle)
	{

		return Matrix4x4(cos(angle), -sin(angle), 0, 0,
			sin(angle), cos(angle), 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1);

	}

	inline void Print()
	{
		printf("%f, %f, %f, %f,\n%f, %f, %f, %f,\n%f, %f, %f, %f,\n%f, %f, %f, %f\n",
			m[0], m[4], m[8], m[12],
			m[1], m[5], m[9], m[13],
			m[2], m[6], m[10], m[14],
			m[3], m[7], m[11], m[15]);
	}
};