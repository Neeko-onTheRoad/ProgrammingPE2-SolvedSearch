#include "LocaleManager.Hxx"

namespace nk::LocaleManager {

	std::wstring Utf8ToWString(const std::string& str) {
			
		int size_needed = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int)str.size(), NULL, 0);
		std::wstring wstr(size_needed, 0);
		MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int)str.size(), &wstr[0], size_needed);
		return wstr;

	}

	std::string WStringToUtf8(const std::wstring& wstr) {

		int size_needed = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), (int)wstr.size(), NULL, 0, NULL, NULL);
		std::string str(size_needed, 0);
		WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), (int)wstr.size(), &str[0], size_needed, NULL, NULL);
		return str;

	}

	std::string URLEncode(const std::string& input) {
		std::ostringstream encoded;
		for (unsigned char c : input) {
			encoded << '%' << std::setw(2) << std::setfill('0') << std::hex << std::uppercase << (int)c;
		}
		return encoded.str();
	}


}