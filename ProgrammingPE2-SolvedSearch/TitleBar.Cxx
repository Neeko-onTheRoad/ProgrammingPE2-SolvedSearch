#include "TitleBar.Hxx"

namespace nk {

	void TitleBar::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		
		target.draw(background, states);
		target.draw(closeBackground, states);
		target.draw(minimalizeBackground, states);
		target.draw(closeIcon, states);
		target.draw(minimalizeIcon, states);

	}

	void TitleBar::Update(const sf::Event& event) {

		if (isWindowMoveing) {

			if (event.type == sf::Event::MouseButtonReleased) {

				isWindowMoveing = false;

				if (ClientWindow::Get().GetPosition().y < 0) {
					ClientWindow::Get().SetPosition(ClientWindow::Get().GetPosition().x, 0);
				}

			}
			else if (event.type == sf::Event::MouseMoved) {
				ClientWindow::Get().SetPosition(sf::Mouse::getPosition() - windowMoveingMouseOffset);
			}
			
		}
		else {

			if (event.type != sf::Event::MouseButtonPressed) return;
			if (!background.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) return;
			if (event.mouseButton.button != sf::Mouse::Button::Left) return;

			windowMoveingMouseOffset = {
				event.mouseButton.x,
				event.mouseButton.y
			};

			isWindowMoveing = true;

		}

	}

	TitleBar::TitleBar(
		float height,
		float buttonWidth,
		float iconSize,
		const sf::Color& backgroundColor,
		const sf::Color& iconColor,
		const sf::Color& iconHoverColor,
		const sf::Color& iconHoverBackgroundColor
	) {
		
		sf::Vector2f backgroundSize {
			ClientWindow::Get().GetSizeF().x,
			ClientWindow::Get().GetSizeF().y * height
		};

		background.setPosition(0.f, 0.f);
		background.setSize(backgroundSize);
		background.setFillColor(backgroundColor);

		sf::Vector2f buttonBackgroundSize {
			ClientWindow::Get().GetSizeF().x * buttonWidth,
			ClientWindow::Get().GetSizeF().y * height
		};

		sf::Vector2f closeBackgroundPosition {
			ClientWindow::Get().GetSizeF().x * (1 - buttonWidth),
			0.f
		};

		sf::Vector2f minimalizeButtonBackgroundPosition{
			ClientWindow::Get().GetSizeF().x * (1 - buttonWidth * 2),
			0.f
		};

		closeBackground.setPosition(closeBackgroundPosition);
		closeBackground.setSize(buttonBackgroundSize);
		closeBackground.setFillColor(iconHoverBackgroundColor);
		minimalizeBackground.setPosition(minimalizeButtonBackgroundPosition);
		minimalizeBackground.setSize(buttonBackgroundSize);
		minimalizeBackground.setFillColor(iconHoverBackgroundColor);

	}


}