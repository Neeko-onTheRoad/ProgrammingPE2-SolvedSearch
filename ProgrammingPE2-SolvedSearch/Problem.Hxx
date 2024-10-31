#pragma once

#include <vector>
#include <string>
#include "nlohmann/json.hpp"
#include "LocaleManager.Hxx"

namespace nk {

	namespace nlm = nlohmann;

	class Problem {

	private:
		std::string title;
		int id;
		int tier;
		float averageTries;
		int acceptedUserCount;
		std::vector<std::string> tagKeys;

	public:
		Problem();

		std::wstring GetTitle() const;
		int GetId() const;
		int GetTier() const;
		float GetAverageTries() const;
		int GetAcceptedUserCount() const;
		const std::vector<std::string>& GetTags() const;
	
		void LoadFromJson(const nlm::json& json);

	};

}