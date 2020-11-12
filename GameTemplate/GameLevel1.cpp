#include "GameLevel1.h"
#include "GameEngine.h"

void GameLevel1::Enter()
{
	bgSpriteTex = GameEngine::Instance()->LoadTexture("Img/Levels/SF_Level_1.jpg");

	GameState::Enter();
}
