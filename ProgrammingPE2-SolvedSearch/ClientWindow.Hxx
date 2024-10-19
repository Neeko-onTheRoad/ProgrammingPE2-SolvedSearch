#pragma once

#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "ClientObject.Hxx"

namespace nk {

	class ClientWindow {
		
//======================================================================| Types

	public:
		using ObjectLayers = std::unordered_map<int, std::vector<ClientObject*>>;

//======================================================================| Singleton

	private:
		static ClientWindow* instance;
		void SetupSingleton();

	public:
		static ClientWindow& Get();

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
		sf::Event event;
		ObjectLayers objectLayers;

//======================================================================| Con/Destroctors

	public:
		ClientWindow();
		~ClientWindow();

//======================================================================| Methods

	public:
		void StartAndWaitForEnd();

	private:
		void MakeScene();
		void UpdateAll();
		void RenderAll() const;

	};

}