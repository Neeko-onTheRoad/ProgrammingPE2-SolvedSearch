#pragma once

#include <SFML/System.hpp>
#include "JsonConvertable.Hxx"

namespace nk {

	class ClientData : public JsonConvertable {

	public:
		float SizeMultiply = 1.f;
		unsigned FrameRate = 144u;
		bool VSyncEnabled = true;
		unsigned AntialiasingLevel = 4u;

		nlm::json ToJson() const override;
		void FromJson(const nlm::json& jsonData) override;

	};


}