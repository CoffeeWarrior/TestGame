#include "pch.h"
#include "Renderer.h"
#include "OpenGL/OpenGLImplementation.h"

namespace Hunter {
	
	void Renderer::Init() {
		if (instance == nullptr) {
			instance = new Renderer;
		}
	}

	void Renderer::Draw(const Sprite& image, int x_pos, int y_pos, int width, int height)
	{
		instance->mDrawingEngine->Draw(image, x_pos, y_pos, width, height);
	}
	
	void Renderer::ShutDown() {
		if (instance != nullptr) {
			delete instance;
		}
	}


	Renderer::Renderer()
	{
#ifdef _HUNTER_OPENGL
		mDrawingEngine = new OpenGLImplementation;
#else
#only_OpenGL_is_supported_at_the_moment
#endif
	}
}
