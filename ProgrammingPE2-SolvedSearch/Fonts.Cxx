#include "Fonts.Hxx"

namespace nk::Fonts {

	sf::Font NanumSquareRound::Light;
	sf::Font NanumSquareRound::Regular;
	sf::Font NanumSquareRound::Bold;
	sf::Font NanumSquareRound::ExtraBold;

	void LoadFonts() {

		NanumSquareRound::Light.loadFromFile(FontPath + "NanumSquareRoundL.ttf");
		NanumSquareRound::Regular.loadFromFile(FontPath + "NanumSquareRoundR.ttf");
		NanumSquareRound::Bold.loadFromFile(FontPath + "NanumSquareRoundB.ttf");
		NanumSquareRound::ExtraBold.loadFromFile(FontPath + "NanumSquareRoundEB.ttf");

	}

}