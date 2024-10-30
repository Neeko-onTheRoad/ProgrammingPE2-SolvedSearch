#pragma once

#include <vector>
#include <string>
#include "nlohmann/json.hpp"

namespace nk {

	namespace nlm = nlohmann;

	class Problem {

	private:
		std::string title;
		int level;
		float averageTries;
		int acceptedUserCount;
		std::vector<std::string> tagKeys;

	public:
		std::string GetTitle() const;
		int GetLevel() const;
		float GetAverageTries() const;
		int GetAcceptedUserCount() const;
		const std::vector<std::string>& GetTags() const;
	
		void LoadFromJson(const nlm::json& json);

	};

}