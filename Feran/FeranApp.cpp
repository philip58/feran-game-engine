#include "pch.h"
#include "FeranApp.h"
#include "../stbi/stb_image.h"
#include "glad/glad.h"

namespace fr
{
	template<typename T>
	FeranApp<T>::FeranApp()
	{
	}
	template<typename T>
	void FeranApp<T>::Init()
	{
		if (sInstance == nullptr)
		{
			sInstance = new T;
		}
	}
	template<typename T>
	void FeranApp<T>::RunInterface()
	{
		sInstance->Run();
	}
	template<typename T>
	void fr::FeranApp<T>::Run()
	{
		mWindow.Create("Game PF", 1000, 800);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			FR_ERROR("Failed to initialize GLAD");
			return;
		}

		float vertices[] = {
			-0.5f, -0.5f, 0.0f, 0.0f,
			 0.5f, -0.5f, 1.0f, 0.0f,
			-0.5f, 0.5f, 0.0f, 1.0f,
			0.5f, 0.5f, 1.0f, 1.0f,
		};

		unsigned int indices[] = {
			0, 1, 2,
			1, 2, 3
		};

		unsigned int VAO;
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		unsigned int VBO;
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		unsigned int EBO;
		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)(2*sizeof(float)));
		glEnableVertexAttribArray(1);

		//unsigned char* data = stbi_load(FileSystem::getPath("resources/textures/container.jpg").c_str(), &width(), &height(), &nrChannels, 0);

		/////////// Textures ///////////

		unsigned int texture;
		glGenTexture(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int width, height, nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load("../Assets/Pictures/text.png", &width, &height, &nrChannels);

		if (data) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGB, GL_UNSIGNED_BIT, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			FR_ERROR("Failed to load a picture from the file!");
		}

		stbi_image_free(data);

		while (mShouldContinue)
		{
			OnUpdate();

			glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			glUseProgram(shaderProgram);
			glBindVertexArray(VAO);
			glDrawArray(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			mWindow.SwapBuffers();
			mWindow.PollEvents();
		}
	}
	template<typename T>
	void FeranApp<T>::OnUpdate()
	{
	}
}