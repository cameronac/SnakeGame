#include "Tail.h"
#include <iostream>

//Constructors
//Adding Lead Tail before Head
Tail::Tail(int tailIdentifier, Direction* playerDirection, Direction lastTailDirection, PositionHolder* positionHolder, int positionOffsetX, int positionOffsetY)
{
	this->leadingDirection = playerDirection;
	this->tailIdentifier = tailIdentifier;
	this->currentDirection = lastTailDirection;
	this->fillRect.x = *positionHolder->x + positionOffsetX;
	this->fillRect.y = *positionHolder->y + positionOffsetY;

	//Pointer Assignments
	this->currentPosition = new PositionHolder(&fillRect.x, &fillRect.y);
	this->positionHolder = positionHolder;
}

//Adding New Tail to Leading Tail Constructor
Tail::Tail(int tailIdentifier, Direction *leadingDirection, Direction lastTailDirection, std::queue<Move> tailQueue, PositionHolder* positionHolder, int positionOffsetX, int positionOffsetY)
{
	this->leadingDirection = leadingDirection;
	this->tailIdentifier = tailIdentifier;
	this->currentDirection = lastTailDirection;
	this->tailQueue = tailQueue;
	this->positionHolder = positionHolder;
	this->fillRect.x = *positionHolder->x + positionOffsetX;
	this->fillRect.y = *positionHolder->y + positionOffsetY;
	this->currentPosition = new PositionHolder(&fillRect.x, &fillRect.y);
	setInitialPosition();
}

//Destructor
Tail::~Tail() {
	delete currentPosition;

	currentPosition = NULL;
}

//Sets Up New Snake Tail Starting Position
void Tail::setInitialPosition() {

	switch (*leadingDirection) {
	case Direction::right:
		fillRect.x = *positionHolder->x - 32;
		break;
	case Direction::left:
		fillRect.x = *positionHolder->x + 32;
		break;
	case Direction::up:
		fillRect.y = *positionHolder->y + 32;
		break;
	case Direction::down:
		fillRect.y = *positionHolder->y - 32;
		break;
	}
}

//Updates Tail Object| Should Be called Every Frame
void Tail::checkTail()
{

	//Check Queue
	if (tailQueue.empty() == false) {
		Move top = tailQueue.front();
		//Check Tail Position
		switch (currentDirection) {
		case Direction::right:
			if (fillRect.x >= top.xPosition) {
				currentDirection = top.direction;
				fillRect.x = top.xPosition;
				tailQueue.pop();
			}
			break;
		case Direction::left:
			if (fillRect.x <= top.xPosition) {
				currentDirection = top.direction;
				fillRect.x = top.xPosition;
				tailQueue.pop();
			}
			break;
		case Direction::up:
			if (fillRect.y <= top.yPosition) {
				currentDirection = top.direction;
				fillRect.y = top.yPosition;
				tailQueue.pop();
			}
			break;
		case Direction::down:
			if (fillRect.y >= top.yPosition) {
				currentDirection = top.direction;
				fillRect.y = top.yPosition;
				tailQueue.pop();
			}
			break;
		}
	}

	//Move Tail in Direction
	switch (currentDirection) {
	case Direction::right:
		fillRect.x += 3;
		break;
	case Direction::left:
		fillRect.x -= 3;
		break;
	case Direction::up:
		fillRect.y -= 3;
		break;
	case Direction::down:
		fillRect.y += 3;
		break;
	}

	//Make Sure Tails are close to the Head or next Tail
	switch (currentDirection) {
	case Direction::right:

		//Check X Position
		if (fillRect.x < *positionHolder->x - 32) {
			fillRect.x = *positionHolder->x - 32;
		}

		//Check Y Position
		if (fillRect.y > *positionHolder->y + 32) {
			fillRect.y = *positionHolder->y + 32;
		}
		break;
	case Direction::left:

		//Check X Position
		if (fillRect.x > *positionHolder->x + 32) {
			fillRect.x = *positionHolder->x + 32;
		}

		//Check Y Position
		if (fillRect.y < *positionHolder->y - 32) {
			fillRect.y = *positionHolder->y - 32;
		}
		break;
	case Direction::up:

		//Check X Position
		if (fillRect.x < *positionHolder->x - 32) {
			fillRect.x = *positionHolder->x - 32;
		}

		//Check Y Position
		if (fillRect.y > *positionHolder->y + 32) {
			fillRect.y = *positionHolder->y + 32;
		}

		break;
	case Direction::down:

		//Check X Position
		if (fillRect.x < *positionHolder->x - 32) {
			fillRect.x = *positionHolder->x - 32;
		}

		//Check Y Position
		if (fillRect.y < *positionHolder->y - 32) {
			fillRect.y = *positionHolder->y - 32;
		}
		break;
	}

}
