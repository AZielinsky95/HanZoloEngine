#pragma once

#include <glm.hpp>
#include "Plane.h"
#include "Vector3.h"


class Frustum
{
public:

	Frustum();
	~Frustum();

	static enum {OUTSIDE, INTERESECT, INSIDE};

	Plane pl[6];

	// First letter indicates where point is on the near or far plane
	// Second letter indicates where the point is on the top or bottom
	// Third letter indicates whether point is on left or right

	glm::vec3 ntl, ntr, nbl, nbr, ftl, ftr, fbl, fbr;

	// nearD: distance from camera to near plane
	// farD : distance from camera to far plane
	float nearD, farD, ratio, angle, tang;

	//nearWidth,nearHeight,farWidth,farHeight
	float nw, nh, fw, fh;

	/*This function takes exactly the same parameters as the function gluPerspective.
	Each time the perspective definitions change, for instance when a window is resized, 
	this function should be called as well. */

	void setCamInternals(float angle, float ratio, float nearD, float farD);

	//This function takes three vectors that contain the information for the gluLookAt function : 
	//the position of the camera, a point to where the camera is pointing and the up vector.
	//Each time the camera position or orientation changes, this function should be called as well.

	void setCamDef(glm::vec3 &p, glm::vec3 &l, glm::vec3 &u);

	/*Once the planes have been extracted, it is possible to find out if a point is inside or outside 
	the frustum.Computing the signed distance tells us which side of the plane the point is on.
	Assuming that the planes' normals are pointing inwards, then if the signed distance is negative 
	the point is outside the frustum. Otherwise the point is on the right side of the plane.*/

	int pointInFrustum(glm::vec3 &p);


	//int sphereInFrustum(glm::vec3 &p, float ratio);
	int boxInFrustum(Vector3 center,int width,int height,int depth);


private:

	enum {TOP = 0,BOTTOM ,LEFT ,RIGHT ,NEARP ,FARP };
	

};

