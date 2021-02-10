#pragma once

#include <string>

#include "Core.h"
#include "Logger.h"

#if defined(COMPILE_WITH_SFML)
#include <SFML/Graphics.hpp>
#elif defined(COMPILE_WITH_SDL)
#endif

namespace Amber
{
    struct WindowProps
    {
        std::string title;
        bool vsync;
        unsigned int width;
        unsigned int height;

        WindowProps(const std::string& t_title = "Amber Framework",
                    const bool& t_vsync = false,
                    const unsigned int& t_width = 1280,
                    const unsigned int& t_height = 720) : title(t_title), width(t_width), height(t_height), vsync(t_vsync) {}
    };

    class AMBER_API Window
    {
    public:
#if defined(COMPILE_WITH_SFML)
    sf::RenderWindow m_window;
    sf::Event m_event;
    WindowProps m_windowProps;
#endif
    public:
    ~Window();

    void Init(const WindowProps& t_props = WindowProps());
    void OnUpdate();

    void ClearWindow();
    };
}

/*

namespace GameEngine
{
	class GAMEENGINE_API Window
	{
	public:
		SDL_Window* m_window = nullptr;
		SDL_Renderer* m_renderer = nullptr;

		std::shared_ptr<WindowProps> m_windowProps;

		//using EventCallbackFn = std::function<void(Event&)>;

		Window();
		~Window();

		void OnUpdate();
		void ClearWindow();

		std::shared_ptr<WindowProps> Get_windowProps();

		void Init(const WindowProps& t_props = WindowProps());

		// Properties
		void Set_WindowBordered(const SDL_bool& t_state);
		void Set_WindowResizable(const SDL_bool& t_state);

        // Drawing with Renderer
        void Set_Renderer_Color(const Uint8& t_red, const Uint8& t_green, const Uint8& t_blue, const Uint8& t_alpha);

        // Pixel/Point
        void DrawR_Pixel(const int& t_x, const int& t_y);
        void DrawR_Pixels(const std::vector<SDL_Point>& t_points, const int& t_count);
        void DrawR_CPixel(const int& t_x, const int& t_y, const int& t_pixelSizeX, const int& t_pixelSizeY);
        void DrawR_CPixels(const std::vector<SDL_Rect>& t_rects, const int& t_count, const int& t_pixelSizeX, const int& t_pixelSizeY);
        // Line
        void DrawR_Line(const int& t_x1, const int& t_y1, const int& t_x2, const int& t_y2);
        void DrawR_Lines(const std::vector<SDL_Point>& t_points, const int& t_count);
        void DrawR_CLine(const int& t_x1, const int& t_y1, const int& t_x2, const int& t_y2, const int& t_pixelSizeX, const int& t_pixelSizeY) ;
        void DrawR_CLines(const std::vector<SDL_Point>& t_points, const int& t_count, const int& t_pixelSizeX, const int& t_pixelSizeY);
        // Rectangle [BLANK]
        void DrawR_Rectangle(const int& t_x, const int& t_y, const int& t_sizeX, const int& t_sizeY);
        void DrawR_Rectangles(const std::vector<SDL_Rect>& t_rects, const int& t_count);
        void DrawR_CRectangle(const int& t_x, const int& t_y, const int& t_sizeX, const int& t_sizeY, const int& t_pixelSizeX, const int& t_pixelSizeY);
        void DrawR_CRectangles(const std::vector<SDL_Rect>& t_rects, const int& t_count, const int& t_pixelSizeX, const int& t_pixelSizeY);
        // Fonts
        void DrawR_Font8x8(const int& t_x, const int& t_y, const int& t_id);
        void DrawR_Font8x8_string(const int& t_x, const int& t_y, const std::string& t_ids) ;
        void DrawR_CFont8x8(const int& t_x, const int& t_y, const int& t_id, const int& t_pixelSizeX, const int& t_pixelSizeY);
	};
}
*/
