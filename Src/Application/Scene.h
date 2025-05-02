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
	KdTexture BackTex;
	Math::Matrix BackMat;

	KdTexture m_playerTex;
	KdTexture m_enemyTex;
	KdTexture m_enemy2Tex;
	KdTexture m_bulletTex;

	int sceneNum;
	int scoreBord;

public:

	// �����ݒ�
	void Init();

	// ���
	void Release();

	// �X�V����
	void Update();

	// �`�揈��
	void Draw2D();

	void TitleUpdate();
	void TitleDraw();

	void GameUpdate();
	void GameDraw();

	void ResultUpdate();
	void ResultDraw();

	Enemy1* GetEnemy1(int e1);
	Enemy2* GetEnemy2(int e2);

	// GUI����
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
