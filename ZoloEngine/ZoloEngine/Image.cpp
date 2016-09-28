#include "Image.h"
#include "Errors.h"

Image::Image()
{
	texture.id = 0;
}
Image::~Image()
{
}

void Image::init(std::string filePath)
{
	//Initializes texture properties to 0!
	texture = {};

	// Load and create a texture 
	glGenTextures(1, &(texture.id));
	glBindTexture(GL_TEXTURE_2D, texture.id);

	// Set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	// Set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//Load And Generate Texture
	unsigned char* image = SOIL_load_image(filePath.c_str(), &texture.width, &texture.height, 0, SOIL_LOAD_RGBA);

	if (image == '\0')
	{
		fatalError("Unable to load image.");
	}

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture.width, texture.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

}

void Image::bind()
{

	glBindTexture(GL_TEXTURE_2D,texture.id);

}

void Image::unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}


