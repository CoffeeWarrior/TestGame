#include <pch.h>
#include "HunterApp.h"
#include "Windows/WindowsWindow.h"

namespace Hunter {
	HunterApp* HunterApp::GetApplication() {
		return instance;
	}

	void HunterApp::Init() {
		if (instance == nullptr) { 
			instance = new HunterApp;
		}
	}

	HunterApp::HunterApp() {
		assert(instance == nullptr);
		
		appWindow = new WindowsWindow;
		bool success{ appWindow->CreateWindow(800, 600) };
		assert(success);

		
	}

	void HunterApp::RunGame() {
		HLOG("Starting the game");
		while (true) { // will add better condition later
			appWindow->SwapBuffers();
			appWindow->PollForEvents();
		}
	}

	HunterApp::~HunterApp() {
		appWindow->DeleteWindow();
	}
}
