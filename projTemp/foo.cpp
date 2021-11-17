#include "foo.h"
#include "libOTe/TwoChooseOne/IknpOtExtReceiver.h"


namespace projTemp
{
    bool Foo::isFeatureXEnabled()
    {
        oc::IknpOtExtReceiver recver;

#ifdef PROJTEMP_ENABLE_X
        return true;
#else
        return false;
#endif
    }
}
