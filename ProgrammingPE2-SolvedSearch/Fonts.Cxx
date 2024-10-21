#include "Fonts.Hxx"

namespace nk::Fonts {

	void LoadFonts() {

		NanumSquareRound::Light.loadFromFile(FontPath + "NanumSquareRoundL.ttf");
		NanumSquareRound::Regular.loadFromFile(FontPath + "NanumSquareRoundR.ttf");
		NanumSquareRound::Bold.loadFromFile(FontPath + "NanumSquareRoundB.ttf");
		NanumSquareRound::ExtraBold.loadFromFile(FontPath + "NanumSquareRoundEB.ttf");

	}

}