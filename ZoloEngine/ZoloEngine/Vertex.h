#pragma once
#include "Vector3.h"
#include <glew.h>

struct Color
{
	GLubyte r;
	GLubyte g;
	GLubyte b;
	GLubyte a;
};

struct UV {
	float u;
	float v;
};

struct Vertex
{
	Vector3 position;
	Color color;

	//UV texture coordinates
	UV uv;
	//Vector3 normals;

	void setPosition(int _x, int _y, int _z)
	{
		position.x = _x;
		position.y = _y;
		position.z = _z;	
	}

	void setColor(GLubyte _r, GLubyte _g, GLubyte _b, GLubyte _a)
	{
		color.r = _r;
		color.g = _g;
		color.b = _b;
		color.a = _a;
	}

	void setUV(float _u, float _v)
	{
		uv.u = _u;
		uv.v = _v;
	}
	
};