#include "PositionHolder.h"

PositionHolder::PositionHolder(int* x, int* y)
{
	this->x = x;
	this->y = y;
}

PositionHolder::~PositionHolder() {
	//std::cout << x << ", " << y << std::endl;
	//std::cout << "PositionHolder Freed" << std::endl;
}