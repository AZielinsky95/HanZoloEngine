#pragma once
#include "Vector3.h"

class Quaternion
{
public:
Vector3 quat;
float w;

Quaternion(){};

Quaternion(const Quaternion &obj)
{
	quat = obj.quat;
	w = obj.w;
}

inline Quaternion(Vector3 vector3, float w_)
{
quat = vector3; 
w = w_;
}

inline Quaternion operator + (Quaternion& q)
{
	return Quaternion(Vector3(quat.x + q.quat.x, quat.y + q.quat.y,quat.z + q.quat.z),w+q.w);
}

inline Quaternion operator = (Quaternion& q)
{
	return Quaternion(Vector3(quat.x = q.quat.x, quat.y = q.quat.y, quat.z = q.quat.z), w = q.w);
}

inline bool operator == (Quaternion& q)
{
	return (quat.x == q.quat.x && quat.y == q.quat.y & quat.z == q.quat.z) && w == q.w;
}

inline bool operator != (Quaternion& q)
{
	return (quat.x != q.quat.x && quat.y != q.quat.y & quat.z != q.quat.z) && w != q.w;
}

inline Quaternion operator - (Quaternion& q)
{
	return Quaternion(Vector3(quat.x - q.quat.x, quat.y - q.quat.y,quat.z - q.quat.z),w-q.w);
}

inline Quaternion operator * (float q)
{
	return Quaternion(Vector3(quat.x * q,quat.y * q, quat.z * q),w*q);
}

inline const Quaternion operator / (float q)
{
	return Quaternion(Vector3(quat.x /q,quat.y /q, quat.z / q),w/q);
}

inline float GetMagnitude(const Quaternion q)
{
	return sqrt(q.quat.x * q.quat.x + q.quat.y * q.quat.y + q.quat.z * q.quat.z + w * w);
}

inline float GetMag()
{
	return sqrt(quat.x * quat.x + quat.y * quat.y + quat.z * quat.z + w * w);
}

inline Quaternion Normalize()
{
	return *this/GetMag();
}

inline float DotProduct(Quaternion other)
{
	return (quat.x * other.quat.x) + (quat.y * other.quat.y) + (quat.z  * other.quat.z) + (w * other.w);
}

inline Quaternion CalcCrossProduct(Quaternion quat2)
{
	Vector3 cross = Vector3::CalcCrossProduct(quat,quat2.quat);
	float _w    = Vector3::DotProduct(quat,quat2.quat);

	return Quaternion(cross,-_w);
}

inline Quaternion Conjugate()
{
	quat.x = -quat.x;
	quat.y = -quat.y;
	quat.z = -quat.z;
	w = -w;
	return Quaternion(quat,w);
}

inline Quaternion Inverse()
{
	return Conjugate()/(GetMag() * GetMag());
}

inline Quaternion Product(Quaternion other)
{
	Quaternion product = CalcCrossProduct(other);
	product.quat.x - DotProduct(other);
	product.quat.y - DotProduct(other);
	product.quat.z - DotProduct(other);
	product.w - DotProduct(other);

	return product;
}

inline Quaternion RotX(Quaternion &q, float theta)
{
	Vector3 n = Vector3(1,0,0);

	q.quat.x = sin(theta/2) * n.x;
	q.quat.y = sin(theta/2) * n.y;
	q.quat.z = sin(theta/2) * n.z;
	w		 = cos(theta/2);

	return q;

}

inline Quaternion RotY(Quaternion &q, float theta)
{
	Vector3 n = Vector3(0,1,0);

	q.quat.x = sin(theta/2) * n.x;
	q.quat.y = sin(theta/2) * n.y;
	q.quat.z = sin(theta/2) * n.z;
	w		 = cos(theta/2);

	return q;

}

inline Quaternion RotZ(Quaternion &q, float theta)
{
	Vector3 n = Vector3(0,0,1);

	q.quat.x = sin(theta/2) * n.x;
	q.quat.y = sin(theta/2) * n.y;
	q.quat.z = sin(theta/2) * n.z;
	w		 = cos(theta/2);

	return q;

}

//LINEAR INTERPOLATION (LERP)
inline Quaternion Lerp(Quaternion q1,Quaternion q2,float t)
{
    return Quaternion((q1 + ((q2-q1)*t)).Normalize());
}

//SLERP
static Quaternion Slerp(Quaternion &q1, Quaternion &q2, float t)
{
 float angle = acos(q1.DotProduct(q2)) * (3.14/180);
 return q1 * ((sin(angle) * (1 - t)) / sin(angle)) + q2 * ((sin(t * angle)) / sin(angle));

}

};