#include "main.h"
#include "Scene.h"

void Scene::Draw2D()
{
	BackMat = Math::Matrix::CreateTranslation(0, 0, 0);
	SHADER.m_spriteShader.SetMatrix(BackMat);
	SHADER.m_spriteShader.DrawTex(&BackTex, { 0,0,1280,720 }, 1.0f);

	switch (sceneNum)
	{
	case 0:
		TitleDraw();

		break;
	case 1:
		GameDraw();
		break;
	case 2:
		ResultDraw();
		break;
	}
}

void Scene::Update()
{
	
	switch (sceneNum)
	{
	case 0:
		TitleUpdate();

		break;
	case 1:
		GameUpdate();
		break;
	case 2:
		ResultUpdate();
		break;
	}

}

void Scene::Init()
{
	sceneNum = 1;
	scoreBord = 0;

	m_player.Init();

	BackTex.Load("Texture/back.png");

	m_playerTex.Load("Texture/player.png");
	m_enemyTex.Load("Texture/enemy.png");
	m_enemy2Tex.Load("Texture/enemy2.png");
	m_bulletTex.Load("Texture/bullet.png");

	m_player.SetTex(&m_playerTex);

	for (int e1 = 0; e1 < Enemy1Max; e1++)
	{
		m_enemy1[e1].Init();
		m_enemy1[e1].SetTex(&m_enemyTex);
	}
	for (int e2 = 0; e2 < Enemy2Max; e2++)
	{
		m_enemy2[e2].Init();
		m_enemy2[e2].SetTex(&m_enemy2Tex);
	}

	m_player.SetOwner(this);
}

void Scene::Release()
{
	BackTex.Release();
	m_playerTex.Release();
	m_enemyTex.Release();
	m_enemy2Tex.Release();
	m_bulletTex.Release();
}

void Scene::TitleUpdate()
{
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		scoreBord = 0;
		m_player.Init();
		for (int e1 = 0; e1 < Enemy1Max; e1++)
		{
			m_enemy1[e1].Init();
		}
		for (int e2 = 0; e2 < Enemy2Max; e2++)
		{
			m_enemy2[e2].Init();
		}
		sceneNum = 1;
	}
}

void Scene::TitleDraw()
{
	SHADER.m_spriteShader.DrawString(-200, -200, "Press [ENTER] Start", Math::Color(0.5, 1, 1, 1));
}

void Scene::GameUpdate()
{
	m_player.Update();
	for (int e1 = 0; e1 < Enemy1Max; e1++)
	{
		if (!m_enemy1[e1].GetAlive())
		{
			scoreBord += 10;
			m_enemy1[e1].Revibal();
		}

		m_enemy1[e1].Update();
		m_player.HitBulletEnemy1(e1);
		m_player.HitPlayerEnemy1(e1);
	}
	for (int e2 = 0; e2 < Enemy2Max; e2++)
	{
		if (!m_enemy2[e2].GetAlive())
		{
			scoreBord += 30;
			m_enemy2[e2].Revibal();
		}

		m_enemy2[e2].Update();
		m_player.HitBulletEnemy2(e2);
		m_player.HitPlayerEnemy2(e2);
	}


	if (!m_player.GetAlive())
	{
		Sleep(60 * 10);
		sceneNum = 2;
	}
}

void Scene::GameDraw()
{
	m_player.Draw();
	for (int e1 = 0; e1 < Enemy1Max; e1++)
	{
		m_enemy1[e1].Draw();
	}
	for (int e2 = 0; e2 < Enemy2Max; e2++)
	{
		m_enemy2[e2].Draw();
	}
}

void Scene::ResultUpdate()
{
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		sceneNum = 0;
	}
}

void Scene::ResultDraw()
{

}

Enemy1* Scene::GetEnemy1(int e1)
{
	return &m_enemy1[e1];
}

Enemy2* Scene::GetEnemy2(int e2)
{
	return &m_enemy2[e2];
}

void Scene::ImGuiUpdate()
{
	return;

	ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiSetCond_Once);
	ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_Once);

	// デバッグウィンドウ
	if (ImGui::Begin("Debug Window"))
	{
		ImGui::Text("FPS : %d", APP.m_fps);
	}
	ImGui::End();
}
