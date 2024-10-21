#include "Icons.Hxx"

namespace nk::Icons {

	void LoadIcons() {
		
		CloseButton.loadFromFile(IconPath + "CloseButton.png");
		CloseButton.loadFromFile(IconPath + "MinimalizeButton.png");

	}

}