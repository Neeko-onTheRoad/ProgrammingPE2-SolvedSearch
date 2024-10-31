#include "QueryResultButton.Hxx"

namespace nk {

	sf::Color QueryResultButton::backgroundColor;
	sf::Color QueryResultButton::hoverBackgroundColor;
	sf::Color QueryResultButton::clickBackgroundColor;
	sf::Color QueryResultButton::foregroundColor;
	sf::Vector2f QueryResultButton::size;
	float QueryResultButton::xPosition;
	float QueryResultButton::textMargin;
	unsigned QueryResultButton::textSize;

	void QueryResultButton::SetVisualDefault() {
		background.setFillColor(backgroundColor);
	}

	void QueryResultButton::SetVisualHover() {
		background.setFillColor(hoverBackgroundColor);
	}

	void QueryResultButton::SetVisualClick() {
		background.setFillColor(clickBackgroundColor);
	}

	void QueryResultButton::OpenWeb() const {
		std::string	url = "explorer https://noj.am/" + std::to_string(id);
		system(url.c_str());
	}

	void QueryResultButton::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(background, states);
		target.draw(name, states);
		target.draw(tier, states);
	}

	void QueryResultButton::Update(const sf::Event& event) {
		
		bool cursorHovering = background
			.getGlobalBounds()
			.contains(
				static_cast<float>(event.mouseMove.x),
				static_cast<float>(event.mouseMove.y)
			);

		if (hovering) {
			bool mouseMoved = event.type == sf::Event::MouseMoved;

			if (mouseMoved && !cursorHovering) {
				SetVisualDefault();
				hovering = false;
				clicking = false;
			}
		}
		if (clicking) {
			if (event.type != sf::Event::MouseButtonReleased) return;

			SetVisualDefault();
			OpenWeb();
			clicking = false;
		}
		else if (hovering) {
			if (event.type != sf::Event::MouseButtonPressed) return;

			SetVisualClick();
			clicking = true;
		}
		else {
			if (event.type != sf::Event::MouseMoved) return;
			if (!cursorHovering) return;

			SetVisualHover();
			hovering = true;
		}

	}

    QueryResultButton::QueryResultButton(
		SolvedAcManager& solvedManager,
		std::wstring title,
		int id,
		int tier,
		std::vector<std::string> tags,
		float yPosition
	) : solvedManager(solvedManager) {

		this->id = id;
		
		sf::Vector2f backgroundPosition = {
			xPosition,
			yPosition
		};

		background.setFillColor(backgroundColor);
		background.setSize(size);
		background.setPosition(backgroundPosition);

		sf::Vector2f namePosition = backgroundPosition + sf::Vector2f(
			textMargin * ClientWindow::Get().GetSize().x,
			textMargin * ClientWindow::Get().GetSize().x
		);

		name.setFillColor(foregroundColor);
		name.setCharacterSize(textSize);
		name.setString(title + L"  ");
		name.setPosition(namePosition);
		name.setFont(Fonts::NanumSquareRound::Bold);

		sf::Vector2f tierPosition = {
			name.getGlobalBounds().getPosition().x + name.getGlobalBounds().getSize().x,
			name.getGlobalBounds().top
		};

		this->tier.setTexture(Icons::GetSolvedTier(tier));

		float tierScale = name.getGlobalBounds().height / this->tier.getGlobalBounds().height;
		tierScale *= 1.1f;

		this->tier.setScale(tierScale, tierScale);
		this->tier.setPosition(tierPosition);

	}

	sf::Vector2f QueryResultButton::GetSize() const {
		return background.getSize();
	}

	float QueryResultButton::GetHeigh() {
		return size.y;
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

	void QueryResultButton::SetTextMargin(float margin) {
		textMargin = margin;
	}

	void QueryResultButton::SetTextSize(unsigned size) {
		textSize = size;
	}

}