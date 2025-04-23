#pragma once

class Player
{
public:

	Player(){}
	~Player() {}

	void Update();
	void Draw();
	void Init();

	void SetTex(KdTexture* pTex);

	void BulletUpdate();
	void BulletDraw();
	void BulletInit();

	void SetBTex(KdTexture* bTex);
	bool GetBAlive();
	Math::Vector2 GetBPos();
	float GetBRadius();

	void BulletShot(Math::Vector2 pos, float targetAngle);
	void BulletHit();

private:

	Math::Matrix playerMat;
	Math::Vector2 playerPos;

	KdTexture* playerTex;
	KdTexture* bulletTex;

	KdTexture* m_pTex;
	KdTexture* m_bTex;

	static const int m_bulletMax = 100;

	bool m_playerAlive;

};