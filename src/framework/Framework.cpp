#include "Framework.h"

namespace Amber
{
    void Framework::Run() const
    {
        AMBER_CORE_INFO("[Framework] -> [Status] -> [Running]");
        while(m_running)
        {
            for (const auto& layer : this->m_layerStack.m_layers)
            {
                layer->OnUpdate();
            }
        }
    }

    void Framework::PushLayer(Layer* t_layer)
    {
        m_layerStack.PushLayer(t_layer);
    }

    void Framework::PopLayer(Layer* t_layer)
    {
        m_layerStack.PopLayer(t_layer);
    }
}
