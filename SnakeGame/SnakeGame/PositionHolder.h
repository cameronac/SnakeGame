#pragma once
#include <iostream>

struct PositionHolder {
	int* x;
	int* y;
	PositionHolder(int* x, int* y);
	~PositionHolder();
};