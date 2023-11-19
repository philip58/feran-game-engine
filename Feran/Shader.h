#pragma once
#include "Utilities.h"
#include "pch.h"

namespace fr
{
	class FERAN_API Shader
	{
	public:
		Shader(const std::string& vertexSFile, const std::string& fragmentSFile);
		void Bind();
	private:
		std::unique_ptr<ShaderImplementation> mImplementation;
	};
}