#include "Tail.h"
#include <iostream>

//Constructors
Tail::Tail(int tailIdentifier, Direction playerDirection, Direction lastTailDirection, int xPosition, int yPosition)
{
	this->playerDirection = playerDirection;
	this->tailIdentifier = tailIdentifier;
	this->currentDirection = lastTailDirection;
	this->fillRect.x = xPosition;
	this->fillRect.y = yPosition;
}

Tail::Tail(int tailIdentifier, Direction playerDirection, Direction lastTailDirection, std::queue<Move> tailQueue, int xPosition, int yPosition)
{
	this->playerDirection = playerDirection;
	this->tailIdentifier = tailIdentifier;
	this->currentDirection = lastTailDirection;
	this->tailQueue = tailQueue;
	this->fillRect.x = xPosition;
	this->fillRect.y = yPosition;
}

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
		fillRect.x += 2;
		break;
	case Direction::left:
		fillRect.x -= 2;
		break;
	case Direction::up:
		fillRect.y -= 2;
		break;
	case Direction::down:
		fillRect.y += 2;
		break;
	}

	//Make Sure Tail is Close to it's desired Position
	//TODO
	switch (currentDirection) {
	case Direction::right:
		break;
	case Direction::left:
		break;
	case Direction::up:
		break;
	case Direction::down:
		break;
	}

}
