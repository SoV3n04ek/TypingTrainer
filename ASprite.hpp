#pragma once
#include <SFML/Graphics.hpp>

class ASprite : public sf::Sprite
{
public:
	ASprite(sf::Sprite sprite)
	:
		Sprite(sprite)
	{ }
	ASprite(sf::Sprite &sprite)
	: 
		Sprite(sprite)
	{ }
	ASprite(sf::Texture& texture)
	: 
		Sprite(texture)
	{ }
	ASprite(const sf::Texture& texture)
		:
		Sprite(texture)
	{ }
	
	virtual ~ASprite() = 0;


};