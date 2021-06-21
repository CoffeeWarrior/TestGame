#pragma once

#include "HunterCentral.h"

namespace Hunter {
	class HUNTER_API Window { //this is an interface for glfw, so we can we can not use third party libraries directly.
	public:
		virtual bool CreateWindow(unsigned int width, unsigned int height) = 0; //pure virtual function
		virtual void DeleteWindow() = 0;
		virtual void SwapBuffers() = 0;
		virtual void PollForEvents() = 0;

	};
}