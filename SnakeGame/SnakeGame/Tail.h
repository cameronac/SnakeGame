#pragma once
#include "SDL.h"
#include "Color.h"
#include "Move.h"
#include <queue>
#include "Direction.h"
#include "PositionHolder.h"

class Tail {

	public:
		Tail(int tailIdentifier, Direction playerDirection, Direction lastTailDirection, PositionHolder* positionHolder, int positionOffsetX, int positionOffsetY);
		Tail(int tailIdentifier, Direction playerDirection, Direction lastTailDirection, std::queue<Move> tailQueue, PositionHolder* positionHolder, int positionOffsetX, int positionOffsetY); //Constructor
		std::queue<Move> tailQueue;
		void checkTail(); //Checks Tail every Frame and moves directions when needed
		SDL_Rect fillRect = { 32, 32, 32, 32 };
		Color color = Color(0xFF, 0x00, 0x00, 0xFF);
		Direction playerDirection;
		Direction currentDirection;
		int tailIdentifier;
		PositionHolder* positionHolder = NULL;
		PositionHolder* currentPosition = &PositionHolder(&fillRect.x, &fillRect.y);
};