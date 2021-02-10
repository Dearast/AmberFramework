#include "Framework.h"

#include <memory>

extern Amber::Framework* Amber::CreateFramework();

int main()
{
    Amber::Logger::Init();

    auto framework = Amber::CreateFramework();
    framework->Run();
    delete framework;

    return 0;
}
