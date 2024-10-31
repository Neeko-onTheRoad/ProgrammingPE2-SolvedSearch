#pragma once

#include "QueryTable.Hxx"

namespace nk {

	class QueryTable;

	class QueryButton : public ClientObject {

	private:
		QueryTable* queryTable;
		sf::RectangleShape background;
		sf::Text name;		
		sf::Color backgroundColor;
		sf::Color foregroundColor;
		sf::Color hoverBackgroundColor;
		sf::Color hoverForegroundColor;
		sf::Color clickBackgroundColor;
		sf::Color clickForegroundColor;

		bool hovering = false;
		bool clicking = false;

	private:
		void SetVisualDefault();
		void SetVisualHover();
		void SetVisualClick();

		void Search();

	protected:
		void Update(const sf::Event& event) override;
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	public:
		QueryButton(
			QueryTable* queryTable, 
			sf::Vector2f size,
			float yPos,
			unsigned fontSize,
			sf::Color backgroundColor,
			sf::Color foregroundColor,
			sf::Color hoverBackgroundColor,
			sf::Color hoverForegroundColor,
			sf::Color clickBackgroundColor,
			sf::Color clickForegroundColor
		);

		sf::Vector2f GetPosition() const;
		sf::Vector2f GetSize() const;

	};

}