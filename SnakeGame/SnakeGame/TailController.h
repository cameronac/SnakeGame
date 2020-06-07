#pragma once
#include "Tail.h"
#include <vector>

//Keeps Track of how many tails are being created
class TailController
{
	private:
		std::vector<Tail> tails;
		int tailCount;

	public:
		int* xPosition;
		int* yPosition;
		double* speed;

	public:
		TailController();
		TailController(int* xPosition, int* yPosition, double* speed);
		int getTailCount();
		Tail* getTailAt(int at);
		void addNewTail();
		void deleteLastTail();
		void reset();
};

