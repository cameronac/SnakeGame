#pragma once
#include "SDL.h"
#include "Color.h"
#include "Move.h"
#include <queue>
#include "Direction.h"

class Tail {

	public:
		Tail(int tailIdentifier, Direction playerDirection, Direction lastTailDirection, int xPosition, int yPosition);
		Tail(int tailIdentifier, Direction playerDirection, Direction lastTailDirection, std::queue<Move> tailQueue, int xPosition, int yPosition); //Constructor
		std::queue<Move> tailQueue;
		void checkTail(); //Checks Tail every Frame and moves directions when needed
		SDL_Rect fillRect = { 32, 32, 32, 32 };
		Color color = Color(0xFF, 0x00, 0x00, 0xFF);
		Direction playerDirection;
		Direction currentDirection;
		int tailIdentifier;
};