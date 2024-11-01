#include "TierSlide.Hxx"

namespace nk {

	TierSlide::~TierSlide() { 
		for (auto& gridLines : gridLines) {
			delete gridLines;
		}
	}

	TierSlide::TierSlide() {
		
		

	}

}

