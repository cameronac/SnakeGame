#pragma once
#include "SDL.h"

class FPSController
{	
	//Public Properties
	public:
		double lastTime;
		double deltaTime;
	//Public Methods
	public:
		FPSController();
		~FPSController();
		void updateFPS();
};

