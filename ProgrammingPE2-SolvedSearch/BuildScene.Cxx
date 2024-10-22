#include "BuildScene.Hxx"

using namespace nk;

void BuildScene(ClientWindow& client) {
	
	using Layer = ClientWindow::Layers;

	
	client.AddObject(
		new Background(
			Icons::SolvedTierBackground
		),
		Layer::Background
	);


	client.AddObject(
		new TitleBar(
			0.04f,
			0.035f,
			0.43f,
			AcColors::DarkerGray,
			AcColors::LightGray,
			AcColors::White,
			AcColors::LightGray
		),
		Layer::TitleBar
	);


}