#include "QueryTable.Hxx"

namespace nk{
	
	void QueryTable::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		
		target.draw(resultSpriteBuffer, states);
		 
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
		
		for (auto& division : divisions) {
			division->UpdateBase(event);
		}

	}

	QueryTable::QueryTable(
		Ratio width,
		Ratio margin,
		const sf::Color& backgroundColor
	) : solvedManager() {
		
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

	}

	void QueryTable::AddDivision(QueryDivision* division) {
		divisions.push_back(division);
	}

}