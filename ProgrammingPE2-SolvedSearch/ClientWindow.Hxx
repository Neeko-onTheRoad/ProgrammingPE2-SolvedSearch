#pragma once

#define NOMINMAX

#include <climits>
#include <algorithm>
#include <Windows.h>
#include <unordered_map>
#include <SFML/Graphics.hpp>

#include "Fonts.Hxx"
#include "Icons.Hxx"
#include "ClientObject.Hxx"
#include "QueryButton.Hxx"

#include "TitleBar.Hxx"
#include "Background.Hxx"
#include "QueryTable.Hxx"


namespace nk {

	class ClientWindow {

//======================================================================| Types

	public:
		using ObjectLayers = std::map<int, std::vector<ClientObject*>>;

		enum Layers {
			Background			= INT_MIN,
			ObjectBackgrounds	= INT16_MIN,
			ObjectEffectBack	= CHAR_MIN,
			Objects				= NULL,
			ObjectEffectFront	= CHAR_MAX,
			ObjectForegrounds	= INT16_MAX,
			TitleBar			= INT_MAX
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

	public:
		sf::RenderWindow* renderWindow;
		sf::Event event;
		ObjectLayers objectLayers;
		WNDPROC originalWindow;
		float titleBarSize;

//======================================================================| Con/Destroctors

	public:
		ClientWindow();
		~ClientWindow();

//======================================================================| Methods

	private:
		void UpdateAll();
		void RenderAll() const;

	public:
		void BuildScene();
		void Start();

		void AddObject(ClientObject* object, Layers layer);
		bool RemoveObject(ClientObject* object);

		void SetTitleBarOffset(float titleBarSize);
		float GetTitleBarOffset() const;

		sf::Vector2f GetSize() const;
		sf::Vector2f GetRawSizeF() const;
		sf::Vector2u GetRawSize() const;

		sf::Vector2i GetPosition() const;
		void SetPosition(sf::Vector2i position);
		void SetPosition(int x, int y);

		void Close();
		void Minimize();

	};

}