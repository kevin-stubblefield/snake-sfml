#pragma once
#include <SFML\Graphics.hpp>

class Player
{
public:
	Player(sf::Texture& texture);
	~Player();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

private:
	sf::Sprite body;
	sf::Vector2f direction;
	float timeSinceMove;
	float timeToMove;
};