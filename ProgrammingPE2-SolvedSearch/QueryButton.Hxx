#pragma once

#include "QueryTable.Hxx"

namespace nk {

	class QueryButton : public ClientObject {

	private:
		QueryTable* queryTable;

	protected:
		void Update(const sf::Event& event) override;
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	public:
		QueryButton();

	};

}