#pragma once
#include "Sprite.h"
#include "Mesh.h"
#include <SDL.h>
#include <glew.h>
#include "GLSLProgram.h"
#include "Camera.h"
#include "GameObject.h"
#include "GLTexture.h"



enum class GameState {PLAY,EXIT};

class GameEngine
{
public:
	GameEngine();
	~GameEngine();

	void run();
	void drawGame();

private:
	void initSystems();
	void initShaders();
	void processInput();
	void gameLoop();

	SDL_Window* window;
	int screenWidth;
	int screenHeight;
	GameState gameState;
	Sprite testSprite;
	Camera camera;

	GameObject cube;
	GameObject cube2;
	GLSLProgram shader;

	float time;
};