#include "QueryResultButton.Hxx"

namespace nk {

	sf::Color QueryResultButton::backgroundColor;
	sf::Color QueryResultButton::hoverBackgroundColor;
	sf::Color QueryResultButton::clickBackgroundColor;
	sf::Color QueryResultButton::foregroundColor;
	sf::Color QueryResultButton::tagColor;
	sf::Color QueryResultButton::tagHoverColor;
	sf::Vector2f QueryResultButton::size;
	float QueryResultButton::xPosition;
	float QueryResultButton::textMargin;
	unsigned QueryResultButton::textSize;
	float QueryResultButton::tierSize;
	unsigned QueryResultButton::tagTextSize;

	void QueryResultButton::SetVisualDefault() {
		background.setFillColor(backgroundColor);
		infoText.setFillColor(tagColor);
		for (auto& tagText : tagTexts) {
			tagText->setFillColor(tagColor);
		}
	}

	void QueryResultButton::SetVisualHover() {
		background.setFillColor(hoverBackgroundColor);
		infoText.setFillColor(tagHoverColor);
		for (auto& tagText : tagTexts) {
			tagText->setFillColor(tagHoverColor);
		}
	}

	void QueryResultButton::SetVisualClick() {
		background.setFillColor(clickBackgroundColor);
		infoText.setFillColor(tagHoverColor);
		for (auto& tagText : tagTexts) {
			tagText->setFillColor(tagHoverColor);
		}
	}

	void QueryResultButton::OpenWeb() const {
		std::string	cmd = "explorer https://noj.am/" + std::to_string(id);
		system(cmd.c_str());
	}

	void QueryResultButton::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(background, states);
		target.draw(name, states);
		target.draw(tier, states);
		target.draw(infoText, states);

		for (auto& tagBackground : tagBackgrounds) {
			target.draw(*tagBackground, states);
		}
		for (auto& tagText : tagTexts) {
			target.draw(*tagText, states);
		}
	}

	void QueryResultButton::Update(const sf::Event& event) {
		
		if (event.type == sf::Event::MouseLeft) {
			SetVisualDefault();
			return;
		}

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

	QueryResultButton::~QueryResultButton() {
	
		for (auto& tag : tagTexts) {
			delete tag;
		}

		for (auto& tagBackground : tagBackgrounds) {
			delete tagBackground;
		}

	}

	QueryResultButton::QueryResultButton(
		SolvedAcManager& solvedManager,
		std::wstring title,
		int id,
		int tier,
		std::vector<std::string> tags,
		float yPosition,
		float averageTries,
		int acceptedUserCount
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

		float tierScale = tierSize / this->tier.getGlobalBounds().height;

		this->tier.setScale(tierScale, tierScale);
		this->tier.setPosition(tierPosition);

		sf::Vector2f infoTextPosition = {
			this->tier.getPosition().x + this->tier.getGlobalBounds().width * 2.5f,
			tierPosition.y
		};

		std::wostringstream infoTextString;

		infoTextString << L"평균시도 횟수 ";
		infoTextString << std::fixed;
		infoTextString.precision(2);
		infoTextString << averageTries;
		infoTextString << L"회  |  정답자 ";
		infoTextString << acceptedUserCount;
		infoTextString << L"명";

		infoText.setString(infoTextString.str());
		infoText.setCharacterSize(tagTextSize - 2);
		infoText.setFillColor(tagColor);
		infoText.setPosition(infoTextPosition);
		infoText.setFont(Fonts::NanumSquareRound::Bold);
		infoText.setOrigin(infoText.getGlobalBounds().height, 0.f);

		float prevTagXPosition = 0.f;

		for (auto& tag : tags) {
			
			sf::Text* tagText = new sf::Text;

			sf::Vector2f tagButtonPosition = backgroundPosition + sf::Vector2f(
				textMargin * ClientWindow::Get().GetSize().x + prevTagXPosition,
				-textMargin * ClientWindow::Get().GetSize().x + background.getSize().y
			);

			tagText->setFillColor(tagColor);
			tagText->setCharacterSize(tagTextSize);
			tagText->setFont(Fonts::NanumSquareRound::Bold);
			tagText->setString(L"#" + LocaleManager::Utf8ToWString(solvedManager.GetTagNameByKey(tag)));
			tagText->setOrigin(0.f, tagText->getGlobalBounds().height);
			tagText->setPosition(tagButtonPosition);

			float tagRight =
				tagText->getPosition().x + 
				tagText->getGlobalBounds().width;

			float backgroundRight = 
				background.getPosition().x +
				background.getSize().x -
				textMargin * ClientWindow::Get().GetSize().y;

			if (tagRight >= backgroundRight) {
				delete tagText;
				break;
			}

			prevTagXPosition +=
				tagText->getGlobalBounds().width +
				textMargin * ClientWindow::Get().GetSize().x;

			tagTexts.push_back(tagText);

		}

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

	void QueryResultButton::SetTagColor(const sf::Color& color) {
		tagColor = color;
	}

	void QueryResultButton::SetTagHoverColor(const sf::Color& color) {
		tagHoverColor = color;
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

	void QueryResultButton::SetTierSize(float size) {
		tierSize = size;
	}

	void QueryResultButton::SetTagTextSize(unsigned size) {
		tagTextSize = size;
	}

}