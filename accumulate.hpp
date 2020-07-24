#pragma once
#include <iostream>
#include <vector>
#include <iterator>

typedef struct {
    template <typename T>
    auto operator()(const T& x , const T& y) const{
        return x+y;
    }

} add;

namespace itertools {

    template<class T,class FUNC = add>
    class accumulate {
        const  T& container;
        const FUNC& function;
    public:

        accumulate(const T& con, const FUNC& f= add() ) : container(con),function(f){}

        class iterator{
            decltype(container.begin()) iter;
            typename std::decay<decltype(*(container.begin()))>::type sum;// to remove the const..
            const accumulate& acc;


        public:
            iterator(decltype(container.begin()) curr,const accumulate& acc): iter(curr),acc(acc) {
                if (curr!= acc.container.end())sum = *curr;
            }
            iterator& operator++(){  //++i
                ++iter;
                if(iter==acc.container.end())return *this;
                sum=acc.function(sum,*iter);
                return *this;
            }
            const iterator operator++(int){ //i++
                iterator temp = *this;
                sum=acc.function(sum,*(iter++));
                return temp;
            }
            bool operator==(const iterator &it) const {// we just comper no change anything
                return iter==it.iter;
            }
            bool operator!=(const iterator &it) const {// we just comper no change anything
                return !(iter==it.iter);
            }
            auto operator*(){
                return sum;
            }
//            iterator& operator=(const iterator &temp_iter) // we just comper no change anything
//            {
//                return *this;
//            }

        };

        iterator begin() const { //the const is on the this
            return iterator(container.begin(),*this);

        }
        iterator end() const { //the const is on the this
            return iterator(container.end(),*this);
        }
    };
}