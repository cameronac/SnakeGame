#include "PlayerController.h"
#include <stdio.h>
#include <iostream>
#include "Move.h"

//Default Initializer
PlayerController::PlayerController()
{
	this->tailController = TailController(&fillRect.x, &fillRect.y, &spd);
	this->direction = Direction::right;
}

//Custom Initializer
PlayerController::PlayerController(InputController* inputController)
{
	this->tailController = TailController(&fillRect.x, &fillRect.y, &spd);
	this->direction = Direction::right;
    this->inputController = inputController;
}

//Destructor
PlayerController::~PlayerController()
{
	printf("Destructor Called");
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
		yPosition += -spd;
		fillRect.y = (int)floor(yPosition);
		break;
	case Direction::down:
		yPosition += spd;
		fillRect.y = (int)floor(yPosition);
		break;
	case Direction::right:
		xPosition += spd;
		fillRect.x = (int)floor(xPosition);
		break;
	case Direction::left:
		xPosition += -spd;
		fillRect.x = (int)floor(xPosition);
		break;
	default:
		break;
	}

	//TODO
	//Before Checking Tails State We need to check if the direction has changed and assign it to all the tail queues
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
		tail->checkTail(fillRect.x, fillRect.y);
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
		std::cout << tail->fillRect.x << ", " << tail->fillRect.y << "  |  ";

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
