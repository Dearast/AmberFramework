#include "../../framework/AmberFramework.h"

#if defined(COMPILE_WITH_SFML)  //NOTE When is defined for SFML
class LayerWindowExample : public Amber::LayerWindow
{
    public:
        LayerWindowExample() : LayerWindow({"LayerWindowExample - SFML", true, 320, 240})
        {

        }

        void OnUpdate() override
        {
            this->m_window->ClearWindow();

            //TODO Add some examples

            this->m_window->OnUpdate();
        }

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

        void OnDetach() override
        {
            //FIXME This move to LayerWindow or Window!
            this->m_window->m_window.close();
        }
};
#elif defined(COMPILE_WITH_SDL)  //NOTE When is defined for SDL2
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
#endif

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
