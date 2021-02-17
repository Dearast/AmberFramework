#pragma once

#include "Core.h"

#include <memory>

#include <SDL2/SDL.h>

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
    virtual void OnEvent([[maybe_unused]] SDL_Event& t_event)  {}
    };
}
