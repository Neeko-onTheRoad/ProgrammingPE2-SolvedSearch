#include "QueryTagButton.Hxx"

namespace nk {

	sf::Color QueryTagButton::backgroundColor;
	sf::Color QueryTagButton::foregroundColor;
	sf::Color QueryTagButton::hoverBackgroundColor;
	sf::Color QueryTagButton::hoverForegroundColor;
	sf::Color QueryTagButton::clickBackgroundColor;
	sf::Color QueryTagButton::clickForegroundColor;
	float QueryTagButton::textMarginLeft;
	unsigned QueryTagButton::textSize;
	sf::Vector2f QueryTagButton::size;

	void QueryTagButton::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(background, states);
		target.draw(name, states);
	}

	void QueryTagButton::Update(const sf::Event& event) { 
	
		

	}

	QueryTagButton::QueryTagButton(std::wstring name, std::string target, sf::Vector2f position) {
		
		this->target = target;

		background.setFillColor(backgroundColor);
		background.setSize(size);

		this->name.setString(name);
		this->name.setFont(Fonts::NanumSquareRound::Bold);
		this->name.setCharacterSize(textSize);
		this->name.setFillColor(foregroundColor);

		SetPosition(position);
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
		return background.getPosition();
	}

	void QueryTagButton::SetPosition(sf::Vector2f position) {
		background.setPosition(position);

		sf::Vector2f textPositionDelta = {
			textMarginLeft * ClientWindow::Get().GetSize().x,
			size.y / 2 - this->name.getGlobalBounds().height / 1.5f
		};
		this->name.setPosition(textPositionDelta + position);
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