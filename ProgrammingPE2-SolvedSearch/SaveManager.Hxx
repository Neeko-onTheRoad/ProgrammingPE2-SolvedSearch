#pragma once

#include <fstream>
#include <concepts>
#include <nlohmann/json.hpp>
#include "ClientData.Hxx"
#include "JsonConvertable.Hxx"

namespace nk {

	namespace nlm = nlohmann;

	class SaveManager {

	public:

		
		static void Save(const JsonConvertable& target, std::string path);

		template <class T>
		T Load(std::string path) {

			static_assert(
				std::derived_from<T, JsonConvertable>,
				"Need to convert to JsonConvertable object"
			);

			std::string loadedString;

			std::ifstream file("./dat/" + path);

			if (file.fail() || !file.is_open()) {
				return T();
			}

			file >> loadedString;
			file.close();

			T result;
			result.FromJson(nlm::json::parse(loadedString));

			return result;

		}

	};



}