#pragma once
#include "Hunter.h"
#include "Unit.h"
#include <deque>

class GameApp : public Hunter::HunterApp {
public:
	GameApp();
	
	void OnUpdate() override;

	void OnKeyPressed(Hunter::KeyPressedEvent& event) override;
private:
	Unit mBuddy;
	std::deque<Unit> enemies;

	enum class Action
	{
		None,
		LeftMove, 
		RightMove,
		UpMove,
		DownMove
	} mBuddyAction;
};