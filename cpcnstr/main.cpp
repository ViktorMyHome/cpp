#include "constr.h"
#include <iostream>

// Integer Add(const Integer &a, const Integer &b) {
//     Integer temp;
//     temp.SetValue(a.GetValue() + b.GetValue());
//     return temp;
// }

Integer Add(int a, int b) {
    Integer temp(a+b);
    return temp;
//    return Integer(a+b);
}

void print(const Integer & i) {
    std::cout<<i.GetValue()<<std::endl;
}


Integer CreateInteger(int num)
{
    Integer temp{num};
    return temp;//due to temp is returned by value, move constructor will be called
}

int main() {
    
    //Integer i(5);
    //std::cout<<i.GetValue()<<std::endl;
    //Integer i2(i);//shallow copy - we copy address

    //deep copy - we have to copy value
    //copy constructor is involved when we pass a object as argument by value
    //or when a function return an object by value
    //or when one object ia assigned by another: i=i2

    //Rules of 3
    //All should be defined if a user implements any of them
    //Destructor - will free the resource
    //Copy constructor - perform deep copy
    //Copy assignment operator - perform deep copy
    //This will be due to allocation of somme resources in a constructor.

    //Rules of 5
    //If a class has ownership semantics, then you must provide a user defined
    //Destructor - may be released
    //Copy constructor - may create copy of resource
    //Copy assignment operator - the same
    //move constructor - insure to move undreline resource to another resource
    //move assignment operator - the same

    //Rule of zero
    //if a class does not have ownership semantics then do not provide any user defined functions from the rule of 5

    //copy ellision - teporary object is removed,

    //Delegating constructor invokes another constructor-reduces duplicate initialization

    //std::cout<<i2.GetValue()<<std::endl;

    std::cout<<"-------new program--------"<<std::endl;

    //Integer a(1), b(3);
    //a.SetValue(Add(a,b).GetValue());
    //a.PrintValue();

    // //Integer a=3;//Integer a = Integer(3);
    // {
    //     Integer a=Add(3,5);
    //     a.PrintValue();
    // }
    // std::cout<<"-------new program--------"<<std::endl;

    // Integer b(1);
    // //auto c{static_cast<Integer&&>(b)};//will call move constructor Integer(Integer &&)
    // auto c{std::move(b)};//will call move constructor Integer(Integer &&)

    // c.SetValue(0);
    // //c.SetValue(1); segmentation fault(core dumped)
    // print(c);

    std::cout<<"-------new program--------"<<std::endl;

    Integer q{5};
    q.SetValue(9);
    Integer s{std::move(q)}; //= CreateInteger(8);
    s.PrintValue();

    return 0;
}