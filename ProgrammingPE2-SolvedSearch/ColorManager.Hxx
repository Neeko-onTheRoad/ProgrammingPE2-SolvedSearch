#pragma once

#include <SFML/Graphics.hpp>

namespace nk {

	namespace ColorManager {

		void SetOpacity(sf::Shape& shape, sf::Uint8 opacity);
		void SetOpacity(sf::Sprite& sprite, sf::Uint8 opacity);

	}

}