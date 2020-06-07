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
				printf("Triggered Right");
				currentDirection = top.direction;
				tailQueue.pop();
			}
			break;
		case Direction::left:
			if (fillRect.x <= top.xPosition) {
				printf("Triggered Left");
				currentDirection = top.direction;
				tailQueue.pop();
			}
			break;
		case Direction::up:
			if (fillRect.y <= top.yPosition) {
				currentDirection = top.direction;
				tailQueue.pop();
			}
			break;
		case Direction::down:
			if (fillRect.y >= top.yPosition) {
				currentDirection = top.direction;
				tailQueue.pop();
			}
			break;
		}
	}
	
	//Move Tail in Direction
	switch (currentDirection) {
	case Direction::right:
		fillRect.x += 2.0;
		break;
	case Direction::left:
		fillRect.x -= 2.0;
		break;
	case Direction::up:
		fillRect.y -= 2.0;
		break;
	case Direction::down:
		fillRect.y += 2.0;
		break;
	}

}
