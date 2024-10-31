#include "QueryResult.Hxx"

namespace nk {

	void QueryResult::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	}

	void QueryResult::Update(const sf::Event&) { }

	QueryResult::QueryResult(
		sf::Vector2f position,
		sf::Vector2f size
	) {
		
		this->position = position;
		this->size = size;

		

	}
}