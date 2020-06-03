#pragma once
#include "SDL.h"

struct Color {
	public:
		Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
		Uint8 r;
		Uint8 g;
		Uint8 b;
		Uint8 a;
};