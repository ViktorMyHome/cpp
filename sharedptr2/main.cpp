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

void go1(shared_ptr<int> p1){
    cout<<p1.use_count()<<endl; // copy constructor is called: 4
}

void go2(shared_ptr<int> &p1){
    cout<<p1.use_count()<<endl; // 3 not a copy
}

void test(){
    shared_ptr<int> p1{new int{20}};

    shared_ptr<int> p2{p1}; //copy constructor OK
    shared_ptr<int> p3;
    p3 = p2;
    *p1 = 5;
    cout<<*p1<<" "<<*p2<<" "<<*p3<<endl;

    auto p4 = make_shared<int>(20); // preferred
}

void test2(){
    shared_ptr<int> p1{new int{20}};
    cout<<p1.use_count()<<endl;
    shared_ptr<int> p2{p1};
    cout<<p1.use_count()<<" "<<p2.use_count()<<endl;
    {
        shared_ptr<int> p3;
        p3 = p2;
        cout<<p1.use_count()<<" "<<p3.use_count()<<endl;
        go1(p2);
        cout<<p1.use_count()<<endl;
        go2(p2);
    } // go out of scope
    cout<<p1.use_count()<<" "<<p2.use_count()<<endl;
    p1 = nullptr;
    cout<<p2.use_count()<<endl;
}

void test_vector(){
    shared_ptr<int> p1{new int{20}};
    cout<<p1.use_count()<<endl;
    vector<shared_ptr<int>> vec;
    vec.push_back(p1);
    vec.push_back(p1);
    vec.push_back(p1);
    cout<<p1.use_count()<<endl; // 4
    vec.clear();
    cout<<p1.use_count()<<endl; // 1
}



int main() {



    test();

    test2();

    test_vector();

    return 0;
}
