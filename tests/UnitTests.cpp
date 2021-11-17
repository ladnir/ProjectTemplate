

#include "cryptoTools/Common/Log.h"
#include <functional>
#include "UnitTests.h"
#include "foo_Tests.h"

namespace projTemp_Tests
{
    oc::TestCollection Tests([](oc::TestCollection& t) {

        t.add("Foo_FeatureCheck_test       ", Foo_FeatureCheck_test);

        // add more tests like so
        //t.add("Foo_Wizbang_test          ", Foo_Wizbang_test);
    });
}
