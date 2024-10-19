#include "ClientData.Hxx"

namespace nk {

	nlm::json ClientData::ToJson() const {
		return nlm::json{
			{ "SizeMultiply", SizeMultiply },
			{ "FrameRate", FrameRate },
			{ "VSyncEnabled", VSyncEnabled },
			{ "AntialiasingLevel", AntialiasingLevel }
		};
	}

	void ClientData::FromJson(const nlm::json& jsonData) {
		jsonData.at("SizeMultiply").get_to(SizeMultiply);
		jsonData.at("FrameRate").get_to(FrameRate);
		jsonData.at("VSyncEnabled").get_to(VSyncEnabled);
		jsonData.at("AntialiasingLevel").get_to(AntialiasingLevel);
	}

}