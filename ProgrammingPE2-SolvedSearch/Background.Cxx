#include "Background.Hxx"
#include "ClientWindow.Hxx"

#include <iostream>

namespace nk {

	Background::Background(sf::Color color) {
		backgroundRect.setFillColor(color);
		backgroundRect.setPosition(0.f, 0.f);
		backgroundRect.setSize((sf::Vector2f)ClientWindow::DEFAULT_SIZE);
	}

	void Background::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(backgroundRect, states);
	}

}