// Serves as entry point for the game and a holder for the window

#include <SFML\Graphics.hpp>
#include "Player.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(512, 512), "Snake");
	sf::Clock clock;

	sf::Texture texture;
	texture.loadFromFile("block.png");

	Player player(texture);
	
	while (window.isOpen()) {
		float deltaTime = clock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		player.Update(deltaTime);

		window.clear(sf::Color(236, 221, 180));
		player.Draw(window);
		window.display();
	}
}