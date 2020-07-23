#include <iostream>
#include <vector>
#include <string>
#include<ostream>

using namespace std;

template<class T> class iterable_printer {
    const T& the_iterable;
public:
    iterable_printer(const T& x): the_iterable(x) {
        cout << "constructor " << endl;
    }
    void print() {
        for (auto item: the_iterable) {
            cout << item << " ";
        }
        cout << endl;
    }
};


int main() {
    vector<string> v1;
    //vector<int> v2(v1.begin(), v1.end());  // static assert

    auto v2 = vector({1,2,3,4});
    cout << endl;

    iterable_printer(vector<int>({1,2,3,4})).print();
}