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

	protected:
		void Update(const sf::Event& event) override;
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	public:
		QueryButton(
			QueryTable* queryTable, 
			sf::Vector2f size,
			float yPos,
			float outlineThickness,
			unsigned fontSize,
			sf::Color backgroundColor,
			sf::Color foregroundColor,
			sf::Color hoverBackgroundColor,
			sf::Color hoverForegroundColor,
			sf::Color clickBackgroundColor,
			sf::Color clickForegroundColor
		);

	};

}