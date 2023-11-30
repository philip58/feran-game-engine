#include"pch.h"
#include"Picture.h"

namespace fr
{
	Picture::Picture()
	{

	}

	void Picture::Bind()
	{
		mImplementation->Bind();
	}

	unsigned int Picture::GetHeight() const
	{
		return height;
	}

	unsigned int Picture::GetWidth() const
	{
		return width;
	}

	
}