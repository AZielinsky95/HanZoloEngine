#version 130


in vec4 fragmentColor;
in vec2 fragmentUV;

out vec4 color;

uniform sampler2D myTexture;

void main(){

color =  texture(myTexture,fragmentUV) * fragmentColor ;

}