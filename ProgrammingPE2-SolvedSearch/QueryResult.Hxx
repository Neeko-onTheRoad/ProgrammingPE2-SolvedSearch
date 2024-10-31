#include <array>
#include "ClientObject.Hxx"
#include "QueryResultButton.Hxx"

namespace nk {

	class QueryResult : public ClientObject {

	private:
		sf::Vector2f position;
		sf::Vector2f size;

		std::array<QueryButton, 5> buttons;

	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void Update(const sf::Event&) override;

	public:
		QueryResult(
			sf::Vector2f position,
			sf::Vector2f size
		);

	};

}