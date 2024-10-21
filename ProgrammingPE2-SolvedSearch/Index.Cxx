#include "BuildScene.Hxx"

int main() {
	
	nk::ClientWindow client;
	BuildScene(client);
	client.StartAndWaitForEnd();

	return EXIT_SUCCESS;


}
