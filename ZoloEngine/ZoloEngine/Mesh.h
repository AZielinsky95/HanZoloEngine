#pragma once

#include "Vertex.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <string>
#include <vector>



class Mesh
{
public:
	Mesh();
	~Mesh();
	
	enum PrimitiveTypeList
	{
		Prim_NULL,
		Prim_Points,
		Prim_Lines,
		Prim_Triangles,
		Prim_TriangleFans,
		Prim_Quads
	};

	PrimitiveTypeList primType;

	std::vector<Vertex> vertices;
	//GLuint *indices;
	int numVerts;
	//Texture *textures;

	Mesh(std::vector<Vertex> _vertices, PrimitiveTypeList prims);

	void Update();
	void setupMesh();
	bool enableWireFrameMode;

private: 

	GLuint vboID;

	void drawMesh();

	

};

