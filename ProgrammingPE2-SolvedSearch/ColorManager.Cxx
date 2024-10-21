#include "ColorManager.Hxx"

namespace nk::ColorManager {

	void SetOpacity(sf::Shape& shape, sf::Uint8 opacity) {
		sf::Color color = shape.getFillColor();
		shape.setFillColor(sf::Color(color.r, color.g, color.b, opacity));
	}

	void SetOpacity(sf::Sprite& sprite, sf::Uint8 opacity) {
		sf::Color color = sprite.getColor();
		sprite.setColor(sf::Color(color.r, color.g, color.b, opacity));
	}

}