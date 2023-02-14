#pragma once

#include "Window.hh"

struct GLFWwindow;

namespace TVE {

    class WIN32Window : public Window {
    private:
    struct WindowData {
        uint32_t width, height;
        std::string title;
        EventCallbackFunction callback;
    };
    public:
        WIN32Window() = delete;
        WIN32Window(const WindowProperties& prop);
        ~WIN32Window();

        void setEventCallback(const EventCallbackFunction& func) override;
        void update() override;

        uint32_t getWidth() const override;
        uint32_t getHeight() const override;
    private:
        GLFWwindow* _glfwWindow;
        WindowData _data;
    };

}