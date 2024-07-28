#include "integer.h"
#include <iostream>
#include <memory>



int main() {

	Printer prn;
	int num{};
	std::cin>>num;
	std::shared_ptr<int> p{new int{num}};
	prn.SetValue(p);
	if(*p > 10){
		p = nullptr;
	}

	prn.Print();
    return 0;
}



