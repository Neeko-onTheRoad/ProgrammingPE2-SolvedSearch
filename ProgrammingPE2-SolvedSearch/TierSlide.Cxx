#include "TierSlide.Hxx"

namespace nk {

	void TierSlide::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(centerLine, states);

		for (auto& gridLine : gridLines) {
			target.draw(*gridLine, states);
		}
	}

	void TierSlide::Update(const sf::Event& event) {
	}

	TierSlide::~TierSlide() {
		for (auto& gridLines : gridLines) {
			delete gridLines;
		}
	}

	TierSlide::TierSlide(
		QueryTable* queryTable,
		float centerLineThickness,
		float centerLineMargin,
		float gridLineThickness,
		float gridLineWidth,
		const sf::Color& lineColor,
		const sf::Color& gridLineDefaultColor
	) {
		
		this->queryTable = queryTable;

		sf::Vector2f centerLineSize = {
			centerLineThickness * ClientWindow::Get().GetSize().x,
			queryTable->GetLeftSideHeight() -
			centerLineMargin * ClientWindow::Get().GetSize().y * 2.f
		};

		sf::Vector2f centerLinePosition = queryTable->GetPosition() + sf::Vector2f(
			queryTable->GetSize().x / 4.f,
			centerLineMargin * ClientWindow::Get().GetSize().y
		);

		centerLine.setFillColor(lineColor);
		centerLine.setSize(centerLineSize);
		centerLine.setOrigin(centerLine.getSize().x / 2.f, 0.f);
		centerLine.setPosition(centerLinePosition);

		gridLines.resize(Icons::SolvedTierCount);

		sf::Vector2f gridLineSize = {
			gridLineWidth * ClientWindow::Get().GetSize().x,
			gridLineThickness * ClientWindow::Get().GetSize().y
		};

		for (int lineIndex = 0; lineIndex < Icons::SolvedTierCount; lineIndex++) {

			sf::RectangleShape* gridLine = new sf::RectangleShape;

			gridLine->setFillColor(gridLineDefaultColor);
			gridLine->setSize(gridLineSize);
			gridLine->setOrigin(gridLineSize / 2.f);
			gridLine->setPosition(centerLinePosition);
			
			gridLines.push_back(gridLine);

		}

	}

}

