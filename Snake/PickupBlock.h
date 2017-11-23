#pragma once
#include <SFML\Graphics.hpp>

class PickupBlock
{
public:
	PickupBlock(sf::Texture& texture, sf::Vector2f position);
	~PickupBlock();

	void Draw(sf::RenderWindow& window);

	void SetPosition(sf::Vector2f position) { body.setPosition(position); }

	sf::FloatRect GetBounds() { return body.getGlobalBounds(); }

private:
	sf::Sprite body;
	bool pickedUp;
};

