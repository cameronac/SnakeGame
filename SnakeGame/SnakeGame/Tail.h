#pragma once
#include "SDL.h"
#include "Color.h"

struct Tail {

	public:
		Tail(double xPosition, double yPosition, int tailIdentifier);
		double xPosition;
		double yPosition;
		SDL_Rect fillRect = { 32, 32, 32, 32 };
		Color color = Color(0xFF, 0x00, 0x00, 0xFF);
		int tailIdentifier;
};