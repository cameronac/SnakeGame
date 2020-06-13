#include "RenderController.h"
#include <stdio.h>
#include <iostream>
#include <string>


//Constructor
RenderController::RenderController()
{
	//Initialize Fonts
	if (TTF_Init() == -1) {
		printf("Initializing TTF_Init Failed!");
	}

	//Create Renderer
	renderer = SDL_CreateRenderer(&*WindowController::Get().window, -1, SDL_RENDERER_ACCELERATED);
	font = TTF_OpenFont("../Fonts/04B_30__.ttf", 32);

	if (font == NULL) {
		printf("Failed to load font!");
	}

	//Create Renderer
	if (renderer == NULL) {
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
	}
}

//Destructor
RenderController::~RenderController()
{
	SDL_DestroyTexture(texture);
	TTF_CloseFont(font);
	SDL_DestroyRenderer(renderer);
	
	texture = NULL;
	font = NULL;
	renderer = NULL;
	TTF_Quit();
}

//Public Methods
SDL_Renderer* RenderController::renderer = nullptr;
TTF_Font* RenderController::font = nullptr;
SDL_Texture* RenderController::texture = nullptr;
TailController* RenderController::tailController = nullptr;

///Updates Screen With Newly assigned objects| Should always be called: When Objects are added and background is set then call this to display those objects
void RenderController::DisplayRender()
{
	WindowController* windowController = &WindowController::Get();
	SDL_Rect fruitRect = SDL_Rect { windowController->SCREEN_WIDTH-192, 0, 192, 32 };
	DisplayFont();

	//Render texture to screen
	if (SDL_RenderCopy(renderer, texture, NULL, &fruitRect) == -1) {
		printf("Failed to RenderCopy!");
	}
	SDL_RenderPresent(renderer);
}

///Sets Up Background Before Rendering Objects Start| Should always be called: Before calling DisplayRender()
void RenderController::SetupBackground()
{  
	if (SDL_SetRenderDrawColor(renderer, 0x80, 0xFF, 0x80, 0xFF) == -1) {
		printf("Couldn't Set Render Draw Color");
	}

	SDL_RenderClear(renderer);
}

//Displays Font
void RenderController::DisplayFont()
{
	//Destroy Texture 
	SDL_DestroyTexture(texture);

	//Color
	SDL_Color color = SDL_Color{ 0, 0, 0, 255 };

	//Getting Tail Count
	int count = 0;
	if (tailController != nullptr) {
		count = tailController->getTailCount() - 1;
	}

	//Set up Surface
	std::string fruitString = "Fruit: " + std::to_string(count);
	const char* fruitText = fruitString.c_str();
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, fruitText, color);
	//std::cout << textSurface->w << " " << textSurface->h << std::endl;

	//Creating a Texture from Surface and Error checking
	if (textSurface == NULL) {
		printf("TextSurface is NULL!");
	} else {
		texture = SDL_CreateTextureFromSurface(renderer, textSurface);
		
		if (texture == NULL) {
			printf("Texture is NULL!");
		}

		//Get rid of old surface
		SDL_FreeSurface(textSurface);
	}
}
