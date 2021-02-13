/*
#include "Framework.h"

#include <memory>

extern Amber::Framework* Amber::CreateFramework();

int main()
{
    Amber::Logger::Init();

    //FIXME Getting error [deleting a pointer through a type that is not marked 'gsl::owner<>'; consider using a smart pointer instead]
    //TODO Create smart pointer here
    std::unique_ptr<Amber::Framework> framework = std::make_unique<Amber::Framework>(Amber::CreateFramework());
    framework->Run();
    //delete framework;

    return 0;
}
*/
