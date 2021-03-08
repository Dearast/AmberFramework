#include "../../framework/AmberFramework.h"

constexpr int WINDOW_SIZE_X = 320;
constexpr int WINDOW_SIZE_Y = 480;

class Layer_MainWindow : public Amber::LayerWindow
{
    private:
        uint8_t m_gameState = 0;      //DESC: 0 = MainMenu | 1 = In Arcade(In Game) | 2 = GameOver
        uint8_t m_mainMenuState = 0;  //DESC: 0 = Play | 1 = Quit
    public:
        Layer_MainWindow() : LayerWindow({"Asteroids tunnels", true, WINDOW_SIZE_X, WINDOW_SIZE_Y})
        {

        }

        void OnUpdate() override
        {
            Window_Clear();

            //TODO: Use imgui
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
                        Draw_SetColor(Amber::Colors::Red);
                    }
                    Draw_Print(160, 210, "Quit");

                    break;
                }
            }
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
