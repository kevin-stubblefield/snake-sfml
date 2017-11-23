#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <iostream>
#include "Block.h"
#include "UI.h"

class Player
{
public:
	Player(sf::Texture& texture, UI& ui);
	~Player();

	void Init();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void AddBlock();
	void GameOver();

	sf::FloatRect GetBounds() { return body.getGlobalBounds(); }

private:
	sf::Sprite body;
	sf::Texture& texture;
	sf::Vector2f direction;
	sf::Vector2f previousDirection;
	std::vector<Block> blocks;
	UI& ui;
	float timeSinceMove;
	float timeToMove;
	int timesMoved;
};