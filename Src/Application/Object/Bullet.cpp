#include "Bullet.h"

void Bullet::Update()
{
	if (!m_alive)return;

	m_pos.x += cos(m_angle) * m_moveSpeed;
	m_pos.y += sin(m_angle) * m_moveSpeed;

	m_mat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);

	if (m_pos.x < -640 || m_pos.x > 640 || m_pos.y < -360 || m_pos.y > 360)
	{
		m_alive = false;
	}
}

void Bullet::Draw()
{
	if (m_alive)
	{
		SHADER.m_spriteShader.SetMatrix(m_mat);
		SHADER.m_spriteShader.DrawTex(m_bTex, Math::Rectangle{ 0,0,16,16 }, 1.0f);
	}
}

void Bullet::Init()
{
	m_pos.x = 0.0f;
	m_pos.y = 0.0f;
	m_alive = false;
}

void Bullet::SetTex(KdTexture* bTex)
{
	m_bTex = bTex;
}

bool Bullet::GetAlive()
{
	return m_alive;
}

Math::Vector2 Bullet::GetPos()
{
	return m_pos;
}

float Bullet::GetRadius()
{
	return m_radius;
}

void Bullet::Shot(Math::Vector2 pos, float targetAngle)
{
	m_pos = pos;
	m_angle = targetAngle;
	m_alive = true;
}

void Bullet::Hit()
{
	m_alive = false;
}
