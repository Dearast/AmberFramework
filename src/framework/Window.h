#pragma once

#include <string>

#include "Core.h"
#include "Logger.h"

#include <SDL2/SDL.h>

namespace Amber
{
    enum Colors
    {
        Red   = 0xFF0000,
        Green = 0x00FF00,
        Blue  = 0x0000FF,
    };

    struct WindowProps
    {
        std::string title;
        bool vsync;
        int width;
        int height;

        WindowProps(const std::string& t_title = "Amber Framework",
                    const bool& t_vsync = false,
                    const int& t_width = 1280,
                    const int& t_height = 720) : title(t_title), vsync(t_vsync), width(t_width), height(t_height) {}
    };

    class AMBER_API Window
    {
    public:
    WindowProps m_windowProps;
    SDL_Window* m_window = nullptr;
    SDL_Renderer* m_renderer = nullptr;
    public:
    ~Window();

    void Init(const WindowProps& t_props = WindowProps());
    void OnUpdate();

    void ClearWindow();

    //NOTE Setting Window Properties
    void Set_Window_Bordered(const SDL_bool& t_state);
    void Set_Window_Resizable(const SDL_bool& t_state);
    //NOTE Setting Renderer Properties
    void Set_Renderer_Color(const Uint8& t_red, const Uint8& t_green, const Uint8& t_blue, const Uint8& t_alpha = 255);
    void Set_Renderer_Color(const Uint32& t_hexColor, const Uint8& t_alpha = 255);
    //NOTE Drawing with Renderer Pixels
    void DrawR_Pixel(const int& t_x, const int& t_y);
    //TODO: Implement drawing under commented section
/*
    void DrawR_Pixels(const std::vector<SDL_Point>& t_points, const int& t_count);
    */
    void DrawR_CPixel(const int& t_x, const int& t_y, const int& t_pixelSizeX, const int& t_pixelSizeY);
    //TODO: Implement drawing under commented section
/*
    void DrawR_CPixels(const std::vector<SDL_Rect>& t_rects, const int& t_count, const int& t_pixelSizeX, const int& t_pixelSizeY);
    */
    //NOTE Drawing with Renderer Lines
    void DrawR_Line(const int& t_x1, const int& t_y1, const int& t_x2, const int& t_y2);
    //TODO: Implement drawing under commented section
/*
    void DrawR_Lines(const std::vector<SDL_Point>& t_points, const int& t_count);
    */
    void DrawR_CLine(const int& t_x1, const int& t_y1, const int& t_x2, const int& t_y2, const int& t_pixelSizeX, const int& t_pixelSizeY) ;
    //TODO: Implement drawing under commented section
/*
    void DrawR_CLines(const std::vector<SDL_Point>& t_points, const int& t_count, const int& t_pixelSizeX, const int& t_pixelSizeY);
    //NOTE Drawing with Renderer Rectangles [BLANK]
    void DrawR_Rectangle(const int& t_x, const int& t_y, const int& t_sizeX, const int& t_sizeY);
    void DrawR_Rectangles(const std::vector<SDL_Rect>& t_rects, const int& t_count);
    void DrawR_CRectangle(const int& t_x, const int& t_y, const int& t_sizeX, const int& t_sizeY, const int& t_pixelSizeX, const int& t_pixelSizeY);
    void DrawR_CRectangles(const std::vector<SDL_Rect>& t_rects, const int& t_count, const int& t_pixelSizeX, const int& t_pixelSizeY);
    */
    //NOTE Drawing with Renderer Fonts
    void DrawR_Font8x8(const int& t_x, const int& t_y, const size_t& t_id);
    void DrawR_Font8x8_string(const int& t_x, const int& t_y, const std::string& t_ids) ;
    void DrawR_CFont8x8(const int& t_x, const int& t_y, const size_t& t_id, const int& t_pixelSizeX, const int& t_pixelSizeY);
    void DrawR_CFont8x8_string(const int& t_x, const int& t_y, const std::string& t_ids, const int& t_pixelSizeX, const int& t_pixelSizeY);
    };
}
