#include "Feran.h"
#include <iostream>

class MyGame : public fr::FeranApp<MyGame>
{
public:
	MyGame()
	{
		SetKeyPressedCallback([this](const fr::KeyPressed& e) {OnKeyPress(e); });
		SetKeyReleasedCallback([this](const fr::KeyReleased& e) {OnKeyRelease(e); });
		units.emplace_back("../Assets/Pictures/ship.png", 400, 500);
		units.emplace_back("../Assets/Pictures/ship.png", 0, 0);
	}



	virtual void OnUpdate() override
	{
		//std::cout << "Feran running" << std::endl;

		//Draw(x, y, mPic);
		
		//new
		Draw(background);
		Draw(player);
		
		if (units.size() != 0) 
		{
			for (int i = 0; i < units.size(); i++) {
				Draw(units[i]);
			}
		}

		if (projectiles.size() != 0)
		{
			for (int i = 0; i < projectiles.size(); i++) {
				Draw(projectiles[i]);

				if (projectileDirection[i] == "right")
				{
					projectiles[i].UpdateXCoord(10);
				}
				if (projectileDirection[i] == "left")
				{
					projectiles[i].UpdateXCoord(-10);
				}
				if (projectileDirection[i] == "up")
				{
					projectiles[i].UpdateYCoord(10);
				}
				if (projectileDirection[i] == "down")
				{
					projectiles[i].UpdateYCoord(-10);
				}
			}
		}

		/*
		for (int i = 0; i < units.size(); i++) {
			for (int j = 0; j < projectiles.size(); j++) {
				if (UnitsOverlap(units[i], projectiles[j])) {
					units.erase(units.begin() + i);
					std::cout << "hit" << std::endl;
				}
				else {
					std::cout << "Nope" << std::endl;
				}
			}
		}
		*/

		if (rightPressed)
		{
			player.UpdateXCoord(10);
		}
		if (leftPressed)
		{
			player.UpdateXCoord(-10);
		}
		if (upPressed)
		{
			player.UpdateYCoord(10);
		}
		if (downPressed)
		{
			player.UpdateYCoord(-10);
		}

	}

	void OnKeyPress(const fr::KeyPressed& e)
	{
		if (e.GetKeyCode() == FERAN_KEY_D)
		{
			rightPressed = true;
		}
		else if (e.GetKeyCode() == FERAN_KEY_A)
		{
			leftPressed = true;
		}
		else if (e.GetKeyCode() == FERAN_KEY_W)
		{
			upPressed = true;
		}
		else if (e.GetKeyCode() == FERAN_KEY_S)
		{
			downPressed = true;
		}

		//shooting projectiles
		if (e.GetKeyCode() == FERAN_KEY_RIGHT)
		{
			projectiles.emplace_back( "../Assets/Pictures/laser.png", player.GetXCoord()+35, player.GetYCoord());
			projectileDirection.push_back("right");
		}
		else if (e.GetKeyCode() == FERAN_KEY_LEFT)
		{
			projectiles.emplace_back("../Assets/Pictures/laser.png", player.GetXCoord()+35, player.GetYCoord());
			projectileDirection.push_back("left");
		}
		else if (e.GetKeyCode() == FERAN_KEY_UP)
		{
			projectiles.emplace_back("../Assets/Pictures/laser.png", player.GetXCoord()+35, player.GetYCoord());
			projectileDirection.push_back("up");
		}
		else if (e.GetKeyCode() == FERAN_KEY_DOWN)
		{
			projectiles.emplace_back("../Assets/Pictures/laser.png", player.GetXCoord()+35, player.GetYCoord());
			projectileDirection.push_back("down");
		}
	}

	void OnKeyRelease(const fr::KeyReleased& e)
	{
		if (e.GetKeyCode() == FERAN_KEY_D)
		{
			rightPressed = false;
		}
		else if (e.GetKeyCode() == FERAN_KEY_A)
		{
			leftPressed = false;
		}
		else if (e.GetKeyCode() == FERAN_KEY_W)
		{
			upPressed = false;
		}
		else if (e.GetKeyCode() == FERAN_KEY_S)
		{
			downPressed = false;
		}
	}

private:
	fr::Unit background{ "../Assets/Pictures/galaxy.png", 0, 0 };
	fr::Unit player{ "../Assets/Pictures/ship.png", 450, 300 };
	std::vector<fr::Unit> units;
	std::vector<fr::Unit> projectiles;
	std::vector<std::string> projectileDirection;
	//fr::Unit player{ "../Assets/Pictures/ship.png", 300, 300 };
	bool leftPressed = false;
	bool rightPressed = false;
	bool upPressed = false;
	bool downPressed = false;

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
