#pragma once

#include <stdio.h>
#include <memory>
#include <iostream>
using namespace std;

struct HotDrink
{
    virtual ~HotDrink() = default;
    virtual void prepare(int volume) = 0;
};

struct Tea : HotDrink
{
    void prepare(int volume) override {
        std::cout<<"Take tea bag, boil water, por "<<volume
            <<"ml, add some lemon\n";
    }
};

struct Coffe: HotDrink{
    void prepare(int volume) override {
        cout<<"Grind some beans, boil water, pour"<<volume
            <<"ml, add cream, enjoy\n";
    }
};