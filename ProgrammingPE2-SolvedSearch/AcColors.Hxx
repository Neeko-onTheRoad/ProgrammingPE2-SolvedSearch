#pragma once

#include <SFML/Graphics.hpp>
#include "Icons.Hxx"

namespace nk {
	
	class AcColors {

	public:
		static sf::Color DarkerGray;
		static sf::Color DarkGray;
		static sf::Color LightGray;
		static sf::Color Hilight;
		static sf::Color White;

		static std::vector<sf::Color> TierColor;

		static void LoadColors();

	};

}