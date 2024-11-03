#include "TierSlide.Hxx"

namespace nk {

	void TierSlide::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(centerLine, states);


		for (auto& gridLine : gridLines) {
			target.draw(*gridLine, states);
		}

		target.draw(scrollBar, states);

		for (auto& scrollCircle : scrollCircles) {
			target.draw(scrollCircle, states);
		}
	}

	void TierSlide::Update(const sf::Event& event) {

		sf::Vector2f mousePosition = event.type == sf::Event::MouseMoved ? sf::Vector2f(
			static_cast<float>(event.mouseMove.x),
			static_cast<float>(event.mouseMove.y)
		) : sf::Vector2f(
			static_cast<float>(event.mouseButton.x),
			static_cast<float>(event.mouseButton.y)
		);

		for (int i = 0; i < 2; i++) {

			sf::CircleShape& circle = scrollCircles[i];

			bool& hovering = scrollHovering[i];
			bool& clicking = scrollClicking[i];

			int& scrollLevel = this->scrollLevel[i];

			bool mouseHovered = circle.getGlobalBounds().contains(mousePosition);

			if (clicking) {
				if (event.type == sf::Event::MouseMoved) {

					if (scrollLevel == 0) {

					}
					else if (scrollLevel == Icons::SolvedTierCount) {

					}
					else {

					}

					continue;
				}
				if (event.type == sf::Event::MouseButtonReleased) {
					if (mouseHovered) {
						circle.setFillColor(scrollCircleHoverColor);
						clicking = false;
					}
					else {
						circle.setFillColor(scrollCircleDefaultColor);
						clicking = false;
						hovering = false;
					}
					continue;
				}
			}
			if (hovering) {
				if (event.type == sf::Event::MouseMoved) {
					if (mouseHovered) continue;
					circle.setFillColor(scrollCircleDefaultColor);
					hovering = false;
					continue;
				}
				if (event.type == sf::Event::MouseButtonPressed) {
					clicking = true;
					circle.setFillColor(scrollCircleClickColor);
				}
			}
			if (event.type == sf::Event::MouseMoved) {
				if (!mouseHovered) continue;
				circle.setFillColor(scrollCircleHoverColor);
				hovering = true;
				continue;
			}
		}
	}

	void TierSlide::UpdateScrollBar() {

		float circle1YPosition = scrollCircles[0].getPosition().y;
		float circle2YPosition = scrollCircles[1].getPosition().y;

		sf::CircleShape& topCircle = scrollCircles[0];
		sf::CircleShape& bottomCircle = scrollCircles[1];

		if (circle1YPosition > circle2YPosition) {
			topCircle = scrollCircles[1];
			bottomCircle = scrollCircles[0];
		}

		sf::Vector2f scrollBarPosition = topCircle.getPosition();
		sf::Vector2f scrollBarSize = {
			scrollBarThickness * ClientWindow::Get().GetSize().x,
			bottomCircle.getPosition().y - topCircle.getPosition().y
		};

		scrollBar.setSize(scrollBarSize);
		scrollBar.setOrigin(scrollBarSize.x / 2.f, 0.f);
		scrollBar.setPosition(scrollBarPosition);

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
		
		this->scrollCircleDefaultColor = scrollCircleDefaultColor;
		this->scrollCircleHoverColor = scrollCircleHoverColor;
		this->scrollCircleClickColor = scrollCircleClickColor;
		this->scrollBarThickness = scrollBarThickness;

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
			scrollCircle.setOrigin(scrollCircleSize, scrollCircleSize);

		}

		scrollCircles[0].setPosition(gridLines.front()->getPosition());
		scrollCircles[1].setPosition(gridLines.back()->getPosition());

		scrollLevel[0] = 0;
		scrollLevel[1] = Icons::SolvedTierCount - 1;

		scrollBar.setFillColor(scrollBarColor);
		UpdateScrollBar();

	}

}

