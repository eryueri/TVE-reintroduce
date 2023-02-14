#pragma once

#include "Event.hh"

namespace TVE {
    class MouseMoveEvent : public Event {
    public:
        MouseMoveEvent() = delete;
        MouseMoveEvent(float x, float y)
            : _x(x), _y(y) {}
        ~MouseMoveEvent() = default;

         std::string verboseStr() const override;
         
         EVENT_CLASS_TYPE(MouseMove);

         EVENT_CLASS_CATEGORY(EventCategory::Input | EventCategory::Mouse);
    private:
        float _x, _y;
    };

    class MouseKeyPressedEvent : public Event {
    public:
        MouseKeyPressedEvent() = delete;
        MouseKeyPressedEvent(int code)
            : _code(code) {}
        ~MouseKeyPressedEvent() = default;

         std::string verboseStr() const override;
         
         EVENT_CLASS_TYPE(MouseKeyPressed);

         EVENT_CLASS_CATEGORY(EventCategory::Input | EventCategory::Mouse);
    private:
        int _code;
    };
    
    class MouseKeyReleasedEvent : public Event {
    public:
        MouseKeyReleasedEvent() = delete;
        MouseKeyReleasedEvent(int code)
            : _code(code) {}
        ~MouseKeyReleasedEvent() = default;

         std::string verboseStr() const override;
         
         EVENT_CLASS_TYPE(MouseKeyReleased);

         EVENT_CLASS_CATEGORY(EventCategory::Input | EventCategory::Mouse);
    private:
        int _code;
    };
    
    class MouseScrollEvent : public Event {
    public:
        MouseScrollEvent() = delete;
        MouseScrollEvent(float x, float y)
            : _xOffset(x), _yOffset(y) {}
        ~MouseScrollEvent() = default;

         std::string verboseStr() const override;
         
         EVENT_CLASS_TYPE(MouseScroll);

         EVENT_CLASS_CATEGORY(EventCategory::Input | EventCategory::Mouse);
    private:
        float _xOffset, _yOffset;
    };
}
