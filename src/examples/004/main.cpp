#include "../../framework/AmberFramework.h"

class Layer_MainWindow : public Amber::LayerWindow
{
    public:
        Layer_MainWindow() : LayerWindow({"LayerWindowExample - SDL2", true, 320, 240})
        {

        }

        void OnUpdate() override
        {
            this->m_window->ClearWindow();

            //TODO Add some examples
            this->m_window->Set_Renderer_Color(255, 200, 60);
            this->m_window->DrawR_CFont8x8_string(0, 0, "Amber Framework", 2, 2);
            this->m_window->DrawR_Font8x8_string(0, 8*4, "Hello, World!");

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

class Framework_004 : public Amber::Framework
{
    public:
        Framework_004()
        {
            PushLayer(std::make_shared<Layer_MainWindow>());
        }
};

Amber::Framework* Amber::CreateFramework()
{
    return new Framework_004();
}
