#include "Framework.h"

namespace Amber
{
    void Framework::Run()
    {
        AMBER_CORE_INFO("[Framework] -> [Status] -> [Running]");

        while(m_running)
        {
            if(this->m_closeWhenAllLayerAreClosed)
            {
                if(this->m_layerStack.size() == 0)
                {
                    this->m_running = false;
                }
            }

            OnEvent();

            for (const auto& layer : this->m_layerStack.m_layers)
            {
                layer->OnUpdate();
                if(layer->m_running == false)
                {
                    PopLayer(layer);
                }
            }
        }
    }

    void Framework::OnEvent()
    {
        for (const auto& layer : this->m_layerStack.m_layers)
        {
            #if defined(COMPILE_WITH_SFML)
            layer->OnEvent(this->m_event);
            #endif
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
