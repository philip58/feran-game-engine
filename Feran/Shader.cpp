#include "Shader.h"
#include "pch.h"

namespace fr
{
	Shader::Shader(const std::string& vertexSFile, const std::string& fragmentSFile)
	{
#ifdef FERAN_MSCPP
		mImplementation = std::unique_ptr<ShaderImplementation>{ new OpenGLShader(vertexSFile, fragmentSFile)};

#elif FERAN_APPLE
		mImplementation = std::unique_ptr<ShaderImplementation>{ new OpenGLShader(vertexSFile, fragmentSFile) };
	};

#elif FERAN_LINUX
		mImplementation = std::unique_ptr<ShaderImplementation>{ new OpenGLShader(vertexSFile, fragmentSFile) };

#endif
	}

	void Shader::Bind()
	{
		mImplementation->Bind();
	}

}