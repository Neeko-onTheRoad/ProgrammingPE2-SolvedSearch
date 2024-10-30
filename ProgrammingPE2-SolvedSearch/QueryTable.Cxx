
#include "QueryTable.Hxx"

namespace nk{
	
	void QueryTable::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		
		target.draw(resultSpriteBuffer, states);
		target.draw(centerLine, states);
		target.draw(buttonLine, states);
	}

	void QueryTable::Rerender() {

		maskedTexture.clear(sf::Color::Transparent);
		maskedTexture.draw(background);

		for (auto& queryButton : queryButtons) {
			queryButton->DrawBase(maskedTexture, renderStates);
		}

		resultSpriteBuffer.setTexture(maskedTexture.getTexture());
		resultSpriteBuffer.setTextureRect(sf::IntRect(
			0,
			ClientWindow::Get().GetRawSize().y,
			ClientWindow::Get().GetRawSize().x,
			-static_cast<int>(ClientWindow::Get().GetRawSize().y)
		));

	}

	void QueryTable::Update(const sf::Event& event) {

		if (event.type == sf::Event::MouseWheelScrolled) {
			
			float newScroll = scroll + 100 * event.mouseWheelScroll.delta;

			if (newScroll > 0.f) newScroll = 0.f;
			else {
				
				float bottom = background.getPosition().y + background.getSize().y;
				float nowBottom =
					queryButtons.back()->GetPosition().y +
					QueryTagButton::GetSize().y;

				if (bottom - newScroll + scroll > nowBottom) {
					float newScrollTemp =
						background.getSize().y -
						QueryTagButton::GetSize().y * queryButtons.size();

					newScroll = newScrollTemp;
				}

			}

			if (scroll != newScroll) {
				scroll = newScroll;

				for (int i = 0; i < queryButtons.size(); i++) {
					QueryTagButton* queryButton = queryButtons[i];
				
					sf::Vector2f position = queryButtonOrigin + sf::Vector2(
						0.f, QueryTagButton::GetSize().y * i + scroll
					);

					queryButton->SetPosition(position);
				}

				isNeedRerender = true;
			}
		}

		for (auto& queryButton : queryButtons) {
			queryButton->UpdateBase(event);
			if (queryButton->IsNeedRerender()) {
				isNeedRerender = true;
			}
		}

	}

	QueryTable::QueryTable(
		float width,
		float margin,
		float centerLineThickness,
		float centerLineMargin,
		float buttonLineMargin,
		float buttonLineBottomMargin,
		const sf::Color& backgroundColor,
		const sf::Color& centerLineColor
	) {
		
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

		maskedTexture.create(
			ClientWindow::Get().GetRawSize().x,
			ClientWindow::Get().GetRawSize().y
		);
		
		sf::Vector2f centerLineSize = {
			centerLineThickness * ClientWindow::Get().GetSize().x,
			backgroundSize.y - ClientWindow::Get().GetSize().y * centerLineMargin * 2
		};

		sf::Vector2f centerLinePosition = {
			backgroundSize.x / 2 + background.getPosition().x - centerLineSize.x / 2.f,
			background.getPosition().y + ClientWindow::Get().GetSize().y * centerLineMargin
		};

		centerLine.setSize(centerLineSize);
		centerLine.setPosition(centerLinePosition);
		centerLine.setFillColor(centerLineColor);

		sf::Vector2f buttonLineSize = {
			backgroundSize.x / 2.f * (1.f - buttonLineMargin * 2.f),
			centerLineThickness * ClientWindow::Get().GetSize().x
		};

		sf::Vector2f buttonLinePosition = {
			backgroundSize.x / 4.f + background.getPosition().x,
			backgroundSize.y * (1 - buttonLineBottomMargin)
		};

		buttonLine.setSize(buttonLineSize);
		buttonLine.setOrigin(buttonLineSize / 2.f);
		buttonLine.setPosition(buttonLinePosition);
		buttonLine.setFillColor(centerLineColor);

		QueryTagButton::SetBackgroundColor(AcColors::DarkerGray);
		QueryTagButton::SetForegroundColor(AcColors::LightGray);
		QueryTagButton::SetHoverBackgroundColor(AcColors::DarkGray);
		QueryTagButton::SetHoverForegroundColor(AcColors::LightGray);
		QueryTagButton::SetClickBackgroundColor(AcColors::LightGray);
		QueryTagButton::SetClickForegroundColor(AcColors::White);
		QueryTagButton::SetActivatedBackgroundColor(AcColors::Hilight);
		QueryTagButton::SetActivatedForegroundColor(AcColors::White);

		QueryTagButton::SetTextMarginLeft(0.02f);
		QueryTagButton::SetTextSize(23);
		QueryTagButton::SetSize({
			background.getSize().x / 2,
			background.getSize().y / 20
		});

		queryButtonOrigin = {
			background.getPosition().x + background.getSize().x / 2,
			background.getPosition().y
		};

		sf::Vector2f offset = { 0, 0 };

		for (auto& name : solvedManager.GetNames()) {
			queryButtons.push_back(new QueryTagButton(
				LocaleManager::Utf8ToWString(name),
				solvedManager.GetTagKeyByName(name),
				queryButtonOrigin + offset
			));
			offset.y += QueryTagButton::GetSize().y;
		}

	}

    sf::Vector2f QueryTable::GetSize() const {
        return background.getSize();
    }

	sf::Vector2f QueryTable::GetPosition() const {
		return background.getPosition();
	}

	std::vector<std::string> QueryTable::GetActiveTags() {

		std::vector<std::string> result;

		std::vector<std::string> activatedTags;

		for (auto& queryButton : queryButtons) {
			if (!queryButton->IsButtonActivated()) continue;

			std::string resultStr = LocaleManager::WStringToUtf8(queryButton->GetName());
			activatedTags.push_back(solvedManager.GetTagKeyByName(resultStr));
		}

		const std::vector<Problem*>& reseavedJson = solvedManager.GetProblems(activatedTags, 0, 30);

		return result;

	}


}