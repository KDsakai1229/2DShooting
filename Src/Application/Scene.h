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
