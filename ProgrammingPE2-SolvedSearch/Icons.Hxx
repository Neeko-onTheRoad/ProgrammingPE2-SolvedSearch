#pragma once

#include <SFML/Graphics.hpp>

namespace nk {

	namespace Icons {

		const static std::string IconPath = "./res/Icons/";

		static sf::Texture CloseButton;
		static sf::Texture MinimalizeButton;

		void LoadIcons();

	}

}