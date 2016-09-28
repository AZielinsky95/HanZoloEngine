#pragma once

#include <glm.hpp>
#include <glew.h>
#include <gtc/matrix_transform.hpp>

#include "Vector3.h"
#include "Frustum.h"
#include "GLSLProgram.h"


class Camera
{
public:
	Camera();
	~Camera();

	void init(int _screenWidth, int _screenHeight);

	void update();

	//setters
	void setPosition(const Vector3& newPosition) { position = newPosition;  }
	void setScale(const float newScale) { scale = newScale;  }

	//getters
	Vector3 getPosition() { return position; }
	float getScale() { return scale; }
	glm::mat4 getProjectionMatrix() { return projectionMatrix; }
	glm::mat4 getModelViewMatrix() { return modelViewMatrix; }
	//glm::mat4 getTranslationMatrix() { return translationMatrix; }
	//glm::mat4 getEndMatrix() { return endMatrix; }

private:
	int screenWidth, screenHeight;
	float scale;
	Vector3 position;
	Frustum frustum;
	glm::mat4 projectionMatrix;
	glm::mat4 modelViewMatrix;

};

