#pragma once

#include "Utilities.h"
#include"GameWindow.h"

namespace fr
{
	template<typename T>
	class FeranApp
	{
	public:
		static void Init();
		static void RunInterface();

		void Run();
		virtual void OnUpdate();

		friend typename T;

	private:
		FeranApp();

		inline static FeranApp* sInstance{ nullptr };

		GameWindow mWindow;

		bool mShouldContinue{ true };
	};

};

#include "FeranApp.cpp"