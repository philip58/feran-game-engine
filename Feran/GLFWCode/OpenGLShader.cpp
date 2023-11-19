#include"OpenGLShader.h"
#include"glad/glad.h"
#include"GLFW/glfw3.h"
#include "pch.h"

namespace fr
{
	OpenGLShader::OpenGLShader(const std::string& vertexSF, const std::string& fragmentSF)
	{
		const char* vertexShaderSource = R"(
			#version 330 core

			layout (location = 0) in vec2 aPos;
			layout (location = 1) in vec2 aTC;

			out vec2 TexCoord;

			void main()
			{
				gl_Position = vec4(aPos.x, aPos.y, 1.0, 1.0;
				TexCoord = aTC;
			}
		)";

		const char* fragmentShaderSource = R"(
			#version 330 core
			out vec4 FragColor;
			void main()
			{
				FragColor= vec4(1.0f, 0.0f, 0.0f, 1.0f);
			}
		)";

		unsigned int vertexShader;
		vertexShader = glCreateShader(GL_VERTEX_SHADER);

		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
		glCompileShader(vertexShader);

		int  success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			FR_ERROR("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog);
		}

		unsigned int fragmentShader;
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			FR_ERROR("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog);
		}

		unsigned int shaderProgram;
		shaderProgram = glCreateProgram();

		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glLinkProgram(shaderProgram);

		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
			FR_ERROR("Linking FAILED with the message/; " << infoLog);
		}

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	void OpenGLShader::Bind()
	{
		glUseProgram(mShaderProgram);
	}
}