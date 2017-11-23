#include "Player.h"

Player::Player(sf::Texture& texture, UI& ui) :
 texture(texture), ui(ui) {
	body.setTexture(texture);
	body.setColor(sf::Color(236, 221, 180));
	body.setOrigin(16.0f, 16.0f);
	this->texture = texture;
	this->ui = ui;

	Init();
}


Player::~Player() {
	
}

void Player::Init() {
	body.setPosition(272.0f, 240.0f);

	timeSinceMove = 0.0f;
	previousDirection = direction;
	timeToMove = 0.8f;
	timesMoved = 0;

	blocks.push_back(Block(texture, sf::Vector2f(body.getPosition().x, body.getPosition().y)));
	blocks.push_back(Block(texture, sf::Vector2f(body.getPosition().x, body.getPosition().y)));

	ui.Reset();
}

void Player::Update(float deltaTime) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && ui.IsGameOver()) {
		Init();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && previousDirection.x == 0.0f && !ui.IsGameOver()) {
		direction.x = -1.0f;
		direction.y = 0.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && previousDirection.x == 0.0f && !ui.IsGameOver()) {
		direction.x = 1.0f;
		direction.y = 0.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && previousDirection.y == 0.0f && !ui.IsGameOver()) {
		direction.x = 0.0f;
		direction.y = 1.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && previousDirection.y == 0.0f && !ui.IsGameOver()) {
		direction.x = 0.0f;
		direction.y = -1.0f;
	}

	for (int i = 0; i < blocks.size(); i++) {
		if (body.getGlobalBounds().intersects(blocks[i].GetBounds()) && timesMoved > 2) {
			GameOver();
		}
	}

	if (timeSinceMove > timeToMove) {
		if (direction.x != 0.0f || direction.y != 0.0f)
			timesMoved++;
		body.move(direction * 32.0f);
		for (int i = 0; i < blocks.size(); i++) {
			sf::Vector2f tempDirection = blocks[i].GetDirection();
			blocks[i].SetDirection(previousDirection);
			blocks[i].Move();
			previousDirection = tempDirection;
		}
		timeSinceMove = 0;
		previousDirection = direction;
	}

	if (GetBounds().left >= 512.0f || GetBounds().left <= -32.0f
		|| GetBounds().top >= 512.0f || GetBounds().top <= -32.0f) {
		GameOver();
	}

	timeSinceMove += deltaTime;
}

void Player::Draw(sf::RenderWindow& window) {
	for (int i = 0; i < blocks.size(); i++) {
		blocks[i].Draw(window);
	}
	window.draw(body);
}

void Player::AddBlock() {
	sf::Vector2f lastBlockPosition = blocks.back().GetPosition();
	sf::Vector2f lastBlockDirection = blocks.back().GetDirection();
	sf::Vector2f newBlockPosition = sf::Vector2f(
		lastBlockPosition.x - lastBlockDirection.x * 32.0f,
		lastBlockPosition.y - lastBlockDirection.y * 32.0f
	);
	blocks.push_back(Block(texture, newBlockPosition, lastBlockDirection));
	timeToMove = std::max(timeToMove - 0.08f, 0.075f);
}

void Player::GameOver() {
	blocks.clear();
	ui.GameOver();
	direction = sf::Vector2f(0.0f, 0.0f);
}