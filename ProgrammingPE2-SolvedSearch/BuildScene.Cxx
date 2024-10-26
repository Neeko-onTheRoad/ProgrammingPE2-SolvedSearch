#include "ClientWindow.Hxx"

namespace nk {
	void ClientWindow::BuildScene() {
	
		nk::TitleBar* titleBar = new nk::TitleBar(
			0.04f, // height
			0.035f, // buttonWidth
			0.43f, // iconSize
			AcColors::DarkerGray, // backgroundColor
			AcColors::LightGray, // iconColor
			AcColors::White, // iconHoverColor
			AcColors::LightGray // iconHoverBackgroundColor
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

		AddObject(
			new QueryTable(
				0.48f, // width
				0.02f, // margin
				0.001f, // centerLineThickness
				0.02f, // centerLineMargin
				AcColors::DarkerGray, // backgroundColor
				AcColors::DarkGray // centerLineColor
			),
			Layers::ObjectBackgrounds
		);
	}
}