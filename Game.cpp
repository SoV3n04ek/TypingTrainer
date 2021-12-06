#include "Game.h"

void Game::update()
{
	mWindow.clear();

	// temporary replacement
	
	std::vector<sf::Text> menuTexts;
	sf::Font font;
	
	if (!font.loadFromFile("fonts\\Raleway-Medium.ttf\0")) {}

	sf::Texture t;
	t.loadFromFile("bg1.jpg");
	sf::Sprite background_s(t);

	for (int count_chars = 1; count_chars <= 10; count_chars++)
	{
		char rs = (char)(97 + rand() % 26);
		std::string s[10] =
		{
			 "a", 
			 "b" ,
			 "c" ,
				"d",
			"j", "k", "l","o","b","v"
		};
		
		sf::Text option;
		option.setFont(font);
		option.setCharacterSize(34);
		option.setStyle(sf::Text::Bold | sf::Text::Underlined);
		option.setString(s[count_chars-1]);
		option.setPosition(sf::Vector2f(1280 / 4 + count_chars * 40 , 720 - 480));

		sf::Color color(sf::Color::Black);
		option.setFillColor(color);
		menuTexts.push_back(option);
	}

	// 
	sf::Text option;
	option.setFont(font);
	option.setCharacterSize(34);
	option.setStyle(sf::Text::Bold | sf::Text::Underlined);
	option.setString(std::string("Put your fingers in the base position: F J. Let's start by pressing any key"));
	option.setPosition(sf::Vector2f(40, 0));
	menuTexts.push_back(option);
	// create ruka

	sf::Texture d;
	d.loadFromFile("ruka.jpg");
	sf::Sprite ruka(d);
	ruka.setPosition(340, 450);
	// DRAW

	mWindow.draw(background_s); 
	for (auto& text : menuTexts)
		mWindow.draw(text);
	//mWindow.draw(mPlayer);
	mWindow.draw(ruka);
	
	mWindow.display();
}

void Game::render()
{
	
}
//health
//mechanical
//inside
//passive
//slave
//presence
//stem
//consciousness
//folklore
//metal
//demand
//coast
//door
//prisoner
//manufacture
//test
//peace
//abundant
//minister
//broken
//unrest
//raw
//create
//man
//news
//ceremony
//refuse
//slab
//wrist
//live
//light
//effort
//warrant
//outlook
//trust
//spine
//star
//word
//lump
//rumor
void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			mWindow.close();
	}
}

Game::Game()
:
	mWindow(sf::VideoMode(1280, 720), "Typing Trainer", sf::Style::Close),
	mPlayer()

{
	srand(time(0));

	// init player
	mPlayer.setRadius(40.f);
	mPlayer.setPosition(100.f, 100.f);
	sf::Color c = sf::Color::Blue;
	mPlayer.setFillColor(c);
	
	
}

Game::~Game() { }

void Game::run()
{
	while (mWindow.isOpen())
	{
		processEvents();
		update();
		render();
	}
}