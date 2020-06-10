#include "Fruit.h"
#include <random>

//Constructor
Fruit::Fruit()
{
}

//Respawn/Move to a Random Area on the Screen
void Fruit::respawn()
{
	//Get a Random Number between 0-640, and 0-480
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr1(15, 640-15); //Define Range: X
	std::uniform_int_distribution<> distr2(15, 480-15); //Define Range: Y

	fillRect.x = distr1(gen);	//Generate and Assign Random Number
	fillRect.y = distr2(gen);
}

//Update Fruit if Collided with 
void Fruit::checkFruit(PlayerController& playerController)
{
	//Check For collision with Player if there is respawn and add a Tail to the player
	//Within X Position
	if (fillRect.x + fillRect.w > playerController.fillRect.x && fillRect.x < playerController.fillRect.x + playerController.fillRect.w) {
		
		//Within Y Position
		if (fillRect.y + fillRect.h > playerController.fillRect.y && fillRect.y < playerController.fillRect.y + playerController.fillRect.h) {
			playerController.tailController->addNewTail();
			respawn();
		}
	}
}

//Renders Fruit
void Fruit::renderFruit(RenderController& renderController)
{
	//Render Fruit
	if (SDL_SetRenderDrawColor(renderController.renderer, color.r, color.g, color.b, color.a) == -1) {
		printf("Error Setting Render Draw Color!");
	}

	if (SDL_RenderFillRect(renderController.renderer, &fillRect) == -1) {
		printf("Error Rendering Fill Rect!");
	}
}
