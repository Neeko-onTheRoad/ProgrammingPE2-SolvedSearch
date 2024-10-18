#pragma once

#include "APIManager.Hxx"

namespace nk {

	class SolvedAcManager {
		
//======================================================================| Constants

	private:
		const std::string URL_SOLVED_AC;
		const std::string URI_PROBLEM;

//======================================================================| Con/Destructors

	public:
		SolvedAcManager() : APIManager("http://solved.ac/api/v3") {};

	};

}