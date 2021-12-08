#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "ASprite.hpp"

class Level
{
	std::vector<ASprite> elements;
public:
	Level(std::string fileName)
	{

	}

	~Level() { }

	void draw(sf::RenderWindow& window)
	{

	}
};