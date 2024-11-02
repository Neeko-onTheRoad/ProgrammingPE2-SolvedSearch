#include "Icons.Hxx"

namespace nk {
	
	const std::string Icons::IconPath = "./res/Icons/";

	sf::Texture Icons::CloseButton;
	sf::Texture Icons::MinimizeButton;
	sf::Texture Icons::SolvedLogo;
	sf::Texture Icons::SolvedLogoNoBG;
	sf::Texture Icons::SolvedTierBackground;
	std::unordered_map<int, sf::Texture> Icons::solvedTiers;
	int Icons::SolvedTierCount;

	void Icons::LoadIcons() {
		
		CloseButton.loadFromFile(IconPath + "CloseButton.png");
		MinimizeButton.loadFromFile(IconPath + "MinimizeButton.png");
		SolvedLogo.loadFromFile(IconPath + "SolvedLogo.png");
		SolvedLogoNoBG.loadFromFile(IconPath + "SolvedLogoNoBG.png");
		SolvedTierBackground.loadFromFile(IconPath + "SolvedTierBackground.png");

		CloseButton.setSmooth(true);
		MinimizeButton.setSmooth(true);
		SolvedLogo.setSmooth(true);
		SolvedLogoNoBG.setSmooth(true);
		SolvedTierBackground.setSmooth(true);

		std::string solvedTierIconsPath = IconPath + "SolvedTier/";

		for (int i = 0; i <= 30; i++) {
			solvedTiers[i].loadFromFile(solvedTierIconsPath + std::to_string(i) + ".png");
			SolvedTierCount++;
		}

	}

    sf::Texture& Icons::GetSolvedTier(int level) {
        return solvedTiers[level];
    }

}