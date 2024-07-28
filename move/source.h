#include <stdio.h>

// class Car {
// private:
//     float fuel;
//     float speed;
//     int passengers{0};
//     static int totalCount;
// public:
//     Car();
//      //Delegating constructor invokes another constructor-reduces duplicate initialization
//      Car(float amount, int pass);
//     ~Car();
//     void FillFuel(float amount);
//     void AddPassengers(int count);
//     static void ShowCount();
//     void Dashboard() const;
// };


class Integer{
    int *m_pInt;
public:
    Integer();
    Integer(int value);
    Integer(const Integer &obj);
    //move constructor
    Integer(Integer &&obj);
    int GetValue() const;
    void SetValue(int value);
    ~Integer();
};

