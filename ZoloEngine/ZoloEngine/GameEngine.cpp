#include "GameEngine.h"
#include  "Errors.h"
#include "Vertex.h"
#include <glm.hpp>
#include <iostream>
#include <string>


float cubeRot = 0;
Sprite sprite;
GLTexture texture;

GameEngine::GameEngine(){
	time = 0;
	window = nullptr;
	screenWidth = 1024;
	screenHeight = 768;
	gameState = GameState::PLAY;
	camera.init(screenWidth, screenHeight);
	cube = GameObject();
}

GameEngine::~GameEngine(){}

void GameEngine::run()
{
	initSystems();

	//INIT CUBES
	cube.setImage("brickwall.png");
	//cube.setImage("container.jpg");
	cube.createCube(Vector3(1.5f, 0, 0), Vector3(1, 1, 1), Vector3(0, 0, 0));

	cube2.setImage("brickwall.png");
	cube2.createCube(Vector3(-1.5f, 0.0f, 0.0f), Vector3(1, 1, 1), Vector3(0, 0, 0));
	
	gameLoop();

}

void GameEngine::gameLoop()
{
	while (gameState != GameState::EXIT)
	{
		//Handle User Input
		processInput();
		//Update the camera!
		camera.update();
		//Increment rotation of Cube!
		cubeRot += 0.05f;
		//Draw Game!
		drawGame();
	}

}

void GameEngine::processInput()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			gameState = GameState::EXIT;
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				gameState = GameState::EXIT;
			}
			if (event.key.keysym.sym == SDLK_w)
			{
				camera.setPosition(Vector3(camera.getPosition().x, camera.getPosition().y, (camera.getPosition().z - 1)));
			}
			if (event.key.keysym.sym == SDLK_s)
			{
				camera.setPosition(Vector3(camera.getPosition().x, camera.getPosition().y, (camera.getPosition().z + 1)));
			}
		}
	
	}

}

void GameEngine::initSystems()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("ZoloEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_OPENGL);


	if (window == nullptr)
	{
		fatalError("SDL WINDOW COULD NOT BE CREATED!");
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(window);
	if (glContext == nullptr)
	{
		fatalError("SDL_GL context oculd not be created!");
	}

	GLenum error = glewInit();
	if (error != GLEW_OK)
	{
		fatalError("Could not init glew!");
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	glEnable(GL_DEPTH_TEST);
	//Black glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	//White
	glClearColor(1, 1, 1, 1);

	initShaders();
}

void GameEngine::initShaders()
{
	shader.compileShaders("Shaders/colorShading.vert", "Shaders/colorShading.frag");
	shader.addAttribute("vertexPosition");
	shader.addAttribute("vertexColor"); 
	shader.addAttribute("vertexUV");
	shader.linkShaders();
}

void GameEngine::drawGame()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	shader.use();

	camera.update();

	cube.Update();
	cube.setRotation(Vector3(-cubeRot, 0, 0));
	//cube.enableWireFrameMode();


	//transformMatrix = cube2.getTransformMatrix();
	//glUniformMatrix4fv(transformMatrixLoc, 1, GL_FALSE, &(transformMatrix[0][0]));
	cube2.Update();

	cube2.setRotation(Vector3(cubeRot, 0, 0));
	//cube2.enableWireFrameMode();

	shader.unuse();

	SDL_GL_SwapWindow(window);
}