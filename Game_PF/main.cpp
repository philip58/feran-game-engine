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
