#include "LocaleManager.Hxx"

namespace nk {

	namespace Locale {
		std::wstring Utf8ToWString(const std::string& str) {
			int size_needed = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int)str.size(), NULL, 0);
			std::wstring wstr(size_needed, 0);
			MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int)str.size(), &wstr[0], size_needed);
			return wstr;
		}
	}

}