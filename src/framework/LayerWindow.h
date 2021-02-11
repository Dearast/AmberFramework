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
#if defined(COMPILE_WITH_SFML)
        void OnEvent(sf::Event& t_event) override  {}
#elif defined(COMPILE_WITH_SDL)
        void OnEvent(SDL_Event& t_event) override  {}
#endif
    };
}
