#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;

// virtual = run-time polymorphism, dynamic/late binding
// non-virtual = compile time polymorphism, static/early binding
// allowing us to write generic code (process(shapes)), without knowing exact children
// extensibility/flexibility/code reuse
// it is a bit slower + little memory than static binding  

class A{

public:
    virtual void f1()   {cout<<"A::f1\n";}
    virtual void f2()   {cout<<"A::f2\n";}
    void f3()           {cout<<"A::f3\n";}

    virtual ~A(){cout<<"~A()"<<endl;}
    A(){cout<<"A()"<<endl;}
    A(const A& a) = delete;
    A& operator=(A& a) = delete;
    virtual int value1(){
        return 1;
    }
    int value2(){
        return 2;
    }
    // virtual A* what() const{
    //     throw logic_error("not implemented");
    // }
};

class B: public A{
public:
    int c;
    B(){cout<<"B()"<<endl;}
    B(int c):A(), c(c){}
    // virtual A* what() const{
    //     return new B(*this);
    // }
    virtual ~B()        {cout<<"~B()"<<endl;}
    void virtual f1()           {cout<<"B::f1\n";}
    void virtual f2()           {cout<<"B::f2\n";}
    void f3()           {cout<<"B::f3\n";}
    int value1(){
        return c*value2();
    }
};


class C: public B{
public:
    C(){cout<<"C()"<<endl;}
    virtual ~C(){cout<<"~C()"<<endl;}
    void virtual f1()           {cout<<"C::f1\n";}
    void virtual f2()           {cout<<"C::f2\n";}
    void f3()           {cout<<"C::f3\n";}
};

class D: public C{

public:
    void f1()           {cout<<"D::f1\n";}
    void f2()           {cout<<"D::f2\n";}
    void f3()           {cout<<"D::f3\n";}

    D(){cout<<"D()"<<endl;}
    virtual ~D(){cout<<"~D()"<<endl;}  
};


int ff(int&& a){//rvalue regerence, does not make a copy
    return a+1;
}

int main(){
    int a = 0;
    int &lvalue = a;
    int &&t = 2*a+1;
    cout<<ff(3)<<endl;
    int &&r1 = 10;
    cout<<r1<<" "<<&r1<<" "<<sizeof(r1)<<" "<<r1<<endl;



    A* d1 = new D();
    d1->f1();
    d1->f2();
    d1->f3();

    B* d2 = new D();
    d2->f1();
    d2->f2();
    d2->f3();

    D* d3 = new D();

    d2->f1();
    d2->f2();
    d2->f3();


    delete d1;
    delete d2;
    delete d3;
    // A* a1 = new B(11);
    // A* a2 = a1->what();

    A* a1 = new B(10);
    cout<<a1->value1()<<endl;
return 0;
}
