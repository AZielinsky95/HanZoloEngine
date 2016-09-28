#pragma once

#include "Mesh.h"
#include "Vector3.h"
#include "Vertex.h"
#include "Image.h"
#include <glm.hpp>
#include <string>
#include <gtc/matrix_transform.hpp>


struct Transform
{
	Vector3 scale;
	Vector3 position;
	Vector3 rotation;
};

class GameObject
{
public:
	GameObject();
	~GameObject();

	//GETTERS
	Vector3 getScale()	  { return transform->scale; }
	Vector3 getPosition()   { return transform->position; }
	Vector3 getRotation()   { return transform->rotation; }

	//SETTERS
	void setScale(Vector3 newScale) { transform->scale = newScale; }
	void setPosition(Vector3 newPosition) { transform->position = newPosition; }
	void setRotation(Vector3 newRotation) { transform->rotation = newRotation; }

	//UPDATE FUNCTION!
	void Update();
	
	//CREATE A CUBE FUNCTION!
	void createCube(Vector3 _position, Vector3 _scale, Vector3 _rotation);

	void enableWireFrameMode() { mesh->enableWireFrameMode = true; }
	void disableWireFrameMode() { mesh->enableWireFrameMode = false; }

	//YOUR OBJECTS TRANSFORM!
	Transform *transform;

	//GET TRANSFORM MATRIX
	glm::mat4 getTransformMatrix() { return transformMatrix; }

	void setImage(std::string filePath)
	{
		image->init(filePath);
	}
	
	

private:
	Mesh *mesh;
	Image *image;
	glm::mat4 transformMatrix;

};

