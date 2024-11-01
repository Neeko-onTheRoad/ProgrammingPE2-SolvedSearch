#pragma once

#include "AcColors.Hxx"
#include "ClientObject.Hxx"

namespace nk {

	class TierSlide : public ClientObject {

	private:
		sf::RectangleShape centerLine;
		std::vector<sf::RectangleShape*> gridLines;

	public:
		~TierSlide();
		TierSlide();

	};

}