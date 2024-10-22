#pragma once

#include "ClientObject.Hxx"

namespace nk {

	class QueryTable : public ClientObject {

	private:
		sf::RectangleShape background;

	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void Update(const sf::Event& event) override;

	public:
		QueryTable();

	};

}