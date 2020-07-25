#include "doctest.h"
#include <iostream>

#include <vector>
#include <deque>
#include <list>

#include "range.hpp"
#include "accumulate.hpp"
#include "compress.hpp"
#include "filterfalse.hpp"

using namespace std;
using namespace itertools;

TEST_CASE ("range test") {
    auto num=2;
    for (auto i:range(2, 20)) {
                CHECK(i==num);
        num++;
    }

    num=-10;
    for (auto i:range(-20, 20)) {
                CHECK(i==num);
        num++;
    }

    range test(3, 3);
            CHECK(test.begin()==test.end());
            CHECK_NOTHROW(range(2,10));
            CHECK_NOTHROW(range(10,2));
            CHECK_THROWS(range(1,-1));
            CHECK_THROWS(range(3,-3));
            CHECK_THROWS(range(5,-5));
            CHECK_THROWS(range(7,-7));
            CHECK_THROWS(range(1,-2));
            CHECK_THROWS(range(3,-2));
            CHECK_THROWS(range(5,-2));
            CHECK_THROWS(range(7,-2));
}

TEST_CASE ("accumulate test") {
    auto num= 0;
    for (auto i: accumulate(range(2, 20))) {
        num+=(i-num);
                CHECK(i==num);
    }
    for (auto i: accumulate(range(-2,2))) {
        num+=(i-num);
                CHECK(i==num);
    }


    vector<string> vString = {"Meitar", "and", "Salome", "and", "Rivka", "do", "good", "tests"};
    string tempS= "";
    int lenghtS= 0;
    for (auto i: accumulate(vString)) {
        lenghtS = i.length();
        tempS += i.substr(tempS.length(), lenghtS);
                CHECK(i == tempS);
    }

    num= 1;
    for (int i: accumulate(range(2,20), [](int a, int b) { return a*b; })) {

        if (num!=0) {
            num *= (i / num);
                    CHECK(i == num);
        }
    }
    for (int i: accumulate(range(-2,30), [](int a, int b) { return a*b; })) {

        if (num!=0) {
            num *= (i / num);
                    CHECK(i == num);
        }
    }
}