#pragma once
#include "Game.h"

void Game::update()
{
	mWindow.clear();
	mWindow.draw(mPlayer);
	mWindow.display();
}

void Game::render()
{
		
}

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
	mWindow(sf::VideoMode(640, 480), "SFML App"),
	mPlayer()
{
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