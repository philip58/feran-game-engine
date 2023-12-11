#pragma once
#include"PictureImplementation.h"

namespace fr
{
	class OpenGLPicture : public PictureImplementation
	{
	public:
		OpenGLPicture(const std::string& pic);
		OpenGLPicture(std::string&& pic);
		~OpenGLPicture();

		void Bind() override;
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;

	private:
		unsigned int mPictureProgram;
	};
}