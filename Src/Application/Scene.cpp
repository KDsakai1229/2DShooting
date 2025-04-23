#include "main.h"
#include "Scene.h"
#include "Object/Player.h"

void Scene::Draw2D()
{
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

	m_playerTex.Load("Texture/player.png");
	m_bulletTex.Load("Texture/bullet.png");

	m_player.SetTex(&m_playerTex);
}

void Scene::Release()
{
	BackTex.Release();
	m_playerTex.Release();
	m_bulletTex.Release();
}

void Scene::TitleUpdate()
{
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		sceneNum = 1;
	}
}

void Scene::TitleDraw()
{

}

void Scene::GameUpdate()
{
	m_player.Update();
	m_player.BulletUpdate();
}

void Scene::GameDraw()
{
	m_player.Draw();
}

void Scene::ResultUpdate()
{
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		sceneNum = 0;
	}
}

void Scene::ResultDraw()
{

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
