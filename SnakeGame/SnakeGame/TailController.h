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
		TailController();
		int getTailCount();
		Tail getTailAt(int at);
		void addNewTail();
		void deleteLastTail();
		void reset();
};

