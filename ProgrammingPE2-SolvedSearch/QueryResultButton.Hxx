#pragma once

#include "ClientObject.Hxx"
#include "SolvedAcManager.Hxx"

namespace nk {

	class QueryResultButton : public ClientObject {

	private:
		static sf::Color backgroundColor;
		static sf::Color hoverBackgroundColor;
		static sf::Color clickBackgroundColor;
		static sf::Color foregroundColor;
		static sf::Vector2f size;
		static float xPosition;

		sf::RectangleShape background;
		sf::Text title;
		sf::Sprite tier;
		std::vector<sf::Text> tags;

		SolvedAcManager& solvedManager;

	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void Update(const sf::Event& event) override;

	public:
		QueryResultButton(
			SolvedAcManager& solvedManager,
			std::string title,
			int tier,
			std::vector<std::string> tags,
			float yPosition
		);

		sf::Vector2f GetPosition() const;
		
		static void SetBackgroundColor(const sf::Color& color);
		static void SetHoverBackgroundColor(const sf::Color& color);
		static void SetClickBackgroundColor(const sf::Color& color);
		static void SetForegroundColor(const sf::Color& color);
		static void SetSize(sf::Vector2f size);
		static void SetXPosition(float xPosition);


	};

}