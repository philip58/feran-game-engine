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
		while (mShouldContinue)
		{
			OnUpdate();
		}
	}
	template<typename T>
	void FeranApp<T>::OnUpdate()
	{
	}
}