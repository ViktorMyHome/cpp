#include <iostream>
#include <functional>
#include <memory>
using namespace std;


int sq(int x){
    return x*x;
}

void test1(){
    std::function<int(int)> f = sq;
    cout<<f(5)<<endl;
}

void deleter(int *p){
    cout<<"special delete "<<endl;
    delete p;
}

double f(){
    auto b = 1.5;
    return b;
}

struct Employee{
    string name;
    int *id = nullptr;
    Employee(int id_, string name_){
        name = name_;
        id = new int{id_};
    }
    Employee(const Employee &e){
        this->name = e.name;
        this->id = new int;
    }
    ~Employee(){
        cout<<"Destructor "<<endl;
        if(id!=nullptr)
            delete id;
        id = nullptr;
    }
    void print(){
        cout<<*id<<" "<<name<<" ";
    }
};

int main() {

    // unique_ptr<int, function<void(int*)>> p2{new int{5}, deleter};

    // double i = 10.2;
    // decltype(i) j = i*2;
    // decltype(f()) j3;
    // j3 = 3;

    Employee e1(20, "belal");
    e1.print();
    Employee e2(e1);
    e2.print();

    return 0;
}
