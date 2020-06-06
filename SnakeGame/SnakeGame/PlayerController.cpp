#include "PlayerController.h"
#include <stdio.h>

//Default Initializer
PlayerController::PlayerController()
{
	this->tailController = TailController();
	this->direction = Direction::right;
}

//Custom Initializer
PlayerController::PlayerController(InputController* inputController)
{
    this->inputController = inputController;
	this->tailController = TailController();
	this->direction = Direction::right;
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
		if (inputController->rightKey && direction != Direction::left) {
			direction = Direction::right;
		}

		//Left Key
		if (inputController->leftKey && direction != Direction::right) {
			direction = Direction::left;
		}

		//Up Key
		if (inputController->upKey && direction != Direction::down) {
			direction = Direction::up;
		}

		//Down Key
		if (inputController->downKey && direction != Direction::up) {
			direction = Direction::down;
		}

		//TODO: Only for Testing purposes; Delete
		//Space Key
		if (inputController->spaceKey) {
			tailController.addNewTail();
		}
	}

	//Move Player In Direction
	switch (direction) {
	case Direction::up:
		yPosition += -spd;
		fillRect.y = floor(yPosition);
		break;
	case Direction::down:
		yPosition += spd;
		fillRect.y = floor(yPosition);
		break;
	case Direction::right:
		xPosition += spd;
		fillRect.x = floor(xPosition);
		break;
	case Direction::left:
		xPosition += -spd;
		fillRect.x = floor(xPosition);
		break;
	default:
		break;
	}
}

//Takes in a renderer and adds players elements to it to draw
void PlayerController::renderPlayer(RenderController* renderController)
{
	//Render Player
	//Render the Head of the player
	if (SDL_SetRenderDrawColor(renderController->renderer, color.r, color.g, color.b, color.a) == -1) {
		printf("Error Setting Render Draw Color!");
	}

	if (SDL_RenderFillRect(renderController->renderer, &fillRect) == -1) {
		printf("Error Rendering Fill Rect!");
	}

	//Render the Tails of the player
	for (int i = 0; i < tailController.getTailCount(); i++) {
		Tail tail = tailController.getTailAt(i);

		//Drawing Tail Color
		if (SDL_SetRenderDrawColor(renderController->renderer, tail.color.r, tail.color.g, tail.color.b, tail.color.a) == -1) {
			printf("Error Setting Render Draw Color!");
		}

		//Filling in Tail Rect
		if (SDL_RenderFillRect(renderController->renderer, &tail.fillRect) == -1) {
			printf("Error Rendering Fill Rect!");
		}
	}
}
