#include "Sprite.h"
#include "Vertex.h"
#include <cstddef>




Sprite::Sprite()
{
	vboID = 0;

}

Sprite::~Sprite()
{
	if (vboID != 0)
	{
		glDeleteBuffers(1, &vboID);
	}

}

void Sprite::init(float _x, float _y,float _width, float _height)
{
	x = _x;
	y = _y;
	width = _width;
	height = _height;

	//if Vertex buffer Id hasn't been created yet
	//create it
	if (vboID == 0)
	{
		glGenBuffers(1, &vboID);
	}

	Vertex vertexData[6];


	//First Triangle
	vertexData[0].setPosition(x + width, y + height,0);
	vertexData[0].setUV(1.0f, 1.0f);

	vertexData[1].setPosition(x , y + height, 0);
	vertexData[1].setUV(0.0f, 1.0f);

	vertexData[2].setPosition(x, y, 0);
	vertexData[2].setUV(0.0f, 0.0f);

	//Second Triangle 
	vertexData[3].setPosition(x, y, 0);
	vertexData[3].setUV(0.0f, 0.0f);

	vertexData[4].setPosition(x + width, y, 0);
	vertexData[4].setUV(1.0f, 0.0f);

	vertexData[5].setPosition(x + width, y + height, 0);
	vertexData[5].setUV(1.0f, 1.0f);

	for (int i = 0; i < 6; i++)
	{
		vertexData[i].color.r = 255;
		vertexData[i].color.g = 0;
		vertexData[i].color.b = 255;
		vertexData[i].color.a = 255;
	}


	//Activate/Bind buffer
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	//Upload Data here
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
	//UnbindBuffer
	glBindBuffer(GL_ARRAY_BUFFER, 0);



}

void Sprite::draw()
{
	glBindBuffer(GL_ARRAY_BUFFER, vboID);

	glEnableVertexAttribArray(0);


	//this is the position attribute pointer
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
	//this is the color attrib pointer
	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));
	glEnableVertexAttribArray(1);
	//This is the UV attribute pointer
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));
	glEnableVertexAttribArray(2);

	glDrawArrays(GL_TRIANGLES, 0,6);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

