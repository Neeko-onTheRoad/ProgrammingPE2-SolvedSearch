#pragma once

#include <vector>
#include "AcColors.Hxx"
#include "LocaleManager.Hxx"
#include "QueryTagButton.Hxx"
#include "SolvedAcManager.Hxx"

namespace nk {

	class QueryTagButton;

	class QueryTable : public ClientObject {

	private:
		sf::RectangleShape background;
		sf::RenderTexture maskedTexture;
		sf::Sprite resultSpriteBuffer;
		sf::RectangleShape backgroundMask;
		sf::RectangleShape centerLine;
		sf::RectangleShape buttonLine;
		sf::RenderStates renderStates;
		sf::Vector2f queryButtonOrigin;

		std::vector<QueryTagButton*> queryButtons;
		float scroll = 0.f;

	public:
		SolvedAcManager SolvedManager;


	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void Rerender() override;
		void Update(const sf::Event& event) override;

	public:
		QueryTable(
			float width,
			float margin,
			float centerLineThickness,
			float centerLineMargin,
			float buttonLineMargin,
			float buttonLineBottomMargin,
			const sf::Color& backgroundColor,
			const sf::Color& centerLineColor
		);

		sf::Vector2f GetSize() const;
		sf::Vector2f GetPosition() const;
		float GetMargin() const;
		float GetLeftSideHeight() const;

		std::vector<std::string> GetActiveTags();

	};

}