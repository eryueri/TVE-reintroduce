#include "Application.hh"

#include "pch.hh"

#include "Log.hh"
#include "Events/Event.hh"
#include "Window/WIN32Window.hh"

namespace TVE {
	
	Application* Application::_instance = nullptr;
	Application::Destructor Application::_destructor{};
	
	Application::Application()
	{
		LOG_INIT();
		_window = new WIN32Window{WindowProperties{}};
		_window->setEventCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));
		_inited = true;
		_terminate = false;
	}

	Application* Application::getInstance()
	{
		if (!_instance) {
			_instance = new Application{};
		}
		return _instance;
	}
	
	Application::~Application()
	{
		delete _window;
	}

	void Application::run()
	{
		if (!_inited) {
			throw std::runtime_error(
				"* Application not inited!\n"
				"* Make sure to call init() before calling run()\n"
				);
		}

		while (!_terminate) {
			_window->update();
		}
	}
	
	void Application::onEvent(Event& e)
	{
		switch (e.getEventType()) {
			case EventType::WindowClose: {
				_terminate = true;
			} break;
			default: {

			} break;
		}
		LOG_TRACE(e.verboseStr());
	}

}