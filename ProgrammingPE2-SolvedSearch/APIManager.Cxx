#include "APIManager.Hxx"

namespace nk {

	const char* ApiManager::MASTER_KEY = 
		"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/116.0.0.0 Safari/537.36";

	ApiManager::ApiManager(std::string hostUrl) {

		this->hostUrl = hostUrl;
		curlClient = curl_easy_init();

		if (!curlClient) {
			throw std::runtime_error("Fail to init curl");
		}

		curl_easy_setopt(curlClient, CURLOPT_USERAGENT, ApiManager::MASTER_KEY);

	}

	ApiManager::~ApiManager() {

		if (curlClient) {
			curl_easy_cleanup(curlClient);
		}

	}

	std::string ApiManager::BuildUrl() const {
		
		std::ostringstream result;
		result << hostUrl;
		result << uri;

		if (queries.size() == 0) {
			return result.str();
		}

		result << "?";

		for (auto it = queries.begin(); it != queries.end(); it++) {
			result << it->first << "=" << it->second;

			if (std::next(it) != queries.end()) {
				result << "&";
			}
		}

		return result.str();
	}

	std::string ApiManager::BuildHeader(const StringPair& header) const {
		return header.first + ": " + header.second;
	}

	size_t ApiManager::WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
		size_t newLength = size * nmemb;
		userp->append((char*)contents, newLength);
		return newLength;
	}

	void ApiManager::SetUri(const std::string& uri) {
		this->uri = uri;
	}

	void ApiManager::SetQuery(const std::string& key, const std::string& value) {
		queries[key] = value;
	}

	void ApiManager::ClearQuery() {
		queries.clear();
	}

	void ApiManager::SetHeader(const std::string& key, const std::string& value) {
		headers[key] = value;
	}

	void ApiManager::ClearHeader() {
		headers.clear();
	}

	void ApiManager::ClearAll() {
		uri = "";
		ClearQuery();
		ClearHeader();
	}

	std::string ApiManager::GetResponse() {
		
		std::string readBuffer;
		CURLcode errorCode;

		std::string url = BuildUrl();

		curl_easy_setopt(curlClient, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curlClient, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curlClient, CURLOPT_WRITEDATA, &readBuffer);

		struct curl_slist* headerSlist = nullptr;
		for (auto& header : this->headers) {
			headerSlist = curl_slist_append(headerSlist, BuildHeader(header).c_str());
		}
		curl_easy_setopt(curlClient, CURLOPT_HTTPHEADER, headerSlist);
		curl_easy_setopt(curlClient, CURLOPT_USERAGENT, MASTER_KEY);

		errorCode = curl_easy_perform(curlClient);
		if (errorCode != CURLE_OK) {
			std::cerr
				<< "curl_easy_perform() failed: "
				<< curl_easy_strerror(errorCode)
				<< std::endl;
		}

		curl_slist_free_all(headerSlist);
		return readBuffer;

	}

	std::string ApiManager::GetResponseAndClear() {

		std::string result = GetResponse();
		ClearAll();
		return result;

	}

}
