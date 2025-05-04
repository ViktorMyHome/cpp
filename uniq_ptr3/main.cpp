#include <iostream>
#include <memory>
#include <string.h>
#include <vector>
using namespace std;

#define MAX(xpar,ypar) (((xpar)>(ypar))?(xpar):(ypar))


void fast_initialize(){
    int n = 10000000;
    unique_ptr<int[]> p1{new int[n]}; // creating the memory and use it.
    
    int *p = p1.get();

    memset(p, -1, n*sizeof(int)); // now we have array -1 -1 -1 -1 -1
}

void test(){
    auto p1 = make_unique<int>(20);
    // return the pointer and set nullptr
    int* p = p1.release();
    if(p1 == nullptr)
        cout<<" p1 gone"<<endl;
    cout<<*p<<endl;
    delete p;
    p = nullptr;
}

void warning(){
    int *p = new int{30};
    unique_ptr<int> p1{p};
    unique_ptr<int> p2{p};
}


/*
emplace_back - method used to insert an element at the end of vector.
Element is created directly in the memory allocated to the vector avoiding
unnecessary copies or moves.

release() function is releasing pointer for you and giving you
the responsibility to remove it
*/

int main() {

    int n = 5;
    unique_ptr<int[]> p1 {new int[n]};
    unique_ptr<int[]> p2 {new int[n]()};
    unique_ptr<int[]> p3 = make_unique<int[]>(n);

    for(int i=0; i<n; ++i)
        p1[i] = 7;

    vector<unique_ptr<int>> vec;
    vec.push_back(std::make_unique<int>(7)); // move semantic - rvalue reference?

    unique_ptr<int> p21 = make_unique<int>(20);
    //vec.push_back(p1); // copy constructor for unique ptr

    // emplace_back constructs in-place even without std::move
    vec.emplace_back(move(p21));
    vec.emplace_back(std::make_unique<int>(17));
    //cout<<*p21<<endl;
    for(auto &p : vec){
        cout<<*p<<endl;
    }

    test();

    int a=5;
    int b=7;
    cout<<"MAX(3,9)"<<MAX(++a,b++)<<endl;
    cout<<"a"<<a<<endl;
    cout<<"b"<<b<<endl;  

    unsigned int x = 0;
    x--;
    printf("x=%x\n",x);

    return 0;
}
