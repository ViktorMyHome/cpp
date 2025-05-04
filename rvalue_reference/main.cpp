#include <iostream>
using namespace std;

void f2(int &a){ cout<<"f2()"<<endl;}
void f2(int &&a){ cout<<"f2&&()"<<endl;}
void f1(int &a){ 
    cout<<"f1()"<<endl;
    f2(a);
}
void f1(int &&a){
    cout<<"f1&&()"<<endl;
    f2(a);
}


int main() {
    int x =10;
    f2(x);
    f2(10);
    f1(x);
    f1(10);

    return 0;
}
