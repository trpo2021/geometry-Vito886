#define CATCH_CONFIG_MAIN
#include <iostream>
#include "../thirdparty/catch.hpp"
#include <libgeometry/checks.h>
#include <libgeometry/counting.h>

int sum(int a, int b)
{
    return a + b;
}

TEST_CASE("first test", "")
{
    SECTION("first section")
    {
        CHECK(sum(1,2) == 3);
    }
    system("PAUSE");
}
