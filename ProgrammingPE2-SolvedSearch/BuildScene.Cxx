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

	client.AddObject(
		new QueryTable(
			0.48f, // width
			0.02f, // margin
			0.001f, // centerLineThickness
			0.02f, // centerLineMargin
			AcColors::DarkerGray, // backgroundColor
			AcColors::DarkGray // centerLineColor
		),
		Layer::ObjectBackgrounds
	);

}