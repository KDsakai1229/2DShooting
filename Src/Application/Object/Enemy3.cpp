#include "Enemy3.h"

Enemy3::Enemy3()
{
	m_pos.x = rand() % (1280 - 64) + 1 - (640 - 32);
	m_pos.y = 1500;
	m_move.x = 0;
	m_move.y = 0;
	m_alive = true;
	life = 15;
	m_eTex = nullptr;
}

Enemy3::~Enemy3()
{
	
}

void Enemy3::Init(int e3)
{
	m_pos.x = rand() % (1280 - 64) + 1 - (640 - 32);
	m_pos.y = rand() % 720 + 480;
	if (e3 % 2 == 0)
	{
		m_move.x = m_moveSpeedX;
	}
	else
	{
		m_move.x = -m_moveSpeedX;
	}
	m_move.y = -m_moveSpeedY;
	m_alive = true;
	life = 15;
}

void Enemy3::Update()
{
	if (!m_alive)return;

	m_pos += m_move;

	if (m_pos.y < -640)
	{
		m_pos.y = rand() % 720 + 720;
	}
	if (m_pos.x > 640 || m_pos.x < -640)
	{
		m_move.x *= -1;
	}

	m_mat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
}

void Enemy3::Draw()
{
	if (!m_alive)return;
	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(m_eTex, Math::Rectangle{ 0,0,128,128 }, 1.0f);
}

void Enemy3::SetTex(KdTexture* eTex)
{
	m_eTex = eTex;
}

bool Enemy3::GetAlive() const
{
	return m_alive;
}

Math::Vector2 Enemy3::GetPos() const
{
	return m_pos;
}

float Enemy3::GetRadius() const
{
	return m_radius;
}

void Enemy3::Hit()
{
	life -= 1;
	if (life <= 0)
	{
		m_alive = false;
	}
}

void Enemy3::Revibal()
{
	m_pos.x = rand() % (1280 - 64) + 1 - (640 - 32);
	m_pos.y = rand() % 720 + 480;
	m_alive = true;
	life = 15;
}
