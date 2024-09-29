#pragma once

#include <stdio.h>
#include <memory>
#include "hotdrink.h"
using namespace std;

struct HotDrinkFactory // Abstract Factory
{
    virtual unique_ptr<HotDrink> make() const = 0;
};

struct TeaFactory : HotDrinkFactory
{
    unique_ptr<HotDrink> make() const override {
        return std::make_unique<Tea>();
    }
};

struct CoffeFactory : HotDrinkFactory
{
    unique_ptr<HotDrink> make() const override {
        return make_unique<Coffe>();
    }
};
