#pragma once

#define NOMINMAX

#include <vector>
#include "Problem.Hxx"
#include "AcColors.Hxx"
#include "ClientObject.Hxx"
#include "ClientWindow.Hxx"
#include "nlohmann/json.hpp"
#include "QueryResultButton.Hxx"

namespace nk {

	class QueryResultButton;

	class QueryResult : public ClientObject {

	private:
		unsigned buttonCount;
		float buttonMargin;

		sf::Vector2f position;
		sf::Vector2f size;

		std::vector<QueryResultButton*> buttons;

		SolvedAcManager& solvedManager;

	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void Update(const sf::Event& event) override;

	public:
		QueryResult(
			SolvedAcManager& solvedManager,
			sf::Vector2f position,
			sf::Vector2f size,
			unsigned buttonCount,
			float buttonMargin
			);

		void SetButton(const std::vector<Problem*>& problems);

	};

}