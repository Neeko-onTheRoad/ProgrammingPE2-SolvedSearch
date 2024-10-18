#include "ClientWindow.Hxx"

namespace nk::Client {
	
	const sf::Vector2u			ClientWindow::DEFAULT_SIZE			= sf::Vector2u(1600u, 900u);
	const std::string			ClientWindow::DEFAULT_TITLE			= "N/A";
	const sf::Uint16			ClientWindow::DEFAULT_STYLE			= sf::Style::None;
	const sf::ContextSettings	ClientWindow::DEFAULT_SETTINGS		= sf::ContextSettings(0, 0, 4); // x4 antialiasing
	const unsigned				ClientWindow::DEFAULT_FRAME_RATE	= 144u; // Because of my Monitor ;)

	ClientWindow::ClientWindow() {
		renderWindow = new sf::RenderWindow(
			sf::VideoMode(DEFAULT_SIZE.x, DEFAULT_SIZE.y),
			DEFAULT_TITLE,
			DEFAULT_STYLE,
			DEFAULT_SETTINGS
		);

		renderWindow->setFramerateLimit(DEFAULT_FRAME_RATE);
		renderWindow->setVerticalSyncEnabled(DEFAULT_VERTICAL_SYNC_ENABLED);
	}

	void ClientWindow::Start() {

		

	}

}