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
	playerController.renderPlayer(&*renderController);

}

//Toggles a Pause in Game
void GameController::togglePause()
{
}
