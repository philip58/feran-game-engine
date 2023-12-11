#pragma once
#include"pch.h"
#include"Utilities.h"
#include"PictureImplementation.h"

namespace fr
{
	class FERAN_API Picture
	{
	public:
		Picture(const std::string& pic);
		Picture(std::string&& pic);

		void Bind();
		int GetHeight() const;
		int GetWidth() const;
	private:
		std::unique_ptr<PictureImplementation> mImplementation;
	};
}
