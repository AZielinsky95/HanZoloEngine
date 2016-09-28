#include "Camera.h"



Camera::Camera() : position(0.0f, 0.0f, 5.0f),
	scale(1.0f),
	modelViewMatrix(1.0f),
	projectionMatrix(1.0f),
	screenWidth(1024),
	screenHeight(768)

{
}

Camera::~Camera()
{
}

void Camera::init(int _screenWidth, int _screenHeight)
{
	screenWidth = _screenWidth;
	screenHeight = _screenHeight;
}

void Camera::update()
{
		projectionMatrix = glm::perspective(45.0f, (float)screenWidth / (float)screenHeight, 1.0f, 100.0f);
		modelViewMatrix = glm::lookAt(glm::vec3(getPosition().x,getPosition().y,getPosition().z), glm::vec3(0.0f,0.0f,0.0f), glm::vec3(0.0f,1.0f,0.0f));
	
		GLint projMatrixLoc = GLSLProgram::getUniformLocation("projection");
		GLint modelViewMatrixLoc = GLSLProgram::getUniformLocation("modelview");

		glm::mat4 projectionMatrix = getProjectionMatrix();
		glm::mat4 modelViewMatrix = getModelViewMatrix();

		glUniformMatrix4fv(projMatrixLoc, 1, GL_FALSE, &(projectionMatrix[0][0]));
		glUniformMatrix4fv(modelViewMatrixLoc, 1, GL_FALSE, &(modelViewMatrix[0][0]));
}