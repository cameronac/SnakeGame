#include "TailController.h"
#include <queue>

//Constructor
TailController::TailController(PositionHolder* positionHolder, const int* speed, Direction* direction)
{
	this->tailCount = 0;
	this->direction = direction;
	this->positionHolder = positionHolder;
	this->tails.push_back(new Tail(tailCount, &*this->direction, Direction::right, &*this->positionHolder, -32, 0));
	this->tailCount += 1;
	this->speed = speed;
}

//Destructor
TailController::~TailController() {

	//Delete Allocated Tails
	for (int i = 0; i < tailCount; i++) {
		delete tails[i];
	}

	tails.clear();
}


//Public Methods 

//Returns Tails Count 
int TailController::getTailCount()
{
	return tailCount;
}

//Returns the Tail Object at a specific Index
Tail* TailController::getTailAt(int at)
{
	return &*tails[at];
}

//Add a new tail to the tails vector
void TailController::addNewTail()
{
	//Adds a new tail by getting the leading tails address of positionHolder so it can follow that tail
	if (tailCount > 0) {
		Tail* leadingTail = getTailAt(tailCount - 1);
		int size = 32;
		tails.push_back(new Tail(tailCount, &leadingTail->currentDirection, leadingTail->currentDirection, leadingTail->tailQueue, leadingTail->currentPosition, 0, 0));
		tailCount += 1;
	}
}

//Deletes all Tails and Resets Tail at index 0 properties
void TailController::deleteAllTails()
{
	//Hold Tail at Index 0
	Tail* firstTail;

	//Delete Tails
	for (int i = 0; i < getTailCount(); i++) {
		
		if (i == 0) {
			firstTail = getTailAt(i);
			continue;
		}
		else {
			delete getTailAt(i);
		}
	}

	//Clear Vector
	tails.clear();

	tailCount = 1;	//Reset Count
	tails.push_back(firstTail); //Add First Tail to Vector
	firstTail->currentDirection = Direction::right;	//Reset Direction
	std::queue<Move> empty;		//Swapping out queue for an empty queue
	std::swap(firstTail->tailQueue, empty);
}

void TailController::reset()
{
}
