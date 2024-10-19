#pragma once

#include <nlohmann/json.hpp>

namespace nk {

	namespace nlm = nlohmann;

	class JsonConvertable {

	public:
		virtual nlm::json ToJson() const = 0;
		virtual void FromJson(const nlm::json& jsonData) = 0;

	};

}