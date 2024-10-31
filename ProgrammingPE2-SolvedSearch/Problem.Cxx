#include "Problem.Hxx"

namespace nk {
	Problem::Problem() {
		title = "N/A";
		tier = 1;
		id = 1000;
		averageTries = 0.f;
		acceptedUserCount = 0;
	}

	std::wstring Problem::GetTitle() const {
		return LocaleManager::Utf8ToWString(title);
	}

    int Problem::GetId() const {
        return id;
    }

	int Problem::GetTier() const {
		return tier;
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
		
		title = json.at("titleKo");
		id = json.at("problemId");
		tier = json.at("level");

		averageTries = json.at("averageTries");
		
		for (auto& tag : json.at("tags")) {
			tagKeys.push_back(tag.at("key"));
		}

	}

}