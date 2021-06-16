#include <pch.h>
#include "HunterApp.h"


namespace Hunter {
	HunterApp* HunterApp::GetApplication() {
		return instance;
	}

	void HunterApp::Init() {
		if (instance == nullptr) { //Professor did this line different, he said instance != nullptr - seems wrong
			instance = new HunterApp;
		}
	}

	HunterApp::HunterApp() {
		assert(instance == nullptr);
	}

	void HunterApp::RunGame() {
		HLOG("Starting the game");
		while (true) { // will add better condition later

		}
	}
}
