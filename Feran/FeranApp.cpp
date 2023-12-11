#include "pch.h"
#include "FeranApp.h"
#include"Utilities.h"
#include"../Feran/include/Feran.h"
#include"GLFW/glfw3.h"
#include "../stbi/stb_image.h"
#include"Shader.h"
#include"Picture.h"
#include"Renderer.h"

namespace fr
{
	template<typename T>
	FeranApp<T>::FeranApp()
	{
		mWindow.Create("Game PF", 1000, 800);
		//glad initialized here
		mRenderer.Init();

		//calls DefaultWindowCloseHandler
		SetWindowCloseCallback([this]() {DefaultWindowCloseHandler(); });
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
	void FeranApp<T>::Run()
	{
		fr::Shader shader("../Assets/Shaders/DefaultVertexShader.glsl", "../Assets/Shaders/DefaultFragmentShader.glsl");
		fr::Picture pic{ "../Assets/Pictures/smile.png" };
		mNextFrameTime = std::chrono::steady_clock::now();
		
		while(mShouldContinue)
		{
		// clear screen
			mRenderer.Clear();
			shader.Bind();
			shader.SetUniform2Ints("ScreenSize",mWindow.GetWidth(), mWindow.GetHeight());
			OnUpdate();
		 
			std::this_thread::sleep_until(mNextFrameTime);
			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;
		 
			mWindow.SwapBuffers();
			mWindow.PollEvents();
		}
	}
		//mWindow.Create("Game PF", 1000, 800);

		//unsigned char* data = stbi_load(FileSystem::getPath("resources/textures/container.jpg").c_str(), &width(), &height(), &nrChannels, 0);
		/////////// Shaders  ///////////

		//fr::Shader shader("../Assets/Shaders/DefaultVertexShader.glsl", "../Assets/Shaders/DefaultFragmentShader.glsl");
		//mNextFrameTime = std::chrono::steady_clock::now();

		/////////// Textures ///////////
		// for testing picture (after shaders)
		
		// 
		// picture
		//create texture object

		/*
		while (mShouldContinue)
		{
			OnUpdate();

			mRenderer.Clear();
			//glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
			//glClear(GL_COLOR_BUFFER_BIT);

			shader.Bind();
			shader.SetUniform2Ints("ScreenSize", 1000, 800);
			pic.Bind();

			//glUseProgram(shader);
			glBindVertexArray(VAO);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			//std::this_thread::sleep_until(mNextFrameTime);
			//mNextFrame = std::chrono::steady_clock::now() + mFrameDuration;

			mWindow.SwapBuffers();
			mWindow.PollEvents();
		}
		*/
	//}
	template<typename T>
	void FeranApp<T>::OnUpdate()
	{
	}

	template<typename T>
	void FeranApp<T>::Draw(int x, int y, Picture& pic)
	{
		mRenderer.Draw(x, y, pic);
	}

	template<typename T>
	void FeranApp<T>::Draw(Unit& item)
	{
	}

	template<typename T>
	void FeranApp<T>::SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc)
	{
		//mWindow.SetKeyPressedCallback(callbackFunc);
	}

	template<typename T>
	void FeranApp<T>::SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc)
	{
		mWindow.SetKeyReleasedCallback(callbackFunc);
	}

	template<typename T>
	void FeranApp<T>::SetWindowCloseCallback(std::function<void()> callbackFunc)
	{
		mWindow.SetWindowCloseCallback(callbackFunc);
	}

	template<typename T>
	void FeranApp<T>::DefaultWindowCloseHandler()
	{
		mShouldContinue = false;
	}
}