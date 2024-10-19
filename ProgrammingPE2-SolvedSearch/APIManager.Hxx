#pragma once

#define CURL_STATICLIB

#include <sstream>
#include <iostream>
#include <unordered_map>

#include <curl/curl.h>

namespace nk {
	class ApiManager {

//======================================================================| Constants

	private:
		static const char* MASTER_KEY;

//======================================================================| Types

	private:
		using StringPair = std::pair<std::string, std::string>;
		using StringPairs = std::unordered_map<std::string, std::string>;

//======================================================================| Members

	private:
		CURL*		curlClient;
		std::string hostUrl;
		std::string uri;
		StringPairs queries;
		StringPairs headers;

//======================================================================| Con/Destructors

	public:
		ApiManager(std::string hostUrl);
		~ApiManager();

//======================================================================| Methods

	private:
		std::string BuildUrl() const;
		std::string BuildHeader(const StringPair& header) const;
		static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp);

	public:
		void SetUri(const std::string& uri);
		void SetQuery(const std::string& key, const std::string& value);
		void SetHeader(const std::string& key, const std::string& value);

		void ClearQuery();
		void ClearHeader();
		void ClearAll();

		std::string GetResponse();
		std::string GetResponseAndClear();
	};
}