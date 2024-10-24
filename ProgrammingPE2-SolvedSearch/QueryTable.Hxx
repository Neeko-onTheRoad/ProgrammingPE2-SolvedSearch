#pragma once

#include <vector>
#include "QueryDivision.Hxx"
#include "SolvedAcManager.Hxx"

namespace nk {

	class QueryTable : public ClientObject {

	private:
		sf::RectangleShape background;
		sf::RenderTexture maskedTexture;
		sf::Sprite resultSpriteBuffer;
		sf::RectangleShape backgroundMask;
		sf::RenderStates renderStates;

		std::vector<QueryDivision*> divisions;

		SolvedAcManager solvedManager;

	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void Rerender() override;
		void Update(const sf::Event& event) override;

	public:
		QueryTable(
			Ratio width,
			Ratio margin,
			const sf::Color& backgroundColor
		);

		void AddDivision(QueryDivision* division);

	};

}