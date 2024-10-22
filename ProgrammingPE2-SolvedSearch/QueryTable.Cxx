#include "QueryTable.Hxx"

namespace nk{
	
	void QueryTable::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		
		target.draw(background, states);
		 
	}

	void QueryTable::Update(const sf::Event& event) {

		
	
	}

	QueryTable::QueryTable(
		Ratio width,
		Ratio margin,
		const sf::Color& backgroundColor
	) {
		
		sf::Vector2f backgroundSize = {
			ClientWindow::Get().GetSize().x * width,
			ClientWindow::Get().GetSize().y * (1 - margin * 2)
		};

		float marginPosition = ClientWindow::Get().GetSize().y * margin;

		background.setSize(backgroundSize);
		background.setPosition(marginPosition, marginPosition + ClientWindow::Get().GetTitleBarOffset());
		background.setFillColor(backgroundColor);

	}

}