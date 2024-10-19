#include "SaveManager.Hxx"

namespace nk {

	void SaveManager::Save(const JsonConvertable& target, std::string path) {
		
		std::ofstream result("./dat/" + path);
		result << target.ToJson();
		result.close();

	}

}