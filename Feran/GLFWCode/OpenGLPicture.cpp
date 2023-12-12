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
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		//load data into file
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(pic.c_str(), &width, &height, &nrChannels, 0);

		if (data) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			FR_ERROR("Failed to load a picture from the file!");
		}

		//create picture object
		stbi_image_free(data);
	}

	OpenGLPicture::OpenGLPicture(std::string&& pic)
	{
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		//load data into file
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(std::move(pic.c_str()), &width, &height, &nrChannels, 0);

		if (data) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			FR_ERROR("Failed to load a picture from the file!");
		}

		//create picture object
		stbi_image_free(data);
	}

	OpenGLPicture::~OpenGLPicture()
	{
		glDeleteTextures(GL_TEXTURE_2D, &texture);
	}

	void OpenGLPicture::Bind()
	{
		glBindTexture(GL_TEXTURE_2D, texture);
	}

	int OpenGLPicture::GetWidth() const
	{
		return width;
	}

	int OpenGLPicture::GetHeight() const
	{
		return height;
	}
}