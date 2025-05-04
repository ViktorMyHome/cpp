#include <iostream>
#include <memory>
#include <string.h>
#include <vector>
using namespace std;

struct DepartmentSimple;

struct Employee{
    weak_ptr<DepartmentSimple> department;
    ~Employee(){cout<<" Destroy Employee"<<endl;}
    void print();
};

void Employee::print(){

    // make sure, original NOT removed
    if(!department.expired()){
        shared_ptr<DepartmentSimple> dep_origin = department.lock();
        cout<<" Department is not expired "<<endl;
    } else {
        cout<<" Department expired "<<endl;
    }
}
struct DepartmentSimple{
    shared_ptr<Employee> employee;
    ~DepartmentSimple(){cout<<" Destroy DepartmentSimple"<<endl;}
};




int main() {

    shared_ptr<Employee> e = make_shared<Employee>();

    // 1.create shared ptr, 2.assign/construct to weak ptr
    shared_ptr<DepartmentSimple> ds = make_shared<DepartmentSimple>();
    e->department = ds;
    ds->employee = e;

    weak_ptr<DepartmentSimple> d2 = weak_ptr<DepartmentSimple>(e->department);

    e->print();

    cout<<e.use_count()<<" "<<ds.use_count()<<endl;
    ds = nullptr;
    e->print();

    return 0;
}
