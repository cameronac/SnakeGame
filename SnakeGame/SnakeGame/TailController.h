#pragma once
#include "Tail.h"
#include <vector>
#include "Direction.h"
#include "PositionHolder.h"

//Keeps Track of how many tails are being created
class TailController
{
	private:
		std::vector<Tail> tails;
		int tailCount;

	public:
		PositionHolder* positionHolder;
		int* speed;
		Direction* direction;

	public:
		TailController();
		TailController(PositionHolder* positionHolder, int* speed, Direction* direction);
		int getTailCount();
		Tail* getTailAt(int at);
		void addNewTail();
		void deleteLastTail();
		void reset();
};

