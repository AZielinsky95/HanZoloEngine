#include "Frustum.h"
#define ANG2RAD 3.14159265358979323846/180.0

Frustum::Frustum()
{
}


Frustum::~Frustum()
{
}


void Frustum::setCamInternals(float angle, float ratio, float nearD, float farD)
{
	// store the information
	this->ratio = ratio;
	this->angle = angle;
	this->nearD = nearD;
	this->farD = farD;

	// compute width and height of the near and far plane sections
	tang = (float)tan(ANG2RAD * angle * 0.5);
	nh = nearD * tang;
	nw = nh * ratio;
	fh = farD  * tang;
	fw = fh * ratio;
}

void Frustum::setCamDef(glm::vec3 &p, glm::vec3 &l, glm::vec3 &u)
{
	glm::vec3 dir, nc, fc, X, Y, Z;

	// compute the Z axis of camera
	// this axis points in the opposite direction from 
	// the looking direction
	Z = p - l;
	Z = glm::normalize(Z);

	// X axis of camera with given "up" vector and Z axis
	X = u * Z;
	X = glm::normalize(X);

	// the real "up" vector is the cross product of Z and X
	Y = Z * X;

	// compute the centers of the near and far planes
	nc = p - Z * nearD;
	fc = p - Z * farD;

	// compute the 4 corners of the frustum on the near plane
	ntl = nc + Y * nh - X * nw;
	ntr = nc + Y * nh + X * nw;
	nbl = nc - Y * nh - X * nw;
	nbr = nc - Y * nh + X * nw;

	// compute the 4 corners of the frustum on the far plane
	ftl = fc + Y * fh - X * fw;
	ftr = fc + Y * fh + X * fw;
	fbl = fc - Y * fh - X * fw;
	fbr = fc - Y * fh + X * fw;

	// compute the six planes
	// the function set3Points assumes that the points
	// are given in counter clockwise order
	pl[TOP].fromPoints(ntr, ntl, ftl);
	pl[BOTTOM].fromPoints(nbl, nbr, fbr);
	pl[LEFT].fromPoints(ntl, nbl, fbl);
	pl[RIGHT].fromPoints(nbr, ntr, fbr);
	pl[NEARP].fromPoints(ntl, ntr, nbr);
	pl[FARP].fromPoints(ftr, ftl, fbl);
}



int Frustum::pointInFrustum(glm::vec3 &p)
{
	int result = INSIDE;
	for (int i = 0; i < 6; i++) {

		if (pl[i].dot(pl[i],p) < 0)
			return OUTSIDE;
	}
	return(result);
}
