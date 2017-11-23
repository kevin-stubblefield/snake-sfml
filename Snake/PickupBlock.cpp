#include "PickupBlock.h"



PickupBlock::PickupBlock(sf::Texture& texture, sf::Vector2f position) {
	body.setTexture(texture);
	body.setOrigin(16.0f, 16.0f);
	body.setPosition(position);
	body.setColor(sf::Color(65, 100, 76));
}


PickupBlock::~PickupBlock() {
}

void PickupBlock::Draw(sf::RenderWindow & window) {
	window.draw(body);
}
