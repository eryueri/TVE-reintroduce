#pragma once

#include "pch.hh"

namespace TVE {
    
    enum class EventType : uint16_t {
        None = 0,
        MouseMove, MouseKeyPressed, MouseKeyReleased, MouseScroll, 
        KeyPressed, KeyReleased, KeyRepeated, 
        ControllerKeyPressed, ControllerKeyReleased,
        WindowClose, WindowResize, WindowFocus, WindowUnFocus,
    };
    
    enum class EventCategory : uint8_t {
        None = 0,
        Input = 1 << 0,
        Output = 1 << 1,
        Mouse = 1 << 2,
        Keyboard = 1 << 3,
        Controller = 1 << 4,
        Window = 1 << 5,
    };

    uint8_t operator&(const EventCategory& a, const EventCategory& b);
    uint8_t operator&(const EventCategory& a, const uint8_t& b);
    uint8_t operator&(const uint8_t& a, const EventCategory& b);
    uint8_t operator|(const EventCategory& a, const EventCategory& b);
    uint8_t operator|(const EventCategory& a, const uint8_t& b);
    uint8_t operator|(const uint8_t& a, const EventCategory& b);
    
    class Event {
    public:
        virtual EventType getEventType() const = 0;
        virtual uint8_t getEventCategoryFlags() const = 0;
        virtual const char* getName() const = 0;
        virtual std::string verboseStr() const;
        bool isInCategory(const EventCategory& category);
    };
    
    #define EVENT_CLASS_TYPE(type) \
    static EventType getStaticType() { return EventType::type; } \
    EventType getEventType() const override { return getStaticType(); } \
    const char* getName() const override { return #type; }

    #define EVENT_CLASS_CATEGORY(category) \
    uint8_t getEventCategoryFlags() const override { return static_cast<uint8_t>(category); }
}