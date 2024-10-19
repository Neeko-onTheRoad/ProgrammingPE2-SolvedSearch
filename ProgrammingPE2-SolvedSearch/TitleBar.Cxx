#include "TitleBar.Hxx"

namespace nk {

	void TitleBar::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		
		target.draw(background, states);
		target.draw(closeBackground)

	}

}