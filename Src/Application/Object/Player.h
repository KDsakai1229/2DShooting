#pragma once

class Player
{
public:

	Player(){}
	~Player() { Release(); }

	void Update();
	void Draw();
	void Init();


private:

	void Release();

};