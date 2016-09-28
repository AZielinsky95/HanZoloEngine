#pragma once

#include "GLTexture.h"
#include <SOIL.h>
#include <string>

class Image
{
public:
	Image();
	~Image();


	void init(std::string filePath);

	void bind();
	void unbind();

/*	virtual int getPixelStorageParameter();

	virtual GLenum getPixelStorageType();

	virtual void setPixel(int x, int y, float r, float g, float b);

	virtual int getWidth(){ return texture.width; }
	virtual int getHeight(){ return texture.height; }

	//Returns the format used to represent the data
	virtual GLenum getPixelType();*/


private:
	GLTexture texture;
};

