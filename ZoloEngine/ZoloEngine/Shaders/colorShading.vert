#version 130		

in vec3 vertexPosition;
in vec4 vertexColor;
in vec2 vertexUV;

out vec4 fragmentColor;
out vec2 fragmentUV;


uniform mat4 transform;
uniform mat4 projection;
uniform mat4 modelview;


void main() {

gl_Position = projection * modelview * transform * vec4(vertexPosition, 1.0);

fragmentColor = vertexColor;

fragmentUV = vertexUV;
}