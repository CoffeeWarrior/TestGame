#pragma once
#include "Hunter.h"
#include "Unit.h"
#include <deque>
#include "Enemy.h"

class GameApp : public Hunter::HunterApp {
public:
	GameApp();
	
	void OnUpdate() override;

	void OnKeyPressed(Hunter::KeyPressedEvent& event) override;
private:
	Unit mBuddy;
	std::deque<Enemy> mEnemies;
	long long timer;

	enum class Action
	{
		None,
		LeftMove, 
		RightMove,
		UpMove,
		DownMove
	} mBuddyAction;
};