#pragma once

#include "Event.hh"

namespace TVE {
    
    class WindowCloseEvent : public Event {
    public:
        WindowCloseEvent() = default;
        ~WindowCloseEvent() = default;

        EVENT_CLASS_TYPE(WindowClose);

        EVENT_CLASS_CATEGORY(EventCategory::Input | EventCategory::Window);
    };
    
    class WindowResizeEvent : public Event {
    public:
        WindowResizeEvent() = default;
        ~WindowResizeEvent() = default;
        
        EVENT_CLASS_TYPE(WindowResize);

        EVENT_CLASS_CATEGORY(EventCategory::Input | EventCategory::Window);
    };
    
    class WindowMoveEvent : public Event {
    public:
        WindowMoveEvent() = default;
        ~WindowMoveEvent() = default;
        
        EVENT_CLASS_TYPE(WindowMove);

        EVENT_CLASS_CATEGORY(EventCategory::Input | EventCategory::Window);
    };
    
    class WindowFocusEvent : public Event {
    public:
        WindowFocusEvent() = default;
        ~WindowFocusEvent() = default;

        EVENT_CLASS_TYPE(WindowFocus);
        
        EVENT_CLASS_CATEGORY(EventCategory::Input | EventCategory::Window);
    };
    
    class WindowUnFocusEvent : public Event {
    public:
        WindowUnFocusEvent() = default;
        ~WindowUnFocusEvent() = default;

        EVENT_CLASS_TYPE(WindowUnFocus);
        
        EVENT_CLASS_CATEGORY(EventCategory::Input | EventCategory::Window);
    };
    
}