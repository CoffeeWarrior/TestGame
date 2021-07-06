#include "pch.h"
#include "HunterApp.h"
#include "Windows/WindowsWindow.h"
#include "Renderer.h"
#include "Sprite.h"

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
		
		Renderer::Init();
		
		Sprite test1{"../Hunter/assets/sprites/Sprite1.png"};
		Sprite test2{ "../Hunter/assets/sprites/Gooby.png" };

		while (true) { // will add better condition later
			Renderer::Draw(test1, 100, 100, test1.getWidth(), test1.getHeight());
			Renderer::Draw(test2, 100, 100, test2.getWidth(), test2.getHeight());
			appWindow->SwapBuffers();
			appWindow->PollForEvents();
		}
	}

	HunterApp::~HunterApp() {
		appWindow->DeleteWindow();
	}
	int HunterApp::GetWindowWidth()
	{
		return instance->appWindow->GetWidth();
	}
	int HunterApp::GetWindowHeight()
	{
		return instance->appWindow->GetWidth();
	}
}
