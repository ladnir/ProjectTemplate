#include "tests/UnitTests.h"

#include "cryptoTools/Common/CLP.h"

#include "projTemp/foo.h"

void run_experiemnt(oc::CLP& cmd)
{
    std::cout << "experiment took 0 seconds" << std::endl;
}

int main(int argc, char** argv)
{
    oc::CLP cmd(argc, argv);


    if (cmd.isSet("exp"))
    {
        run_experiemnt(cmd);
        return 0;
    }
    else
    {
        // run unit tests if user passed in -u
        auto r = projTemp_Tests::Tests.runIf(cmd);

        return r == oc::TestCollection::Result::failed;
    }

    return 0;
}