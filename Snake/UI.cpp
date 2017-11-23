#include "UI.h"

UI::UI(sf::Font& font) {
	scoreText.setFont(font);
	scoreText.setFillColor(sf::Color::Black);
	scoreText.setString("0");
	float scoreWidth = scoreText.getLocalBounds().width;
	float scoreHeight = scoreText.getLocalBounds().height;
	scoreText.setOrigin(std::floor(scoreWidth * 0.5f), std::floor(scoreHeight * 0.5f));
	scoreText.setPosition(sf::Vector2f(256.0f, 10.0f));

	gameOverText.setFont(font);
	gameOverText.setFillColor(sf::Color::Black);
	gameOverText.setString("Game Over!");
	float gameOverWidth = gameOverText.getLocalBounds().width;
	float gameOverHeight = gameOverText.getLocalBounds().height;
	gameOverText.setOrigin(std::floor(gameOverWidth * 0.5f), std::floor(gameOverHeight * 0.5f));
	gameOverText.setPosition(256.0f, 200.0f);

	Reset();
}


UI::~UI() {
}

void UI::Draw(sf::RenderWindow& window) {
	window.draw(scoreText);
	if (gameOver) {
		window.draw(gameOverText);
	}
}

void UI::Reset() {
	score = 0;
	scoreText.setString(std::to_string(score));
	gameOver = false;
}

void UI::AddToScore(int value) {
	score += value;
	scoreText.setString(std::to_string(score));
}

void UI::GameOver() {
	gameOver = true;
}