#include "PlayerController.h"
#include <stdio.h>
#include <iostream>
#include "Move.h"

//Default Initializer
PlayerController::PlayerController()
{
	this->tailController = TailController(&fillRect.x, &fillRect.y, &spd, &direction);
	this->direction = Direction::right;
}

//Custom Initializer
PlayerController::PlayerController(InputController* inputController)
{
	this->tailController = TailController(&fillRect.x, &fillRect.y, &spd, &direction);
	this->direction = Direction::right;
    this->inputController = inputController;
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
		if (inputController->rightKey && direction != Direction::left && direction != Direction::right) {
			direction = Direction::right;
			didChangeDirection = true;
		}

		//Left Key
		if (inputController->leftKey && direction != Direction::right && direction != Direction::left) {
			direction = Direction::left;
			didChangeDirection = true;
		}

		//Up Key
		if (inputController->upKey && direction != Direction::down && direction != Direction::up) {
			direction = Direction::up;
			didChangeDirection = true;
		}

		//Down Key
		if (inputController->downKey && direction != Direction::up && direction != Direction::down) {
			direction = Direction::down;
			didChangeDirection = true;
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
		fillRect.y += -spd;
		break;
	case Direction::down:
		fillRect.y += spd;
		break;
	case Direction::right:
		fillRect.x += spd;
		break;
	case Direction::left:
		fillRect.x += -spd;
		break;
	default:
		break;
	}

	//Add new Direction change to queue
	if (didChangeDirection == true) {
		for (int i = 0; i < tailController.getTailCount(); i++) {
			Tail* tail = tailController.getTailAt(i);
			tail->tailQueue.push(Move(fillRect.x, fillRect.y, direction));
		}
		didChangeDirection = false;
	}

	//Check Tails State
	for (int i = 0; i < tailController.getTailCount(); i++) {
		Tail* tail = tailController.getTailAt(i);
		tail->checkTail();
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
		Tail* tail = tailController.getTailAt(i);

		//Drawing Tail Color
		if (SDL_SetRenderDrawColor(renderController->renderer, tail->color.r, tail->color.g, tail->color.b, tail->color.a) == -1) {
			printf("Error Setting Render Draw Color!");
		}

		//Filling in Tail Rect
		if (SDL_RenderFillRect(renderController->renderer, &tail->fillRect) == -1) {
			printf("Error Rendering Fill Rect!");
		}
	}
}
