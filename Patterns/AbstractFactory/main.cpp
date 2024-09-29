#include "hotdrinkfactory/hotdrink.h"
#include <iostream>



#include "hotdrinkfactory/hotdrinkfactory.h"
#include "hotdrinkfactory/drinkfactory.h"


//#define MAX(x,y) (((x)>(y))?(x):(y))
#define MAX(x,y) (x>y?x:y)

unique_ptr<HotDrink> make_drink(string type)
{
    unique_ptr<HotDrink> drink;
    if(type == "tea")
    {
        drink = make_unique<Tea>();
        drink->prepare(200);
    }
    else{
        drink = make_unique<Coffe>();
        drink->prepare(50);
    }
    return drink;
}

int main() {
    
    int a=5,b=7;
    int m = 0;
    //int m = MAX(++a,b++);
    int k = (++a);
    int d = (b++);
    if (k>b)
    m = k;
    else
    m = d;
    std::cout<<" m="<<m<<std::endl;
    std::cout<<" a = "<<a<<std::endl;
    std::cout<<" b = "<<b<<std::endl;

    //auto d = make_drink("tea");
    DrinkFactory df;
    auto c = df.make_drink("coffe");

    return 0;
}