#pragma once
#include "ASprite.hpp"

class Image : public ASprite
{

public:
	Image(sf::Texture &texture)
	:
		ASprite(texture)
	{ }

};