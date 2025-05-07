#pragma once

class Enemy2
{
public:

	Enemy2();
	~Enemy2();

	void Init(int e2);
	void Update();
	void Draw();

	void SetTex(KdTexture* eTex);
	bool GetAlive() const;
	Math::Vector2 GetPos() const;
	float GetRadius() const;

	void Hit();
	void Revibal();

private:

	const float m_moveSpeedX = 5.0f;
	const float m_moveSpeedY = 3.0f;
	const float m_radius = 32.0f;

	KdTexture* m_eTex;
	Math::Vector2 m_pos;
	Math::Vector2 m_move;
	Math::Matrix m_mat;
	bool m_alive;

	int life;

};