#include "pch.h"
#include "FeranApp.h"

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

		/*
		float vertices[] = {
			-0.5f, -0.5f,
			 0.5f, -0.5f,
			-0.5f, 0.5f
		}

		unsigned int VAO;
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		unsigned int VBO;
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		
		///////////// Shaders //////////
		//raw string
		const char* vertexShaderSource = R"(
			#version 300 core
			"layout (location = 0) in vec3 aPos;
			void main()
			{
				gl_Position = vec4(aPos.x, aPos.y, 1.0, 1.0;
			}
		)";
		*/
				

		while (mShouldContinue)
		{
			OnUpdate();

			mWindow.SwapBuffers();
			mWindow.PollEvents();
		}
	}
	template<typename T>
	void FeranApp<T>::OnUpdate()
	{
	}
}