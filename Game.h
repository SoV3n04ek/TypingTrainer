#pragma once
#include <vector>
#include <ctime>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "Menu.hpp"
#include "ASprite.hpp"

class Game
{
	sf::RenderWindow mWindow;
	sf::CircleShape mPlayer;
	std::vector<ASprite> v;

	void update();

	void render();

	void processEvents();
public:
	Game();

	~Game();

	size_t showMenu()
	{
		sf::Texture t;
		t.loadFromFile("bg1_menu.jpg");
		sf::Sprite background_s(t);
		
		Menu menu;
		while (mWindow.isOpen())
		{
			sf::Event event;
			while (mWindow.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					mWindow.close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
				menu.down();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
				menu.up();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
			{
				if (menu.getIndexSelectedItem() == PLAY)
					return PLAY;
				if (menu.getIndexSelectedItem() == OPTIONS)
					return OPTIONS;
				if (menu.getIndexSelectedItem() == EXIT)
					return EXIT;
			}

			sf::sleep(sf::milliseconds(110));
			mWindow.clear(sf::Color::Black);
			mWindow.draw(background_s);
			menu.draw(mWindow);
			mWindow.display();
		}
	}

	void start()
	{
		if (showMenu() == PLAY)
			run();
		mWindow.close();
	}

	void run();
};