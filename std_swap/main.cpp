#include <iostream>
#include <vector>
#include <utility>
#include <memory>
using namespace std;

class MyPair{
private:
    int *firstPtr{nullptr};
    int *secondPtr{nullptr};
public:
    MyPair(int first=0, int second=0){
        cout<<"constructor"<<endl;
        SetFirst(first), SetSecond(second);
    }
    void SetFirst(int first){
        if(firstPtr == nullptr)
            firstPtr = new int;
        *firstPtr = first;
    }
    void SetSecond(int second){
        if(secondPtr == nullptr)
            secondPtr = new int;
        *secondPtr = second;
    }
    MyPair(const MyPair& other){
        cout<<"copy constructor"<<endl;
        SetFirst(*other.firstPtr);
        SetSecond(*other.secondPtr);
    }
    void swap(MyPair& other){
        std::swap(firstPtr, other.firstPtr);
        std::swap(secondPtr, other.secondPtr);
    }
    MyPair& operator=(MyPair&& other){
        cout<<"assignment operator with rvalue"<<endl;
        if(this == &other) return *this;
        other.swap(*this);
    }
    MyPair& operator=(MyPair &other){
        cout<<" assignment operator with lvalue"<<endl;
        if(this == &other) return *this;
        if(other.firstPtr != nullptr) SetFirst(*other.firstPtr);
        if(other.secondPtr != nullptr) SetSecond(*other.secondPtr);
    }
    MyPair(MyPair&& other){
        cout<<"move constructor"<<endl;
        *this = std::move(other);
    }
    ~MyPair(){
        cout<<"~MyPair()"<<endl;
        if(firstPtr != nullptr) delete firstPtr;
        if(secondPtr != nullptr) delete secondPtr;
    }
    void print(){
        cout<<"("<<*firstPtr<<","<<*secondPtr<<")"<<endl;
    }

};

void myFuncRValue(int val){
    val = 6;
}


int main(){
    MyPair p1 = move(MyPair(2,5));
    p1.print();




    int a = 9;
    //a++ = 10;// why not compiled
    //++a = 10; // why is compiled.
    myFuncRValue(a);
    cout<<" a = "<<a<<endl;
    const char * const str = "hello";

    unsigned short &&r1 = 10;
    cout<<r1<<" "<<&r1<<" "<<sizeof(r1)<<endl; //10 0x7ffdcc92a230 2

    int val = 77;
    vector<int> vec;
    vec.push_back(val);
    cout<<val<<endl;

    unsigned short sh = 10;
    unsigned short &shref = sh;
    cout<<"&shref "<<&shref<<" shref "<<shref<<endl;

    unique_ptr<int> p1{new int{20}};



return 0;
}
