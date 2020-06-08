#include "TailController.h"
#include <iostream>

//Initializers
TailController::TailController(PositionHolder* positionHolder, int* speed, Direction* direction)
{
	this->tailCount = 0;
	this->direction = direction;
	this->positionHolder = positionHolder;
	this->tails.push_back(new Tail(tailCount, *direction, Direction::right, &*this->positionHolder, -32, 0));
	this->tailCount += 1;

	//Setting Arguments
	this->speed = speed;
}

TailController::~TailController() {

	for (int i = 0; i < tailCount; i++) {
		delete tails[i];
	}

	tails.clear();
}


//Returns Tails Count 
int TailController::getTailCount()
{
	return tailCount;
}

//Returns a tail at a specific Index
Tail* TailController::getTailAt(int at)
{
	return &*tails[at];
}

//Add a new tail to the tails vector
void TailController::addNewTail()
{
	if (tailCount > 0) {
		Tail* leadingTail = getTailAt(tailCount - 1);
		int size = 32;
		std::cout << *leadingTail->currentPosition->x << std::endl;
		tails.push_back(new Tail(tailCount, *direction, leadingTail->currentDirection, leadingTail->tailQueue, leadingTail->currentPosition, 0, 0));
		tailCount += 1;
	}
}

void TailController::deleteLastTail()
{

}

void TailController::reset()
{
}
