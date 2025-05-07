#pragma once

#include "Object/Player.h"
#include "Object/Enemy1.h"
#include "Object/Enemy2.h"
#include "Object/Enemy3.h"

class Scene
{
private:

	static const int Enemy1Max = 100;
	static const int Enemy2Max = 20;
	static const int Enemy3Max = 5;

	Player m_player;
	Enemy1 m_enemy1[Enemy1Max];
	Enemy2 m_enemy2[Enemy2Max];
	Enemy3 m_enemy3[Enemy3Max];
	KdTexture BackTex;
	Math::Matrix BackMat;
	KdTexture TitleTex;
	Math::Matrix TitleMat;
	Math::Matrix ExplosionMat;

	KdTexture m_playerTex;
	KdTexture m_enemyTex;
	KdTexture m_enemy2Tex;
	KdTexture m_enemy3Tex;
	KdTexture m_bulletTex;
	KdTexture m_explTex;

	int sceneNum;
	int scoreBord;

public:

	// ‰Šúİ’è
	void Init();

	// ‰ğ•ú
	void Release();

	// XVˆ—
	void Update();

	// •`‰æˆ—
	void Draw2D();

	void TitleUpdate();
	void TitleDraw();

	void GameUpdate();
	void GameDraw();

	void ResultUpdate();
	void ResultDraw();

	void ExplosionDraw(int f,Math::Matrix mat);

	Enemy1* GetEnemy1(int e1);
	Enemy2* GetEnemy2(int e2);
	Enemy3* GetEnemy3(int e3);

	// GUIˆ—
	void ImGuiUpdate();

private:

	Scene() {}

public:
	static Scene& GetInstance()
	{
		static Scene instance;
		return instance;
	}
};

#define SCENE Scene::GetInstance()
