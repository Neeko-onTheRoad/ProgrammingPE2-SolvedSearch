#include "BuildScene.Hxx"

using namespace nk;

void BuildScene(ClientWindow& client) {
	
	using Layer = ClientWindow::Layers;

	
	TitleBar* titleBar = new TitleBar(
		0.04f, // height
		0.035f, // buttonWidth
		0.43f, // iconSize
		AcColors::DarkerGray, // backgroundColor
		AcColors::LightGray, // iconColor
		AcColors::White, // iconHoverColor
		AcColors::LightGray // iconHoverBackgroundColor
	);

	client.AddObject(
		titleBar,
		Layer::TitleBar
	);
	client.SetTitleBarOffset(titleBar->GetHeight());

	client.AddObject(
		new Background(
		Icons::SolvedTierBackground // backgroundTexture
	),
		Layer::Background
	);

	QueryTagButton::SetBackgroundColor(AcColors::DarkerGray);
	QueryTagButton::SetForegroundColor(AcColors::LightGray);
	QueryTagButton::SetHoverBackgroundColor(AcColors::DarkGray);
	QueryTagButton::SetHoverForegroundColor(AcColors::LightGray);
	QueryTagButton::SetClickBackgroundColor(AcColors::LightGray);
	QueryTagButton::SetClickForegroundColor(AcColors::White);

	client.AddObject(
		new QueryTable(
			0.48f,
			0.02f,
			0.001f,
			0.02f,
			AcColors::DarkerGray,
			AcColors::DarkGray
		),
		Layer::ObjectBackgrounds
	);

}