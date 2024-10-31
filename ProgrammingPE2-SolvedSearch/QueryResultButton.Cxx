#include "QueryResultButton.Hxx"

namespace nk {

	sf::Color QueryResultButton::backgroundColor;
	sf::Color QueryResultButton::hoverBackgroundColor;
	sf::Color QueryResultButton::clickBackgroundColor;
	sf::Color QueryResultButton::foregroundColor;
	sf::Vector2f QueryResultButton::size;
	float QueryResultButton::xPosition;

	void QueryResultButton::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	}

	void QueryResultButton::Update(const sf::Event& event) {
	}

    QueryResultButton::QueryResultButton(
		SolvedAcManager& solvedManager,
		std::string title,
		int tier,
		std::vector<std::string> tags,
		float yPosition
	) : solvedManager(solvedManager) {
		
		sf::Vector2f backgroundPosition = {
			xPosition,
			yPosition
		};

		background.setFillColor(backgroundColor);
		background.setSize(size);
		background.setPosition(backgroundPosition);

	}

	sf::Vector2f QueryResultButton::GetPosition() const {
		return background.getPosition();
	}

	void QueryResultButton::SetBackgroundColor(const sf::Color& color) {
		backgroundColor = color;
	}

	void QueryResultButton::SetHoverBackgroundColor(const sf::Color& color) {
		hoverBackgroundColor = color;
	}

	void QueryResultButton::SetClickBackgroundColor(const sf::Color& color) {
		clickBackgroundColor = color;
	}

	void QueryResultButton::SetForegroundColor(const sf::Color& color) {
		foregroundColor = color;
	}

	void QueryResultButton::SetSize(sf::Vector2f size) {
		QueryResultButton::size = size;
	}

	void QueryResultButton::SetXPosition(float xPosition) {
		QueryResultButton::xPosition = xPosition;
	}

}