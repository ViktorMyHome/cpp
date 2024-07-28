#include "constr.h"
#include <iostream>

int main() {
    
        Car car;
        //car.FillFuel(6);
        car.AddPassengers(2);
        Car::ShowCount();
        car.Dashboard();
    try {
        throw(1);
    }
    catch(...) {
        std::cout<<"catch(...)"<<std::endl;
        
    }

    return 0;
}