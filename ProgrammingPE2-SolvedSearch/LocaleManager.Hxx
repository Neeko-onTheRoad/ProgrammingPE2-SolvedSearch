#pragma once

#include <locale>
#include <Windows.h>

namespace nk {
	
	namespace Locale {
		std::wstring Utf8ToWString(const std::string& str);
	}

}