#pragma once
#include"RendererImplementation.h"

namespace fr
{
	class OpenGLRenderer : public RendererImplementation
	{
	public:
		virtual void Init() override;
		virtual void Draw(int x, int y, Picture& pic) override;
		virtual void Clear() override;
	};
}