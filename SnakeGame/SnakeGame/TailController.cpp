#include "TailController.h"
#include <stdio.h>

//Initializer
TailController::TailController()
{
	this->tailCount = 0;
	this->tails.push_back(Tail(0, 0, tailCount));
	this->tailCount += 1;
}

//Returns Tails Count 
int TailController::getTailCount()
{
	return tailCount;
}

//Returns a tail at a specific Index
Tail TailController::getTailAt(int at)
{
	return tails[at];
}

//Add a new tail to the tails vector
void TailController::addNewTail()
{
	tails.push_back(Tail(0, 0, tailCount));
	tailCount += 1;
}

void TailController::deleteLastTail()
{

}

void TailController::reset()
{
}
