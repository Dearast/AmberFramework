#include "LayerWindow.h"

namespace Amber
{
    LayerWindow::LayerWindow(const WindowProps& t_windowProps)
    {
        this->m_window = std::make_shared<Window>();
        this->m_window->Init(t_windowProps);
    }
}
