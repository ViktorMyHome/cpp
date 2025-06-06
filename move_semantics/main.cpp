#include <iostream>
#include <memory>
#include <string.h>
#include <vector>
using namespace std;

class MyPair{
private:
    int *firstPtr = nullptr;
    int *secondPtr = nullptr;
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
public:

    MyPair(int first = 0, int second = 0){
        cout<<" constructor "<<endl;
        SetFirst(first);SetSecond(second);
    }
    MyPair(const MyPair &other){
        cout<<" copy constructor "<<endl;
        SetFirst(*other.firstPtr);SetSecond(*other.secondPtr);
    }
    ~MyPair(){
        cout<<" destructor "<<endl;
        if(firstPtr == nullptr && secondPtr == nullptr)
            cout<<" already freed "<<endl;
        if(firstPtr != nullptr)
            delete firstPtr;
        if(secondPtr != nullptr)
            delete secondPtr;
    }

    MyPair(MyPair&& other){
        cout<<" move constructor "<<endl;
        firstPtr = other.firstPtr;
        secondPtr = other.secondPtr;
        other.firstPtr = other.secondPtr = nullptr;
    }

    MyPair& operator=(MyPair& other){
        cout<<" assignment lvalue"<<endl;
        if(this == &other)
            return *this;
        
        if(other.firstPtr != nullptr)
            SetFirst(*other.firstPtr);
        if(other.secondPtr != nullptr)
            SetSecond(*other.secondPtr);
        
        return *this;
    }

    MyPair& operator=(MyPair&& other){
        cout<<" assignment rvalue"<<endl;
        if(this == &other)
            return *this;
        
        if(firstPtr != nullptr)
            delete firstPtr;
        if(secondPtr != nullptr)
            delete secondPtr;
        firstPtr = other.firstPtr;
        secondPtr = other.secondPtr;
        other.firstPtr = other.secondPtr = nullptr;
        
        return *this;
    }

    MyPair& operator++(){ // ++p
        ++*firstPtr;
        ++*secondPtr;
        return *this; // lvalue
    }

    MyPair operator++(int){
        MyPair temp;
        temp = *this;
        ++*firstPtr;
        ++*secondPtr;
        return temp;
    }

};

/*
    Without move constructor two objects will be created.
*/


int main() {
    // vector<MyPair> v;
    // v.push_back(MyPair(3,6));
    // cout<<"after vector push"<<endl;

    // MyPair p1(1,5);
    // MyPair p2(p1);

    // MyPair p3;
    // p3 = MyPair(1,5);//Rvalue
    // MyPair p4;
    // p4 = p3;

    MyPair p5(2,5), p6;
    p6 = ++p5; // assignment lvalue
    p6 = p5++; // assignment rvalue



    return 0;
}
