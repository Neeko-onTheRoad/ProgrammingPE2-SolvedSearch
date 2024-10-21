#pragma once

#include "ClientWindow.Hxx"

namespace nk {

	class TitleBar : public ClientObject {

	private:
		sf::RectangleShape background;
		sf::RectangleShape closeBackground;
		sf::RectangleShape minimalizeBackground;

		sf::Sprite closeIcon;
		sf::Sprite minimalizeIcon;

		bool isWindowMoveing = false;
		sf::Vector2i windowMoveingMouseOffset;

	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void Update(const sf::Event& event) override;

	public:
		TitleBar(
			float height,
			float buttonWidth,
			float iconSize,
			const sf::Color& backgroundColor,
			const sf::Color& iconColor,
			const sf::Color& iconHoverColor,
			const sf::Color& iconHoverBackgroundColor
		);

	};

}