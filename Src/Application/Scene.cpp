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
	sceneNum = 0;
	scoreBord = 0;

	m_player.Init();

	BackTex.Load("Texture/back.png");
	TitleTex.Load("Texture/Title.png");

	m_playerTex.Load("Texture/player.png");
	m_enemyTex.Load("Texture/enemy.png");
	m_enemy2Tex.Load("Texture/enemy2.png");
	m_enemy3Tex.Load("Texture/Sun.png");
	m_bulletTex.Load("Texture/bullet.png");

	m_player.SetTex(&m_playerTex);

	for (int e1 = 0; e1 < Enemy1Max; e1++)
	{
		m_enemy1[e1].Init();
		m_enemy1[e1].SetTex(&m_enemyTex);
	}
	for (int e2 = 0; e2 < Enemy2Max; e2++)
	{
		m_enemy2[e2].Init(e2);
		m_enemy2[e2].SetTex(&m_enemy2Tex);
	}
	for (int e3 = 0; e3 < Enemy3Max; e3++)
	{
		m_enemy3[e3].Init(e3);
		m_enemy3[e3].SetTex(&m_enemy3Tex);
	}

	m_player.SetOwner(this);
}

void Scene::Release()
{
	BackTex.Release();
	TitleTex.Release();
	m_playerTex.Release();
	m_enemyTex.Release();
	m_enemy2Tex.Release();
	m_enemy3Tex.Release();
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
			m_enemy2[e2].Init(e2);
		}
		for (int e3 = 0; e3 < Enemy3Max; e3++)
		{
			m_enemy3[e3].Init(e3);
		}
		sceneNum = 1;
	}
}

void Scene::TitleDraw()
{
	//SHADER.m_spriteShader.DrawString(-200, 200, "INVASION of ENDLESS", Math::Color(0.5, 1, 1, 1));
	//SHADER.m_spriteShader.DrawString(-200, -200, "Press [ENTER] Start", Math::Color(0.5, 1, 1, 1));

	TitleMat = Math::Matrix::CreateTranslation(0, 0, 0);
	SHADER.m_spriteShader.SetMatrix(TitleMat);
	SHADER.m_spriteShader.DrawTex(&TitleTex, { 0,0,1280,720 }, 1.0f);
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

		if (scoreBord < 300 && e1 >= 10 - 1)break;
		if (scoreBord < 5000 && e1 >= 30 - 1)break;
		if (scoreBord < 10000 && e1 >= 50 - 1)break;
	}

	for (int e2 = 0; e2 < Enemy2Max; e2++)
	{
		if (scoreBord < 200)break;

		if (!m_enemy2[e2].GetAlive())
		{
			scoreBord += 50;
			m_enemy2[e2].Revibal();
		}

		m_enemy2[e2].Update();
		m_player.HitBulletEnemy2(e2);
		m_player.HitPlayerEnemy2(e2);

		if (scoreBord < 500 && e2 >= 2 - 1)break;
		if (scoreBord < 10000 && e2 >= 5 - 1)break;
		if (scoreBord < 15000 && e2 >= 10 - 1)break;
	}

	for (int e3 = 0; e3 < Enemy3Max; e3++)
	{
		if (scoreBord < 3000)break;

		if (!m_enemy3[e3].GetAlive())
		{
			scoreBord += 300;
			m_enemy3[e3].Revibal();
		}

		m_enemy3[e3].Update();
		m_player.HitBulletEnemy3(e3);
		m_player.HitPlayerEnemy3(e3);

		if (scoreBord < 10000 && e3 >= 1 - 1)break;
		if (scoreBord < 20000 && e3 >= 2 - 1)break;
	}


	if (!m_player.GetAlive())
	{
		Sleep(60 * 15);
		sceneNum = 2;
	}
}

void Scene::GameDraw()
{
	m_player.Draw();
	for (int e1 = 0; e1 < Enemy1Max; e1++)
	{
		m_enemy1[e1].Draw();

		if (scoreBord < 300 && e1 >= 10 - 1)break;
		if (scoreBord < 5000 && e1 >= 30 - 1)break;
		if (scoreBord < 10000 && e1 >= 50 - 1)break;
	}
	for (int e2 = 0; e2 < Enemy2Max; e2++)
	{
		if (scoreBord < 200)break;

		m_enemy2[e2].Draw();

		if (scoreBord < 500 && e2 >= 2 - 1)break;
		if (scoreBord < 10000 && e2 >= 5 - 1)break;
		if (scoreBord < 15000 && e2 >= 10 - 1)break;
	}

	D3D.SetBlendState(BlendMode::Add);
	for (int e3 = 0; e3 < Enemy3Max; e3++)
	{
		if (scoreBord < 3000)break;

		m_enemy3[e3].Draw();

		if (scoreBord < 10000 && e3 >= 1 - 1)break;
		if (scoreBord < 20000 && e3 >= 2 - 1)break;
	}


	D3D.SetBlendState(BlendMode::Alpha);
	char Stext[200];
	sprintf_s(Stext, sizeof(Stext), "SCORE:%010d", scoreBord);
	SHADER.m_spriteShader.DrawString(-620, 350, Stext, Math::Color(1, 0, 1));
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
	char Stext[200];
	sprintf_s(Stext, sizeof(Stext),"SCORE:%010d", scoreBord);
	SHADER.m_spriteShader.DrawString(-150, 50, Stext, Math::Color(1, 0, 1));

	SHADER.m_spriteShader.DrawString(-170, -200, "Press [SPACE] to Title", Math::Color(0.5, 1, 1, 1));
}

Enemy1* Scene::GetEnemy1(int e1)
{
	return &m_enemy1[e1];
}

Enemy2* Scene::GetEnemy2(int e2)
{
	return &m_enemy2[e2];
}

Enemy3* Scene::GetEnemy3(int e3)
{
	return &m_enemy3[e3];
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
