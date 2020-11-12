#pragma once
#include "Player.h"

class Enemy : public Player
{
public:
	Enemy(SDL_Texture* tex, double x, double y);

	//Over-ride the base player class's Update functionality
	void Update() override;

};