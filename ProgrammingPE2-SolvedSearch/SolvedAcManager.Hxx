#pragma once

#include <set>
#include <string>
#include <nlohmann/json.hpp>
#include "APIManager.Hxx"
#include "LocaleManager.Hxx"

namespace nk {

	namespace nlm = nlohmann;

	class SolvedAcManager {

//======================================================================| Constants

	public:
		static const std::string URL_SOLVED_AC;
		static const std::string URI_SEARCH_PROBLEM;
		static const std::string URI_TAG_LIST;
		static const std::string URI_TAG_SHOW;

//======================================================================| Members

	private:
		ApiManager apiManager;

		std::set<std::string> tagKeys;
		std::set<std::string> tagNames;
		std::unordered_map<std::string, std::string> tagKeyNameTable;
		std::unordered_map<std::string, std::string> tagNameKeyTable;

//======================================================================| Con/Destructors

	public:
		SolvedAcManager();

//======================================================================| Methods

	private:
		void InitTags();

	public:
		const std::set<std::string>& GetTags() const;
		const std::set<std::string>& GetNames() const;

		const std::string GetTagNameByKey(std::string key) const;
		const std::string GetTagKeyByName(std::string name) const;

	};

}