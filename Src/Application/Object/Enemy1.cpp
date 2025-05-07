#include "Enemy1.h"

Enemy1::Enemy1()
{
	m_pos.x = rand() % (1280 - 64) + 1 - (640 - 32);
	m_pos.y = 1500;
	m_move.x = 0;
	m_move.y = 0;
	m_alive = true;
	m_eTex = nullptr;
}

Enemy1::~Enemy1()
{

}

void Enemy1::Init()
{
	m_pos.x = rand() % (1280 - 64) + 1 - (640 - 32);
	m_pos.y = rand() % 720 + 480;
	m_move.x = 0;
	m_move.y = -m_moveSpeed;
	m_alive = true;
}

void Enemy1::Update()
{
	if (!m_alive)return;

	m_pos += m_move;

	if (m_pos.y < -640)
	{
		m_pos.y = rand() % 720 + 720;
	}

	m_mat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
}

void Enemy1::Draw()
{
	if (!m_alive)return;
	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(m_eTex, Math::Rectangle{ 0,0,64,64 }, 1.0f);
}

void Enemy1::SetTex(KdTexture* eTex)
{
	m_eTex = eTex;
}

bool Enemy1::GetAlive() const
{
	return m_alive;
}

Math::Vector2 Enemy1::GetPos() const
{
	return m_pos;
}

float Enemy1::GetRadius() const
{
	return m_radius;
}

void Enemy1::Hit()
{
	m_alive = false;
}

void Enemy1::Revibal()
{
	m_pos.x = rand() % (1280 - 64) + 1 - (640 - 32);
	m_pos.y = rand() % 720 + 480;
	m_alive = true;
}
