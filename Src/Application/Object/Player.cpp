#include "Player.h"
#include "../Scene.h"

void Player::Update()
{
	if (m_playerAlive)
	{
		if (GetAsyncKeyState('D') & 0x8000)
		{
			m_playerPos.x += m_moveSpeed;
		}
		if (GetAsyncKeyState('A') & 0x8000)
		{
			m_playerPos.x -= m_moveSpeed;
		}
		if (GetAsyncKeyState('W') & 0x8000)
		{
			m_playerPos.y += m_moveSpeed;
		}
		if (GetAsyncKeyState('S') & 0x8000)
		{
			m_playerPos.y -= m_moveSpeed;
		}

		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			if (m_bCooltime <= 0)
			{
				for (int b = 0; b < m_bulletMax; b += 3)
				{
					if (!m_bullet[b].GetAlive())
					{
						m_bullet[b].Shot(m_playerPos, DirectX::XMConvertToRadians(90));
						m_bullet[b + 1].Shot(m_playerPos, DirectX::XMConvertToRadians(90 - 15));
						m_bullet[b + 2].Shot(m_playerPos, DirectX::XMConvertToRadians(90 + 15));
						m_bCooltime = bCoolTime;
						break;
					}
				}
			}
		}

		playerMat = Math::Matrix::CreateTranslation(m_playerPos.x, m_playerPos.y, 0);
	}

	for (int b = 0; b < m_bulletMax; b++)
	{
		m_bullet[b].Update();
	}

	if (m_bCooltime > 0)
	{
		m_bCooltime--;
	}
}

void Player::Draw()
{
	for (int b = 0; b < m_bulletMax; b++)
	{
		m_bullet[b].Draw();
	}

	playerMat = Math::Matrix::CreateTranslation(m_playerPos.x, m_playerPos.y, 0);
	SHADER.m_spriteShader.SetMatrix(playerMat);
	SHADER.m_spriteShader.DrawTex(m_pTex, Math::Rectangle{ 0,0,64,64 }, 1.0f);
}

void Player::Init()
{
	m_playerPos.x = 0;
	m_playerPos.y = -300;

	m_playerAlive = true;
	
	m_bTex.Load("Texture/bullet.png");
	for (int b = 0; b < m_bulletMax; b++)
	{
		m_bullet[b].SetTex(&m_bTex);
		m_bullet[b].Init();
	}

	m_bCooltime = bCoolTime;
}

void Player::SetTex(KdTexture* pTex)
{
	m_pTex = pTex;
}

void Player::SetOwner(Scene* pOwner)
{
	m_pOwner = pOwner;
}

bool Player::GetAlive() const
{
	return m_playerAlive;
}

void Player::HitBulletEnemy1(int eNum)
{
	enemy1 = m_pOwner->GetEnemy1(eNum);

	if (!enemy1->GetAlive())return;

	const Math::Vector2 enemyPos = enemy1->GetPos();

	for (int i = 0; i < m_bulletMax; i++)
	{
		if (!m_bullet[i].GetAlive())continue;

		const Math::Vector2 bulletPos = m_bullet[i].GetPos();

		const float x = bulletPos.x - enemyPos.x;
		const float y = bulletPos.y - enemyPos.y;
		const float z = sqrt(x * x + y * y);

		const float sumRadius = enemy1->GetRadius() + m_bullet[i].GetRadius();

		if (z < sumRadius)
		{
			enemy1->Hit();
			m_bullet[i].Hit();
		}
	}
}

void Player::HitPlayerEnemy1(int eNum)
{
	enemy1 = m_pOwner->GetEnemy1(eNum);

	if (!enemy1->GetAlive())return;

	const Math::Vector2 enemyPos = enemy1->GetPos();

	const float x = m_playerPos.x - enemyPos.x;
	const float y = m_playerPos.y - enemyPos.y;
	const float z = sqrt(x * x + y * y);

	const float sumRadius = enemy1->GetRadius() + m_radius;

	if (z < sumRadius)
	{
		enemy1->Hit();
		m_playerAlive = false;
	}
	
}

void Player::HitBulletEnemy2(int eNum)
{
	enemy2 = m_pOwner->GetEnemy2(eNum);

	if (!enemy2->GetAlive())return;

	const Math::Vector2 enemyPos = enemy2->GetPos();

	for (int i = 0; i < m_bulletMax; i++)
	{
		if (!m_bullet[i].GetAlive())continue;

		const Math::Vector2 bulletPos = m_bullet[i].GetPos();

		const float x = bulletPos.x - enemyPos.x;
		const float y = bulletPos.y - enemyPos.y;
		const float z = sqrt(x * x + y * y);

		const float sumRadius = enemy2->GetRadius() + m_bullet[i].GetRadius();

		if (z < sumRadius)
		{
			enemy2->Hit();
			m_bullet[i].Hit();
		}
	}
}

void Player::HitPlayerEnemy2(int eNum)
{
	enemy2 = m_pOwner->GetEnemy2(eNum);

	if (!enemy2->GetAlive())return;

	const Math::Vector2 enemyPos = enemy2->GetPos();

	const float x = m_playerPos.x - enemyPos.x;
	const float y = m_playerPos.y - enemyPos.y;
	const float z = sqrt(x * x + y * y);

	const float sumRadius = enemy2->GetRadius() + m_radius;

	if (z < sumRadius)
	{
		enemy2->Hit();
		m_playerAlive = false;
	}
}

void Player::HitBulletEnemy3(int eNum)
{
	enemy3 = m_pOwner->GetEnemy3(eNum);

	if (!enemy3->GetAlive())return;

	const Math::Vector2 enemyPos = enemy3->GetPos();

	for (int i = 0; i < m_bulletMax; i++)
	{
		if (!m_bullet[i].GetAlive())continue;

		const Math::Vector2 bulletPos = m_bullet[i].GetPos();

		const float x = bulletPos.x - enemyPos.x;
		const float y = bulletPos.y - enemyPos.y;
		const float z = sqrt(x * x + y * y);

		const float sumRadius = enemy3->GetRadius() + m_bullet[i].GetRadius();

		if (z < sumRadius)
		{
			enemy3->Hit();
			m_bullet[i].Hit();
		}
	}
}

void Player::HitPlayerEnemy3(int eNum)
{
	enemy3 = m_pOwner->GetEnemy3(eNum);

	if (!enemy3->GetAlive())return;

	const Math::Vector2 enemyPos = enemy3->GetPos();

	const float x = m_playerPos.x - enemyPos.x;
	const float y = m_playerPos.y - enemyPos.y;
	const float z = sqrt(x * x + y * y);

	const float sumRadius = enemy3->GetRadius() + m_radius;

	if (z < sumRadius)
	{
		enemy3->Hit();
		m_playerAlive = false;
	}
}
