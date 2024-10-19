#pragma once

#include <locale>
#include <Windows.h>

namespace nk {
	
	class LocaleManager {
		static std::wstring Utf8ToWString(const std::string& str);
	};

}