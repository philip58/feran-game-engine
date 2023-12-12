#include "Feran.h"
#include <iostream>

class MyGame : public fr::FeranApp<MyGame>
{
public:
	MyGame()
	{
		SetKeyPressedCallback([this](const fr::KeyPressed& e) {OnKeyPress(e); });
	}

	virtual void OnUpdate() override
	{
		//std::cout << "Feran running" << std::endl;

		//Draw(x, y, mPic);
		
		//new
		Draw(mUnit);
	}

	void OnKeyPress(const fr::KeyPressed& e)
	{
		
		if(e.GetKeyCode() == FERAN_KEY_RIGHT)
		{
			mUnit.UpdateXCoord(50);
		} 
		else if(e.GetKeyCode() == FERAN_KEY_LEFT)
		{
			 mUnit.UpdateYCoord(50);
		}
		
	}

private:
	fr::Picture mPic{ "../Assets/Pictures/smile.png" };
	fr::Unit mUnit{ "../Assets/Pictures/smile.png", 300, 300 };

};

FERAN_APPLICATION_START(MyGame);

//symbol \ means it continues to next line
//int main()\
//{\
//MyGame game; \
//game.Run(); \
//return(0); \
//}

#if FR_DEBUG==2
#define FR_ERROR(x) std::cout<<x<<std::endl; 
#define FR_LOG(x) std::cout<<x<<std::endl;
#elif FR_DEBUG==1
#define FR_ERROR(x) std::cout<<x<<std::endl; 
#define FR_LOG(x) 
#else
#define FR_ERROR(x) 
#define FR_LOG(x)
#endif

#ifdef FERAN_MSCPP
#ifdef FERAN_LIB
#define FERAN_API __declspec(dllexport)
#else
#define FERAN_API __declspec(dllimport)
#endif // FERAN_API
#else 
#define FERAN_API
#endif // FERAN_MSCPP

//symbol \ means it continues to next line
//do not press space after \ because error will orccur 
#define FERAN_APPLICATION_START(ClassName) \
int main()\
{\
	ClassName::Init();\
	ClassName::RunInterface();\
	return(0);\
}
