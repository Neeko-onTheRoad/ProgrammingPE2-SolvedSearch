#include "Icons.Hxx"

namespace nk::Icons {

	static void LoadIcons() {
		
		CloseButton.loadFromFile(IconPath + "CloseButton.png");
		CloseButton.loadFromFile(IconPath + "MinimalizeButton.png");

	}

}