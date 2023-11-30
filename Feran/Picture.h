#pragma once
#include"pch.h"
#include"Utilities.h"
#include"PictureImplementation.h"

namespace fr
{
	class FERAN_API Picture
	{
	public:
		Picture();
		void Bind();
		unsigned int GetHeight() const;
		unsigned int GetWidth() const;
	private:
		unsigned int height;
		unsigned int width;
		std::unique_ptr<PictureImplementation> mImplementation;
	};
}
