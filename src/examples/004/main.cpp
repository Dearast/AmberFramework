#include "../../framework/AmberFramework.h"

class Layer_MainWindow:public Amber::LayerWindow
{
    private:
        std::string m_windowName = "Example - 004";
    public:
        Layer_MainWindow():LayerWindow({this->m_windowName, true, 320, 240})
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

class Framework:public Amber::Framework
{
    public:
        Framework()
        {
            PushLayer(std::make_shared<Layer_MainWindow>());
        }
};

Amber::Framework* Amber::CreateFramework()
{
    return new Framework();
}
