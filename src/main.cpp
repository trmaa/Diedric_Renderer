#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<vector>
#include<glm/glm.hpp>
#include"window.hpp"

std::vector<sf::Vector2f> vertex(3);
std::vector<glm::ivec2> pairs(3);

int main() {
	vertex[0] = sf::Vector2f(400,100);
	vertex[1] = sf::Vector2f(500,50);
	vertex[2] = sf::Vector2f(300,50);

	pairs[0] = glm::ivec2(0, 1);
	pairs[1] = glm::ivec2(1, 2);
	pairs[2] = glm::ivec2(2, 0);

	Window window;

	sf::Clock clck;
    sf::Time elapsed;
    float deltaTime;
	sf::Event event;
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			} else if (event.type == sf::Event::Resized) {
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				window.setView(sf::View(visibleArea));
			}
		}
		elapsed = clck.restart();
        deltaTime = elapsed.asSeconds();
		
		window.repaint(deltaTime, vertex, pairs);
	}
}
