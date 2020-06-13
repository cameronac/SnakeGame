#pragma once
#include "SDL.h"
#include "RenderController.h"
#include "InputController.h"
#include "PlayerController.h"
#include "WindowController.h"
#include "Fruit.h"

/*
	Keeps Track of GameState and updates objects
*/
class GameController
{
	//Public Variables
	public: 
		RenderController* renderController = &RenderController::Get();	//Renderer
		InputController* inputController = &InputController::Get();	//Input 
		WindowController* windowController = &WindowController::Get(); //Window
		PlayerController* playerController;	//Player
		Fruit* fruit; //Fruit

		//Get Class 
		/*static GameController& Get() {
			static GameController instance;
			return instance;
		}*/
		GameController(); //Constructor
		~GameController();	//Destructor

	//Public Methods
	public:
		//GameController(const GameController&) = delete; //Copy Constructor
		void GameRefresh();	//Refreshes Game by updating the current state of all objects and adds them to the renderer respectivley
		void RestartGame(); //Restarts the Game

	private:
		

};


