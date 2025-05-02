#pragma once
#include "Bullet.h"

class Scene;
class Enemy1;
class Enemy2;

class Player
{
public:

	Player() {}
	~Player() { m_bTex.Release(); }

	void Update();
	void Draw();
	void Init();

	void SetTex(KdTexture* pTex);
	void SetOwner(Scene* pOwner);

	bool GetAlive() const;

	void HitBulletEnemy1(int eNum);
	void HitPlayerEnemy1(int eNum);

	void HitBulletEnemy2(int eNum);
	void HitPlayerEnemy2(int eNum);

private:

	Math::Matrix playerMat;
	Math::Vector2 m_playerPos;

	KdTexture* m_pTex;
	KdTexture m_bTex;

	Scene* m_pOwner;

	static const int m_bulletMax = 300;
	static const int m_bCoolTime = 10;

	Math::Vector2 m_bPos;
	Math::Matrix m_bMat;
	float m_bAngle;
	bool m_bAlive;

	const float m_moveSpeed = 5.0f;
	const float m_radius = 32.0f;
	bool m_playerAlive;

	Bullet m_bullet[m_bulletMax];

	static const int Enemy1Max = 100;

	Enemy1* enemy1;
	Enemy2* enemy2;

};