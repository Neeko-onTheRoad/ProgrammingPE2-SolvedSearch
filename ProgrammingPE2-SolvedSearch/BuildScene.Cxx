#include "BuildScene.Hxx"

using namespace nk;

void BuildScene(ClientWindow& client) {
	
	using Layer = ClientWindow::Layers;

	
	Background* background = new Background(
		AcColors::DarkGray
	);
	client.AddObject(background, Layer::Background);


	TitleBar* titleBar = new TitleBar(
		0.04f,
		0.04f,
		AcColors::DarkerGray,
		AcColors::LightGray,
		AcColors::Hilight,
		AcColors::White
	);
	client.AddObject(titleBar, Layer::TitleBar); 


}