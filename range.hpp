#pragma once
namespace itertools {

    class range {
        int start;
        int finish;

    public:

        range(int a, int b) : start(a), finish(b) {}

        class iterator {
            int current;

        public:

            iterator(int curr=0) : current(curr) {}

            iterator& operator++() {//++i
                current = current + 1;
                return *this;
            }
             iterator operator++(int) {//i++
                iterator temp = *this;
                current = current + 1;
                return temp;
            }

            bool operator==(const iterator &it) const {
                return current == it.current;
            }
            bool operator!=(const iterator &it) const {
                return current != it.current;
            }
            int operator*(){//get the value
                return current;
            }
        };

        iterator begin() const{ //return iterator
            return iterator(start);
        }
        iterator end() const { //return iterator
            return iterator(finish);
        }
    };
}
