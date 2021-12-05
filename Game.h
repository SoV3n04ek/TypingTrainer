#include <SFML/Graphics.hpp>

class Game 
{
	sf::RenderWindow mWindow;
	sf::CircleShape mPlayer;
	
	void update();
	
	void render();
	
	void processEvents();
public:
	Game();
	
	~Game();

	void run();
};