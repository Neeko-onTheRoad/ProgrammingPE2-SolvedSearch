#pragma once

#include "AcColors.Hxx"
#include "QueryTable.Hxx"
#include "ClientObject.Hxx"

namespace nk {

	class QueryTable;

	class TierSlide : public ClientObject {

	private:
		QueryTable* queryTable;

		sf::RectangleShape centerLine;
		std::vector<sf::RectangleShape*> gridLines;
		sf::CircleShape scrollCircles[2];

	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void Update(const sf::Event& event) override;

	public:
		~TierSlide();
		TierSlide(
			QueryTable* queryTable,
			float centerLineThickness,
			float centerLineMargin,
			float gridLineThickness,
			float gridLineWidth,
			float gridStartLineThickness,
			float gridStartLineWidth,
			float scrollBarThickness,
			float scrollCircleSize,
			float scrollCircleOutlineThickness,
			const sf::Color& lineColor,
			const sf::Color& gridLineDefaultColor,
			const sf::Color& scrollBarColor,
			const sf::Color& scrollCircleDefaultColor,
			const sf::Color& scrollCircleHoverColor,
			const sf::Color& scrollCircleClickColor
		);



	};

}