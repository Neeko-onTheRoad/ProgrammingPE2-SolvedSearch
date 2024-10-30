#include "Problem.Hxx"

namespace nk {

	std::string Problem::GetTitle() const {
		return title;
	}

	int Problem::GetLevel() const {
		return level;
	}

	float Problem::GetAverageTries() const {
		return averageTries;
	}

	int Problem::GetAcceptedUserCount() const {
		return acceptedUserCount;
	}

	const std::vector<std::string>& Problem::GetTags() const {
		return tagKeys;
	}

	void Problem::LoadFromJson(const nlm::json& json) {
		
		title = json.at("title");
		level = json.at("level");
		averageTries = json.at("averageTries");
		
		for (auto& tag : json.at("tags")) {
			tagKeys.push_back(tag.at("key"));
		}

	}

}