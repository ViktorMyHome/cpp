#include <iostream>
using namespace std;

struct Document
{

};

struct IPriner
{
    virtual void print(Document& doc) = 0;
};

struct IScaner
{
    virtual void print(Document& doc) = 0;
};


int main() {

    Rectangle r(3,4);
    int wi = r.getWidth();
    std::cout<<" width = "<<wi<<"\n";
    process(r);

    Square sq{5};
    process(sq);

    return 0;
}



