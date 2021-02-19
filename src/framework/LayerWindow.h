#pragma once

#include <memory>

#include "Core.h"
#include "Logger.h"
#include "Layer.h"
#include "Window.h"
#include <memory>

namespace Amber
{
    class AMBER_API LayerWindow : public Layer
    {
    public:
        std::shared_ptr<Window> m_window;
    public:
        LayerWindow(const WindowProps& t_windowProps = WindowProps());

        void OnAttach() override {}
        void OnDetach() override {}
        void OnUpdate() override {}
        void OnEvent([[maybe_unused]] SDL_Event& t_event) override  {}

        //NOTE Reintrepret from Window
        void Window_Draw();
        void Window_Clear();

        void Draw_SetColor(const Uint8& t_red, const Uint8& t_green, const Uint8& t_blue, const Uint8& t_alpha = 255);

        void Draw_Pixel(const int& t_x, const int& t_y);
        void Draw_Pixel(const int& t_x, const int& t_y, const int& t_pixelSizeX, const int& t_pixelSizeY);
        void Draw_Pixels(const std::vector<SDL_Point>& t_points, const int& t_count);
        void Draw_Pixels(const std::vector<SDL_Rect>& t_rects, const int& t_count, const int& t_pixelSizeX, const int& t_pixelSizeY);

        void Draw_Print(const int& t_x, const int& t_y, const int& t_id);
        void Draw_Print(const int& t_x, const int& t_y, const std::string& t_ids) ;
        void Draw_Print(const int& t_x, const int& t_y, const int& t_id, const int& t_pixelSizeX, const int& t_pixelSizeY);
        void Draw_Print(const int& t_x, const int& t_y, const std::string& t_ids, const int& t_pixelSizeX, const int& t_pixelSizeY);
    };
}
