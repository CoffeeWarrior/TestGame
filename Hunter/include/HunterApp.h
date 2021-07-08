#pragma once
#include "HunterCentral.h"
#include "Window.h"
#include "KeyboardEvents.h"
#include "pch.h"

namespace Hunter {
	class HUNTER_API HunterApp {
	public:
		virtual void RunGame(); //The method that starts the game
		
		static HunterApp* GetApplication(); //return our instance pointer - the method is static because people should be able to call this method without an object.
		virtual ~HunterApp();

		virtual void OnUpdate();

		static int GetWindowWidth();
		static int GetWindowHeight();

		virtual void OnKeyPressed(KeyPressedEvent& event);
	protected:
		HunterApp();
	private:
		inline static HunterApp* instance{ nullptr }; //inline allows us to specify nullptr right in the class definition

		Window* appWindow{ nullptr }; //we use window pointer here, this can point at all derived classes,
		
		std::chrono::steady_clock::time_point mNextFrameTime;
		std::chrono::milliseconds mFrameDuration{ 33 };
	};
}
