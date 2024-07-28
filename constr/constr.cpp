#include "constr.h"
#include <iostream>

int Car::totalCount = 0;



//const functions can not modify state of the object
Car::Car():Car(0.0, 0) {
    std::cout<<"Car()"<<std::endl;
}
Car::~Car() {
    --totalCount;
    std::cout<<"~Car()"<<std::endl;
}
Car::Car(float amount, int pass) {
    std::cout<<"Car(float, int)"<<std::endl;
    ++totalCount;
    fuel = amount;
    speed = 0;
    passengers = pass;
}
void Car::FillFuel(float amount) {
    fuel = amount;
}
void Car::AddPassengers(int passanger) {
    passengers += passanger;
}
void Car::Dashboard() const {
    std::cout<<"Fuel:"<<fuel<<std::endl;
}
void Car::ShowCount() {
    std::cout<<"Total cars : "<<totalCount<<std::endl;
}