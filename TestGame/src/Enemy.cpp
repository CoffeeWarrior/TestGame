#include "..\include\Enemy.h"
#include "GameApp.h"
#include <time.h>
Enemy::Enemy(const std::string& spritePath, int newSpeed): Unit(spritePath, newSpeed)
{
	setSpawn();
}



void Enemy::setSpawn()
{
	srand(time(NULL));
	int xPos{ std::rand() % 2 };
	
	if (xPos == 0) { //if zero go past the left of the screen
		SetXCoord(0 - GetWidth());
		start = StartSide::Left;
	}
	else { //go past the right of the screen
		SetXCoord(GameApp::GetWindowWidth());
		this->Speed() *= -1; //go left
		start = StartSide::Right;
	}

	SetYCoord(std::rand()% (GameApp::GetWindowHeight() - this->GetHeight()));

}

bool Enemy::offScreen()
{
	if (start == StartSide::Right) {
		return GetXCoord() < 0 - GetWidth();;
	}
	else {
		return GetXCoord() > GameApp::GetWindowWidth();
	}
}

