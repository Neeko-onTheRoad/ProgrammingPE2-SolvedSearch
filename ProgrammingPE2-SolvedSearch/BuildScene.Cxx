#include "Background.Hxx"
#include "BuildScene.Hxx"

using namespace nk;

void BuildScene(ClientWindow& client) {
	
	using Layer = ClientWindow::Layers;

	client.AddObject(new nk::Background(sf::Color(21, 32, 43)), Layer::Background);

}