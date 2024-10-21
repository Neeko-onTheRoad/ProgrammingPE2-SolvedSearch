#include "ClientWindow.Hxx"

namespace nk {
	
	ClientWindow* ClientWindow::instance = nullptr;

	void ClientWindow::SetupSingleton() {
		if (instance != nullptr) {
			delete this;
		}
		else {
			instance = this;
		}
	}

	ClientWindow& ClientWindow::Get() {
		if (instance == nullptr) {
			instance = new ClientWindow();
		}

		return *instance;
	}
	
	const sf::Vector2u ClientWindow::DEFAULT_SIZE = sf::Vector2u(1600u, 900u);
	const std::string ClientWindow::DEFAULT_TITLE = "N/A";
	const sf::Uint16 ClientWindow::DEFAULT_STYLE = sf::Style::None;
	const sf::ContextSettings ClientWindow::DEFAULT_SETTINGS = sf::ContextSettings(0, 0, 4); // x4 antialiasing
	const unsigned ClientWindow::DEFAULT_FRAME_RATE	= 144u;
	const bool ClientWindow::DEFAULT_VERTICAL_SYNC_ENABLED = true;

	ClientWindow::ClientWindow() {

		renderWindow = new sf::RenderWindow(
			sf::VideoMode(DEFAULT_SIZE.x, DEFAULT_SIZE.y),
			DEFAULT_TITLE,
			DEFAULT_STYLE,
			DEFAULT_SETTINGS
		);

		renderWindow->setFramerateLimit(DEFAULT_FRAME_RATE);
		renderWindow->setVerticalSyncEnabled(DEFAULT_VERTICAL_SYNC_ENABLED);

		event = sf::Event();

		SetupSingleton();

	}

	ClientWindow::~ClientWindow() {
		delete renderWindow;
	}


	void ClientWindow::StartAndWaitForEnd() {

		while (renderWindow->isOpen()) {

			renderWindow->pollEvent(event);
			UpdateAll();

			renderWindow->clear();
			RenderAll();
			renderWindow->display();

		}

	}

	void ClientWindow::UpdateAll() {
		for (const auto& objectLayer : objectLayers) {
			for (const auto& object : objectLayer.second) {
				object->UpdateBase(event);
			}
		}
	}

	void ClientWindow::RenderAll() const {
		for (const auto& objectLayer : objectLayers) {
			for (const auto& object : objectLayer.second) {
				object->DrawBase(*renderWindow, sf::RenderStates());
			}
		}
	}

	void ClientWindow::AddObject(ClientObject* object, Layers layer) {
		objectLayers[layer].push_back(object);
	}

	bool ClientWindow::RemoveObject(ClientObject* object) {

		for (auto& objectLayer : objectLayers) {

			auto& objects = objectLayer.second;
			auto objectFound = std::find(objects.begin(), objects.end(), object);

			if (objectFound != objects.end()) {
				objects.erase(objectFound);
				return true;
			}
		}

		return false;
	}

	sf::Vector2f ClientWindow::GetSizeF() const {
		return (sf::Vector2f)renderWindow->getSize();
	}

	sf::Vector2u ClientWindow::GetSize() const {
		return renderWindow->getSize();
	}

	sf::Vector2i ClientWindow::GetPosition() const {
		return renderWindow->getPosition();
	}

	void ClientWindow::SetPosition(sf::Vector2i position) {
		renderWindow->setPosition(position);
	}

}
