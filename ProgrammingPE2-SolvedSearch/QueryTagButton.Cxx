#include "QueryTagButton.Hxx"

namespace nk {

	void QueryTagButton::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(background, states);
		target.draw(name, states);
	}

	void QueryTagButton::Update(const sf::Event& event) { 
	
	}

	QueryTagButton::QueryTagButton(std::string target, sf::Vector2f position) {
		
		background.setFillColor(backgroundColor);
		background.setSize(size);
		background.setPosition(position);


		name.setString(target);
		name.setFont(Fonts::NanumSquareRound::Bold);
		name.setCharacterSize(textSize);
		name.setColor(foregroundColor);

		sf::Vector2f textPositionDelta = {
			ClientWindow::Get().GetSize().x * textMarginLeft,
			size.y / 2 - name.getGlobalBounds().height / 2
		};
		name.setPosition(textPositionDelta + position);
	
	}

	bool QueryTagButton::IsActivated() const {
		return isActivated;
	}

	std::string QueryTagButton::GetTarget() const {
		return name.getString();
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

	void QueryTagButton::SetHeight(Ratio height) {
		QueryTagButton::height = height;
	}

	void QueryTagButton::SetTextMarginLeft(Ratio margin) {
		textMarginLeft = margin;
	}

	void QueryTagButton::SetTextSize(unsigned size) {
		textSize = size;
	}

	void QueryTagButton::SetSize(sf::Vector2f size) {
		size = size;
	}

}