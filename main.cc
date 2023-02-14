#include "Core/Application.hh"
#include <iostream>

int main()
{
	TVE::Application* app = TVE::Application::getInstance();
	try {
		app->run();
	} catch (std::exception& e) {
		std::cout << e.what();
	}
}