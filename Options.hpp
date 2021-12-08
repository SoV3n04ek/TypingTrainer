#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

class Options 
{
	size_t countItems;
	size_t indexSelectedItem;
	sf::Font font;
	std::vector<sf::Text> optionsTexts;
public:
	Options(float width = 1280, float height = 720, size_t choozedOption = 0)
		:
		indexSelectedItem(choozedOption),
		countItems(2)
	{
		//if (!font.loadFromFile("fonts\\arial.ttf\0"))
		//{ }
		/*if (!font.loadFromFile("fonts\\orange-juice-2-0.ttf\0"))
		{ }*/
		if (!font.loadFromFile("fonts\\Raleway-Medium.ttf\0")) {}
		const char* cstrs[256] = {
			"Music", "Exit"
		};

		sf::Color red = sf::Color::Red;
		sf::Color white = sf::Color::White;
		sf::Text text;

		text.setFont(font);
		text.setCharacterSize(34);
		text.setStyle(sf::Text::Bold | sf::Text::Underlined);

		for (int i = 0; i < countItems; i++)
		{
			if (i == indexSelectedItem)
				text.setFillColor(red);
			else
				text.setFillColor(white);

			text.setString(cstrs[i]);
			text.setPosition(sf::Vector2f(width / 4, height / (countItems + 1) * (i + 1)));
			optionsTexts.push_back(text);
		}
	}
	~Options() { 	}

	std::vector<sf::Text>& getVector() { return optionsTexts; };

	Options& setTextColor(size_t optionIndex, sf::Color color)
	{
		size_t i = 0;

		for (auto& text : optionsTexts)
		{
			if (i == indexSelectedItem)
			{
				text.setFillColor(color);
				break;
			}
			++i;
		}

		return *this;
	}

	void down()
	{
		if (indexSelectedItem + 1 >= countItems)
			return;
		setTextColor(indexSelectedItem, sf::Color::White);
		++indexSelectedItem;
		setTextColor(indexSelectedItem, sf::Color::Red);
	}

	void up()
	{
		if (indexSelectedItem == 0)
			return;
		setTextColor(indexSelectedItem, sf::Color::White);
		--indexSelectedItem;
		setTextColor(indexSelectedItem, sf::Color::Red);
	}

	void addOption(sf::Text option) { optionsTexts.push_back(option); }

	void addOption(const std::string& str, int x, int y)
	{
		countItems++;
		sf::Text option(str, font, 64);
		sf::Color color(sf::Color::White);
		option.setFillColor(color);
		optionsTexts.push_back(option);
	}

	void draw(sf::RenderWindow& window) const
	{
		for (auto& text : optionsTexts)
			window.draw(text);
	}

	size_t getIndexSelectedItem() const { return indexSelectedItem; }

	void setFillColor(size_t index, sf::Color color)
	{
		size_t i = 0;
		for (auto& text : optionsTexts)
		{
			text.setFillColor(color);
			break;
		}
	}	
};