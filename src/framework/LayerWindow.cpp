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

    void LayerWindow::Renderer_SetColor(const Uint8& t_red, const Uint8& t_green, const Uint8& t_blue, const Uint8& t_alpha)
    {
        this->m_window->Set_Renderer_Color(t_red, t_green, t_blue, t_alpha);
    }
    void LayerWindow::Renderer_Print(const int& t_x, const int& t_y, const int& t_id)
    {
        this->m_window->DrawR_Font8x8(t_x, t_y, t_id);
    }
    void LayerWindow::Renderer_Print(const int& t_x, const int& t_y, const std::string& t_ids)
    {
        this->m_window->DrawR_Font8x8_string(t_x, t_y, t_ids);
    }
    void LayerWindow::Renderer_Print(const int& t_x, const int& t_y, const int& t_id, const int& t_pixelSizeX, const int& t_pixelSizeY)
    {
        this->m_window->DrawR_CFont8x8(t_x, t_y, t_id, t_pixelSizeX, t_pixelSizeY);
    }
    void LayerWindow::Renderer_Print(const int& t_x, const int& t_y, const std::string& t_ids, const int& t_pixelSizeX, const int& t_pixelSizeY)
    {
        this->m_window->DrawR_CFont8x8_string(t_x, t_y, t_ids, t_pixelSizeX, t_pixelSizeY);
    }
}
