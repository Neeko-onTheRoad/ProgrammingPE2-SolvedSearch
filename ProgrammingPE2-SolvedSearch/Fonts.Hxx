#pragma once

#include <SFML/Graphics.hpp>

namespace nk {

	namespace Fonts {

		const static std::string FontPath = "./res/Fonts/";
		
		class NanumSquareRound {
		public:

			static sf::Font Light;
			static sf::Font Regular;
			static sf::Font Bold;
			static sf::Font ExtraBold;

		};

		void LoadFonts();

	};

}