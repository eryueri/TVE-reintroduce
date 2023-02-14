#pragma once

#include "pch.hh"

namespace TVE {
    
    class Event;
    
    struct WindowProperties {
        uint32_t width;
        uint32_t height;
        std::string windowTitle;
        WindowProperties(
            const uint32_t& w = 800, const uint32_t& h = 600,
            const std::string& t = "TVEDemo"
        ) : width(w), height(h), windowTitle(t) {}
    };
    
    class Window {
    public:
        using EventCallbackFunction = std::function<void(Event&)>;

        Window() = default;
        virtual ~Window() = default;
        
        virtual void setEventCallback(const EventCallbackFunction& func) = 0;
        virtual void update() = 0;

        virtual uint32_t getWidth() const = 0;
        virtual uint32_t getHeight() const = 0;
    };

}