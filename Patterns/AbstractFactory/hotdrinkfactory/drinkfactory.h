#pragma once

#include <stdio.h>
#include <map>
#include "hotdrink.h"
#include "hotdrinkfactory.h"

struct DrinkFactory
{
    map<string, unique_ptr<HotDrinkFactory>> hot_factories;
public:
    DrinkFactory() {
        hot_factories["coffe"] = make_unique<CoffeFactory>();
        hot_factories["tea"] = make_unique<TeaFactory>();        
    }

    unique_ptr<HotDrink> make_drink(const string& name)
    {
        auto drink = hot_factories[name]->make();
        drink->prepare(200);
        return drink;
    }
};

