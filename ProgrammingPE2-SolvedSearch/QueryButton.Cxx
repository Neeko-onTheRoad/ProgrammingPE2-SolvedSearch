#include "QueryButton.Hxx"

namespace nk {

	void QueryButton::Update(const sf::Event& event) {

		

	}

	void QueryButton::draw(sf::RenderTarget& target, sf::RenderStates states) const {

		target.draw(background, states);
		target.draw(name, states);

	}

	QueryButton::QueryButton(
		QueryTable* queryTable,
		sf::Vector2f size,
		float yPos,
		float outlineThickness,
		unsigned fontSize,
		sf::Color backgroundColor,
		sf::Color foregroundColor,
		sf::Color hoverBackgroundColor,
		sf::Color hoverForegroundColor,
		sf::Color clickBackgroundColor,
		sf::Color clickForegroundColor
	) {

		this->backgroundColor = backgroundColor;
		this->foregroundColor = foregroundColor;
		this->hoverBackgroundColor = hoverBackgroundColor;
		this->hoverForegroundColor = hoverForegroundColor;
		this->clickBackgroundColor = clickBackgroundColor;
		this->clickForegroundColor = clickForegroundColor;

		this->queryTable = queryTable;

		sf::Vector2f position = queryTable->GetPosition() + sf::Vector2f(
			queryTable->GetSize().x / 4,
			queryTable->GetSize().y * yPos
		);

		sf::Vector2f newSize = {
			queryTable->GetSize().x * size.x,
			queryTable->GetSize().y * size.y
		};

		background.setSize(newSize);
		background.setOrigin(background.getSize() / 2.f);
		background.setPosition(position);
		background.setFillColor(backgroundColor);
		background.setOutlineColor(foregroundColor);
		background.setOutlineThickness(outlineThickness);

		name.setFont(Fonts::NanumSquareRound::ExtraBold);
		name.setString(L"°Ë»ö");
		name.setCharacterSize(fontSize);
		name.setOrigin(name.getGlobalBounds().width / 2.f, name.getGlobalBounds().height / 2.f);
		name.setPosition(position.x, position.y - ClientWindow::Get().GetSize().y * 0.0025f);
		name.setFillColor(foregroundColor);

	}
}