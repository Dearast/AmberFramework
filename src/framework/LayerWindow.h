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
    };
}
