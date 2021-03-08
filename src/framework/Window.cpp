#include "Window.h"

#include "Font8x8.hpp"

namespace Amber
{
    Window::~Window()
    {
        SDL_DestroyRenderer(this->m_renderer);
        SDL_DestroyWindow(this->m_window);
    }

    void Window::Init(const WindowProps& t_props)
    {
        this->m_windowProps = t_props;
        if(SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            AMBER_CORE_ERROR("SDL2 could not initialize! SDL_Error: {0}", SDL_GetError());
        }
        else
        {
            const char* titleBuffer = this->m_windowProps.title.c_str();
            this->m_window = SDL_CreateWindow(titleBuffer, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->m_windowProps.width, this->m_windowProps.height, SDL_WINDOW_SHOWN);
            if(this->m_window == nullptr)
            {
                AMBER_CORE_ERROR("SDL2 could not create window! SDL_Error: {0}", SDL_GetError());
            }
            else
            {
                if(this->m_windowProps.vsync)
                {
                    this->m_renderer = SDL_CreateRenderer(this->m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
                }
                else
                {
                    this->m_renderer = SDL_CreateRenderer(this->m_window, -1, SDL_RENDERER_ACCELERATED);
                }

                if(this->m_renderer == nullptr)
                {
                    AMBER_CORE_ERROR("SDL2 could not create renderer for window! SDL_Error: {0}", SDL_GetError());
                }
                else
                {
                    SDL_SetRenderDrawColor(this->m_renderer, 0, 0, 0, 255);
                    SDL_RenderClear(this->m_renderer);
                    SDL_RenderPresent(this->m_renderer);

                    AMBER_CORE_INFO("SDL2 is initialized!");
                }
            }
        }
    }

    void Window::OnUpdate()
    {
        SDL_RenderPresent(this->m_renderer);
    }

    void Window::ClearWindow()
    {
        SDL_SetRenderDrawColor(this->m_renderer, 0, 0, 0, 255);
        SDL_RenderClear(this->m_renderer);
    }

    void Window::Set_Window_Bordered(const SDL_bool& t_state)
    {
        SDL_SetWindowBordered(this->m_window, t_state);
    }

    void Window::Set_Window_Resizable(const SDL_bool& t_state)
    {
        SDL_SetWindowResizable(this->m_window, t_state);
    }

    void Window::Set_Renderer_Color(const Uint8& t_red, const Uint8& t_green, const Uint8& t_blue, const Uint8& t_alpha)
    {
        SDL_SetRenderDrawColor(this->m_renderer, t_red, t_green, t_blue, t_alpha);
    }

    void Window::Set_Renderer_Color(const Uint32& t_hexColor, const Uint8& t_alpha)
    {
        const Uint8 red   = static_cast<Uint8>((t_hexColor & 0xFF0000) >> 16);
        const Uint8 green = static_cast<Uint8>((t_hexColor & 0x00FF00) >> 8);
        const Uint8 blue  = static_cast<Uint8>(t_hexColor & 0x0000FF);

        SDL_SetRenderDrawColor(this->m_renderer, red, green, blue, t_alpha);
    }

    void Window::DrawR_Pixel(const int& t_x, const int& t_y)
    {
        SDL_RenderDrawPoint(this->m_renderer, t_x, t_y);
    }

//TODO: Implement drawing under commented section
/*
    void Window::DrawR_Pixels(const std::vector<SDL_Point>& t_points, const int& t_count)
    {
    }
    */

    void Window::DrawR_CPixel(const int& t_x, const int& t_y, const int& t_pixelSizeX, const int& t_pixelSizeY)
    {
        SDL_Rect rect{ t_x, t_y, t_pixelSizeX, t_pixelSizeY };
        SDL_RenderFillRect(this->m_renderer, &rect);
    }

//TODO: Implement drawing under commented section
/*
    void Window::DrawR_CPixels(const std::vector<SDL_Rect>& t_rects, const int& t_count, const int& t_pixelSizeX, const int& t_pixelSizeY)
    {
    }
    */

    void Window::DrawR_Line(const int& t_x1, const int& t_y1, const int& t_x2, const int& t_y2)
    {
        SDL_RenderDrawLine(this->m_renderer, t_x1, t_y1, t_x2, t_y2);
    }

//TODO: Implement drawing under commented section
/*
    void Window::DrawR_Lines(const std::vector<SDL_Point>& t_points, const int& t_count)
    {
    }
    */

    void Window::DrawR_CLine(const int& t_x1, const int& t_y1, const int& t_x2, const int& t_y2, const int& t_pixelSizeX, const int& t_pixelSizeY)
    {
        for (int y = 0; y < t_pixelSizeY; y++) {
            for (int x = 0; x < t_pixelSizeX; x++) {
                this->DrawR_Line(t_x1 + x, t_y1 + y, t_x2 + x, t_y2 + y);
            }
        }
    }

//TODO: Implement drawing under commented section
/*
    void Window::DrawR_CLines(const std::vector<SDL_Point>& t_points, const int& t_count, const int& t_pixelSizeX, const int& t_pixelSizeY)
    {
    }

    void Window::DrawR_Rectangle(const int& t_x, const int& t_y, const int& t_sizeX, const int& t_sizeY)
    {
    }

    void Window::DrawR_Rectangles(const std::vector<SDL_Rect>& t_rects, const int& t_count)
    {
    }

    void Window::DrawR_CRectangle(const int& t_x, const int& t_y, const int& t_sizeX, const int& t_sizeY, const int& t_pixelSizeX, const int& t_pixelSizeY)
    {
    }

    void Window::DrawR_CRectangles(const std::vector<SDL_Rect>& t_rects, const int& t_count, const int& t_pixelSizeX, const int& t_pixelSizeY)
    {
    }
    */

    void Window::DrawR_Font8x8(const int& t_x, const int& t_y, const size_t& t_id)
    {
        int x, y;
        int set;
        for (y = 0; y < 8; y++) {
            for (x = 0; x < 8; x++) {
                set = font8x8[t_id][y] & 1 << x;
                if (set > 0)
                {
                    this->DrawR_Pixel(t_x + x, t_y + y);
                }
            }
        }
    }

    void Window::DrawR_Font8x8_string(const int& t_x, const int& t_y, const std::string& t_ids)
    {
        for (size_t i = 0; i < t_ids.size(); i++)
        {
            if (t_ids[i] != ' ')
            {
                this->DrawR_Font8x8(t_x + (8 * static_cast<int>(i)), t_y, static_cast<size_t>(t_ids[i]));
            }
        }
    }

    void Window::DrawR_CFont8x8(const int& t_x, const int& t_y, const size_t& t_id, const int& t_pixelSizeX, const int& t_pixelSizeY)
    {
        int x, y;
        int set;
        //int mask; //NOTE: unused
        for (y = 0; y < 8; y++) {
            for (x = 0; x < 8; x++) {
                set = (font8x8[t_id][y] & 1) << x; //NOTE: signed 1
                if (set > 0)
                {
                    this->DrawR_CPixel(t_x + x * t_pixelSizeX, t_y + y * t_pixelSizeY, t_pixelSizeX, t_pixelSizeY);
                }
            }
        }
    }

    void Window::DrawR_CFont8x8_string(const int& t_x, const int& t_y, const std::string& t_ids, const int& t_pixelSizeX, const int& t_pixelSizeY)
    {
        constexpr int fontMultiplyer = 8;
        for (size_t i = 0; i < t_ids.size(); i++)
        {
            if (t_ids[i] != ' ')
            {
                this->DrawR_CFont8x8(t_x + (fontMultiplyer * static_cast<int>(i) * t_pixelSizeX), t_y, static_cast<size_t>(t_ids[i]), t_pixelSizeX, t_pixelSizeY);
            }
        }
    }
}
