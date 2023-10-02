#pragma once

#include "Utilities.h"

namespace fr
{
	template<typename T>
	class FERAN_API FeranApp
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

		bool mShouldContinue{ true };
	};

};

#include "FeranApp.cpp"