#pragma once

#include "Object/Player.h"

class Scene
{
private:

	Player m_player;
	KdTexture BackTex;

	KdTexture m_playerTex;
	KdTexture m_enemyTex;
	KdTexture m_bulletTex;

	int sceneNum;
	int scoreBord;

	static const int Enemy1Max = 100;
	static const int Enemy2Max = 20;

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
