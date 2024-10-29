#include "ClientWindow.Hxx"

namespace nk {
	void ClientWindow::BuildScene() {

		sf::RenderWindow loadingScreen(
			sf::VideoMode(800, 100),
			"Loading",
			sf::Style::None,
			sf::ContextSettings(0, 0, 1)
		);

		sf::Text loadingText;
		loadingText.setFont(Fonts::NanumSquareRound::ExtraBold);
		loadingText.setString("Loading...");
		loadingText.setFillColor(AcColors::LightGray);
		loadingText.setOrigin(
			loadingText.getGlobalBounds().width / 2,
			loadingText.getGlobalBounds().height / 2
		);
		loadingText.setPosition(400, 50);

		loadingScreen.clear(AcColors::DarkGray);
		loadingScreen.draw(loadingText);
		loadingScreen.display();
	
		nk::TitleBar* titleBar = new nk::TitleBar(
			0.04f, // height
			0.035f, // buttonWidth
			0.43f, // iconSize
			AcColors::DarkerGray, // backgroundColor
			AcColors::LightGray, // iconColor
			AcColors::White, // iconHoverColor
			AcColors::LightGray, // iconHoverBackgroundColor
			AcColors::Hilight // iconClickBackgroundColor
		);

		AddObject(
			titleBar,
			Layers::TitleBar
		);
		SetTitleBarOffset(titleBar->GetHeight());

		AddObject(
			new nk::Background(
				Icons::SolvedTierBackground // backgroundTexture
			),
			Layers::Background
		);

		QueryTable* queryTable = new QueryTable(
			0.48f, // width
			0.02f, // margin
			0.001f, // centerLineThickness
			0.02f, // centerLineMargin
			0.02f, // buttonLineMargin
			0.3f, // buttonLineBottomMargin
			AcColors::DarkerGray, // backgroundColor
			AcColors::DarkGray // centerLineColor
		);

		AddObject(
			queryTable,
			Layers::ObjectBackgrounds
		);

		AddObject(
			new QueryButton(
				queryTable,
				{ 0.25f, 0.08f },
				0.88f,
				30,
				AcColors::DarkGray,
				AcColors::LightGray,
				AcColors::LightGray,
				AcColors::White,
				AcColors::Hilight,
				AcColors::White
			),
			Layers::Objects
		);
	}
}