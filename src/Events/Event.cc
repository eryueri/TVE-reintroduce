#include "Event.hh"

namespace TVE {
    bool Event::isInCategory(const EventCategory& category) { return getEventCategoryFlags() & category; }
    std::string Event::verboseStr() const { return getName(); }

    uint8_t operator&(const EventCategory& a, const EventCategory& b) { return static_cast<uint8_t>(a) & static_cast<uint8_t>(b); }
    uint8_t operator&(const EventCategory& a, const uint8_t& b) { return static_cast<uint8_t>(a) & b; }
    uint8_t operator&(const uint8_t& a, const EventCategory& b) { return a & static_cast<uint8_t>(b); }
    uint8_t operator|(const EventCategory& a, const EventCategory& b) { return static_cast<uint8_t>(a) | static_cast<uint8_t>(b); }
    uint8_t operator|(const EventCategory& a, const uint8_t& b) { return static_cast<uint8_t>(a) | b; }
    uint8_t operator|(const uint8_t& a, const EventCategory& b) { return a | static_cast<uint8_t>(b); }
}