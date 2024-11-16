#ifndef WINDOW_HPP
#define WINDOW_HPP

#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<math.h>
#include<iostream>
#include<vector>
#include<glm/glm.hpp>

class Window: public sf::RenderWindow {
private:
	sf::Font _font;
    sf::Text _fpsText;
    uint16_t _fps;
    uint8_t _fpsLimit = 45;

	sf::RectangleShape _line_from_to(const sf::Vector2f& point0, const sf::Vector2f& pointf) {
		sf::RectangleShape line;
		line.setSize(sf::Vector2f(std::hypot(pointf.x - point0.x, pointf.y - point0.y), 5.f));
		line.setFillColor(sf::Color::Black);
		line.setPosition(point0);
		line.setRotation(std::atan2(pointf.y - point0.y, pointf.x - point0.x) * 180.f / 3.14159f);

		return line;
	}

public:
	Window() {
		this->create(sf::VideoMode(480, 270), "Diedric Renderer");
		this->setFramerateLimit(60);

		if (!this->_font.loadFromFile("./bin/fonts/pixelmix.ttf")) {
            std::cerr << ":) no font" << std::endl;
        }

        this->_fpsText.setFont(this->_font);
        this->_fpsText.setCharacterSize(24);
        this->_fpsText.setFillColor(sf::Color(0xff00ffff));
        this->_fpsText.setPosition(10.f, 10.f);
	}

	void repaint(float& deltaTime, const std::vector<sf::Vector2f>& vertex, const std::vector<glm::ivec2>& pairs) {
		this->clear(sf::Color(255, 255, 255));

		for (const glm::ivec2& p : pairs) {
			this->draw(this->_line_from_to(vertex[p.x], vertex[p.y]));
		}		

		this->_fps = static_cast<uint16_t>(1.f / deltaTime);
        this->_fpsText.setString("FPS: " + std::to_string(this->_fps));
        
		this->draw(this->_fpsText);

		this->display();
	}
};

#endif
