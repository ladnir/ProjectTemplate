#include "foo_Tests.h"
#include "cryptoTools/Common/CLP.h"
#include "cryptoTools/Common/TestCollection.h"
#include "projTemp/foo.h"

namespace projTemp_Tests
{

    void Foo_FeatureCheck_test(const oc::CLP& cmd)
    {
        if (projTemp::Foo::isFeatureXEnabled())
        {
            // passed.
            return;
        }
        throw oc::UnitTestFail();
    }


}