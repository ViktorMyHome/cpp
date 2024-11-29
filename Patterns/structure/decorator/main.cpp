#include <string>
#include <cstdio>
#include <memory>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

struct Shape
{
    virtual string str() const = 0;
};

struct Circle : Shape
{
    float radius;
    Circle(){};
    Circle(float radius) : radius(radius) {};

    string str() const override {
        ostringstream oss;
        oss<<"A circle of radius"<<radius;
        return oss.str();
    }

    void resize(float factor)
    {
        radius *= factor;
    }

    // void draw() override {
    //     cout<<"Circle"<<endl;
    // }
};

struct Square : Shape
{
    float side;
    Square() {}
    Square(float side) : side(side) {}
    string str() const override {
        ostringstream oss;
        oss<<"A square with side"<<side;
        return oss.str();
    }
};

struct ColoredShape : Shape
{
    Shape& shape;
    string color;
    ColoredShape(Shape &shape, const string &color) : shape(shape), color(color) {}
    string str() const override {
        ostringstream oss;
        oss << shape.str() << " has the color " << color;
        return oss.str();
    }
};

struct TransparentShape : Shape
{
    Shape& shape;
    uint8_t transparency;
    TransparentShape(Shape &shape, uint8_t transparency) : shape(shape), transparency(transparency) {}
    string str() const override {
        ostringstream oss;
        oss << shape.str() << " has "
            << static_cast<float>(transparency) / 255.f * 100.f
            << " % transparency";
        return oss.str();
    }
};

// struct Group: GraphicObject
// {
//     string name;
//     vector<GraphicObject*> object;

//     Group(const string &name) : name(name) {}
//     void draw() override
//     {
//         cout<<"Group"<<name.c_str()<<"contains:"<<endl;
//         for(auto&& o : object)
//             o->draw();

//     }
// };


int main(){

    Square square{5};
    ColoredShape red_square{square, "red"};
    cout<<square.str() << endl;
    cout<< red_square.str() << endl;

    TransparentShape my_square{red_square, 51};
    cout<<my_square.str()<<endl;

    // Group root("root");
    // Circle c1,c2;
    // root.object.push_back(&c1);

    // Group subgroup("sub");
    // subgroup.object.push_back(&c2);    

    // root.object.push_back(&subgroup);

    // root.draw();

return 0;
}