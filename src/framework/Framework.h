#pragma once

#include "Core.h"
#include "Logger.h"
#include "LayerStack.h"

#include <memory>

#include <SDL2/SDL.h>

namespace Amber
{
    class AMBER_API Framework
    {
    private:
    bool m_running = true;
    bool m_closeWhenAllLayerAreClosed = true;
    LayerStack m_layerStack;
    public:
    SDL_Event m_event;

    void Run();
    void OnEvent();

    void PushLayer(const std::shared_ptr<Layer>& t_layer);

    void PopLayer(const std::shared_ptr<Layer>& t_layer);

    void Set_Running(const bool& t_state) { this->m_running = t_state; }
};

    Framework* CreateFramework();
}
