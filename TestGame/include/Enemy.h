#pragma once
#include "Hunter.h"
#include "Unit.h"
#include "Sprite.h"
class Enemy : public Unit {
public:
	Enemy(const std::string& spritePath, int newSpeed);
	void setSpawn();
	bool offScreen();
private:
	enum class StartSide{
		Left,
		Right
	} start;
};