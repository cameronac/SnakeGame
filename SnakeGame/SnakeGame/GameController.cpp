#include "GameController.h"
#include <stdio.h>
#include <math.h>   

//Initializer
GameController::GameController(RenderController* renderController, InputController* inputController)
{
	this->renderController = renderController;
	this->inputController = inputController;
	this->playerController = PlayerController(&*inputController);
}

//De-initializer
GameController::~GameController()
{
	renderController = NULL;
	inputController = NULL;
}

//Public Methods
//Called Before Rendering| Applies New and Existing objects to the Renderer
void GameController::GameRefresh()
{
	//Checks Player Every Frame| Movement, etc
	playerController.checkPlayer();

	//Render Player
	if (SDL_SetRenderDrawColor(renderController->renderer, playerController.color.r, playerController.color.g, playerController.color.b, playerController.color.a) == -1) {
		printf("Error Setting Render Draw Color!");
	}  
	
	if (SDL_RenderFillRect(renderController->renderer, &playerController.fillRect) == -1) {
		printf("Error Rendering Fill Rect!");
	}
}

//Toggles a Pause in Game
void GameController::togglePause()
{
}
