#pragma once

#include <SFML/Graphics.hpp>

namespace nk {

	class Icons {
	public:

		const static std::string IconPath;

		static sf::Texture CloseButton;
		static sf::Texture MinimizeButton;
		static sf::Texture SolvedLogo;
		static sf::Texture SolvedLogoNoBG;
		static sf::Texture SolvedTierBackground;

		static void LoadIcons();
			
	};

}