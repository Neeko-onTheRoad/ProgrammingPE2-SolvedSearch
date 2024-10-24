#include "QueryDivision.Hxx"

void nk::QueryDivision::AddObject(ClientObject* object, sf::Vector2f position) {
	objects[object] = position;
}