//
//  Demo for itertools exercise.
//
//  Version 1 by Adam Lev-Ari on 02/2020. Copyright © 2020 Adam Lev-Ari. All rights reserved.
//  Version 2 by Erel Segal-Halevi on 06/2020.
//

#include <iostream>



#include "range.hpp"
#include "accumulate.hpp"
#include "filterfalse.hpp"
#include "compress.hpp"


using namespace itertools;
using namespace std;


struct lessThan3 {
    bool operator()(int i) const { return i < 3; }
};

int main(int argc, const char * argv[]) {


    cout << "####  range:  ####";
	for (int i: range(5,9))
		cout << i << " ";      // 5 6 7 8

    vector<int> vecInt = {1,2,3,4};
    vector<int> vecInt2 = {5,6,7,8};
    vector<string> vecString = {"Hello", "Bye", "Adam"};
    vector<float> vecFloat = {-1, 0.3, 5.2, -8.3};
//
    cout<<"## accumulate of vecint"<<endl;
    for (auto i: accumulate(vecInt))
        cout << i << " ";
    cout<<endl;
    cout << "####  accumulate:  ####";


    cout<<"### acc(vecFloat) ####"<<endl;
    for (auto i: accumulate(vecFloat))
        cout << i << " ";
    cout<<endl;
    cout<<"### acc(range) ####"<<endl;
    for (auto i: accumulate(range(5,9)))
        cout << i << " ";
    cout << endl << "accumulate of range with binary operator: " << endl;
	for (int i: accumulate(vecInt2, [](int x, int y){return x*y;}))
		cout << i << " ";      // 5 30 210 1680
//
    cout << endl << "accumulate of vecString: " << endl;
    for (auto i: accumulate(vecString))
        cout << i << " ";      // 5 11 18 26
    cout<<endl;
    cout << "####  Filter False:  ####"<<endl;
    cout << endl << "Filter out all numbers less than 3 in vector{1,2,3,4}: " << endl;
   for(int i =0;i<vecInt.size();i++){
       cout<<"vec value in for"<<vecInt[i]<<endl;

   }
    cout<<"Filterfalse less then3,vecInt"<<endl;
   for (auto i: filterfalse(lessThan3{}, vecInt) )
        cout << i << " ";   // 3 4
    cout << endl;
    cout<< "Filter out all even numbers in range(5,9): " << endl;
    for (auto i: filterfalse([](int i){return i%2==0;}, vecInt2) )
        cout << i << " ";   // 5 7
    cout << endl << endl;

    cout << "####  compress:  ####";
    cout << endl << "compress a string" << endl;
    vector<bool> ans ={true,true,false,true};
    for (auto i: compress(range(5,9),ans))
        cout << i << " ";  // 5 6 8
    cout << endl << endl;

    for (auto i: compress(string("abcd"),ans))
        cout << i << " ";  // a b d
    cout << endl << "compress a range" << endl;

//
//
//    cout << endl;
    return 0;
}
