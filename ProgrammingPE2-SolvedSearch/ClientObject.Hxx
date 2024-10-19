#pragma once

#include <SFML/Graphics.hpp>

namespace nk {

	class ClientObject : public sf::Drawable {	

		friend class ClientWindow;

//======================================================================| Members

	private:
		bool isActivated;
		bool isNeedRerender;

	public:
		sf::RenderStates RenderState;

//======================================================================| Methods

	private:
		void UpdateBase(const sf::Event& event);
		void LateUpdateBase(const sf::Event& event);
		void DrawBase(sf::RenderTarget& target, sf::RenderStates states);

		static sf::RenderStates CombineRenderStates(const sf::RenderStates& s1, const sf::RenderStates& s2);

	protected:
		virtual void Update(const sf::Event& event) {};
		virtual void LateUpdate(const sf::Event& event) {};
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {};
		virtual void Rerender() {};

	public:
		void SetActive(bool active);
		bool IsActive() const;

		
	};

}