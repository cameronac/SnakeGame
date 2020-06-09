#include "GameController.h" 

//Constructor
GameController::GameController(RenderController* renderController, InputController* inputController)
{
	this->renderController = renderController;
	this->inputController = inputController;
	playerController = new PlayerController(&*inputController);
}

//Destructor
GameController::~GameController()
{
	delete playerController;

	playerController = NULL;
	renderController = NULL;
	inputController = NULL;
}

//Public Methods
//Updates all Game Objects and Adds them to the Renderer
void GameController::GameRefresh()
{
	//Update Objects
	playerController->checkPlayer();

	//Add Objects to Renderer
	playerController->renderPlayer(&*renderController);	
}

//Toggles a Pause in Game
void GameController::togglePause()
{
}
