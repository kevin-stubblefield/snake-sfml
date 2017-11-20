#include "Player.h"

Player::Player(sf::Texture& texture) {
	body.setPosition(272.0f, 272.0f);
	body.setOrigin(16.0f, 16.0f);
	body.setTexture(texture);
	timeSinceMove = 0.0f;
	direction.x = 1.0f;
	direction.y = 0.0f;
	timeToMove = 1.0f;
}


Player::~Player()
{
}

void Player::Update(float deltaTime) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && direction.x == 0.0f) {
		direction.x = -1.0f;
		direction.y = 0.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && direction.x == 0.0f) {
		direction.x = 1.0f;
		direction.y = 0.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && direction.y == 0.0f) {
		direction.x = 0.0f;
		direction.y = 1.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && direction.y == 0.0f) {
		direction.x = 0.0f;
		direction.y = -1.0f;
	}

	if (timeSinceMove > timeToMove) {
		body.move(direction * 32.0f);
		timeSinceMove = 0;
	}
	timeSinceMove += deltaTime;
}

void Player::Draw(sf::RenderWindow& window) {
	window.draw(body);
}