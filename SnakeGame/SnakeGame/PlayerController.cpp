#include "PlayerController.h"
#include <stdio.h>

//Default Initializer
PlayerController::PlayerController()
{
	this->tailController = TailController();
}

//Custom Initializer
PlayerController::PlayerController(InputController* inputController)
{
    this->inputController = inputController;
	this->tailController = TailController();
}

//Destructor
PlayerController::~PlayerController()
{
}

//Checks Keys to see if player needs to move
void PlayerController::checkPlayer()
{
	if (inputController != NULL) {
		//Player Movement
		//Right Key
		if (inputController->rightKey) {
			direction = right;
		}

		//Left Key
		if (inputController->leftKey) {
			direction = left;
		}

		//Up Key
		if (inputController->upKey) {
			direction = up;
		}

		//Down Key
		if (inputController->downKey) {
			direction = down;
		}

		//Space Key
		if (inputController->spaceKey) {
			tailController.addNewTail();
		}
	}

	//Move Player In Direction
	switch (direction) {
	case up:
		yPosition += -spd;
		fillRect.y = floor(yPosition);
		break;
	case down:
		yPosition += spd;
		fillRect.y = floor(yPosition);
		break;
	case right:
		xPosition += spd;
		fillRect.x = floor(xPosition);
		break;
	case left:
		xPosition += -spd;
		fillRect.x = floor(xPosition);
		break;

	}
}
