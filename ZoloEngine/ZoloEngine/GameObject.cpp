#include "GameObject.h"
#include "GLSLProgram.h"


GameObject::GameObject() 
{
	image = new Image();
	transform = new Transform();
	transform->position = Vector3(0, 0, 0);
	transform->scale = Vector3(1, 1, 1);
	transform->rotation = Vector3(0, 0, 0);
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
	transformMatrix = glm::scale(transformMatrix, glm::vec3(transform->scale.x, transform->scale.y, transform->scale.z));
	transformMatrix = glm::translate(transformMatrix, glm::vec3(transform->position.x, transform->position.y, transform->position.z));
	transformMatrix = glm::rotate(glm::mat4(1), glm::radians(transform->rotation.x), glm::vec3(1, 0, 0));
	transformMatrix = glm::rotate(transformMatrix, glm::radians(transform->rotation.y), glm::vec3(0, 1, 0));
	transformMatrix = glm::rotate(transformMatrix, glm::radians(transform->rotation.z), glm::vec3(0, 0, 1));


	GLint transformMatrixLoc = GLSLProgram::getUniformLocation("transform");
	glUniformMatrix4fv(transformMatrixLoc, 1, GL_FALSE, &(transformMatrix[0][0]));

	image->bind();
	mesh->Update();
	image->unbind();
}

void GameObject::createCube(Vector3 _pos, Vector3 _scale, Vector3 _rotation)
{
	
	transform->position = _pos;
	transform->scale = _scale;
	transform->rotation = _rotation;

	std::vector<Vertex> cubeVerts;
	Vertex data[24];

	for (int i = 0; i < 24; i++)
	{
		Vertex data;
		cubeVerts.push_back(data);
		//Set position X
		if (i == 2 || i == 3 || i == 4 || i == 5 || i == 8 || i == 9 || i == 10 || i == 11 || i == 18 || i == 19 || i == 20 || i == 21)
			cubeVerts.back().position.x = _pos.x - 0.5f;
		else
			cubeVerts.back().position.x = _pos.x + 0.5f;
		//Set position Y
		if (i == 0 || i == 3 || i == 4 || i == 7 || i == 8 || i == 11 || i == 12 || i == 15 || i == 20 || i == 21 || i == 22 || i == 23)
			cubeVerts.back().position.y = _pos.y - 0.5f;
		else
			cubeVerts.back().position.y = _pos.y + 0.5f;
		//Set position Z
		if (i == 0 || i == 1 || i == 2 || i == 3 || i == 8 || i == 9 || i == 14 || i == 15 || i == 16 || i == 19 || i == 21 || i == 22)
			cubeVerts.back().position.z = _pos.z - 0.5f;
		else
			cubeVerts.back().position.z = _pos.z + 0.5f;

		//Set colour for each vertex
		if (i < 8)
			cubeVerts.back().setColor(255,255,255, 255);
		else if (i < 16)
			cubeVerts.back().setColor(255,255,255, 255);
		else
			cubeVerts.back().setColor(255,255,255, 255);

		//Set Texture to 1 face of cube
		if (i == 0 || i == 4  || i ==  8 || i == 12 || i == 16 || i == 20)
			cubeVerts.back().setUV(1.0f, 0.0f);
		else if (i == 1 || i == 5 || i == 9 || i == 13 || i == 17 || i == 21)
			cubeVerts.back().setUV(1.0f, 1.0f);
		else if (i == 2 || i == 6 || i == 10 || i == 14 || i == 18|| i == 22)
			cubeVerts.back().setUV(0.0f, 1.0f);
		else if (i == 3 || i == 7 || i == 11|| i == 15 || i == 19 || i == 23)
			cubeVerts.back().setUV(0.0f, 0.0f);
	}


	mesh = new Mesh(cubeVerts,Mesh::PrimitiveTypeList::Prim_Quads);

	mesh->setupMesh();



}

