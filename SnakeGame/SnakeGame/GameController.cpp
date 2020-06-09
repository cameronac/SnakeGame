#include "GameController.h" 

//Constructor
GameController::GameController(RenderController* renderController, InputController* inputController, WindowController* windowController)
{
	this->renderController = renderController;
	this->inputController = inputController;
	this->windowController = windowController;
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
	
	//Was there a collision
	if (playerController->isColliding == true) {
		RestartGame();
	}


	//Add Objects to Renderer
	playerController->renderPlayer(&*renderController);	
}

//Restart Game
void GameController::RestartGame()
{
	playerController->fillRect.x = 32;	//Set X Position
	playerController->fillRect.y = 32;	//Set Y Position
	playerController->direction = Direction::right;		//Rest Direction
	playerController->tailController->deleteAllTails();		//Delete all Tails Except for Tail at index 0
	playerController->tailController->getTailAt(0)->fillRect.x = playerController->fillRect.x - 32;	//Reset Tails Position
	playerController->tailController->getTailAt(0)->fillRect.y = playerController->fillRect.y; 
}

