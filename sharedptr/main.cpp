#include "integer.h"
#include <iostream>
#include <memory>

/*
void Display(Integer *p) {
    if(!p) {
        return;
    }
    std::cout << p->GetValue() << std::endl;
}

Integer *GetPointer(int value) {
    Integer *p = new Integer{value};
    return p;
}

void Operate(int value) {
    std::unique_ptr<Integer> p{GetPointer(value)};
    if(p == nullptr) {
        //p = new Integer{value};
        p.reset(new Integer{value});
    }
    p->SetValue(100);
    Display(p.get());
    //p = nullptr;
    //p = new Integer{};
    //p.reset(new Integer{});
    //*p = __LINE__;
    Display(p.get());
    //delete p;
}
*/
int main() {

	std::shared_ptr<Project> prj{new Project{}};
	prj->SetName("Video decoder");

	std::unique_ptr<Employee> e1{new Employee{}};
	e1->SetProject(prj);
	std::unique_ptr<Employee> e2{new Employee{}};
	e2->SetProject(prj);
	std::unique_ptr<Employee> e3{new Employee{}};
	e3->SetProject(prj);

	std::cout<<"Reference count:"<<prj.use_count()<<std::endl;
	
	//ShowInfo(e1);
	//ShowInfo(e2);
	prj->ShowProjectDetails();



    return 0;
}
