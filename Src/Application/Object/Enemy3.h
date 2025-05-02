#pragma once

class Enemy3
{
public:

	Enemy3();
	~Enemy3();

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



};