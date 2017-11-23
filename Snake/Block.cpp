#include "Block.h"



Block::Block(sf::Texture& texture, sf::Vector2f position) {
	body.setTexture(texture);
	body.setOrigin(16.0f, 16.0f);
	body.setPosition(position);
	direction = sf::Vector2f(0.0f, 0.0f);
}

Block::Block(sf::Texture& texture, sf::Vector2f position, sf::Vector2f direction) {
	body.setTexture(texture);
	body.setOrigin(16.0f, 16.0f);
	body.setPosition(position);
	direction = sf::Vector2f(direction);
}


Block::~Block() {
}

void Block::Draw(sf::RenderWindow& window) {
	window.draw(body);
}

void Block::Move() {
	body.move(direction * 32.0f);
}