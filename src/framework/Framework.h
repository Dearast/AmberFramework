#pragma once

#include "Core.h"
#include "Logger.h"
#include "LayerStack.h"

#include <memory>

#if defined(COMPILE_WITH_SFML)
#include <SFML/Graphics.hpp>
#elif defined(COMPILE_WITH_SDL)
#include <SDL2/SDL.h>
#endif

namespace Amber
{
    class AMBER_API Framework
    {
    private:
    bool m_running = true;
    bool m_closeWhenAllLayerAreClosed = true;
    LayerStack m_layerStack;
    public:
#if defined(COMPILE_WITH_SFML)
    sf::Event m_event;
#elif defined(COMPILE_WITH_SDL)
    SDL_Event m_event;
#endif

    void Run();
    void OnEvent();

    void PushLayer(Layer* t_layer);

    void PopLayer(Layer* t_layer);

    void Set_Running(const bool& t_state) { this->m_running = t_state; }
};

    Framework* CreateFramework();
}
