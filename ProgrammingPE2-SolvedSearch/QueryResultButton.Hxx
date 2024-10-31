#include "ClientObject.Hxx"

namespace nk {

	class QueryResultButton : public ClientObject {

	private:
		sf::RectangleShape background;
		sf::Text title;
		std::vector<sf::Text> tags; 

	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void Update(const sf::Event& event) override;

	public:
		QueryResultButton(
			std::string title,
			int tier,
			std::vector<std::string> tags,
			sf::Vector2f position,
			sf::Vector2f size,
			float outLineThickness
		);

	};

}