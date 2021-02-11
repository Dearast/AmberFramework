#pragma once

#include "Core.h"

#include <memory>

#if defined(COMPILE_WITH_SFML)
#include <SFML/Graphics.hpp>
#elif defined(COMPILE_WITH_SDL)
#include <SDL2/SDL.h>
#endif

namespace Amber
{
    class AMBER_API Layer
    {
    public:
    bool m_running = true;
    virtual ~Layer() {}

    virtual void OnAttach() {}
    virtual void OnDetach() {}
    virtual void OnUpdate() {}
#if defined(COMPILE_WITH_SFML)
    virtual void OnEvent(sf::Event& t_event)  {}
#elif defined(COMPILE_WITH_SDL)
    virtual void OnEvent(SDL_Event& t_event)  {}
#endif
    };
}
