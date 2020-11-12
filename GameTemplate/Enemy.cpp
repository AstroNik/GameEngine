#include "Enemey.h"

Enemy::Enemy(SDL_Texture* tex, double x, double y) : Player(tex, x, y)
{
	isFlipped = true;
	spriteSrcRect = { 0,0,70,80 };
	spriteDestRect = { (int)(m_X - 50),(int)(m_Y - 50)  ,70,80 };

	//m_velX = 0.9f;
	//m_velY = 5.5f;

	m_dRadius = 50;

	AddAnimState("Hadouken", AnimStateDefinition(0, 4, 120));
	AddAnimState("Idle", AnimStateDefinition(1, 4, 120));
	AddAnimState("Punch", AnimStateDefinition(2, 3, 120));
	AddAnimState("Move", AnimStateDefinition(3, 5, 120));

}

void Enemy::Update()
{

	this->PlayState("Idle");
	this->spriteSrcRect.x = spriteSrcRect.w * m_iFrame;

	this->UpdateDestRect();
}