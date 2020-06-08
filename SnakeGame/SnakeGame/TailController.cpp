#include "TailController.h"
#include <iostream>

//Initializers
TailController::TailController() {
	this->tailCount = 0;
	this->tailCount += 1;
}

TailController::TailController(PositionHolder* positionHolder, int* speed, Direction* direction)
{
	this->tailCount = 0;
	this->direction = direction;
	this->positionHolder = positionHolder;
	this->tails.push_back(Tail(tailCount, *direction, Direction::right, &*this->positionHolder, -32, 0));
	this->tailCount += 1;

	//Setting Arguments
	this->speed = speed;
}

//Returns Tails Count 
int TailController::getTailCount()
{
	return tailCount;
}

//Returns a tail at a specific Index
Tail* TailController::getTailAt(int at)
{
	return &tails[at];
}

//Add a new tail to the tails vector
void TailController::addNewTail()
{
	if (tailCount > 0) {
		const Tail* lastTail = getTailAt(tailCount);
		int size = 32;
		Tail* upperTail = getTailAt(getTailCount());
		tails.push_back(Tail(tailCount, *direction, lastTail->currentDirection, lastTail->tailQueue, upperTail->currentPosition, 0, 0));
		tailCount += 1;
	}
}

void TailController::deleteLastTail()
{

}

void TailController::reset()
{
}
