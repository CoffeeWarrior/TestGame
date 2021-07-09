#include "..\include\GameApp.h"
#include "Enemy.h"

#define BUDDY_SPEED 10
#define BULLY_SPEED 6

GameApp::GameApp() : mBuddy("assets/Buddy.png", BUDDY_SPEED), mBuddyAction(Action::None), timer(0)
{
	mBuddy.SetXCoord(100);
	mBuddy.SetYCoord(100);
	
}

void GameApp::OnUpdate()
{
	for (auto & enemy : mEnemies) {
		enemy.MoveXBySpeed();
		enemy.Draw();
	}

	/*************************************************************************************************************/
	/********************************************      TIMER CODE ************************************************/
	/*************************************************************************************************************/
	if (timer % 30 == 0) {
		mEnemies.emplace_back("assets/Bully.png", BULLY_SPEED);
	}
	timer++;


	/*************************************************************************************************************/
	/********************************************      BUDDY CODE ************************************************/
	/*************************************************************************************************************/

	if (mBuddyAction == Action::LeftMove) {
		if(mBuddy.GetXCoord() - mBuddy.Speed() >= 0){
			mBuddy.MoveLeft();
		}
	}
	else if (mBuddyAction == Action::RightMove) {
		if (mBuddy.GetXCoord() + mBuddy.Speed() <= GameApp::GetWindowWidth() - mBuddy.GetWidth()) {
			mBuddy.MoveRight();
		}
		
	} 
	else if (mBuddyAction == Action::DownMove) {
		if (mBuddy.GetYCoord() - mBuddy.Speed() >= 0) {
			mBuddy.MoveDown();
		}
	}
	else if (mBuddyAction == Action::UpMove) {
		if (mBuddy.GetYCoord() + mBuddy.Speed() <= GameApp::GetWindowHeight() - mBuddy.GetHeight()) {
			mBuddy.MoveUp();
		}
	}	
	mBuddy.Draw();
	// mBuddyAction = Action::None; //we can have this line, however it feels smoother when character continues moving in a direction
}

void GameApp::OnKeyPressed(Hunter::KeyPressedEvent& event)
{
	if (event.GetKeyCode() == HUNTER_KEY_LEFT) {
		mBuddyAction = Action::LeftMove;
	}
	else if (event.GetKeyCode() == HUNTER_KEY_RIGHT) {
		mBuddyAction = Action::RightMove;
	} 
	else if (event.GetKeyCode() == HUNTER_KEY_UP) {
		mBuddyAction = Action::UpMove;
	}
	else if (event.GetKeyCode() == HUNTER_KEY_DOWN) {
		mBuddyAction = Action::DownMove;
	}
}
