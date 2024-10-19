#include "SaveManager.Hxx"

namespace nk {

	void SaveManager::Save(nlm::json target, std::string path) {
		
		std::ofstream result("./dat/" + path);
		result << target.dump(4);
		result.close();

	}


	nlm::json SaveManager::Load(std::string path) {

		std::string loadedString;

		std::ifstream file("./dat/" + path);
		file >> loadedString;
		file.close();

		return nlm::json::parse(loadedString);

	}


}