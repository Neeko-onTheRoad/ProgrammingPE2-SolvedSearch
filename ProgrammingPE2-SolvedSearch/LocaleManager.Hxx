#pragma once

#include <locale>
#include <sstream>
#include <iomanip>
#include <Windows.h>

namespace nk {
	
	namespace LocaleManager {
		std::wstring Utf8ToWString(const std::string& str);
		std::string WStringToUtf8(const std::wstring& str);
		std::string URLEncode(const std::string& input);
	};

}