#pragma once
#include <SFML\Graphics.hpp>

class Block
{
public:
	Block(sf::Texture& texture);
	~Block();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

private:
	sf::Sprite body;
	sf::Vector2f direction;
	float timeSinceMove;
	float timeToMove;
};