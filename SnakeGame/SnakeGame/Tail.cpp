#include "Tail.h"
#include <iostream>

//Initializer
Tail::Tail(int tailIdentifier)
{
	this->tailIdentifier = tailIdentifier;
}

void Tail::checkTail(int xPosition, int yPosition)
{
	std::cout << xPosition << ", " << yPosition << std::endl;
	
	if (tailIdentifier > 0) {
		fillRect.x = (tailIdentifier * 32) + xPosition;
		fillRect.y = (tailIdentifier * 32) + yPosition;
	}
	else {
		fillRect.x = (32) + xPosition;
		fillRect.y = (32) + yPosition;
	}
}
