#pragma once
#include <SFML\Graphics.hpp>

class Block
{
public:
	Block(sf::Texture& texture, sf::Vector2f position);
	Block(sf::Texture& texture, sf::Vector2f position, sf::Vector2f direction);
	~Block();

	void Draw(sf::RenderWindow& window);
	void Move();

	sf::Vector2f GetPosition() { return body.getPosition(); }

	sf::Vector2f GetDirection() { return direction; }
	void SetDirection(sf::Vector2f direction) { this->direction = direction; }

	sf::FloatRect GetBounds() { return body.getGlobalBounds(); }

private:
	sf::Sprite body;
	sf::Vector2f direction;
};

