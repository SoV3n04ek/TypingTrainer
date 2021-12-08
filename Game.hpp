#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "Menu.hpp"
#include "ASprite.hpp"
#include "Options.hpp"
#include "Config.hpp"

class Game
{
	bool game_status;
	int _k;
	sf::RenderWindow mWindow;
	
	std::vector<sf::Sprite*> v;
	std::vector<sf::Text> menuTexts;
	
	Options options;
	const std::string musicName = "sounds\\music5201841904156672.wav";
	sf::Music music;
	Config cfg;

private:
	void update()
	{
		mWindow.clear();

		// temporary replacement

		sf::Font font;

		if (!font.loadFromFile("fonts\\Raleway-Medium.ttf\0")) {}

		sf::Texture t;
		t.loadFromFile("bg1.jpg");
		sf::Sprite background_s(t);

		for (int count_chars = 1; count_chars <= 10; count_chars++)
		{
			//char rs = (char)(97 + rand() % 26);
			std::string s[10] =
			{
				"a",
				"b" ,
				"c" ,
				"d",
				"j",
				"k",
				"l",
				"o",
				"b",
				"v"
			};

			sf::Text option;
			option.setFont(font);
			option.setCharacterSize(34);
			option.setStyle(sf::Text::Bold | sf::Text::Underlined);
			option.setString(s[count_chars - 1]);
			option.setPosition(sf::Vector2f(1280 / 4 + count_chars * 40, 720 - 480));

			sf::Color color(sf::Color::Black);
			option.setFillColor(color);
			menuTexts.push_back(option);
		}

		// 

		if (_k == 0)
		{
		sf::Text option;
		option.setFont(font);
		option.setCharacterSize(34);
		option.setStyle(sf::Text::Bold | sf::Text::Underlined);
		option.setString(std::string("Put your fingers in the base position: F J. Let's start by pressing any key"));
		option.setPosition(sf::Vector2f(40, 0));
		menuTexts.push_back(option);
		}
		// create hand

		sf::Texture d;
		d.loadFromFile("ruka.jpg");
		sf::Sprite ruka(d);
		ruka.setPosition(340, 450);
		// DRAW

		mWindow.draw(background_s);
		for (auto& text : menuTexts)
			mWindow.draw(text);
		//mWindow.draw(mPlayer);
	/*	for (auto& sprite : v)
			mWindow.draw(sprite);*/

		mWindow.draw(ruka);

		mWindow.display();
	}
	void render()
	{

	}
	void processEvents()
	{
		sf::Event event;
		while (mWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				mWindow.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
			{
				_k++;
			}
		}
	}
public:
	Game()
		:
		mWindow(sf::VideoMode(1280, 720), "Typing Trainer", sf::Style::Close),
		game_status(true),
		_k(0)
	{
		//Init music
		if (!music.openFromFile(musicName)) {}
		music.setLoop(true);
		music.setVolume(cfg.music_volume);
		music.play();

	}

	~Game() {}

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
				switch (menu.getIndexSelectedItem())
				{
				case PLAY:
					return PLAY;
					break;
				case OPTIONS:
					return OPTIONS;
					break;
				case EXIT:
					return EXIT;
				}
			}

			sf::sleep(sf::milliseconds(110));
			mWindow.clear(sf::Color::Black);
			mWindow.draw(background_s);
			menu.draw(mWindow);
			mWindow.display();
		}
	}

	void showOptions()
	{
		sf::Texture t;
		t.loadFromFile("bg1.jpg");
		sf::Sprite background_s(t);

		Options options;
		while (mWindow.isOpen())
		{
			sf::Event event;
			while (mWindow.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					mWindow.close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
				options.down();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
				options.up();

			// if it's music
			if (options.getIndexSelectedItem() == 0)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
				{
					if (cfg.music_volume == 100)
					{
						// do nothing
					}
					else
					{
						cfg.music_volume += 5;
						music.setVolume(cfg.music_volume);
					}
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
				{
					if (cfg.music_volume == 0)
					{
						// do nothing
					}
					else
					{			
						cfg.music_volume -= 5;
						music.setVolume(cfg.music_volume);
					}
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
			{
			
				switch (options.getIndexSelectedItem())
				{
					// if it's music
					case 0:
						if (cfg.music_volume == 0)
							cfg.music_volume = 25;
						else
							cfg.music_volume = 0;
						music.setVolume(cfg.music_volume);
						break;
					// if it's 
					case 1:
						return;
				}
			}

			sf::sleep(sf::milliseconds(110));
			mWindow.clear(sf::Color::Black);
			mWindow.draw(background_s);
			options.draw(mWindow);
			mWindow.display();
		}
	}

	void start()
	{
		while (game_status)
		{

			switch (showMenu())
			{
			case PLAY:
				run();
				break;
			case OPTIONS:
				showOptions();
				break;
			case EXIT:
				mWindow.close();
				game_status = false;
				break;
			};
		}
	}
	
	void run()
	{
		while (mWindow.isOpen())
		{
			processEvents();
			update();
			render();
		}
	}
};