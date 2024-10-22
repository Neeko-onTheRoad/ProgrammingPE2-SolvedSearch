#pragma once

#include "Icons.Hxx"
#include "AcColors.Hxx"
#include "ClientWindow.Hxx"
#include "ColorManager.Hxx"

namespace nk {

	class TitleBar : public ClientObject {

	private:
		sf::RectangleShape background;
		sf::RectangleShape closeBackground;
		sf::RectangleShape minimizeBackground;

		sf::Sprite closeIcon;
		sf::Sprite minimizeIcon;

		bool isWindowMoveing = false;
		sf::Vector2i windowMoveingMouseOffset;

		sf::Color iconColor;
		sf::Color iconHoverColor;

		bool hoveringCloseButton = false;
		bool clickingCloseButton = false;
		bool hoveringMinimizeButton = false;
		bool clickingMinimizeButton = false;


		void UpdateMovement(const sf::Event& event);

		void SetButtonHover(
			bool flag,
			sf::RectangleShape& background,
			sf::Sprite& icon
		) const;

		void UpdateButton(
			const sf::Event& event,
			sf::RectangleShape& background,
			sf::Sprite& icon,
			bool& hovering,
			bool& clicking,
			void(*callback)()
		);

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