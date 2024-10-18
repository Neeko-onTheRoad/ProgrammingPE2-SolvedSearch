#pragma once

#include "APIManager.Hxx"

namespace nk::Network {

	class SolvedAcManager : private APIManager {
		
//======================================================================| Constants

	private:
		const static std::string URL_SOLVED_AC;

//======================================================================| Con/Destructors

	public:
		SolvedAcManager() : APIManager("http://solved.ac/api/v3") {};

	};

}