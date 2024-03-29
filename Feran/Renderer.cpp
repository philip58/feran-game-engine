#include"pch.h"
#include"Renderer.h"
#include"GLFWCode/OpenGlRenderer.h"

namespace fr
{
	Renderer::Renderer()
	{
#ifdef FERAN_MSCPP
		mImplementation = std::unique_ptr<RendererImplementation>{ new OpenGLRenderer };
#elif FERAN_APPLE
		mImplementation = std::unique_ptr<RendererImplementation>{ new OpenGLRenderer };
#elif
		mImplementation = std::unique_ptr<RendererImplementation>{ new OpenGLRenderer };
#endif
	}

	void Renderer::Init()
	{
		mImplementation->Init();
	}

	void Renderer::Draw(int x, int y, Picture& pic)
	{
		mImplementation->Draw(x, y, pic);
	}

	void Renderer::Clear()
	{
		mImplementation->Clear();
	}
}
