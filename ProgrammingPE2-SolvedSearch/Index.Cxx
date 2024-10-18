#include <iostream>
#include <string>
#include <curl/curl.h>
#include "APIManager.Hxx"

#include <fstream>

int main() {
	std::ofstream ofs("Result.txt");

	nk::APIManager m("http://solved.ac/api/v3");
	m.SetUri("/search/problem");
	m.SetQuery("direction", "asc");
	m.SetQuery("query", "");
	m.SetQuery("sort", "id");
	m.SetQuery("page", "10000");

	ofs << m.GetResponseAndClear() << std::endl;

}
