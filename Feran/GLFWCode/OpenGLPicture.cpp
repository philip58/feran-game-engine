#include "pch.h"
#include"OpenGLPicture.h"
#include"glad/glad.h"
#include"GLFW/glfw3.h"
#include"../Utilities.h"
#include"../stbi/stb_image.h"

namespace fr
{
	OpenGLPicture::OpenGLPicture(const std::string& pic)
	{
		unsigned int texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		//load data into file
		int width, height, nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load("../Assets/Pictures/smile.png", &width, &height, &nrChannels, 0);

		if (data) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			FR_ERROR("Failed to load a picture from the file!");
		}

		//create picture object
		stbi_image_free(data);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	OpenGLPicture::OpenGLPicture(std::string&& pic)
	{
		unsigned int texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		//load data into file
		int width, height, nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load("../Assets/Pictures/smile.png", &width, &height, &nrChannels, 0);

		if (data) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			FR_ERROR("Failed to load a picture from the file!");
		}

		//create picture object
		stbi_image_free(data);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	OpenGLPicture::~OpenGLPicture()
	{
		glDeleteProgram(mPictureProgram);
	}

	void OpenGLPicture::Bind()
	{
		glUseProgram(mPictureProgram);
	}

	int OpenGLPicture::GetWidth() const
	{
		return 0;
	}

	int OpenGLPicture::GetHeight() const
	{
		return 0;
	}
}