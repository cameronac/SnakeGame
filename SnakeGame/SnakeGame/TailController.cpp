#include "TailController.h"
#include <iostream>

//Initializers
TailController::TailController() {
	this->tailCount = 0;
	this->tails.push_back(Tail(tailCount));
	this->tailCount += 1;

	//Setting Arguments
	this->xPosition = nullptr;
	this->yPosition = nullptr;
	this->speed = nullptr;
}

TailController::TailController(int* xPosition, int* yPosition, double* speed)
{
	this->tailCount = 0;
	this->tails.push_back(Tail(tailCount));
	this->tailCount += 1;
	
	//Setting Arguments
	this->xPosition = xPosition;
	this->yPosition = yPosition;
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
	int size = 32;
	tails.push_back(Tail(tailCount));
	tailCount += 1;
}

void TailController::deleteLastTail()
{

}

void TailController::reset()
{
}
