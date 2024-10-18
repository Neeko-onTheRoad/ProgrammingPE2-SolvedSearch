#include "ClientWindow.Hxx"

int main() {
	
	nk::Client::ClientWindow client;
	client.StartAndWaitForEnd();

	return EXIT_SUCCESS;

}
