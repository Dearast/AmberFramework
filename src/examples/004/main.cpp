#include "../../framework/AmberFramework.h"

class Layer_MainWindow : public Amber::LayerWindow
{
    public:
        Layer_MainWindow() : LayerWindow({"LayerWindowExample - SDL2", true, 320, 240})
        {

        }

        void OnUpdate() override
        {
            Window_Clear();

            Renderer_SetColor(255, 200, 60);
            Renderer_Print(0, 0, "Amber Framework", 2, 2);
            Renderer_Print(0, 8*4, "Hello, World!");

            //TODO Make some system for better writing japanese without numbers
            //NOTE Some example of printing japanese hiragana on window
            Renderer_Print(0, 8*6, 503, 2, 2);
            Renderer_Print((8*1*2), 8*6, 504, 2, 2);
            Renderer_Print((8*2*2), 8*6, 505, 2, 2);

            //TODO Make some system for global pixel size set
            //NOTE Rendering pixels
            Renderer_Print(0, 100, "This is pixel 1x1 - ");
            Renderer_Pixel(160, 100);

            Renderer_Print(0, 116, "This is pixel 2x2 - ");
            Renderer_Pixel(160, 116, 2, 2);

            Renderer_Print(0, 132, "This is pixel 3x3 - ");
            Renderer_Pixel(160, 132, 3, 3);

            Window_Draw();
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
