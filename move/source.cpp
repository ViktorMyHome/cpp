#include <iostream>
#include "source.h"
// int Car::totalCount = 0;





// //const functions can not modify state of the object
// Car::Car():Car(0.0, 0) {
//     std::cout<<"Car()"<<std::endl;
// }
// Car::~Car() {
//     --totalCount;
//     std::cout<<"~Car()"<<std::endl;
// }
// Car::Car(float amount, int pass) {
//     std::cout<<"Car(float, int)"<<std::endl;
//     ++totalCount;
//     fuel = amount;
//     speed = 0;
//     passengers = pass;
// }
// void Car::FillFuel(float amount) {
//     fuel = amount;
// }
// void Car::AddPassengers(int passanger) {
//     passengers += passanger;
// }
// void Car::Dashboard() const {
//     std::cout<<"Fuel:"<<fuel<<std::endl;
// }
// void Car::ShowCount() {
//     std::cout<<"Total cars : "<<totalCount<<std::endl;
// }


Integer::Integer() {
    std::cout<<"Integer()"<<std::endl;
    m_pInt = new int(0);
}

Integer::Integer(int value) {
    std::cout<<"Integer(int)"<<std::endl;
    m_pInt = new int(value);
}

Integer::Integer(const Integer & obj) {
    std::cout<<"Integer(const Integer & obj)"<<std::endl;
    m_pInt = new int(*obj.m_pInt);
}

Integer::Integer(Integer && obj) {
    std::cout<<"Integer(Integer && obj)"<<std::endl;
    m_pInt = obj.m_pInt;
    obj.m_pInt = nullptr;
}

int Integer::GetValue() const {
    return *m_pInt;
}

void Integer::SetValue(int value) {
    *m_pInt = value;
}

Integer::~Integer() {
    std::cout<<"~Integer()"<<std::endl;
    delete m_pInt;
}