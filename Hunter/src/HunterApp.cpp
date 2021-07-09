#include "pch.h"
#include "HunterApp.h"
#include "Windows/WindowsWindow.h"
#include "Renderer.h"
#include "Sprite.h"
#include "HunterKeys.h"

namespace Hunter {
	HunterApp* HunterApp::GetApplication() {
		return instance;
	}

	HunterApp::HunterApp() {
		assert(instance == nullptr);
		
		instance = this;
#ifdef _HUNTER_WINDOWS
		appWindow = new WindowsWindow;
#else
		#Only_windows_supported_sorry
#endif

		bool success{ appWindow->CreateWindow(1000, 1000) };
		assert(success);

		appWindow->SetKeyPressedCallback([this](KeyPressedEvent& event) {OnKeyPressed(event); });
	}

	void HunterApp::RunGame() {
		HLOG("Starting the game");
		
		Renderer::Init();
		
		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;
		
		while (true) { // will add better condition later

			Renderer::ClearFrame();

			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);
			
			appWindow->SwapBuffers();
			appWindow->PollForEvents();

			mNextFrameTime += mFrameDuration;
		}
	}

	HunterApp::~HunterApp() {
		appWindow->DeleteWindow();
	}

	void HunterApp::OnUpdate()
	{
		//left empty because hunter app will not do anything. It is up to game programmer to create OnUpdate function in inherted game class
	}

	int HunterApp::GetWindowWidth()
	{
		return instance->appWindow->GetWidth();
	}
	int HunterApp::GetWindowHeight()
	{
		return instance->appWindow->GetWidth();
	}
	void HunterApp::OnKeyPressed(KeyPressedEvent& event)
	{
		HLOG(event.GetKeyCode());
	}
}
