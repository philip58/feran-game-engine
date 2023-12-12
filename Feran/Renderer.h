#pragma once
#include"Picture.h"
#include"pch.h"
#include"Utilities.h"
#include"RendererImplementation.h"
#include"Unit.h"

namespace fr
{
	class FERAN_API Renderer
	{
	public:
		Renderer();
		void Init();
		void Draw(int x, int y, Picture& pic);
		void Clear();

	private:
		std::unique_ptr<RendererImplementation> mImplementation;
	};
}
