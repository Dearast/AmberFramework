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
                if(!layer->m_running)
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
            layer->OnEvent(this->m_event);
        }
    }

    void Framework::PushLayer(const std::shared_ptr<Layer>& t_layer)
    {
        m_layerStack.PushLayer(t_layer);
    }

    void Framework::PopLayer(const std::shared_ptr<Layer>& t_layer)
    {
        m_layerStack.PopLayer(t_layer);
    }
}

//NOTE Moved EntryPoint here to framework
int main()
{
    Amber::Logger::Init();

    //FIXME Getting error [deleting a pointer through a type that is not marked 'gsl::owner<>'; consider using a smart pointer instead]
    //TODO Create smart pointer here
    auto framework = Amber::CreateFramework();
    framework->Run();
    delete framework;

    return 0;
}
