#include "../../framework/AmberFramework.h"

class LayerWindowExample : public Amber::LayerWindow
{
    public:
        LayerWindowExample() : LayerWindow({"LayerWindowExample - SDL2", true, 320, 240})
        {

        }

        void OnUpdate() override
        {
            this->m_window->ClearWindow();

            //TODO Add some examples

            this->m_window->OnUpdate();
        }

        void OnEvent(SDL_Event& t_event) override
        {
            while(SDL_PollEvent(&t_event) != 0 )
            {
                if(t_event.type == SDL_QUIT)
                {
                    AMBER_CLIENT_INFO("CLOSING...");
                    this->m_running = false;
                }
            }
        }
};

class ExampleFramework : public Amber::Framework
{
    public:
        ExampleFramework()
        {
            PushLayer(std::make_shared<LayerWindowExample>());
        }
};

Amber::Framework* Amber::CreateFramework()
{
    return new ExampleFramework();
}
