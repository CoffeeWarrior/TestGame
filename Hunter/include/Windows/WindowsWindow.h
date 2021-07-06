#pragma once

#include "Window.h"
#include "HunterCentral.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"


namespace Hunter {
	class HUNTER_API WindowsWindow final: public Window {
	public:
		bool CreateWindow(unsigned int width, unsigned int height) override;
		void DeleteWindow() override;
		void SwapBuffers() override;
		void PollForEvents() override;
		int GetWidth() const override;
		int GetHeight() const override;

	private:
		GLFWwindow* window{ nullptr };
	};
};