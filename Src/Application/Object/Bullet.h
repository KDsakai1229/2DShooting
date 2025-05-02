#pragma once

class Bullet
{
public:

	Bullet(){}
	~Bullet(){}

	void Update();
	void Draw();
	void Init();

	void SetTex(KdTexture* bTex);
	bool GetAlive();
	Math::Vector2 GetPos();
	float GetRadius();

	void Shot(Math::Vector2 pos, float targetAngle);
	void Hit();

private:

	const float m_moveSpeed = 20.0f;
	const float m_radius = 8.0f;

	KdTexture* m_bTex;
	Math::Vector2 m_pos;
	Math::Matrix m_mat;
	float m_angle;
	bool m_alive;

};