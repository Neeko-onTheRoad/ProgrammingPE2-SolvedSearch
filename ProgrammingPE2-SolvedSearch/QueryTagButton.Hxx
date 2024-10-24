#pragma once

#include "Fonts.Hxx"
#include "ClientObject.Hxx"
#include "ClientWindow.Hxx"

namespace nk {

	class QueryTagButton : public ClientObject {

	private:
		static sf::Color backgroundColor;
		static sf::Color foregroundColor;
		static sf::Color hoverBackgroundColor;
		static sf::Color hoverForegroundColor;
		static sf::Color clickBackgroundColor;
		static sf::Color clickForegroundColor;
		static Ratio height;
		static Ratio textMarginLeft;
		static unsigned textSize;
		static sf::Vector2f size;

		sf::Text name;
		sf::RectangleShape background;
		bool isActivated = true;

	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void Update(const sf::Event& event) override;

	public:
		QueryTagButton(
			std::string target,
			sf::Vector2f position
		);

		bool IsActivated() const;
		std::string GetTarget() const;

		static void SetBackgroundColor(const sf::Color& color);
		static void SetForegroundColor(const sf::Color& color);
		static void SetHoverBackgroundColor(const sf::Color& color);
		static void SetHoverForegroundColor(const sf::Color& color);
		static void SetClickBackgroundColor(const sf::Color& color);
		static void SetClickForegroundColor(const sf::Color& color);
		static void SetHeight(Ratio height);
		static void SetTextMarginLeft(Ratio margin);
		static void SetTextSize(unsigned size);
		static void SetSize(sf::Vector2f size);

	};

}