#include "GameController.h"
#include <stdio.h>
#include <math.h>   

//Initializer
GameController::GameController(RenderController* renderController, InputController* inputController, FPSController* fpsController)
{
	this->renderController = renderController;
	this->inputController = inputController;
	this->fpsController = fpsController;
	this->playerController = PlayerController();
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
	//Test Move Player
	playerController.xPosition = (fpsController->deltaTime * 0.01f) * 10;
	playerController.fillRect.x = floor(playerController.xPosition);
	//Position.x += 10 / 1000 * deltaTime;

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
