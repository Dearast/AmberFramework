#include "../../framework/Framework.h"

class Example_001 : public Amber::Framework
{
    public:
        Example_001()
        {
            Amber::Logger::Set_ClientLoggerName("[EXAMP-001]");
            AMBER_CLIENT_INFO("Example_001 is constructed.");
        }

        ~Example_001()
        {

        }
};

Amber::Framework* Amber::CreateFramework()
{
    return new Example_001();
}
