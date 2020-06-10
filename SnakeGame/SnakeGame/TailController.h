#pragma once
#include "Tail.h"
#include <vector>
#include "Direction.h"
#include "PositionHolder.h"

//Keeps Track of how many tails are being created
class TailController
{
	//Private Properties
	private:
		std::vector<Tail*> tails;
		int tailCount;

	//Public Properties
	public:
		PositionHolder* positionHolder;
		const int* speed;
		Direction* direction;
		Tail* getTailAt(int at);

	//Public Methods
	public:
		TailController(PositionHolder* positionHolder, const int* speed, Direction* direction);	//Constructor
		~TailController();	//Destructor
		int getTailCount();	//Returns Tail Count
		void addNewTail();	//Adds New Tail to Tails Vector
		void deleteAllTails();	//Deletes all Tails except for Tail at index 0
		void reset();
};

