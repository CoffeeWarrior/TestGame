#pragma once

#include <HunterCentral.h>
#include <HunterApp.h>

//this symbol: "\" means that line still continues
#define START_GAME(classname) \
int main(){\
classname::Init();\
classname::GetApplication()->RunGame();\
}