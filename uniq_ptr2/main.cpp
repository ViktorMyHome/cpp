#include <iostream>
#include <memory>
using namespace std;


void print1(unique_ptr<int> p) {
    if(p != nullptr)
        cout<<" print1 "<<*p<<endl;
}

void print2(unique_ptr<int> &p) {
    if(p != nullptr){
        cout<<" print2 "<<*p<<endl;
        //p.reset(); // we can destroy
    }
}

void print3(const unique_ptr<int> &p) {
    if(p != nullptr) {
        cout<<" print3 "<<*p<<endl;
        *p = 10; // value can be changed
        // unique_ptr<int> &p2 = p;
        // p.reset();
    }
}




int main() {

    unique_ptr<int> p1 {new int{20}};
    unique_ptr<int> &p2 = p1;
    print1(move(p2));
    //p2.reset(new int{30});
    print2(p2);
    print3(p2);

    return 0;
}
