#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;

int &&OurMove(int &x){
    return static_cast<int&&>(x);
}

void f2(int &a) {cout<<"f2(int &a)"<<endl;}
void f2(int &&a) {cout<<"f2(int &&a)"<<endl;}

void f1(int &a) {
    cout<<"f1(int& a)"<<endl;
    f2(a);    
}
void f1(int &&a) {
    cout<<"f1(&&a)"<<endl;
    // originally it has identity (a)
    // now it is Rvalue (can be moved)
    cout<<"a="<<a<<endl;
    f2(OurMove(a));
    cout<<"a="<<a<<endl;
}


int main(){
    f1(10);
    int a = 20;
    f1(a);


return 0;
}
