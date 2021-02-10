#include "../../framework/AmberFramework.h"

class LayerWindowExample : public Amber::LayerWindow
{
    public:
        LayerWindowExample() : LayerWindow({"LayerWindowExample", true, 320, 240})
        {

        }

        void OnUpdate() override
        {
            this->m_window->ClearWindow();

            //TODO Add some examples

            this->m_window->OnUpdate();
        }

#if defined(COMPILE_WITH_SFML)
        void OnEvent(sf::Event& t_event) override
        {
            while(this->m_window->m_window.pollEvent(t_event))
            {
                if(t_event.type == sf::Event::Closed)
                {
                    AMBER_CLIENT_INFO("CLOSING...");
                    this->m_running = false;
                }
            }
        }
#endif

        void OnDetach()
        {
#if defined(COMPILE_WITH_SFML)
            this->m_window->m_window.close();
#endif
        }
};

class ExampleFramework : public Amber::Framework
{
    public:
        ExampleFramework()
        {
            PushLayer(new LayerWindowExample());
        }
};

Amber::Framework* Amber::CreateFramework()
{
    return new ExampleFramework();
}
