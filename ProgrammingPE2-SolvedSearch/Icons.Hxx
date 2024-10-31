#pragma once

#include <unordered_map>
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

	private:
		static std::unordered_map<int, sf::Texture> solvedTiers;

	public:
		static void LoadIcons();
		static sf::Texture& GetSolvedTier(int level);
			
	};

}