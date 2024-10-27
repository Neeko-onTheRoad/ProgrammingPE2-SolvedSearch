#include "TitleBar.Hxx"

namespace nk {

	void TitleBar::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		
		target.draw(background, states);
		target.draw(closeBackground, states);
		target.draw(minimizeBackground, states);
		target.draw(closeIcon, states);
		target.draw(minimizeIcon, states);

	}

	void TitleBar::SetButtonHover(bool flag, sf::RectangleShape& background, sf::Sprite& icon) const {
		ColorManager::SetOpacity(background, flag ? 255 : 0);
		icon.setColor(flag ? iconHoverColor : iconColor);
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

	void TitleBar::UpdateButton(
		const sf::Event& event,
		sf::RectangleShape& background,
		sf::Sprite& icon,
		bool& hovering,
		bool& clicking, 
		void (*callback)()
	) {

		bool cursorHovering = background
			.getGlobalBounds()
			.contains(
				static_cast<float>(event.mouseMove.x),
				static_cast<float>(event.mouseMove.y)
			);

		if (hovering) {
			bool mouseMoved = event.type == sf::Event::MouseMoved;

			if (mouseMoved && !cursorHovering) {
				SetButtonHover(false, background, icon);
				hovering = false;
				clicking = false;
			}
		}
		if (clicking) {
			if (event.type != sf::Event::MouseButtonReleased) return;
			if (cursorHovering) return;

			callback();
			clicking = false;
		}
		else if (hovering) {
			if (event.type != sf::Event::MouseButtonPressed) return;
			if (cursorHovering) return;

			clicking = true;
		}
		else {
			if (event.type != sf::Event::MouseMoved) return;
			if (!cursorHovering) return;

			SetButtonHover(true, background, icon);
			hovering = true;
		}
	}

	void TitleBar::Update(const sf::Event& event) {

		UpdateButton(
			event,
			closeBackground,
			closeIcon,
			hoveringCloseButton,
			clickingCloseButton,
			[]() { ClientWindow::Get().Close(); }
		);
		UpdateButton(
			event,
			minimizeBackground,
			minimizeIcon,
			hoveringMinimizeButton,
			clickingMinimizeButton,
			[]() { ClientWindow::Get().Minimize(); }
		);
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
			ClientWindow::Get().GetRawSizeF().x,
			ClientWindow::Get().GetRawSizeF().y * height
		};

		background.setPosition(0.f, 0.f);
		background.setSize(backgroundSize);
		background.setFillColor(backgroundColor);

		sf::Vector2f buttonBackgroundSize {
			ClientWindow::Get().GetRawSizeF().x * buttonWidth,
			ClientWindow::Get().GetRawSizeF().y * height
		};

		sf::Vector2f closeBackgroundPosition {
			ClientWindow::Get().GetRawSizeF().x * (1 - buttonWidth),
			0.f
		};

		sf::Vector2f minimizeButtonBackgroundPosition{
			ClientWindow::Get().GetRawSizeF().x * (1 - buttonWidth * 2),
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

	float TitleBar::GetHeight() {
		return background.getSize().y;
	}


}