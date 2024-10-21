#pragma once

#include <SFML/Graphics.hpp>

namespace nk {

	namespace Fonts {

		const static std::string FontPath = "./res/Fonts/";
		
		namespace NanumSquareRound {

			static sf::Font Light;
			static sf::Font Regular;
			static sf::Font Bold;
			static sf::Font ExtraBold;

		}

		static void LoadFonts();

	};

}