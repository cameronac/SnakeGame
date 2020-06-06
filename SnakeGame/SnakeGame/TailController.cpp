#include "TailController.h"
#include <stdio.h>

//Initializer
TailController::TailController()
{
	this->tailCount = 0;
	this->tailCount += 1;
	this->tails.push_back(Tail(0, 0, tailCount));
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
	tailCount += 1;
	tails.push_back(Tail(0, 0, tailCount));
}

void TailController::deleteLastTail()
{

}

void TailController::reset()
{
}
