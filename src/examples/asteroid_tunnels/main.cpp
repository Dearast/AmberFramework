#include "../../framework/AmberFramework.h"

class Layer_MainWindow : public Amber::LayerWindow
{
    private:
        unsigned int m_gameState = 0;  //NOTE 0 = MainMenu | 1 = In Arcade(In Game) | 2 = GameOver
        unsigned int m_mainMenuState = 0;  //NOTE 0 = Play | 1 = Quit
    public:
        Layer_MainWindow() : LayerWindow({"Asteroids tunnels", true, 320, 480})
        {

        }

        void OnUpdate() override
        {
            Window_Clear();

            switch (this->m_gameState) {
                case 0:
                {
                    Draw_SetColor(255, 200, 60);
                    Draw_Print(80, 0, "Asteroids tunnels!");

                    if(this->m_mainMenuState == 0)
                    {
                        Draw_SetColor(255, 200, 60);
                    }
                    else
                    {
                        Draw_SetColor(200, 150, 60);
                    }
                    Draw_Print(160, 200, "Play");

                    if(this->m_mainMenuState == 1)
                    {
                        Draw_SetColor(255, 60, 60);
                    }
                    else
                    {
                        Draw_SetColor(200, 60, 60);
                    }
                    Draw_Print(160, 210, "Quit");

                    break;
                }
            }



            /*

            Draw_Print(0, 0, "Amber Framework", 2, 2);
            Draw_Print(0, 8*4, "Hello, World!");

            //TODO Make some system for better writing japanese without numbers
            //NOTE Some example of printing japanese hiragana on window
            Draw_Print(0, 8*6, 503, 2, 2);
            Draw_Print((8*1*2), 8*6, 504, 2, 2);
            Draw_Print((8*2*2), 8*6, 505, 2, 2);

            //TODO Make some system for global pixel size set
            //NOTE Drawing pixels
            Draw_Print(0, 100, "This is pixel 1x1 - ");
            Draw_Pixel(160, 100);

            Draw_Print(0, 116, "This is pixel 2x2 - ");
            Draw_Pixel(160, 116, 2, 2);

            Draw_Print(0, 132, "This is pixel 3x3 - ");
            Draw_Pixel(160, 132, 3, 3);

            //NOTE Drawing Lines
            Draw_Line(0, 140, 160, 148);
            Draw_Line(0, 150, 160, 158, 2, 2);
*/

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
                if(t_event.type == SDL_KEYDOWN)
                {
                    //NOTE Check keys input for mainMenu
                    switch (this->m_gameState) {
                        case 0:
                        {
                            switch (t_event.key.keysym.sym) {
                                case SDLK_w:
                                {
                                    if(this->m_mainMenuState > 0)
                                    {
                                        this->m_mainMenuState--;
                                    }
                                    break;
                                }
                                case SDLK_s:
                                {
                                    if(this->m_mainMenuState < 1)
                                    {
                                        this->m_mainMenuState++;
                                    }
                                    break;
                                }
                                case SDLK_RETURN:
                                {
                                    switch (this->m_mainMenuState) {
                                        case 0:
                                        {
                                            break;
                                        }
                                        case 1:
                                        {
                                            this->m_running = 0;
                                            break;
                                        }
                                    }

                                }
                            }

                            break;
                        }
                    }
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
