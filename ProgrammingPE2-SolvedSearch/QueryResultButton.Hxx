#pragma once

#include <string>
#include <sstream>

#include "Fonts.Hxx"
#include "ClientObject.Hxx"
#include "ClientWindow.Hxx"
#include "SolvedAcManager.Hxx"

namespace nk {

	class QueryResultButton : public ClientObject {

	private:
		static sf::Color backgroundColor;
		static sf::Color hoverBackgroundColor;
		static sf::Color clickBackgroundColor;
		static sf::Color foregroundColor;
		static sf::Color tagColor;
		static sf::Color tagHoverColor;
		static sf::Vector2f size;
		static float xPosition;
		static float textMargin;
		static unsigned textSize;
		static float tierSize;
		static unsigned tagTextSize;

		sf::RectangleShape background;
		sf::Text name;
		sf::Sprite tier;
		std::vector<sf::RectangleShape*> tagBackgrounds;
		std::vector<sf::Text*> tagTexts;
		sf::Text infoText;

		int id;

		SolvedAcManager& solvedManager;

		bool hovering = false;
		bool clicking = false;

	private:
		void SetVisualDefault();
		void SetVisualHover();
		void SetVisualClick();
		void OpenWeb() const;

	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void Update(const sf::Event& event) override;

	public:
		~QueryResultButton();

		QueryResultButton(
			SolvedAcManager& solvedManager,
			std::wstring title,
			int id,
			int tier,
			std::vector<std::string> tags,
			float yPosition,
			float averageTries,
			int acceptedUserCount
		);

		sf::Vector2f GetSize() const;
		
		static void SetBackgroundColor(const sf::Color& color);
		static void SetHoverBackgroundColor(const sf::Color& color);
		static void SetClickBackgroundColor(const sf::Color& color);
		static void SetForegroundColor(const sf::Color& color);
		static void SetTagColor(const sf::Color& color);
		static void SetTagHoverColor(const sf::Color& color);
		static void SetSize(sf::Vector2f size);
		static void SetXPosition(float xPosition);
		static void SetTextMargin(float margin);
		static void SetTextSize(unsigned size);
		static void SetTierSize(float size);
		static void SetTagTextSize(unsigned size);

		static float GetHeigh();

	};

}