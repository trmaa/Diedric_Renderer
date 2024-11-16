#ifndef WINDOW_HPP
#define WINDOW_HPP

#include<SFML/Graphics.hpp>

class Window: public sf::RenderWindow {
public:
	Window() {
		this->create(sf::VideoMode(800, 450), "Diedric Renderer");
		this->setFramerateLimit(60);
	}

	void repaint() {
		this->clear(sf::Color(255, 255, 255));
		this->display();
	}
};

#endif
