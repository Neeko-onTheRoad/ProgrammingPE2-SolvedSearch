#pragma once

#include <vector>
#include "AcColors.Hxx"
#include "LocaleManager.Hxx"
#include "QueryTagButton.Hxx"
#include "SolvedAcManager.Hxx"

namespace nk {

	class QueryTable : public ClientObject {

	private:
		sf::RectangleShape background;
		sf::RenderTexture maskedTexture;
		sf::Sprite resultSpriteBuffer;
		sf::RectangleShape backgroundMask;
		sf::RectangleShape centerLine;
		sf::RenderStates renderStates;
		sf::Vector2f queryButtonOrigin;
		float queryButtonBottom;

		std::vector<QueryTagButton*> queryButtons;

		SolvedAcManager solvedManager;

		float scroll = 0.f;

	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void Rerender() override;
		void Update(const sf::Event& event) override;

	public:
		QueryTable(
			Ratio width,
			Ratio margin,
			Ratio centerLineThickness,
			Ratio centerLineMargin,
			const sf::Color& backgroundColor,
			const sf::Color& centerLineColor
		);

	};

}