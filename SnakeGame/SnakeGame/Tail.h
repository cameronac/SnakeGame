#pragma once
#include "SDL.h"
#include "Color.h"
#include "Move.h"
#include <queue>

class Tail {

	public:
		Tail(int tailIdentifier); //Constructor
		std::queue<Move> tailQueue;
		void checkTail(int xPosition, int yPosition); //Checks Tail every Frame and moves directions when needed
		SDL_Rect fillRect = { 32, 32, 32, 32 };
		Color color = Color(0xFF, 0x00, 0x00, 0xFF);
		int tailIdentifier;
};