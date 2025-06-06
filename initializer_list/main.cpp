#include <iostream>
#include <memory>
#include <string.h>
#include <vector>
using namespace std;

struct A{
    int x,y;
};

struct B{
    int x, y;
    B(int x_, int y_) : x{x_}, y{y_} {}
};

struct C{
    int x, y;
    static int z;
    C(int x_, int y_) : x{x_}, y{y_} {}
    C(const initializer_list<int> &v){
        x = *(v.begin()), y=*(v.begin() + 1);
    }
    const static void print(){
        z=3;
        std::cout<<"Hello"<<endl;
    }
};



int main() {
    A a{1,3};// agregate initialization
    B b{2,9}; // regular constructor
    C c1{3,7}; // initializer_list
    C c2(3,7);// regular constructor

    // priority: initializer_list, regular constructor, agregate initialization

    return 0;
}
