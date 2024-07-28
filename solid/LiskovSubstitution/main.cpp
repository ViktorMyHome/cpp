#include <iostream>
using namespace std;


class Rectangle
{
protected:
    int width, height;
public:
    Rectangle(int Width, int Height): width{Width}, height{Height} {}
    int getWidth() const{
        return width;
    }
    virtual void setWidth(int width){
        Rectangle::width = width;
    }
    int getHeight() const {
        return height;
    }
    virtual void setHeight(int height){
        Rectangle::height = height;
    }
    int area() const {
        return width* height;
    }
};

class Square: public Rectangle
{
public:
    Square(int size) : Rectangle(size, size) {}

    virtual void setWidth(int width) override{
        this->width = this->height = width;
    }
    virtual void setHeight(int height) override {
       this->width = this->height = height;
    }

};

//this will help
// struct RectanguleFactory
// {
//     static Rectangle create_rectangle(int w, int h);
//     static Recatngle create_square(int size);
// }

//Square should be possible to insert in any Rectangle location

void process (Rectangle& r)
{
    int w = r.getWidth();
    std::cout<<"width "<<w<<"\n";
    r.setHeight(10);
    std::cout<<"expected area = "<<(w*10)
        <<", got "<<r.area()<<endl;
}

int main() {

    Rectangle r(3,4);
    int wi = r.getWidth();
    std::cout<<" width = "<<wi<<"\n";
    process(r);

    Square sq{5};
    process(sq);

    return 0;
}



