#include "QueryTagButton.Hxx"
#include <iostream>

namespace nk {

	sf::Color QueryTagButton::backgroundColor;
	sf::Color QueryTagButton::foregroundColor;
	sf::Color QueryTagButton::hoverBackgroundColor;
	sf::Color QueryTagButton::hoverForegroundColor;
	sf::Color QueryTagButton::clickBackgroundColor;
	sf::Color QueryTagButton::clickForegroundColor;
	sf::Color QueryTagButton::activatedBackgroundColor;
	sf::Color QueryTagButton::activatedForegroundColor;
	float QueryTagButton::textMarginLeft;
	unsigned QueryTagButton::textSize;
	sf::Vector2f QueryTagButton::size;

	void QueryTagButton::SetVisualDefault() {
		background.setFillColor(backgroundColor);
		name.setFillColor(foregroundColor);
		isNeedRerender = true;
	}

	void QueryTagButton::SetVisualHover() {
		background.setFillColor(hoverBackgroundColor);
		name.setFillColor(hoverForegroundColor);
		isNeedRerender = true;
	}

	void QueryTagButton::SetVisualClick() {
		background.setFillColor(clickBackgroundColor);
		name.setFillColor(clickForegroundColor);
		isNeedRerender = true;
	}

	void QueryTagButton::SetVisualActivated() {
		background.setFillColor(activatedBackgroundColor);
		name.setFillColor(activatedForegroundColor);
		isNeedRerender = true;
	}

	void QueryTagButton::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(renderSprite, states);
	}

	void QueryTagButton::Rerender() {
		
		renderTexture.draw(background);
		renderTexture.draw(name);

		renderSprite.setTexture(renderTexture.getTexture());
		renderSprite.setTextureRect(sf::IntRect(0, size.y, size.x, -size.y));
		renderSprite.setPosition(position);

	}

	void QueryTagButton::Update(const sf::Event& event) { 

		float mouseXPos;
		float mouseYPos;

		if (event.type == sf::Event::MouseWheelScrolled) {
			mouseXPos = static_cast<float>(event.mouseWheelScroll.x);
			mouseYPos = static_cast<float>(event.mouseWheelScroll.y);
		}
		else if (event.type == sf::Event::MouseMoved) {
			mouseXPos = static_cast<float>(event.mouseMove.x);
			mouseYPos = static_cast<float>(event.mouseMove.y);
		}
		else {
			mouseXPos = static_cast<float>(event.mouseButton.x);
			mouseYPos = static_cast<float>(event.mouseButton.y);
		}

		isNeedRerender = true;

		bool cursorHovering = renderSprite
			.getGlobalBounds()
			.contains(
				mouseXPos,
				mouseYPos
			);

		if (hovering) {
			bool mouseMoved =
				event.type == sf::Event::MouseMoved ||
				event.type == sf::Event::MouseWheelScrolled;


			if (mouseMoved && !cursorHovering) {
				if (isButtonActivated) {
					SetVisualDefault();
				}
				else {
					SetVisualActivated();
				}
				hovering = false;
				clicking = false;
			}
		}
		if (clicking) {
			if (event.type != sf::Event::MouseButtonReleased) return;
			if (!cursorHovering) return;

			isButtonActivated = !isButtonActivated;
			if (isButtonActivated) {
				SetVisualDefault();
			}
			else {
				SetVisualActivated();
			}
			clicking = false;
		}
		else if (hovering) {
			if (event.type != sf::Event::MouseButtonPressed) return;
			if (!cursorHovering) return;

			if (isButtonActivated) {
				SetVisualClick();
			}
			else {
				SetVisualHover();
			}
			clicking = true;
		}
		else {
			bool mouseMoved =
				event.type == sf::Event::MouseMoved ||
				event.type == sf::Event::MouseWheelScrolled;

			if (!mouseMoved) return;
			if (!cursorHovering) return;

			if (isButtonActivated) {
				SetVisualHover();
			}
			else {
				SetVisualClick();
			}
			hovering = true;
		}

	}

	QueryTagButton::QueryTagButton(std::wstring name, std::string target, sf::Vector2f position) {
		
		this->target = target;

		background.setFillColor(backgroundColor);
		background.setSize(size);

		this->name.setString(name);
		this->name.setFont(Fonts::NanumSquareRound::Bold);
		this->name.setCharacterSize(textSize);
		this->name.setFillColor(foregroundColor);

		this->position = position;

		sf::Vector2f textPositionDelta = {
			textMarginLeft * ClientWindow::Get().GetSize().x,
			size.y / 2 - this->name.getGlobalBounds().height / 1.5f
		};

		this->name.setPosition(textPositionDelta);

		renderTexture.create(size.x, size.y);
	}

	bool QueryTagButton::IsButtonActivated() const {
		return isButtonActivated;
	}

	std::string QueryTagButton::GetTarget() const {
		return target;
	}

	std::string QueryTagButton::GetName() const {
		return name.getString();
	}

	sf::Vector2f QueryTagButton::GetPosition() const {
		return renderSprite.getPosition();
	}

	void QueryTagButton::SetPosition(sf::Vector2f position) {
		this->position = position;
	}

	void QueryTagButton::AddPosition(sf::Vector2f delta) {
		SetPosition(GetPosition() + delta);
	}

	void QueryTagButton::SetBackgroundColor(const sf::Color& color) {
		backgroundColor = color;
	}

	void QueryTagButton::SetForegroundColor(const sf::Color& color) {
		foregroundColor = color;
	}

	void QueryTagButton::SetHoverBackgroundColor(const sf::Color& color) {
		hoverBackgroundColor = color;
	}

	void QueryTagButton::SetHoverForegroundColor(const sf::Color& color) {
		hoverForegroundColor = color;
	}

	void QueryTagButton::SetClickBackgroundColor(const sf::Color& color) {
		clickBackgroundColor = color;
	}

	void QueryTagButton::SetClickForegroundColor(const sf::Color& color) {
		clickForegroundColor = color;
	}

	void QueryTagButton::SetActivatedBackgroundColor(const sf::Color& color) {
		activatedBackgroundColor = color;
	}

	void QueryTagButton::SetActivatedForegroundColor(const sf::Color& color) {
		activatedForegroundColor = color;
	}

	void QueryTagButton::SetTextMarginLeft(float margin) {
		textMarginLeft = margin;
	}

	void QueryTagButton::SetTextSize(unsigned size) {
		textSize = size;
	}

	void QueryTagButton::SetSize(sf::Vector2f size) {
		QueryTagButton::size = size;
	}

	sf::Vector2f QueryTagButton::GetSize() {
		return size;
	}

}