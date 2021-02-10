#pragma once

#include "Core.h"
#include "Logger.h"

namespace Amber
{
    class AMBER_API Framework
    {
    private:
    bool m_running = true;
    public:
    void Run() const;
};

    Framework* CreateFramework();
}
