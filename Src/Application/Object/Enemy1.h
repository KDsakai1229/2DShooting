#pragma once

class Enemy1
{
public:

	Enemy1();
	~Enemy1();

	void Init();
	void Update();
	void Draw();

	void SetTex(KdTexture* eTex);
	bool GetAlive() const;
	Math::Vector2 GetPos() const;
	float GetRadius() const;

	void Hit();
	void Revibal();

private:

	static const int Enemy1Max = 100;

	const float m_moveSpeed = 5.0f;
	const float m_radius = 32.0f;

	KdTexture* m_eTex;
	Math::Vector2 m_pos;
	Math::Vector2 m_move;
	Math::Matrix m_mat;
	bool m_alive;

};