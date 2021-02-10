#include "../../framework/AmberFramework.h"

class LayerExample : public Amber::Layer
{
public:
        LayerExample()
        {
            AMBER_CLIENT_INFO("LayerExample is constructed.");
        }

        ~LayerExample()
        {
            AMBER_CLIENT_INFO("LayerExample is destroyed.");
        }

        void OnAttach() override
        {
            AMBER_CLIENT_INFO("LayerExample is attached.");
        }

        void OnUpdate() override
        {
            //AMBER_CLIENT_INFO("Updating LayerExample...");
        }

        void OnDetach() override
        {
            AMBER_CLIENT_INFO("LayerExample is detached.");
        }
};

class Example_002 : public Amber::Framework
{
    public:
        Example_002()
        {
            Amber::Logger::Set_ClientLoggerName("[EXAMP-002]");
            AMBER_CLIENT_INFO("Example_002 is constructed.");

            PushLayer(new LayerExample());

            //NOTE this will disable Update loop
            this->Set_Running(false);
        }
};

Amber::Framework* Amber::CreateFramework()
{
    return new Example_002();
}
