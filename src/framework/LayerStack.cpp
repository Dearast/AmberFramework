#include "LayerStack.h"
#include <algorithm>

namespace Amber
{
    LayerStack::~LayerStack()
    {
        for(const auto& layer : this->m_layers)
        {
            layer->OnDetach();
            delete layer;
        }
    }

    void LayerStack::PushLayer(Layer* t_layer)
    {
        this->m_layers.emplace_back(t_layer);
        t_layer->OnAttach();
    }

    void LayerStack::PopLayer(Layer* t_layer)
    {
        auto find = std::find(this->m_layers.begin(), this->m_layers.end(), t_layer);
        if(find != this->m_layers.end())
        {
            t_layer->OnDetach();
            this->m_layers.erase(find);
        }
    }
}
