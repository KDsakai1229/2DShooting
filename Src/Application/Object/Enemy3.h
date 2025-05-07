#pragma once

class Enemy3
{
public:

	Enemy3();
	~Enemy3();

	void Init(int e3);
	void Update();
	void Draw();

	void SetTex(KdTexture* eTex);
	bool GetAlive() const;
	Math::Vector2 GetPos() const;
	float GetRadius() const;

	void Hit();
	void Revibal();
	

private:

	const float m_moveSpeedX = 10.0f;
	const float m_moveSpeedY = 5.0f;
	const float m_radius = 16.0f;

	KdTexture* m_eTex;
	Math::Vector2 m_pos;
	Math::Vector2 m_move;
	Math::Matrix m_mat;
	bool m_alive;

	int life;

};