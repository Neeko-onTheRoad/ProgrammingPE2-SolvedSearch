
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
	
	const sf::Vector2u ClientWindow::DEFAULT_SIZE = sf::Vector2u(1600u, 1000u);
	const std::string ClientWindow::DEFAULT_TITLE = "Solved Search";
	const sf::Uint16 ClientWindow::DEFAULT_STYLE = sf::Style::None;
	const sf::ContextSettings ClientWindow::DEFAULT_SETTINGS = sf::ContextSettings(0, 0, 4); // x4 antialiasing
	const unsigned ClientWindow::DEFAULT_FRAME_RATE	= 144u;
	const bool ClientWindow::DEFAULT_VERTICAL_SYNC_ENABLED = true;

	ClientWindow::ClientWindow() {

		SetupSingleton();

		Fonts::LoadFonts();
		Icons::LoadIcons();
		AcColors::LoadColors();
		SolvedAcManager::MakeTierNames();

		renderWindow = new sf::RenderWindow(
			sf::VideoMode(DEFAULT_SIZE.x, DEFAULT_SIZE.y),
			DEFAULT_TITLE,
			DEFAULT_STYLE,
			DEFAULT_SETTINGS
		);

		renderWindow->setFramerateLimit(DEFAULT_FRAME_RATE);
		renderWindow->setVerticalSyncEnabled(DEFAULT_VERTICAL_SYNC_ENABLED);

		event = sf::Event();

		renderWindow->setIcon(
			Icons::SolvedLogo.getSize().x,
			Icons::SolvedLogo.getSize().y,
			Icons::SolvedLogo.copyToImage().getPixelsPtr()
		);

	}

	ClientWindow::~ClientWindow() {
		delete renderWindow;
	}

	void ClientWindow::Start() {

		while (renderWindow->isOpen()) {

			if (renderWindow->pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					renderWindow->close();
					return;
				}
				UpdateAll();
			}

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

	void ClientWindow::SetTitleBarOffset(float titleBarSize) { 
		this->titleBarSize = titleBarSize;
	}

	float ClientWindow::GetTitleBarOffset() const {
		return titleBarSize;
	}

	sf::Vector2f ClientWindow::GetSize() const {
		return GetRawSizeF() - sf::Vector2f{ 0.f, titleBarSize };
	}

	sf::Vector2f ClientWindow::GetRawSizeF() const {
		return (sf::Vector2f)renderWindow->getSize();
	}

	sf::Vector2u ClientWindow::GetRawSize() const {
		return renderWindow->getSize();
	}

	sf::Vector2i ClientWindow::GetPosition() const {
		return renderWindow->getPosition();
	}

	void ClientWindow::SetPosition(sf::Vector2i position) {
		renderWindow->setPosition(position);
	}

	void ClientWindow::SetPosition(int x, int y) {
		renderWindow->setPosition({ x, y });
	}

    void ClientWindow::Close() {
		renderWindow->close();
	}

	void ClientWindow::Minimize() {
		ShowWindow(renderWindow->getSystemHandle(), SW_MINIMIZE);
	}

}
