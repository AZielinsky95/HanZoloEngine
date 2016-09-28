#include "Mesh.h"


Mesh::Mesh() : vboID(0), enableWireFrameMode(false)
{

}


Mesh::~Mesh()
{
	if (vboID != 0)
	{
		glDeleteBuffers(1, &vboID);
	}
}

Mesh::Mesh(std::vector<Vertex> _vertices , PrimitiveTypeList prim)
{
	vertices = _vertices;
	numVerts = vertices.size();
	primType = prim;
}

void Mesh::setupMesh()
{

	//if Vertex buffer Id hasn't been created yet
	//create it
	if (vboID == 0)
	{
		glGenBuffers(1, &vboID);
	}

	//Activate/Bind buffer
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	//Upload Data here
	glBufferData(GL_ARRAY_BUFFER, (vertices.size() * sizeof(Vertex)), vertices.data(), GL_STATIC_DRAW);
	//UnbindBuffer
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Mesh::Update()
{
	drawMesh();
}

void Mesh::drawMesh()
{
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	//this is the position attribute pointer
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
	//this is the color attrib pointer
	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));
	//This is the UV attribute pointer
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));

	switch (primType)
	{
	case Prim_NULL:

		break;

	case Prim_Points:

		glDrawArrays(GL_POINTS, 0,numVerts);

		break;

	case Prim_Lines:

		glDrawArrays(GL_LINES, 0, numVerts);

		break;

	case Prim_Triangles:

		glDrawArrays(GL_TRIANGLES, 0, numVerts);

		break;

	case Prim_TriangleFans:
	
		glDrawArrays(GL_TRIANGLE_FAN, 0, numVerts);

		break;

	case Prim_Quads:

		if (enableWireFrameMode == true)
		{
			glEnable(GL_POLYGON_OFFSET_LINE);
			//glPolygonOffset(-1, -1);
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

			glDrawArrays(GL_QUADS, 0, numVerts);

			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glDisable(GL_POLYGON_OFFSET_LINE);
		}
		else
		{
			glDrawArrays(GL_QUADS, 0, numVerts);
		}

		break;

	default:
		break;

	}


	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0);


}