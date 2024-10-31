#include "QueryResult.Hxx"

namespace nk {

	void QueryResult::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		
		for (auto& button : buttons) {
			target.draw(*button, states);
		}

	}

	void QueryResult::Update(const sf::Event& event) {
	
		for (auto& button : buttons) {
			button->UpdateBase(event);
		}

	}

	QueryResult::QueryResult(
		SolvedAcManager& solvedManager,
		sf::Vector2f position,
		sf::Vector2f size,
		unsigned buttonCount,
		float buttonMargin
	) : solvedManager(solvedManager) {

		this->position = position;
		this->size = size;
		this->buttonCount = buttonCount;
		this->buttonMargin = buttonMargin;

		sf::Vector2f resultButtonSize = {
			size.x,
			size.y / buttonCount - (buttonMargin * ClientWindow::Get().GetSize().y * (buttonCount - 1)) / buttonCount
		};

		QueryResultButton::SetBackgroundColor(AcColors::DarkerGray);
		QueryResultButton::SetHoverBackgroundColor(AcColors::LightGray);
		QueryResultButton::SetClickBackgroundColor(AcColors::Hilight);
		QueryResultButton::SetForegroundColor(AcColors::White);
		QueryResultButton::SetSize(resultButtonSize);
		QueryResultButton::SetXPosition(position.x);
		QueryResultButton::SetTextSize(25u);
		QueryResultButton::SetTextMargin(0.02f);
		QueryResultButton::SetTierSize(25.f);

	}

	void QueryResult::SetButton(const std::vector<Problem*>& problems) {
	
		for (const auto& button : buttons) {
			delete button;
		}

		buttons.clear();

		size_t maxVal = problems.size() > 5ull ? 5ull : problems.size();

		for (int i = 0; i < maxVal; i++) {
			const Problem* const& problem = problems.at(i);

			float yPosition = 
				position.y +
				(QueryResultButton::GetHeigh() + buttonMargin * ClientWindow::Get().GetSize().y) * i;

			QueryResultButton* newButton = new QueryResultButton(
				solvedManager,
				problem->GetTitle(),
				problem->GetId(),
				problem->GetTier(),
				problem->GetTags(),
				yPosition
			);

			buttons.push_back(newButton);
		}

	}
}