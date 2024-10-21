#include "BuildScene.Hxx"

using namespace nk;

void BuildScene(ClientWindow& client) {
	
	using Layer = ClientWindow::Layers;


	client.AddObject(
		new Background(
			AcColors::DarkGray
		),
		Layer::Background
	);


	client.AddObject(
		new TitleBar(
			0.04f,
			0.04f,
			0.8f,
			AcColors::DarkerGray,
			AcColors::LightGray,
			AcColors::Hilight,
			AcColors::White
		),
		Layer::TitleBar
	);


}