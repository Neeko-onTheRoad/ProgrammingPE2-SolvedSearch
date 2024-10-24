#include "QueryTable.Hxx"

namespace nk{
	
	void QueryTable::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		
		target.draw(resultSpriteBuffer, states);
		target.draw(centerLine, states);
		 
	}

	void QueryTable::Rerender() {

		maskedTexture.clear(sf::Color::Transparent);
		maskedTexture.draw(background);


		resultSpriteBuffer.setTexture(maskedTexture.getTexture());
		resultSpriteBuffer.setTextureRect(sf::IntRect(
			0,
			ClientWindow::Get().GetRawSize().y,
			ClientWindow::Get().GetRawSize().x,
			-static_cast<int>(ClientWindow::Get().GetRawSize().y)
		));

	}

	void QueryTable::Update(const sf::Event& event) {
		
		for (auto& queryButton : queryButtons) {
			queryButton->UpdateBase(event);
		}

	}

	QueryTable::QueryTable(
		Ratio width,
		Ratio margin,
		Ratio centerLineThickness,
		Ratio centerLineMargin,
		const sf::Color& backgroundColor,
		const sf::Color& centerLineColor
	) {
		
		sf::Vector2f backgroundSize = {
			ClientWindow::Get().GetSize().x * width,
			ClientWindow::Get().GetSize().y * (1 - margin * 2)
		};

		float marginPosition = ClientWindow::Get().GetSize().y * margin;

		background.setSize(backgroundSize);
		background.setPosition(marginPosition, marginPosition + ClientWindow::Get().GetTitleBarOffset());
		background.setFillColor(backgroundColor);

		renderStates.blendMode = sf::BlendMode(
			sf::BlendMode::DstAlpha,
			sf::BlendMode::Zero,
			sf::BlendMode::Add
		);

		maskedTexture.create(ClientWindow::Get().GetRawSize().x, ClientWindow::Get().GetRawSize().y);
		
		sf::Vector2f centerLineSize = {
			centerLineThickness * ClientWindow::Get().GetSize().x,
			backgroundSize.y - ClientWindow::Get().GetSize().y * centerLineMargin * 2
		};

		sf::Vector2f centerLinePosition = {
			backgroundSize.x / 2 + background.getPosition().x,
			background.getPosition().y + ClientWindow::Get().GetSize().y * centerLineMargin
		};

		centerLine.setSize(centerLineSize);
		centerLine.setPosition(centerLinePosition);
		centerLine.setFillColor(centerLineColor);

	}

	void QueryTable::AddDivision(QueryDivision* division) {
		divisions.push_back(division);
	}

}