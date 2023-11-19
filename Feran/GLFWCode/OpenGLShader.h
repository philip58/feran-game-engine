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

		void Bind() override;

	private:
		unsigned int mShaderProgram;
	};
}
