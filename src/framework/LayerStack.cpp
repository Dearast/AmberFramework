#include "LayerStack.h"

namespace Amber
{
    LayerStack::~LayerStack()
    {
        //NOTE Removing raw pointer from vector is not really smart (-_-)
        //NOTE So here you can look at this https://www.fluentcpp.com/2018/09/18/how-to-remove-pointers-from-a-vector-in-cpp/

        //FIXME Getting error [deleting a pointer through a type that is not marked 'gsl::owner<>'; consider using a smart pointer instead]
        //TODO Sollution is change raw pointer to smart pointer
        for(auto& layer : this->m_layers)
        {
            layer->OnDetach();
            //delete layer;
            layer = nullptr;
        }
        this->m_layers.erase(std::remove(this->m_layers.begin(), this->m_layers.end(), nullptr), this->m_layers.end());
    }

    void LayerStack::PushLayer(const std::shared_ptr<Layer>& t_layer)
    {
        this->m_layers.emplace_back(t_layer);
        t_layer->OnAttach();
    }

    void LayerStack::PopLayer(const std::shared_ptr<Layer>& t_layer)
    {
        auto find = std::find(this->m_layers.begin(), this->m_layers.end(), t_layer);
        if(find != this->m_layers.end())
        {
            t_layer->OnDetach();
            this->m_layers.erase(find);
        }
    }
}
