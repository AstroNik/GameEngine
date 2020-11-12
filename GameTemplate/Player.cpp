#include "Player.h"
#include "GameEngine.h"
#include <algorithm> //for min/max functions

Player::Player(SDL_Texture* tex, double x, double y)
	: SpriteExAnimated(tex, x - 50, y - 50, 0, 1, 4, 0.1f)
{

	spriteSrcRect = { 0,0,70,80 };
	spriteDestRect = { (int)(m_X - 50),(int)(m_Y - 50)  ,70,80 };

	m_velX = 0.9f;
	m_velY = 5.5f;

	m_dRadius = 50;

	AddAnimState("Hadouken", AnimStateDefinition(0, 4, 120));
	AddAnimState("Idle", AnimStateDefinition(1, 4, 120, true));
	AddAnimState("Punch", AnimStateDefinition(2, 3, 120));
	AddAnimState("Move", AnimStateDefinition(3, 5, 120, true));


	AddAnimState("Kick", AnimStateDefinition(6, 5, 120));
	AddAnimState("Roundhouse", AnimStateDefinition(7, 5, 120));
	AddAnimState("Jump", AnimStateDefinition(8, 7, 120));
	AddAnimState("Crouch", AnimStateDefinition(9, 1, 120));

	animStates["Jump"].RegisterOnAnimCompleteCallback
	(std::bind(&Player::OnJumpAnimationComplete, this));

	int aa = 4;
	animStates["Jump"].RegisterOnSomethingCompletedCallback(
		std::bind(&Player::OnSomethingComplete, this, aa)
	);
}

void Player::OnSomethingComplete(int x)
{
	cout << "callback received: " << x << endl;
}

Player::~Player()
{


}


void Player::Render()
{
	this->SpriteExAnimated::Render(); //invoke the base class's Render()
}



void Player::Update()
{

	this->UpdatePlayer();
}


void Player::Jump()
{
	if (m_iFrame < 3)
		m_Y -= m_velY;
	else if (m_iFrame > 3)
	{
		m_Y += m_velY;
		if (m_Y > preJumpYVal)
			m_Y = preJumpYVal;
	}
}

//Engine must call this function when our jump animation is completed.
void Player::OnJumpAnimationComplete()
{
	cout << "Jump animation is completed. TODO: reset player back to pre-jump Y position.\n";

	if (m_Y > preJumpYVal)
		m_Y = preJumpYVal;

}


void Player::MovePlayer(bool isFwd)
{

	if (isFwd)
		m_X += m_velX;
	else
		m_X -= m_velX;

	this->PlayState("Move");
}




void Player::UpdatePlayer()
{


	if (GameEngine::Instance()->KeyDown(SDL_SCANCODE_D))
	{
		this->MovePlayer(true);

	}
	else if (GameEngine::Instance()->KeyDown(SDL_SCANCODE_A))
	{
		this->MovePlayer(false);
	}
	else if (GameEngine::Instance()->KeyDown(SDL_SCANCODE_K)) {
		this->PlayState("Kick");
	}
	else if (GameEngine::Instance()->KeyDown(SDL_SCANCODE_SPACE))
	{

		if (this->currentState != "Jump")
		{
			preJumpYVal = m_Y;

		}

		this->PlayState("Jump");
	}
	else if (GameEngine::Instance()->KeyDown(SDL_SCANCODE_P))
	{
		this->PlayState("Punch");
	}
	else if (GameEngine::Instance()->KeyDown(SDL_SCANCODE_R))
	{
		this->PlayState("Roundhouse");
	}
	else if (GameEngine::Instance()->KeyDown(SDL_SCANCODE_H))
	{
		this->PlayState("Hadouken");
	}
	else {
		this->PlayState("Idle");
	}

	////compare and see if we are in jump state, and if yes, call Jump....
	if (currentState == ("Jump"))
	{
		Jump();
	}


	this->spriteSrcRect.x = spriteSrcRect.w * m_iFrame;
	this->UpdateDestRect();

}

