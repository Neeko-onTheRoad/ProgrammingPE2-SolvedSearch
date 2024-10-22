#include "Icons.Hxx"

namespace nk {
	
	const std::string Icons::IconPath = "./res/Icons/";

	sf::Texture Icons::CloseButton;
	sf::Texture Icons::MinimizeButton;
	sf::Texture Icons::SolvedLogo;
	sf::Texture Icons::SolvedLogoNoBG;
	sf::Texture Icons::SolvedTierBackground;

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
	}

}