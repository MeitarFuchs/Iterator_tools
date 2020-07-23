//
// Created by yirat on 15/06/2020.
//

#include "accumulate.hpp"
#include "range.hpp"
#include "compress.hpp"
#include <vector>
#include "doctest.h"
#include <string>
#include "filterfalse.hpp"
using namespace itertools;
using namespace std;

TEST_CASE("range"){
    int check=1;
    for(int i : range(1,11)){
                CHECK(check++==i);
    }
    check=11;
    for(int i : range(1,11)){
                CHECK(check!=i);
    }
}

TEST_CASE("range in accumulate"){
    vector<int> vecInt ={1,3,6,10};
    int idx=0;
    for(int i : accumulate(range(1,5))){
                CHECK(vecInt[idx++]==i);
    }

    idx=0;
    vecInt={-5,-9,-12,-14,-15};
    for(int i : accumulate(range(-5,0))){
        CHECK(vecInt[idx++]==i);
    }
}

TEST_CASE("vector in accumulate"){
    vector<string> str = {"I","Love","You","So","Much"};
    vector<string> vecStr = {"I","ILove","ILoveYou","ILoveYouSo","ILoveYouSoMuch"};
    int idx=0;
    for(string i : accumulate(str)){
        CHECK(vecStr[idx++]==i);
    }

    idx=0;
    vector<double > dbl = {3.0,1.5,2.5};
    vector<double > vecDbl = {3.0,4.5,7.0};
    for(double i : accumulate(dbl)){
                CHECK(vecDbl[idx++]==i);
    }
    idx=0;
    vector<float> vecfloat = {-1.4,2.3,5.2,-7.7};
    vector<float> flt ={-1.4,0.9,6.1,-1.6};
    for(float i :accumulate(vecfloat)){
        CHECK(flt[idx++]-i<0.00005f);
    }
    idx=0;
    vector<int> vecInt = {1,4,2,5,6,7,8,1,10};
    vector<int> aint = {1,5,7,12,18,25,33,34,44};
    for(int i :accumulate(vecInt)){
        CHECK(aint[idx++]==i);
    }
}

TEST_CASE("accumulate with lambda functions"){
    vector<int> vecInt= {1,2,3,4,5,6,7,8,9,10};
    vector<int> aint={1,2,6,24,120,720,5040,40320,362880,3628800};
    int idx=0;
    for(int i :accumulate(vecInt,[](int a,int b){return a*b;})){
        CHECK(aint[idx++]==i);
    }

    vector<double> vecDbl = {1.5,1.5,-2.5,2.5,-3.5,3.5,-4.5,4.5,-5.5,5.5};
    vector<double > dbl = {1.5,0.0,2.5,0.0,3.5,0.0,4.5,0.0,5.5,0.0};
    idx=0;
    for(double i : accumulate(vecDbl, [](double a , double b){return a-b;})){
        CHECK(dbl[idx++]==i);
    }
}

TEST_CASE("filterfalse"){
    vector<int> vecInt= {1,2,3,4,5,6,7,8,9,10};
    vector<int> aint={2,4,6,8,10};
    int idx=0;
    for(int i : filterfalse([](int a){return a%2!=0;},vecInt)){
        CHECK(aint[idx++]==i);
    }

    vector<char> vecStr= {'a','b','c','d','e','A','B','C','D','E'};
    vector<char> str={'A','B','C','D','E'};
    idx=0;
    for(char i : filterfalse([](char s){return s>=97;},vecStr)){
        CHECK(str[idx++]==i);
    }

    vector<string> vecstr ={"orian","hindi","is","the","partner","of","yirat","peleg"};
    vector<string> st ={"orian","hindi","partner","yirat","peleg"};
    idx=0;
    for(auto i : filterfalse([](string s){return s.size()<4;},vecstr)){
        CHECK(st[idx++]==i);
    }
}


TEST_CASE("compress"){
    vector<bool> boolvec = {true,true,true,false};
    vector<int> vecInt = {1,2,3,4};
    vector<int> aint ={1,2,3};
    int idx =0;
    for (auto i :compress(vecInt,boolvec)){
        cout<<"i is:"<<i<<"|||| boolvec[idx]="<<boolvec[idx]<<endl;
        CHECK(aint[idx++]==i);
    }
    idx=0;
    vector<double> adub = {4.4};
    boolvec = {false,false,false,true};
    vector<double> vecdub = {1,2,3,4.4};
    for(auto i :compress(vecdub,boolvec)){
        cout<<"i is:"<<i<<"|||| boolvec[idx]="<<boolvec[idx]<<endl;
        CHECK(adub[idx]==i);
    }
    idx=0;
    vector<string> vecstr = {"orian","yirat","corona","ariel","university","cpp"};
    vector<string> astr = {"orian","yirat","corona","ariel","university"};
    boolvec={true,true,true,true,true,false};
    for(auto i :compress(vecstr,boolvec)){
        cout<<"i is:"<<i<<"|||| boolvec[idx]="<<boolvec[idx]<<endl;
        CHECK(astr[idx++]==i);
    }

   vecInt = {1,2,3,4,5,6,7,8,9,10};
   aint = {1,3,5,7,9,10};
   boolvec = {true,false,true,false,true,false,true,false,true,true};
   idx=0;
   for(auto i :compress(vecInt,boolvec)) {
       cout << "i is:" << i << "|||| boolvec[idx]=" << boolvec[idx] << endl;
               CHECK(aint[idx++] == i);
   }
};