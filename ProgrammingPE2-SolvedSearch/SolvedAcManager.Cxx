#include "SolvedAcManager.Hxx"

namespace nk {

	const std::string SolvedAcManager::URL_SOLVED_AC = "https://solved.ac/api/v3/";
	const std::string SolvedAcManager::URI_SEARCH_PROBLEM = "search/problem";
	const std::string SolvedAcManager::URI_TAG_LIST = "tag/list";
	const std::string SolvedAcManager::URI_TAG_SHOW = "tag/show";

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
				tagKeyNameTable[key] = name;
			}

		}


	}

	const std::set<std::string>& SolvedAcManager::GetTags() const {
		return tagKeys;
	}
	
	const std::string SolvedAcManager::GetTagName(std::string tag) const {
		return tagKeyNameTable.at(tag);
	}

}