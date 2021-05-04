#define CATCH_CONFIG_MAIN
#include "../thirdparty/catch.hpp"
#include <iostream>
#include <libgeometry/checks.h>
#include <libgeometry/counting.h>
#include <string.h>
#include <vector>

TEST_CASE("Counting circle", "")
{
    SECTION("perim")
    {
        std::vector<float> a{1, 2, 2.2};
        std::vector<float> b{4.1, 2.12, 5.12};
        std::vector<float> c{1, 0, 3.31};
        CHECK(perim(a) == Approx(13.8226));
        CHECK(perim(b) == Approx(32.16896));
        CHECK(perim(c) == Approx(20.79673));
    }
    SECTION("area")
    {
        std::vector<float> a{1, 2, 2.2};
        std::vector<float> b{4.1, 2.12, 5.12};
        std::vector<float> c{1, 0, 3.31};
        CHECK(area(a) == Approx(15.20486));
        CHECK(area(b) == Approx(82.35253));
        CHECK(area(c) == Approx(34.41859));
    }
}
TEST_CASE("for counting", "")
{
    SECTION("sqrSum")
    {
        std::vector<float> a{4, 0, 0};
        std::vector<float> b{0, 0, 0};
        std::vector<float> c{26.01, 29.58, 8.41};
        std::vector<float> d{83.5396, 78.9696, 18.6624};
        CHECK(sqrSum(2, 0) == a);
        CHECK(sqrSum(0, 0) == b);
        std::vector<float> temp = sqrSum(5.1, 2.9);
        for (int i = 0; i < 3; i++) {
            CHECK(temp[i] == Approx(c[i]));
        }
        temp = sqrSum(9.14, 4.32);
        for (int i = 0; i < 3; i++) {
            CHECK(temp[i] == Approx(d[i]));
        }
    }
    SECTION("QuadRoots")
    {
        std::vector<float> a{-0.5, -1};
        std::vector<float> b{-0.60435, -2.89564};
        std::vector<float> input1{4, 6, 2};
        std::vector<float> temp1 = QuadRoots(input1);
        for (int i = 0; i < 2; i++) {
            CHECK(temp1[i] == Approx(a[i]));
        }
        std::vector<float> input2{1.2, 4.2, 2.1};
        std::vector<float> temp2 = QuadRoots(input2);
        for (int i = 0; i < 2; i++) {
            CHECK(temp2[i] == Approx(b[i]));
        }
    }
}

TEST_CASE("intersects", "")
{
    SECTION("cirToCir")
    {
        std::vector<float> c1{0, 0, 2};
        std::vector<float> c2{1, 1, 2};
        CHECK(cirToCir(c1, c2) == 1);
        std::vector<float> c3{9.3, -4.2, 2.8};
        CHECK(cirToCir(c1, c3) == 0);
        std::vector<float> c4{9, -4.2, 2.8};
        CHECK(cirToCir(c1, c4) == 0);
    }
}
TEST_CASE("cheks", "")
{
    SECTION("odz")
    {
        std::vector<char> a = {'g', '*', '1', ' ', ',', '.', '-'};
        CHECK(odz(a[0]) == 1);
        CHECK(odz(a[1]) == 1);
        CHECK(odz(a[2]) == 0);
        CHECK(odz(a[3]) == 0);
        CHECK(odz(a[4]) == 0);
        CHECK(odz(a[5]) == 0);
        CHECK(odz(a[6]) == 0);
    }
    SECTION("figName")
    {
        std::vector<std::string> a
                = {"Circle(1, 2, 3)", "cIrcLE(2, 3, 5)", "circl(2, 3, 5)"};
        CHECK(figName(a[0]) == "circle");
        CHECK(figName(a[1]) == "circle");
        CHECK(figName(a[2]) == "circl");
    }
    SECTION("circleCoords")
    { 
        std::string str1 = "circle(1 2, 3)";   
        std::vector<float> a1 {1,2,3};
        std::vector<float> tres1 = circleCoords(str1);
        for (int i=0; i<3; i++){
            CHECK(tres1[i] == a1[i]);
        }
        std::string str2 = "circle(-2.1 2.3, 4.2)";
        std::vector<float> a2{-2.1, 2.3, 4.2};
        std::vector<float> tres2 = circleCoords(str2);
        for (int i = 0; i < 3; i++) {
            CHECK(tres2[i] == a2[i]);
        }
    }
    system("PAUSE");
}
