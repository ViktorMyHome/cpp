#include <string>
#include <cstdio>
#include <memory>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

struct Square
{
    int side{0};

    explicit Square(const int side) : side(side)
    {}
};

struct Rectangle
{
    virtual int width() const = 0;
    virtual int height() const = 0;

    int area() const
    {
        return width() * height();
    }
};

struct SquareToRectagleAdapter: Rectangle
{
    int Height;
    int Width;
    SquareToRectagleAdapter(const Square& square)
    {
        Height = square.side;
        Width = square.side;
    }
    int width() const
    {
        return Width;
    }
    int height() const
    {
        return Height;
    }
};


int main(){



return 0;
}