#pragma once

#include "ClientObject.Hxx"

namespace nk {

	class TitleBar : public ClientObject {

	private:
		sf::RectangleShape background;
		sf::RectangleShape closeBackground;
		sf::RectangleShape minimalizeBackground;

		sf::Sprite closeIcon;
		sf::Sprite minimalizeIcon;

	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void Update(const sf::Event& event) override;

	};

}