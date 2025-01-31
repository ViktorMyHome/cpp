#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;

// has name -> lvalue
class MyPair{
private:
    int *firstPtr = nullptr;
    int *secondPtr = nullptr;
public:
    MyPair(int first=0, int second =0) {
        cout<<"Constructor\n";
        SetFirst(first);
        SetSecond(second);
    }
    void print(){
        cout<<" *firstPtr = "<<*firstPtr<<endl;
        cout<<" *secondPtr = "<<*secondPtr<<endl;
    }
    MyPair(const MyPair& other){
        cout<<" copy constructor\n";
        SetFirst(*other.firstPtr);
        SetSecond(*other.secondPtr);
    }
    // MyPair(MyPair&& other){
    //     cout<<" move constructor\n";
    //     firstPtr = other.firstPtr;
    //     secondPtr = other.secondPtr;
    //     other.firstPtr = other.secondPtr = nullptr;
    // }
    MyPair& operator=(MyPair& other){
        cout<<"Assignment lvalue\n";
        if(this == &other)
            return *this;
        if(other.firstPtr!=nullptr)
            SetFirst(*other.firstPtr);
        if(other.secondPtr!=nullptr)
            SetFirst(*other.secondPtr);
        return *this;
    }
    MyPair& operator=(MyPair&& other){
        cout<<"Assignment rvalue\n";
        if(this == &other)
            return *this;
        std::swap(firstPtr, other.firstPtr);
        std::swap(secondPtr, other.secondPtr);
        cout<<"end assignment rvalue\n";
        return *this;
    }
    MyPair(MyPair&& other){
        cout<<" Move constructor \n";
        *this = std::move(other);
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
    ~MyPair(){
        cout<<"~MyPair()\n";
        if(firstPtr)
            delete firstPtr;
        if(secondPtr)
            delete secondPtr;
    }
    int getFirst()const{
        return *firstPtr;
    }
    int getSecond()const{
        return *secondPtr;
    }

};



int main(){
    vector<MyPair> v;
    v.push_back(MyPair(3,6));

    //MyPair p1(1,2);
    MyPair p2(MyPair(1,2));



    MyPair p1(3,3);
     cout<<"-----------------\n";   
    p1 = MyPair(5,5);
    cout<<"-----------------\n";
    MyPair p3;
    p3 = p1;

    p1.print();
    p2.print();


return 0;
}
