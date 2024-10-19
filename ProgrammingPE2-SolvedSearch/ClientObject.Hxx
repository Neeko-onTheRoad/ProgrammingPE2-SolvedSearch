#pragma once

#include <SFML/Graphics.hpp>

namespace nk {

	class ClientObject : sf::Drawable {	

	public:
		virtual void Update(const sf::Event& event) {};

	};

}