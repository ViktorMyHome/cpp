#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

enum class Relationship
{
    parent,
    child,
    sibling
};

struct Person
{
    string name;
};

struct Relationships
{
    vector<tuple<Person, Relationship, Person>> relations;

    void add_parent_and_child(const Person& parent, const Person& child)
    {
        relations.push_back({parent, Relationship::parent, child});
        relations.push_back({child, Relationship::child, parent});
    }
};




int main() {



    return 0;
}



