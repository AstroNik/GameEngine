// GameTemplate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "GameEngine.h"
#include "MainMenuState.h"

int main(int argc, char* argv[])
{
	if (!GameEngine::Instance()->Init("Game Template", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, 1024, 768, 0))
		return -1; //close the application if initialization fails

	GameEngine::Instance()->SetInitialState(new MainMenuState());

//	Game::Instance()->InitializeGame();



	while (GameEngine::Instance()->IsRunning())
	{
		GameEngine::Instance()->HandleEvents();
		GameEngine::Instance()->Update();
		GameEngine::Instance()->Render();
		SDL_Delay(10); //delay of 10 ms after every loop iteration


	}
	GameEngine::Instance()->Clean();

	return 0;

}