#include "Background.Hxx"

namespace nk {

	Background::Background(const sf::Texture& backgroundTexture) {
		background.setTexture(backgroundTexture);
	}

	void Background::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(background, states);
	}

}