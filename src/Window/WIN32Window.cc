#include "WIN32Window.hh"

#include <GLFW/glfw3.h>

#include "Events/KeyEvents.hh"
#include "Events/WindowEvents.hh"

namespace TVE {
    static bool isWindowCreated = false;
    WIN32Window::WIN32Window(const WindowProperties& prop)
    {
        if (isWindowCreated)
        {
            throw std::runtime_error(
                "* Window has already been created!\n"
                "* This app currently only supports one Window at runtime!\n"
                );
        }

        _data.width = prop.width;
        _data.height = prop.height;
        _data.title = prop.windowTitle;
        
        glfwInit();
        
        _glfwWindow = glfwCreateWindow(_data.width, _data.height, _data.title.c_str(), nullptr, nullptr);
        
        glfwSetWindowUserPointer(_glfwWindow, (void*)&_data);
        
        glfwSetWindowCloseCallback(
            _glfwWindow,
            [](GLFWwindow* window) {
                WindowData* data = reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
                WindowCloseEvent e{};
                data->callback(e);
            }
        );
        
        glfwSetKeyCallback(
            _glfwWindow,
            [](GLFWwindow* window, int key, int scancode, int action, int mods) {
                WindowData* data = reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
            
                switch (action) {
                    case GLFW_PRESS: {
                        KeyPressedEvent e{key};
                        data->callback(e);
                    } break;
                    case GLFW_RELEASE: {
                        KeyReleasedEvent e{key};
                        data->callback(e);
                    } break;
                    case GLFW_REPEAT: {
                        KeyRepeatedEvent e{key};
                        data->callback(e);
                    } break;
                    default: {

                    } break;
                }
            }
        );
        
    }
    
    void WIN32Window::setEventCallback(const EventCallbackFunction& func)
    {
        _data.callback = func;
    }
    
    void WIN32Window::update()
    {
        glfwPollEvents();
    }
    
    uint32_t WIN32Window::getWidth() const
    {
        return _data.width;
    }
    
    uint32_t WIN32Window::getHeight() const
    {
        return _data.height;
    }
    
    WIN32Window::~WIN32Window()
    {
        glfwTerminate();
    }
}