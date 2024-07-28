#include <stdio.h>

class Car {
private:
    float fuel = 1;
    float speed;
    int passengers{0};
    static int totalCount;
public:
    Car();
     //Delegating constructor invokes another constructor-reduces duplicate initialization
     Car(float amount, int pass);
    ~Car();
    void FillFuel(float amount);
    void AddPassengers(int count);
    static void ShowCount();
    void Dashboard() const;
};