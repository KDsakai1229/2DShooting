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
	
}

void Player::SetBTex(KdTexture* bTex)
{
	m_bTex = bTex;
}

bool Player::GetBAlive()
{
	return false;
}

Math::Vector2 Player::GetBPos()
{
	return Math::Vector2();
}

float Player::GetBRadius()
{
	return 0.0f;
}

void Player::BulletShot(Math::Vector2 pos, float targetAngle)
{
}

void Player::BulletHit()
{
}
