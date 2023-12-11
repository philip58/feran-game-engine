#include"pch.h"
#include"Picture.h"
#include"GLFWCode/OpenGLPicture.h"

namespace fr
{
	Picture::Picture(const std::string& pic)
	{
#ifdef FERAN_MSCPP
		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(pic) };
#elif FERAN_APPLE
		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(pic) };
#elif
		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(pic) };
#endif
	}

	Picture::Picture(std::string&& pic)
	{
#ifdef FERAN_MSCPP
		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(std::move(pic)) };
#elif FERAN_APPLE
		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(std::move(pic)) };
#elif
		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(std::move(pic)) };
#endif
	}

	void Picture::Bind()
	{
		mImplementation->Bind();
	}

	int Picture::GetHeight() const
	{
		return mImplementation->GetHeight();
	}

	int Picture::GetWidth() const
	{
		return mImplementation->GetWidth();
	}

	
}