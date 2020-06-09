#include "PlayerController.h"
#include <stdio.h>
#include <iostream>
#include "Move.h"


//Constructor
PlayerController::PlayerController(InputController* inputController)
{
	//Assigning Pointers
	this->inputController = inputController;
	this->positionHolder = new PositionHolder(&fillRect.x, &fillRect.y);
	this->tailController = new TailController(&*positionHolder, &spd, &direction);
}

//Destructor
PlayerController::~PlayerController()
{
	delete positionHolder;
	delete tailController;

	positionHolder = NULL;
	tailController = NULL;
}


//Public Methods
//Collision Detection| Are we colliding with a Tail
bool PlayerController::isColliding()
{
	//Check for collision
	for (int i = 0; i < tailController->getTailCount(); i++) {

		if (i == 0) {
			continue;	//Skip First Tail
		}
		else {
			Tail* currentTail = tailController->getTailAt(i);

			//Y Position Check
			if (*currentTail->currentPosition->y + 32 > *positionHolder->y && *currentTail->currentPosition->y < *positionHolder->y + 32) {
				//X Position Check
				if (*currentTail->currentPosition->x + 32 > *positionHolder->x && *currentTail->currentPosition->x < *positionHolder->x + 32) {
					return true;
				}
			}
		}
	}

	return false;
}

//Updates the players positions, movement, etc | Should be called every frame
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
			tailController->addNewTail();
		}
	}

	//Collision With Tail
	bool colliding = isColliding();

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
		for (int i = 0; i < tailController->getTailCount(); i++) {
			Tail* tail = tailController->getTailAt(i);
			tail->tailQueue.push(Move(fillRect.x, fillRect.y, direction));
		}
		didChangeDirection = false;
	}

	//Check Tails State
	for (int i = 0; i < tailController->getTailCount(); i++) {
		Tail* tail = tailController->getTailAt(i);
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
	for (int i = 0; i < tailController->getTailCount(); i++) {
		Tail* tail = tailController->getTailAt(i);

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
