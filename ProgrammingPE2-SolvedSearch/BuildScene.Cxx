#include "BuildScene.Hxx"

using namespace nk;

void BuildScene(ClientWindow& client) {
	
	using Layer = ClientWindow::Layers;
	
	client.AddObject(new nk::Background(AcColors::DarkGray), Layer::Background);

}