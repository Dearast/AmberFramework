#include "Window.h"

#include "Font8x8.h"

namespace Amber
{
    Window::~Window()
    {
#if defined(COMPILE_WITH_SFML)
#endif
    }

    void Window::Init(const WindowProps& t_props)
    {
        this->m_windowProps = t_props;
#if defined(COMPILE_WITH_SFML)
        this->m_window.create(sf::VideoMode(800, 600), "SFML window");
#elif defined(COMPILE_WITH_SDL)
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
#endif
    }

    void Window::OnUpdate()
    {
#if defined(COMPILE_WITH_SFML)
        this->m_window.display();
#endif
    }

    void Window::ClearWindow()
    {
#if defined(COMPILE_WITH_SFML)
        this->m_window.clear();
#endif
    }

    #if defined(COMPILE_WITH_SDL)
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

    void Window::DrawR_Pixel(const int& t_x, const int& t_y)
    {
        SDL_RenderDrawPoint(this->m_renderer, t_x, t_y);
    }

    void Window::DrawR_Pixels(const std::vector<SDL_Point>& t_points, const int& t_count)
    {
    }

    void Window::DrawR_CPixel(const int& t_x, const int& t_y, const int& t_pixelSizeX, const int& t_pixelSizeY)
    {
        SDL_Rect rect{ t_x, t_y, t_pixelSizeX, t_pixelSizeY };
        SDL_RenderFillRect(this->m_renderer, &rect);
    }

    void Window::DrawR_CPixels(const std::vector<SDL_Rect>& t_rects, const int& t_count, const int& t_pixelSizeX, const int& t_pixelSizeY)
    {
    }

    void Window::DrawR_Line(const int& t_x1, const int& t_y1, const int& t_x2, const int& t_y2)
    {
    }

    void Window::DrawR_Lines(const std::vector<SDL_Point>& t_points, const int& t_count)
    {
    }

    void Window::DrawR_CLine(const int& t_x1, const int& t_y1, const int& t_x2, const int& t_y2, const int& t_pixelSizeX, const int& t_pixelSizeY)
    {
    }

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

    void Window::DrawR_Font8x8(const int& t_x, const int& t_y, const int& t_id)
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
        for (int i = 0; i < t_ids.size(); i++)
        {
            if (t_ids[i] != ' ')
            {
                this->DrawR_Font8x8(t_x + (8 * i), t_y, t_ids[i]);
            }
        }
    }

    void Window::DrawR_CFont8x8(const int& t_x, const int& t_y, const int& t_id, const int& t_pixelSizeX, const int& t_pixelSizeY)
    {
        int x, y;
        int set;
        int mask;
        for (y = 0; y < 8; y++) {
            for (x = 0; x < 8; x++) {
                set = font8x8[t_id][y] & 1 << x;
                if (set > 0)
                {
                    this->DrawR_CPixel(t_x + x * t_pixelSizeX, t_y + y * t_pixelSizeY, t_pixelSizeX, t_pixelSizeY);
                }
            }
        }
    }
#endif
}

