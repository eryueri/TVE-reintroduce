#pragma once

namespace TVE {
	
	class Window;
	class Event;

	class Application {
	public:
		~Application();
		static Application* getInstance();
		void run();
	private:
		Application();
		void onEvent(Event& e);
		void onWindowCloseEvent(Event& e);
		bool _inited = false;
		bool _terminate = true;
		Window* _window = nullptr;
		static Application* _instance;
	private:
		// class that is used to destory _instance, in fact this might be unnecessary in my mind
		// but considering the possibility of this program running on a system which will not recycle the memory that it demanded when running
		// i'll leave it here
		class Destructor {
		public:
			Destructor() {}
			~Destructor() { if (_instance) delete _instance; }
		};
		static Destructor _destructor;
	};

}