#pragma once
#include <SFML\Graphics.hpp>
#include <string>

class UI {
public:
	UI(sf::Font& font);
	~UI();

	void Draw(sf::RenderWindow& window);

	void Reset();
	void AddToScore(int value);
	void GameOver();

	bool IsGameOver() { return gameOver; }

private:
	sf::Text scoreText;
	sf::Text gameOverText;
	int score;
	bool gameOver;
};

