#pragma once

#include <unordered_map>
#include "ClientWindow.Hxx"

namespace nk {

	class QueryDivision : public ClientObject {

	private:
		using ObjectTable = std::unordered_map<ClientObject*, sf::Vector2f>;

	private:
		bool folded = false;
		sf::Text title;

		ObjectTable objects;

	public:
		void AddObject(ClientObject* object, sf::Vector2f position);

	};

}