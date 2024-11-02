#include "TierSlide.Hxx"

namespace nk {

	void TierSlide::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(centerLine, states);

		for (auto& gridLine : gridLines) {
			target.draw(*gridLine, states);
		}

		for (auto& scrollCircle : scrollCircles) {
			target.draw(scrollCircle, states);
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
		float gridStartLineThickness,
		float gridStartLineWidth,
		float scrollBarThickness,
		float scrollCircleSize,
		float scrollCircleOutlineSize,
		const sf::Color& lineColor,
		const sf::Color& gridLineDefaultColor,
		const sf::Color& scrollBarColor,
		const sf::Color& scrollCircleDefaultColor,
		const sf::Color& scrollCircleHoverColor,
		const sf::Color& scrollCircleClickColor
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

		float gridLineOffset = 
			centerLineSize.y / (Icons::SolvedTierCount - 1);

		for (int lineIndex = 0; lineIndex < Icons::SolvedTierCount; lineIndex++) {

			sf::RectangleShape* gridLine = new sf::RectangleShape;

			if ((lineIndex - 1) % 5 == 0 || !lineIndex) {
				sf::Vector2f gridLineSize = {
					gridStartLineWidth* ClientWindow::Get().GetSize().x,
					gridLineThickness * ClientWindow::Get().GetSize().y
				};

				sf::Vector2f gridLinePosition = centerLinePosition + sf::Vector2f(
					0.f, gridLineOffset * lineIndex
				);

				gridLine->setFillColor(AcColors::TierColor[lineIndex]);
				gridLine->setSize(gridLineSize);
				gridLine->setOrigin(gridLineSize / 2.f);
				gridLine->setPosition(gridLinePosition);

			}
			else {
				sf::Vector2f gridLineSize = {
					gridLineWidth* ClientWindow::Get().GetSize().x,
					gridLineThickness* ClientWindow::Get().GetSize().y
				};

				sf::Vector2f gridLinePosition = centerLinePosition + sf::Vector2f(
					0.f, gridLineOffset * lineIndex
				);

				sf::Color gridLineColor = ColorManager::SetOpacity(AcColors::TierColor[lineIndex], 100);

				gridLine->setFillColor(gridLineColor);
				gridLine->setSize(gridLineSize);
				gridLine->setOrigin(gridLineSize / 2.f);
				gridLine->setPosition(gridLinePosition);

			}

			gridLines[lineIndex] = gridLine;

		}


		for (auto& scrollCircle : scrollCircles) {
				
			scrollCircle.setFillColor(scrollCircleDefaultColor);
			scrollCircle.setRadius(scrollCircleSize);
			scrollCircle.setOutlineThickness(scrollCircleOutlineSize);
			scrollCircle.setOutlineColor(scrollBarColor);
			scrollCircle.setOrigin(scrollCircle.getGlobalBounds().getSize() / 2.f);

		}

		scrollCircles[0].setPosition(gridLines.front()->getPosition());
		scrollCircles[1].setPosition(gridLines.back()->getPosition());

	}

}

