#pragma once
#include "Direction.h"

struct Move {
public:
	Move(int xPosition, int yPosition, Direction direction);
	int xPosition;
	int yPosition;
	Direction direction;
};