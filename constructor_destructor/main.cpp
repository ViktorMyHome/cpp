#include <iostream>
using namespace std;

class ClassA{
private:
    int a;
public:
    int GetA(){
        return a;
    }
    ClassA(){
        a = 1;
        std::cout<<"A constructor"<<endl;
    }
    ~ClassA(){
        std::cout<<"A destructor"<<endl;
    }
};

class ClassB{
public:
    ClassA ca;
    float fb;
    ClassB(){
        fb = 2.2;
        //ca = ClassA();
        std::cout<<"B constructor"<<endl;
    }
    ~ClassB(){
        std::cout<<"B destructor"<<endl;
    }
};

class ClassC{
public:
    ClassB cc;
    bool bc;
    ClassC(){
        bc = true;
    }
    ~ClassC(){
        std::cout<<"C destructor"<<std::endl;
    }
    ClassC(bool value, const ClassB &value_B){
        std::cout<<"C Parametrized constructor"<<std::endl;
        bc = value;
        cc.ca = value_B.ca;
        cc.fb = value_B.fb;
    }
};


int main() {

    ClassA A;

    cout<<" A "<<A.GetA()<<endl;
    ClassB b;
    ClassC c(true,b);

    return 0;
}
