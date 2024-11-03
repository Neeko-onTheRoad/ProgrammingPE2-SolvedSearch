#include "SolvedAcManager.Hxx"

namespace nk {

	const std::string SolvedAcManager::URL_SOLVED_AC = "https://solved.ac/api/v3/";
	const std::string SolvedAcManager::URI_SEARCH_PROBLEM = "search/problem";
	const std::string SolvedAcManager::URI_TAG_LIST = "tag/list";
	const std::string SolvedAcManager::URI_TAG_SHOW = "tag/show";

	std::vector<std::string> SolvedAcManager::solvedTiers;

	SolvedAcManager::SolvedAcManager() : apiManager(URL_SOLVED_AC) {

		SetConsoleOutputCP(CP_UTF8);
		InitTags();

	}

	void SolvedAcManager::InitTags() {

		int page = 1;

		while (true) {

			apiManager.SetUri(URI_TAG_LIST);
			apiManager.SetQuery("page", std::to_string(page++));
			std::string reseaved = apiManager.GetResponseAndClear();

			nlm::json tagsJson = nlm::json::parse(reseaved);
			
			if (tagsJson["items"].size() == 0) break;

			for (const auto& item : tagsJson["items"]) {
				std::string key = item["key"].get<std::string>();
				std::string name = item["displayNames"][0]["name"];

				tagKeys.insert(key);
				tagNames.insert(name);
				tagKeyNameTable[key] = name;
				tagNameKeyTable[name] = key;
			}

		}

	}

	const std::set<std::string>& SolvedAcManager::GetTags() const {
		return tagKeys;
	}

	const std::set<std::string>& SolvedAcManager::GetNames() const {
		return tagNames;
	}

	const std::string SolvedAcManager::GetTagNameByKey(std::string tag) const {
		return tagKeyNameTable.at(tag);
	}

	const std::string SolvedAcManager::GetTagKeyByName(std::string name) const {
		return tagNameKeyTable.at(name);
	}

    std::vector<Problem*> SolvedAcManager::GetProblems(
		const std::vector<std::string>& tags,
		int minTier,
		int maxTier
	) {
		
		std::vector<Problem*> problems;
	
		std::string query;

		if (minTier == maxTier) {
			query += " *" + std::to_string(maxTier);
		}
		else {
			query += " *" + std::to_string(minTier) + ".." + std::to_string(maxTier);
		}

		for (auto& tag : tags) {
			query += " #" + tag;
		}

		apiManager.SetUri(URI_SEARCH_PROBLEM);
		apiManager.SetQuery("direction", "asc");
		apiManager.SetQuery("sort", "random");
		apiManager.SetQuery("page", "1");
		apiManager.SetQuery("query", LocaleManager::URLEncode(query));

		apiManager.SetHeader("Accept", "application/json");
		apiManager.SetHeader("x-solvedac-language", "ko");

		nlm::json reseavedJson = nlm::json::parse(apiManager.GetResponseAndClear());

		for (auto& problemData : reseavedJson["items"]) {
			Problem* problem = new Problem;
			problem->LoadFromJson(problemData);

			problems.push_back(problem);
		}

		return problems;

    }

	void SolvedAcManager::MakeTierNames() {

		solvedTiers.push_back("Unknown");

		std::string tierNames[] = {
			"Bronze", "Silver", "Gold", "Platinum", "Diamond", "Ruby"
		};

		for (auto& tierName : tierNames) {
			for (int level = 5; level >= 1; level--) {
				solvedTiers.push_back(tierName + " " + std::to_string(level));
			}
		}
	}

	std::string SolvedAcManager::GetSolvedTier(int tierCode) {
		return solvedTiers[tierCode];
    }
	
}