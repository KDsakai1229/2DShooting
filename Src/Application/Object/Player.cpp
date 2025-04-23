#include "Player.h"
#include "../Scene.h"

void Player::Update()
{

}

void Player::Draw()
{

}

void Player::Init()
{
	playerPos.x = 0;
	playerPos.y = -300;

	playerTex->Load("Texture/player.png");
	
}

void Player::SetTex(KdTexture* pTex)
{
	m_pTex = pTex;
}

void Player::BulletUpdate()
{

}

void Player::BulletDraw()
{

}

void Player::BulletInit()
{
	bulletTex->Load("Texture/bullet.png");
}
