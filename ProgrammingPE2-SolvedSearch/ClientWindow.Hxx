#pragma once

#include <climits>
#include <algorithm>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "Fonts.Hxx"
#include "Icons.Hxx"
#include "ClientObject.Hxx"

namespace nk {

	class ClientWindow {

//======================================================================| Types

	public:
		using ObjectLayers = std::unordered_map<int, std::vector<ClientObject*>>;

		enum Layers {
			Background = INT_MIN,
			TitleBar = INT_MAX
		};

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

	private:
		void UpdateAll();
		void RenderAll() const;

	public:
		void StartAndWaitForEnd();

		void AddObject(ClientObject* object, Layers layer);
		bool RemoveObject(ClientObject* object);

		sf::Vector2f GetSizeF() const;
		sf::Vector2u GetSize() const;

		sf::Vector2i GetPosition() const;
		void SetPosition(sf::Vector2i position);

	};

}