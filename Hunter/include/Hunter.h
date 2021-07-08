#pragma once

#include <HunterCentral.h>
#include <HunterApp.h>
#include "Windows/WindowsWindow.h"
#include "Sprite.h"
#include "Renderer.h"
#include "HunterKeys.h"


//this symbol: "\" means that line still continues
#define START_GAME(classname) \
	int main(){\
	classname* gamePointer = new classname;\
	gamePointer->GetApplication()->RunGame();\
	delete gamePointer;\
}