#pragma once
#include "Tail.h"
#include <vector>
#include "Direction.h"

//Keeps Track of how many tails are being created
class TailController
{
	private:
		std::vector<Tail> tails;
		int tailCount;

	public:
		int* xPosition;
		int* yPosition;
		int* speed;
		Direction* direction;

	public:
		TailController();
		TailController(int* xPosition, int* yPosition, int* speed, Direction* direction);
		int getTailCount();
		Tail* getTailAt(int at);
		void addNewTail();
		void deleteLastTail();
		void reset();
};

