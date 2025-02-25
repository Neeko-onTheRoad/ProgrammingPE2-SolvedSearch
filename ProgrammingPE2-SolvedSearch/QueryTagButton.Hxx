#pragma once

#include "Fonts.Hxx"
#include "ClientObject.Hxx"
#include "ClientWindow.Hxx"

namespace nk {

	class QueryTagButton : public ClientObject {

	private:
		static sf::Color backgroundColor;
		static sf::Color foregroundColor;
		static sf::Color hoverBackgroundColor;
		static sf::Color hoverForegroundColor;
		static sf::Color clickBackgroundColor;
		static sf::Color clickForegroundColor;
		static sf::Color activatedBackgroundColor;
		static sf::Color activatedForegroundColor;
		static float textMarginLeft;
		static unsigned textSize;
		static sf::Vector2f size;

		sf::Text name;
		std::string target;
		sf::RectangleShape background;

		bool isButtonActivated = false;
		bool hovering = false;
		bool clicking = false;

		sf::Vector2f position;
		sf::RenderTexture renderTexture;
		sf::Sprite renderSprite;

	private:
		void SetVisualDefault();
		void SetVisualHover();
		void SetVisualClick();
		void SetVisualActivated();

	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void Rerender() override;
		void Update(const sf::Event& event) override;

	public:
		QueryTagButton(
			std::wstring name,
			std::string target,
			sf::Vector2f position
		);

		bool IsButtonActivated() const;
		std::string GetTarget() const;
		std::wstring GetName() const;

		sf::Vector2f GetPosition() const;
		void SetPosition(sf::Vector2f position);
		void AddPosition(sf::Vector2f delta);

		static void SetBackgroundColor(const sf::Color& color);
		static void SetForegroundColor(const sf::Color& color);
		static void SetHoverBackgroundColor(const sf::Color& color);
		static void SetHoverForegroundColor(const sf::Color& color);
		static void SetClickBackgroundColor(const sf::Color& color);
		static void SetClickForegroundColor(const sf::Color& color);
		static void SetActivatedBackgroundColor(const sf::Color& color);
		static void SetActivatedForegroundColor(const sf::Color& color);
		static void SetTextMarginLeft(float margin);
		static void SetTextSize(unsigned size);
		static void SetSize(sf::Vector2f size);

		static sf::Vector2f GetSize();

	};

}