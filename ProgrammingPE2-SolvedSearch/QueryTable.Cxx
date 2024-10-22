#include "QueryTable.Hxx"

namespace nk{
	
	void QueryTable::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		
		target.draw(background, states);
		
	}

	void QueryTable::Update(const sf::Event& event) {

	}

	QueryTable::QueryTable() {

	}

}