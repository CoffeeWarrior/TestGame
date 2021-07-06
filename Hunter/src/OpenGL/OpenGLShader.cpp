#include "pch.h"
#include "OpenGL/OpenGLShader.h"
#include "HunterCentral.h"


#include <cassert>
#include <fstream>
#include <sstream>

namespace Hunter {

	bool OpenGLShader::Load(const std::string& vertexFile, const std::string& fragmentFile) {
		std::ifstream vertexSource{vertexFile};
		std::ifstream fragmentSource{fragmentFile};

		std::stringstream fShaderStream, vShaderStream;
		
		vShaderStream << vertexSource.rdbuf();
		fShaderStream << fragmentSource.rdbuf();

		vertexSource.close();
		fragmentSource.close();

		
		std::string vertexCode{ vShaderStream.str() };
		std::string fragmentCode{ fShaderStream.str() };
		

		//these values will be zero if compilation failed
		unsigned int vShader{ CompileShader(vertexCode, GL_VERTEX_SHADER) };
		unsigned int fShader{ CompileShader(fragmentCode, GL_FRAGMENT_SHADER) };
		if (!vShader || !fShader) {
			return false; //our loading failed
		}

		if (mShaderProgram) { //if there is an existing shader, we should delete it
			glDeleteProgram(mShaderProgram);
		}

		mShaderProgram = glCreateProgram();
		glAttachShader(mShaderProgram, vShader);
		glAttachShader(mShaderProgram, fShader);
		glLinkProgram(mShaderProgram);

		int success{ 0 };
		glGetProgramiv(mShaderProgram, GL_LINK_STATUS, &success);

		//delete shaders
		glDeleteShader(vShader);
		glDeleteShader(fShader);

		if (!success) {
			char infoLog[512];
			glGetProgramInfoLog(mShaderProgram, 512, NULL, infoLog);
			HLOG("ERROR LINKING THE SHADER PROGRAM:");
			HLOG(infoLog);
			return false; // our compilation fialed
		}

		

		return true; // our compilation was a success.
	}

	void OpenGLShader::Use() {
		assert(mShaderProgram);

		glUseProgram(mShaderProgram);
	}


	void OpenGLShader::SetVec2Int(const std::string& uniformName, int val1, int val2)
	{
		assert(mShaderProgram);

		int uniformID{ glGetUniformLocation(mShaderProgram, uniformName.c_str()) };
		glUniform2i(uniformID, val1, val2);
	}

	OpenGLShader::~OpenGLShader()
	{
		if (mShaderProgram) {
			glDeleteProgram(mShaderProgram);
		}
	}

	unsigned int OpenGLShader::CompileShader(const std::string& shaderCode, unsigned int openGLMacro) {
		unsigned int shader;
		shader = glCreateShader(openGLMacro); //returns zero if failure
		const char* cstring{ shaderCode.c_str() };
		glShaderSource(shader, 1, &cstring, 0);
		glCompileShader(shader);
		int success{ 0 };
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success) {
			char infoLog[512];
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			HLOG("ERROR COMPILING SHADER:");
			HLOG(infoLog);
		}
		return shader;
	}
}