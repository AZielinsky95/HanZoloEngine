#pragma once
#include <Windows.h>
#include <glew.h>
#include "GLTexture.h"

class Sprite
{

public: 

	Sprite();
	~Sprite();

	void init(float _x, float _y, float _width, float _height);
	void draw();

private:
	float x;
	float y;
	float width;
	float height;

	GLuint vboID;




};