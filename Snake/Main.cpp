#include <SFML\Graphics.hpp>
#include "Player.h"
#include "PickupBlock.h"
#include "UI.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(512, 512), "Snake");
	sf::Clock clock;

	sf::Font font;
	font.loadFromFile("font.ttf");
	UI ui(font);

	sf::Texture blockTexture;
	blockTexture.loadFromFile("block.png");

	Player player(blockTexture, ui);
	PickupBlock pickup(blockTexture, sf::Vector2f((rand() % 15) * 32 + 16, (rand() % 15) * 32 + 16));
	
	srand(time(NULL));
	
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

		if (player.GetBounds().intersects(pickup.GetBounds())) {
			player.AddBlock();
			pickup.SetPosition(sf::Vector2f((rand() % 15) * 32 + 16, (rand() % 15) * 32 + 16));
			ui.AddToScore(5);
		}

		window.clear(sf::Color(236, 221, 180));
		player.Draw(window);
		pickup.Draw(window);
		ui.Draw(window);
		window.display();
	}
}