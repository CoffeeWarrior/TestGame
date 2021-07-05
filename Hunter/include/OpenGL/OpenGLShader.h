#pragma once

#include "Shader.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Hunter {
	class HUNTER_API OpenGLShader : public Shader {
	public:
		bool Load(const std::string& vertexFile, const std::string& fragmentFile) override;
		void Use() override;

		void SetVec2Int(const std::string& uniformName, int val1, int val2) override;
		
		~OpenGLShader();

	private:
	
		unsigned int CompileShader(const std::string & shaderCode, unsigned int openGLMacro); //instead of using this, prof uses 2 shader definitions that are almost identical? 

		unsigned int mShaderProgram;
	};
} 