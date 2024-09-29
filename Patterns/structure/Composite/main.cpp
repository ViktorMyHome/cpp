#include <string>
#include <cstdio>
#include <memory>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

struct GraphicObject
{
    virtual void draw() = 0;
};

struct Circle : GraphicObject
{
    void draw() override {
        cout<<"Circle"<<endl;
    }
};

struct Group: GraphicObject
{
    string name;
    vector<GraphicObject*> object;

    Group(const string &name) : name(name) {}
    void draw() override
    {
        cout<<"Group"<<name.c_str()<<"contains:"<<endl;
        for(auto&& o : object)
            o->draw();

    }
};


int main(){

    Group root("root");
    Circle c1,c2;
    root.object.push_back(&c1);

    Group subgroup("sub");
    subgroup.object.push_back(&c2);    

    root.object.push_back(&subgroup);

    root.draw();

return 0;
}