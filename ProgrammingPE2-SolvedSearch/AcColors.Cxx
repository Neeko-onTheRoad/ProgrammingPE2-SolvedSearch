#include "AcColors.Hxx"

namespace nk {

	sf::Color AcColors::DarkerGray;
	sf::Color AcColors::DarkGray;
	sf::Color AcColors::LightGray;
	sf::Color AcColors::Hilight;
	sf::Color AcColors::White;

	std::vector<sf::Color> AcColors::TierColor;

	void AcColors::LoadColors() {

		DarkerGray	= sf::Color( 20,  25,  34);
		DarkGray	= sf::Color( 21,  32,  43);
		LightGray	= sf::Color( 86, 104, 114);
		Hilight		= sf::Color( 23, 205,  58);
		White		= sf::Color(255, 255, 255);

		for (int i = 0; i < Icons::SolvedTierCount; i++) {
			sf::Texture& texture = Icons::GetSolvedTier(i);
			sf::Color color = texture.copyToImage().getPixel(1, 1);
			TierColor.push_back(color);
		}

	}


}