#pragma once

#include <vector>

#include "Core.h"
#include "Layer.h"

namespace Amber
{
    class AMBER_API LayerStack
    {
    public:
    std::vector<Layer*> m_layers;
    public:
    ~LayerStack();

    void PushLayer(Layer* t_layer);
    void PopLayer(Layer* t_layer);

    unsigned long int size() { return m_layers.size(); }
    };
}
