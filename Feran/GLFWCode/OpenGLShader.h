#pragma once
#include "Utilities.h"
#include "pch.h"
#include"ShaderImplementation.h"

namespace fr
{
	class OpenGLShader : public ShaderImplementation
	{
	public:
		OpenGLShader(const std::string& vertexSF, const std::string& fragmentSF);

		OpenGLShader(std::string&& vertexSF, std::string&& fragmentSF);

		~OpenGLShader();

		void Bind() override;
		virtual void SetUniform2Ints(const std::string& uniformName, int val1, int val2) override;
		virtual void SetUniform2Ints(std::string&& uniformName, int val1, int val2)  override;

	private:
		unsigned int mShaderProgram;

		std::string ReadWholeFile(const std::string& fileName);

		std::string ReadWholeFile(std::string&& fileName);

		// ReadWholeFile("shader.txt");
	};
}
