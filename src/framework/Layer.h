#pragma once

#include "Core.h"

namespace Amber
{
    class AMBER_API Layer
    {
    public:
    virtual void OnAttach() {}
    virtual void OnDetach() {}
    virtual void OnUpdate() {}
    virtual void OnEvent()  {}
    };
}
