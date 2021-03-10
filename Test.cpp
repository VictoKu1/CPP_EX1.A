#pragma once
#include <cmath>
#include "snowman.hpp
#include "doctest.h"
using namespace ariel;
using namespace std;

TEST_CASE("Good snowman test 1 .") {
    CHECK(snowman(11114411)) == ("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(snowman(33232124)) == ("   _\n  /_\\\n\\(o_O)\n (] [)>\n (   )"));
    CHECK(snowman(11112311)) == (" _===_\n\\(.,.)\n ( : )\\\n ( : )"));
}
TEST_CASE("Test if it throws an error for every input in [0,11111111).") {
    for (int i =0;i<11111111;i++){
    CHECK_THROWS(snowman(i));
    }
}

TEST_CASE("Test if it gives a valid value for a between 97656 in base 10 (11111111 in base 5) to 390624 in base 10 (44444444 in base 5"){
    for(int i=97656;i<390624;i++){
        char res[100]; 
        CHECK_NOTHROW(snowman(fromDeci(res, 5, i)));
    }
}

