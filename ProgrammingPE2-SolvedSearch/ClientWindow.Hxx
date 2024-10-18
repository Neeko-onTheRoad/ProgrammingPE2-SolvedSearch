#pragma once

#include <SFML/Graphics.hpp>

namespace nk::Client {

	class ClientWindow {

//======================================================================| Constants

	private:
		const static sf::Vector2u			DEFAULT_SIZE;
		const static std::string			DEFAULT_TITLE;
		const static sf::Uint16				DEFAULT_STYLE;
		const static sf::ContextSettings	DEFAULT_SETTINGS;
		const static unsigned				DEFAULT_FRAME_RATE;
		const static bool					DEFAULT_VERTICAL_SYNC_ENABLED;

//======================================================================| Members

	private:
		sf::RenderWindow* renderWindow;

//======================================================================| Con/Destroctors

	public:
		ClientWindow();

//======================================================================| Methods

	public:
		void Start();

	};

}