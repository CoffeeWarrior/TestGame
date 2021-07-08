#include "..\include\GameApp.h"

GameApp::GameApp(): mBuddy("assets/Buddy.png", 10), mBuddyAction(Action::None)
{
	
}

void GameApp::OnUpdate()
{
	if (mBuddyAction == Action::LeftMove) {
		if(mBuddy.GetXCoord() - mBuddy.Speed() >= 0){
			mBuddy.MoveLeft();
		}
	}
	else if (mBuddyAction == Action::RightMove) {
		if (mBuddy.GetXCoord() + mBuddy.Speed() <= GameApp::GetWindowWidth() - mBuddy.GetWidth()) {
			mBuddy.MoveRight();
		}
		
	}/*
	up/down controls -- reenable if interested in up/down motion
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
	*/
	

	mBuddy.Draw();
	mBuddyAction = Action::None;
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
