#include "PlayerController.h"
#include <stdio.h>

PlayerController::PlayerController()
{
	//Do Nothing
}

PlayerController::PlayerController(InputController* inputController)
{
    this->inputController = inputController;
}

PlayerController::~PlayerController()
{
}

//Checks Keys to see if player needs to move
void PlayerController::checkPlayer()
{
	//Player Movement
	//Right Key
	if (inputController->rightKey) {
		xPosition += spd;
		fillRect.x = floor(xPosition);
	}

	//Left Key
	if (inputController->leftKey) {
		xPosition += -spd;
		fillRect.x = floor(xPosition);
	}

	//Up Key
	if (inputController->upKey) {
		yPosition += -spd;
		fillRect.y = floor(yPosition);
	}

	//Down Key
	if (inputController->downKey) {
		yPosition += spd;
		fillRect.y = floor(yPosition);
	}
}
