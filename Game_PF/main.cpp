#include "Feran.h"
#include <iostream>

class MyGame : public fr::FeranApp<MyGame>
{
public:
	virtual void OnUpdate() override
	{
		std::cout << "Feran running" << std::endl;
	}
};

BEAVER_APPLICATION_START(MyGame);

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
#define BEAVER_APPLICATION_START(ClassName) \
int main()\
{\
	ClassName::Init();\
	ClassName::RunInterface();\
	return(0);\
}