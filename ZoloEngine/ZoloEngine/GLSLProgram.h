#pragma once

#include <string>
#include <glew.h>

class GLSLProgram
{
public:

	static void compileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath);

	static void linkShaders();

	static void addAttribute(const std::string& attributeName);

	static void use();

	static void unuse();

	static GLuint getUniformLocation(const std::string uniformName);

private:

	static void compileShader(const std::string& filePath, GLuint id);

	static int numAttributes;
	static GLuint _programID;
	static GLuint _vertexShaderID;
	static GLuint _fragmentShaderID;
};

