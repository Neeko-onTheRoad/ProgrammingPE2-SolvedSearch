#pragma once

#include "ClientWindow.Hxx"

namespace nk {

	class Background : public ClientObject {

	private:
		sf::RectangleShape backgroundRect;

	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	public:
		Background(const sf::Color& color);


	};

}