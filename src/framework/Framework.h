#pragma once

#include "Core.h"
#include "Logger.h"
#include "LayerStack.h"

namespace Amber
{
    class AMBER_API Framework
    {
    private:
    bool m_running = true;
    LayerStack m_layerStack;
    public:
    void Run() const;

    void PushLayer(Layer* t_layer);

    void PopLayer(Layer* t_layer);

    void Set_Running(const bool& t_state) { this->m_running = t_state; }
};

    Framework* CreateFramework();
}
