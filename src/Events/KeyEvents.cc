#include "KeyEvents.hh"

namespace TVE {

    std::string KeyPressedEvent::verboseStr() const
    {
        std::stringstream ss;
        ss << "Pressed Key: " << _code;
        return ss.ss();
    }

    std::string KeyReleasedEvent::verboseStr() const
    {
        std::stringstream ss;
        ss << "Released Key: " << _code;
        return ss.ss();
    }

    std::string KeyrepeatedEvent::verboseStr() const
    {
        std::stringstream ss;
        ss << "Repeated Key: " << _code;
        return ss.ss();
    }

}