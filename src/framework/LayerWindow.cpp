#include "LayerWindow.h"

namespace Amber
{
    LayerWindow::LayerWindow(const WindowProps& t_windowProps)
    {
        this->m_window = std::make_shared<Window>();
        this->m_window->Init(t_windowProps);
    }

    //NOTE Reintrepret from Window
    void LayerWindow::Window_Draw()
    {
        this->m_window->OnUpdate();
    }

    void LayerWindow::Window_Clear()
    {
        this->m_window->ClearWindow();
    }

    void LayerWindow::Draw_SetColor(const Uint8& t_red, const Uint8& t_green, const Uint8& t_blue, const Uint8& t_alpha)
    {
        this->m_window->Set_Renderer_Color(t_red, t_green, t_blue, t_alpha);
    }

    void LayerWindow::Draw_SetColor(const Uint32& t_hexColor, const Uint8& t_alpha)
    {
        this->m_window->Set_Renderer_Color(t_hexColor, t_alpha);
    }

    void LayerWindow::Draw_Pixel(const int& t_x, const int& t_y)
    {
        this->m_window->DrawR_Pixel(t_x, t_y);
    }
    void LayerWindow::Draw_Pixel(const int& t_x, const int& t_y, const int& t_pixelSizeX, const int& t_pixelSizeY)
    {
        this->m_window->DrawR_CPixel(t_x, t_y, t_pixelSizeX, t_pixelSizeY);
    }
    //TODO: Implement drawing under commented section
/*
    void LayerWindow::Draw_Pixels(const std::vector<SDL_Point>& t_points, const int& t_count)
    {
        this->m_window->DrawR_Pixels(t_points, t_count);
    }
    void LayerWindow::Draw_Pixels(const std::vector<SDL_Rect>& t_rects, const int& t_count, const int& t_pixelSizeX, const int& t_pixelSizeY)
    {
        this->m_window->DrawR_CPixels(t_rects, t_count, t_pixelSizeX, t_pixelSizeY);
    }
    */

    void LayerWindow::Draw_Line(const int& t_x1, const int& t_y1, const int& t_x2, const int& t_y2)
    {
        this->m_window->DrawR_Line(t_x1, t_y1, t_x2, t_y2);
    }
    void LayerWindow::Draw_Line(const int& t_x1, const int& t_y1, const int& t_x2, const int& t_y2, const int& t_pixelSizeX, const int& t_pixelSizeY)
    {
        this->m_window->DrawR_CLine(t_x1, t_y1, t_x2, t_y2, t_pixelSizeX, t_pixelSizeY);
    }
    //TODO: Implement drawing under commented section
/*
    void LayerWindow::Draw_Lines(const std::vector<SDL_Point>& t_points, const int& t_count)
    {
        this->m_window->DrawR_Lines(t_points, t_count);
    }
    void LayerWindow::Draw_Lines(const std::vector<SDL_Point>& t_points, const int& t_count, const int& t_pixelSizeX, const int& t_pixelSizeY)
    {
        this->m_window->DrawR_CLines(t_points, t_count, t_pixelSizeX, t_pixelSizeY);
    }
    */

    void LayerWindow::Draw_Print(const int& t_x, const int& t_y, const size_t& t_id)
    {
        this->m_window->DrawR_Font8x8(t_x, t_y, t_id);
    }
    void LayerWindow::Draw_Print(const int& t_x, const int& t_y, const std::string& t_ids)
    {
        this->m_window->DrawR_Font8x8_string(t_x, t_y, t_ids);
    }
    void LayerWindow::Draw_Print(const int& t_x, const int& t_y, const size_t& t_id, const int& t_pixelSizeX, const int& t_pixelSizeY)
    {
        this->m_window->DrawR_CFont8x8(t_x, t_y, t_id, t_pixelSizeX, t_pixelSizeY);
    }
    void LayerWindow::Draw_Print(const int& t_x, const int& t_y, const std::string& t_ids, const int& t_pixelSizeX, const int& t_pixelSizeY)
    {
        this->m_window->DrawR_CFont8x8_string(t_x, t_y, t_ids, t_pixelSizeX, t_pixelSizeY);
    }
}
