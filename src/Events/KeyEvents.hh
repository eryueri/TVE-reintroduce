#pragma once

#include "Event.hh"

namespace TVE {
    class KeyPressedEvent : public Event {
    public:
        KeyPressedEvent() = delete;
        KeyPressedEvent(int code) 
            : _code(code) {}
        ~KeyPressedEvent() = default;
        
        std::string verboseStr() const override;
        
        EVENT_CLASS_TYPE(KeyPressed);
            
        EVENT_CLASS_CATEGORY(EventCategory::Input | EventCategory::Keyboard);
    private:
        int _code;
    };
    
    class KeyReleasedEvent : public Event {
    public:
        KeyReleasedEvent() = delete;
        KeyReleasedEvent(int code) 
            : _code(code) {}
        ~KeyReleasedEvent() = default;
        
        std::string verboseStr() const override;
        
        EVENT_CLASS_TYPE(KeyReleased);
            
        EVENT_CLASS_CATEGORY(EventCategory::Input | EventCategory::Keyboard);
    private:
        int _code;
    };
    
    class KeyRepeatedEvent : public Event {
    public:
        KeyRepeatedEvent() = delete;
        KeyRepeatedEvent(int code)
            : _code(code) {}
        ~KeyRepeatedEvent() = default;
        
        std::string verboseStr() const override;
        
        EVENT_CLASS_TYPE(KeyRepeated);

        EVENT_CLASS_CATEGORY(EventCategory::Input | EventCategory::Keyboard);
    private:
        int _code;
    };
    
}