/*
#include "gepch.h"
#include "Window.h"
#include "Font8x8.h"

namespace GameEngine
{
	static bool s_SDLInitialized = false;

	void Window::ClearWindow()
	{
		SDL_SetRenderDrawColor(this->m_renderer, 0, 0, 0, 255);
		SDL_RenderClear(this->m_renderer);
	}

	std::shared_ptr<WindowProps> Window::Get_windowProps()
	{
		return this->m_windowProps;
	}

	void Window::Set_Renderer_Color(const Uint8& t_red, const Uint8& t_green, const Uint8& t_blue, const Uint8& t_alpha)
	{
		SDL_SetRenderDrawColor(this->m_renderer, t_red, t_green, t_blue, t_alpha);
	}

	void Window::DrawR_Pixel(const int& t_x, const int& t_y)
	{
		SDL_RenderDrawPoint(this->m_renderer, t_x, t_y);
	}

	void Window::DrawR_Pixels(const std::vector<SDL_Point>& t_points, const int& t_count)
	{
	}

	void Window::DrawR_CPixel(const int& t_x, const int& t_y, const int& t_pixelSizeX, const int& t_pixelSizeY)
	{
		SDL_Rect rect{ t_x, t_y, t_pixelSizeX, t_pixelSizeY };
		SDL_RenderFillRect(this->m_renderer, &rect);
	}

	void Window::DrawR_CPixels(const std::vector<SDL_Rect>& t_rects, const int& t_count, const int& t_pixelSizeX, const int& t_pixelSizeY)
	{
	}

	void Window::DrawR_Line(const int& t_x1, const int& t_y1, const int& t_x2, const int& t_y2)
	{
	}

	void Window::DrawR_Lines(const std::vector<SDL_Point>& t_points, const int& t_count)
	{
	}

	void Window::DrawR_CLine(const int& t_x1, const int& t_y1, const int& t_x2, const int& t_y2, const int& t_pixelSizeX, const int& t_pixelSizeY)
	{
	}

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

	void Window::DrawR_Font8x8(const int& t_x, const int& t_y, const int& t_id)
	{
		int x, y;
		int set;
		for (y = 0; y < 8; y++) {
			for (x = 0; x < 8; x++) {
				set = font8x8[t_id][y] & 1 << x;
				if (set > 0)
				{
					this->DrawR_Pixel(t_x + x, t_y + y);

					//printf("%c", set ? 'X' : ' ');
				}
			}
		}
	}

	void Window::DrawR_Font8x8_string(const int& t_x, const int& t_y, const std::string& t_ids)
	{
		for (int i = 0; i < t_ids.size(); i++)
		{
			if (t_ids[i] != ' ')
			{
				this->DrawR_Font8x8(t_x + (8 * i), t_y, t_ids[i]);
			}
		}
	}

	void Window::DrawR_CFont8x8(const int& t_x, const int& t_y, const int& t_id, const int& t_pixelSizeX, const int& t_pixelSizeY)
	{
		int x, y;
		int set;
		int mask;
		for (y = 0; y < 8; y++) {
			for (x = 0; x < 8; x++) {
				set = font8x8[t_id][y] & 1 << x;
				if (set > 0)
				{
					this->DrawR_CPixel(t_x + x * t_pixelSizeX, t_y + y * t_pixelSizeY, t_pixelSizeX, t_pixelSizeY);

					//printf("%c", set ? 'X' : ' ');
				}
			}
		}
	}

	void Window::Init(const WindowProps& t_props)
	{
		m_windowProps = std::make_shared<WindowProps>(t_props);

#if defined(GE_DEBUG) || defined(GE_RELEASE)
		GE_CORE_INFO("Creating window {0} ({1}, {2})", t_props.title, t_props.width, t_props.height);
#endif

		if (!s_SDLInitialized)
		{
			if (SDL_Init(SDL_INIT_VIDEO) < 0)
			{
#if defined(GE_DEBUG) || defined(GE_RELEASE)
				GE_CORE_ERROR("SDL could not initialize! SDL_Error: {0}", SDL_GetError());
#endif
				// TODO Close all
			}
			else
			{
				const char* buffer = m_windowProps->title.c_str();
				m_window = SDL_CreateWindow(buffer, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_windowProps->width, m_windowProps->height, SDL_WINDOW_SHOWN);
				if (m_window == NULL)
				{
#if defined(GE_DEBUG) || defined(GE_RELEASE)
					GE_CORE_ERROR("Window could not be created! SDL_Error: {0}", SDL_GetError());
#endif
				}
				else
				{
					if (m_windowProps->sync)
					{
						m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
					}
					else
					{
						m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
					}

					if (m_renderer == NULL)
					{
#if defined(GE_DEBUG) || defined(GE_RELEASE)
						GE_CORE_ERROR("Renderer could not be created! SDL_Error: {0}", SDL_GetError());
#endif
					}
					else
					{
						SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
						SDL_RenderClear(m_renderer);
						SDL_RenderPresent(m_renderer);

						s_SDLInitialized = true;
#if defined(GE_DEBUG) || defined(GE_RELEASE)
						GE_CORE_INFO("Window and Renderer is initialized");
#endif
					}
				}
			}
		}
	}
	void Window::Set_WindowBordered(const SDL_bool& t_state)
	{
		SDL_SetWindowBordered(this->m_window, t_state);
	}
	void Window::Set_WindowResizable(const SDL_bool& t_state)
	{
		SDL_SetWindowResizable(this->m_window, t_state);
	}
}
*/
