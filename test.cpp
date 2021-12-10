#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "catch.hpp"

TEST_CASE("Catch operability", "[simple]"){
    REQUIRE(1+1 == 2);
}

#include "funcs.h"

TEST_CASE("test 1, file", "[simple]"){
    std::ofstream inputPrepare;
    inputPrepare.open ("input.txt", std::ofstream::trunc);
    inputPrepare<<
                "2\n"
                "0\n"
                "0"
            ;
    inputPrepare.close();

    std::ifstream input( "input.txt", std::ofstream::in);
    std::ofstream output("output.txt", std::ofstream::trunc);
    parseFile(input,output);
    input.close();
    output.close();

    std::ifstream outputCheck("output.txt", std::ofstream::in);
    std::stringstream buffer;
    buffer<<outputCheck.rdbuf();
    outputCheck.close();
    INFO(buffer.str());
    REQUIRE(buffer.str() ==
            "2"
    );
}

TEST_CASE("3.5 round to 4", ""){
    std::stringstream input(
            "1 0 0"
    );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() == "1"
    );
}
/*
TEST_CASE("test 3", ""){
    std::stringstream input(
            "11 3 2 21 25"
    );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() == "2"
    );
}
*/