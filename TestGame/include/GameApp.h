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
	Hunter::Sprite mGameOverImage;
	long long timer;
	bool mGameEnd;

	enum class Action
	{
		None,
		LeftMove, 
		RightMove,
		UpMove,
		DownMove
	} mBuddyAction;
};