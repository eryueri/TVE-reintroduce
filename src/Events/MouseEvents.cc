#include "MouseEvent.hh"

namespace TVE {
    std::string MouseMoveEvent::verboseStr() const
    {
        std::stringstream ss;
        ss << "Mouse Move to x: " << _x << ", y: " << _y;
        return ss.ss();
    }
    
    std::string MouseKeyPressedEvent::verboseStr() const
    {
        std::stringstream ss;
        ss << "Pressed Mouse Button: " << _code;
        return ss.ss();
    }
    
    std::string MouseKeyReleasedEvent::verboseStr() const
    {
        std::stringstream ss;
        ss << "Released Mouse Button: " << _code;
        return ss.ss();
    }
    
    std::string MouseScrollEvent::verboseStr() const
    {
        std::stringstream ss;
        ss << "Mouse Scrolled Offset x: " << _xOffset << ", y: " << _yOffset;
        return ss.ss();
    }
}