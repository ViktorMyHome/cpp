#include "integer.h"
#include <iostream>
#include <memory>


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
    p.reset(new Integer{});
    *p = __LINE__;
    Display(p.get());
    //delete p;
}

int main() {
    

    return 0;
}