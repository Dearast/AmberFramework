#pragma once

#include <vector>
#include <memory>

#include "Core.h"
#include "Layer.h"

namespace Amber
{
    class AMBER_API LayerStack
    {
    public:
    std::vector<std::shared_ptr<Layer>> m_layers;
    public:
    ~LayerStack();

    void PushLayer(const std::shared_ptr<Layer>& t_layer);
    void PopLayer(const std::shared_ptr<Layer>& t_layer);

    unsigned long int size() { return m_layers.size(); }
    };
}
