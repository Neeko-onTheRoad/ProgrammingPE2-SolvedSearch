#pragma once

#include <fstream>
#include <nlohmann/json.hpp>

namespace nk {

	namespace nlm = nlohmann;

	class SaveManager {

		static void Save(nlm::json target, std::string path);
		static nlm::json Load(std::string path);

	};

}