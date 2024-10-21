#include "TitleBar.Hxx"

namespace nk {

	void TitleBar::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		
		target.draw(background, states);
		target.draw(closeBackground, states);
		target.draw(minimizeBackground, states);
		target.draw(closeIcon, states);
		target.draw(minimizeIcon, states);

	}

	void TitleBar::SetCloseButtonHover(bool flag) {

		hoveringCloseButton = flag;
		
		ColorManager::SetOpacity(closeBackground, flag ? 255 : 0);
		closeIcon.setColor(flag ? iconHoverColor : iconColor);
	}

	void TitleBar::SetMinimizeButtonHover(bool flag) {

		hoveringMinimizeButton = flag;

		ColorManager::SetOpacity(minimizeBackground, flag ? 255 : 0);
		minimizeIcon.setColor(flag ? iconHoverColor : iconColor);
	}

	void TitleBar::UpdateMovement(const sf::Event& event) {

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

			if (hoveringCloseButton || hoveringMinimizeButton) return;

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

	void TitleBar::UpdateCloseButton(const sf::Event& event) {

		if (clickingCloseButton) {

			if (event.type == sf::Event::MouseMoved) {
				if (closeBackground.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y)) return;
				SetCloseButtonHover(false);
				clickingCloseButton = false;
				return;
			}
			if (event.type == sf::Event::MouseButtonReleased) {
				if (!closeBackground.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) return;
				ClientWindow::Get().Close();
				return;
			}

			return;

		}
		if (hoveringCloseButton) {

			if (event.type == sf::Event::MouseMoved) {
				if (closeBackground.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y)) return;
				SetCloseButtonHover(false);
				clickingCloseButton = false;
				return;
			}

			if (event.type == sf::Event::MouseButtonPressed) {
				if (!closeBackground.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) return;
				clickingCloseButton = true;
				return;
			}

			return;

		}

		if (event.type == sf::Event::MouseMoved) {

			if (!closeBackground.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y)) return;
			SetCloseButtonHover(true);

		}
		
	
	}

	void TitleBar::UpdateMinimizeButton(const sf::Event& event) {

		if (clickingMinimizeButton) {

			if (event.type == sf::Event::MouseMoved) {
				if (minimizeBackground.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y)) return;
				SetMinimizeButtonHover(false);
				clickingMinimizeButton = false;
				return;
			}
			if (event.type == sf::Event::MouseButtonReleased) {
				if (!minimizeBackground.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) return;
				ClientWindow::Get().Minimize();
				return;
			}

			return;

		}
		if (hoveringMinimizeButton) {

			if (event.type == sf::Event::MouseMoved) {
				if (minimizeBackground.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y)) return;
				SetMinimizeButtonHover(false);
				clickingMinimizeButton = false;
				return;
			}

			if (event.type == sf::Event::MouseButtonPressed) {
				if (!minimizeBackground.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) return;
				clickingMinimizeButton = true;
				return;
			}

			return;

		}

		if (event.type == sf::Event::MouseMoved) {

			if (!minimizeBackground.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y)) return;
			SetMinimizeButtonHover(true);

		}
	
	}

	void TitleBar::Update(const sf::Event& event) {

		UpdateCloseButton(event);
		UpdateMinimizeButton(event);
		UpdateMovement(event);

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

		this->iconColor = iconColor;
		this->iconHoverColor = iconHoverColor;
		
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

		sf::Vector2f minimizeButtonBackgroundPosition{
			ClientWindow::Get().GetSizeF().x * (1 - buttonWidth * 2),
			0.f
		};

		closeBackground.setPosition(closeBackgroundPosition);
		closeBackground.setSize(buttonBackgroundSize);
		closeBackground.setFillColor(iconHoverBackgroundColor);
		ColorManager::SetOpacity(closeBackground, 0);

		minimizeBackground.setPosition(minimizeButtonBackgroundPosition);
		minimizeBackground.setSize(buttonBackgroundSize);
		minimizeBackground.setFillColor(iconHoverBackgroundColor);
		ColorManager::SetOpacity(minimizeBackground, 0);

		closeIcon.setTexture(Icons::CloseButton);
		sf::FloatRect closeIconBound = closeIcon.getGlobalBounds();
		float closeIconScale = buttonBackgroundSize.y * iconSize / closeIconBound.height;
		closeIcon.setOrigin(closeIconBound.width / 2.f, closeIconBound.height / 2.f);
		closeIcon.setScale(closeIconScale, closeIconScale);
		closeIcon.setColor(AcColors::LightGray);
		closeIcon.setPosition(closeBackgroundPosition + buttonBackgroundSize / 2.f);

		minimizeIcon.setTexture(Icons::MinimizeButton);
		sf::FloatRect minimizeIconBound = minimizeIcon.getGlobalBounds();
		float minimizeIconScale = buttonBackgroundSize.y * iconSize / minimizeIconBound.height;
		minimizeIcon.setOrigin(minimizeIconBound.width / 2.f, minimizeIconBound.height / 2.f);
		minimizeIcon.setScale(minimizeIconScale, minimizeIconScale);
		minimizeIcon.setColor(AcColors::LightGray);
		minimizeIcon.setPosition(minimizeButtonBackgroundPosition + buttonBackgroundSize / 2.f);


	}


}