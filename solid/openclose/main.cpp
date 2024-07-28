#include <iostream>
#include <vector>
using namespace std;



enum class Color { red, green, blue};

enum class Size { small, medium, large};

struct Product
{
    string name;
    Color color;
    Size size;
};

struct ProductFilter
{
    vector <Product*> by_color(vector<Product*> items, Color color)
    {
        vector<Product*> result;
        for(auto& i: items)
            if(i->color == color)
                result.push_back(i);
        return result;
    }
};

template <typename T> struct Specification
{
    virtual bool is_satisfied(T* item) = 0;
};

template <typename T> struct Filter
{
    virtual vector<T*> filter(vector<T*> items, Specification<T>& spec) = 0;
};

struct BetterFilter: Filter<Product>
{
    vector<Product*> filter(vector<Product*> items, Specification<Product> &spec) override
    {
        vector<Product*> result;
        for(auto& item: items)
            if(spec.is_satisfied(item))
                result.push_back(item);
        return result;
    }
};


struct ColorSpecification: Specification<Product>
{
    Color color;
    ColorSpecification(Color color): color(color) {}

    bool is_satisfied(Product *item) override {
        return item->color == color;
    }
};


int main() {

    Product apple{"Apple", Color::green, Size::small};
    Product tree{"Tree", Color::green, Size::large};
    Product house{"House", Color::blue, Size::large};
    vector<Product*> items {&apple, &tree, &house};
    // ProductFilter pf;
    // auto green_things = pf.by_color(items, Color::green);
    // for(auto& item : green_things)
    //     cout<<item->name<<" is green\n";

    BetterFilter bf;
    ColorSpecification green(Color::green);
    for(auto& item : bf.filter(items, green))
        cout<<item->name<<"is green\n";

    
    return 0;
}



