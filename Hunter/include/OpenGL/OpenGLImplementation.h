#pragma once

#include "RendererImplementation.h"
#include "OpenGL/OpenGLShader.h"
namespace Hunter
{
	class OpenGLImplementation : public RendererImplementation {
	public:
		OpenGLImplementation();
		void Init() override;
		void Draw(const Sprite& image, int x_pos, int y_pos, int width, int height) override;
		virtual ~OpenGLImplementation();
		void ClearFrame();
	private:
		OpenGLShader mShaderDefault;
	};
};