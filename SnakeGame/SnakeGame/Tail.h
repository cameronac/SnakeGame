#pragma once
#include "SDL.h"
#include "Color.h"
#include "Move.h"
#include <queue>

struct Tail {

	public:
		Tail(double xPosition, double yPosition, int tailIdentifier); //Constructor
		std::queue<Move> tailQueue;
		void checkTail(); //Checks Tail every Frame and moves directions when needed
		double xPosition;
		double yPosition;
		SDL_Rect fillRect = { 32, 32, 32, 32 };
		Color color = Color(0xFF, 0x00, 0x00, 0xFF);
		int tailIdentifier;
};