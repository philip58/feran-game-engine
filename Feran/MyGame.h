#pragma once
#include "pch.h"
#include "FeranApp.h"
#include "Utilities.h"
#include"Shader.h"
#include"Picture.h"
#include"Events.h"
#include"Unit.h"
#include"Keys.h"

class MyGame : public fr::FeranApp<MyGame>
{
public:
	MyGame()
	{
		SetKeyPressedCallback([this](const fr::KeyPressed& e) {OnKeyPress(e); });
		SetKeyReleasedCallback([this](const fr::KeyReleased& e) {OnKeyRelease(e); });

		std::srand(static_cast<unsigned int>(std::time(nullptr)));
		for (int i = 0; i < 50; i++)
		{
			int random = rand() % 3000;
			units.emplace_back("../Assets/Pictures/asteroid.png", random, 600 + rand() % (2000 - 700 + 1));
		}
	}



	virtual void OnUpdate() override
	{
		//draw background and player
		Draw(background);
		Draw(player);

		//draw obstacles
		for (int i = 0; i < units.size(); i++)
		{
			Draw(units[i]);

			units[i].UpdateYCoord(-1);
		}

		//draw and shoot projectiles
		for (int i = 0; i < projectiles.size(); i++)
		{
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


			//if (projectiles[i].GetYCoord() > 1080 || projectiles[i].GetYCoord() < 0 || projectiles[i].GetXCoord() < 0 || projectiles[i].GetXCoord() > 1920)
			//{
			//	projectiles.erase(projectiles.begin()+i);
			//}

		}

		//collisions for obstacles and player
		for (int i = 0; i < units.size(); i++)
		{
			if (UnitsOverlap(units[i], player))
			{
				Draw(fire);
			}

			//if
		}


		//move the player
		if (rightPressed)
		{
			player.UpdateXCoord(10);
			fire.UpdateXCoord(10);
		}
		if (leftPressed)
		{
			player.UpdateXCoord(-10);
			fire.UpdateXCoord(-10);
		}
		if (upPressed)
		{
			player.UpdateYCoord(10);
			fire.UpdateYCoord(10);
		}
		if (downPressed)
		{
			player.UpdateYCoord(-10);
			fire.UpdateYCoord(-10);
		}

		/*
		for (int i = 0; i < units.size(); i++)
		{
			for (int j = 0; j < projectiles.size(); j++)
			{
				if (UnitsOverlap(units[i], projectiles[j]))
				{
					units[i].SetCoords(-100, -100);
					projectiles.erase(projectiles.begin()+j);
					std::cout << "hit" << std::endl;
					//break;
				}
				else
				{
					std::cout << "Nope" << std::endl;
				}
			}
		}
		*/


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
			projectiles.emplace_back("../Assets/Pictures/laser.png", player.GetXCoord() + 35, player.GetYCoord());
			projectileDirection.emplace_back("right");
		}
		else if (e.GetKeyCode() == FERAN_KEY_LEFT)
		{
			projectiles.emplace_back("../Assets/Pictures/laser.png", player.GetXCoord() + 35, player.GetYCoord());
			projectileDirection.emplace_back("left");
		}
		else if (e.GetKeyCode() == FERAN_KEY_UP)
		{
			projectiles.emplace_back("../Assets/Pictures/laser.png", player.GetXCoord() + 35, player.GetYCoord());
			projectileDirection.emplace_back("up");
		}
		else if (e.GetKeyCode() == FERAN_KEY_DOWN)
		{
			projectiles.emplace_back("../Assets/Pictures/laser.png", player.GetXCoord() + 35, player.GetYCoord());
			projectileDirection.emplace_back("down");
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
	fr::Unit gameOverScreen{ "../Assets/Pictures/gameover.png", 0, 0 };
	fr::Unit background{ "../Assets/Pictures/galaxy.png", 0, 0 };
	fr::Unit player{ "../Assets/Pictures/ship.png", 450, 300 };
	fr::Unit fire{ "../Assets/Pictures/fire.png", player.GetXCoord()-100, player.GetYCoord()-100};
	std::vector<fr::Unit> units;
	std::vector<fr::Unit> projectiles;
	std::vector<std::string> projectileDirection;
	bool leftPressed = false;
	bool rightPressed = false;
	bool upPressed = false;
	bool downPressed = false;
};

