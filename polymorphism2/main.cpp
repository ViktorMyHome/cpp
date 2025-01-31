#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;

// virtual = run-time polymorphism, dynamic/late binding
// non-virtual = compile time polymorphism, static/early binding
// allowing us to write generic code (process(shapes)), without knowing exact children
// extensibility/flexibility/code reuse
// it is a bit slower + little memory than static binding  

class Point{
public:
    int x{};
    int y{};
    Point():x(0), y(0){}
    Point(int X, int Y){
        x=X;
        y=Y;
    }
};

class Shape{
protected:
    int color;
public:
    Shape():color(0){}
    Shape(int c){
        color = c;
    }
    virtual double ComputeArea() const {
        return 0;
    }
    virtual void Draw() const {
        cout<<" Shape::Draw()"<<endl;
    }
    //acts like virtual constructor
    virtual Shape* Clone() const {
        throw logic_error("Shape::Clone() Not implemented. Do override");
        return nullptr;
    }
    virtual ~Shape(){
        cout<<" ~Shape"<<endl;
    }
    int GetColor() const{
        //throw logic_error("Shape::GetColor() Not implemented. Do override");
        return color;
    }
    void SetColor(int color){
        //throw logic_error("Shape::SetColor() Not implemented. Do override");
        color = color;
    }
};

class Rectangle:public Shape{
private:
    Point top_left;
    Point right_buttom;
public:
    Rectangle(int color, int x1, int y1, int x2, int y2):Shape(color),top_left(x1, y1), right_buttom(x2, y2) {
        cout<<"Rectangule()"<<endl;
    }
    double ComputeArea(){
        return (right_buttom.x - top_left.x)*2 + (top_left.y - right_buttom.y)*2;
    }
    // Rectangle(const Rectangle& r){
    //     cout<<" Rectangle(const Rectangle& r) "<<endl;
    //     this->color = r.color;
    //     this->right_buttom.x = r.right_buttom.x;
    //     this->right_buttom.y = r.right_buttom.y;
    //     this->top_left.x = r.top_left.x;
    //     this->top_left.y = r.top_left.y;
    // }
    void Draw() const override final{
        cout<<"Rectangle::Draw() "<<endl;
    }
    Shape* Clone() const{
        return new Rectangle(*this);
    }
};

class Circle:public Shape{
protected:
    double radius;
    Point center;
public:
    Circle(int c, double r, int x, int y): Shape(c), radius(r), center(x, y){
    }
    double ComputeArea(){
        return 3.14*radius*radius;
    }
    void Draw() const override final{
        cout<<"Circle::Draw()"<<endl;
    }
    Shape* Clone() const{
        return new Circle(*this);
    }

};

class ImageEditor{
public:
    vector<Shape*> shapes;
public:
    void AddShape(const Shape &shape){
    //void AddShape(Shape shape){
        shapes.push_back(shape.Clone());
    }
    virtual void Draw()const{
        cout<<"ImageEditor::Draw\n";
        for(auto shapePtr: shapes)
            shapePtr->Draw();
    }
    virtual ~ImageEditor(){
        for(auto shapePtr: shapes)
            delete shapePtr;
    }

};


class AdobeImageEditor: public ImageEditor{
public:
    // void EnlargeShapes(double percent){
    //     for(auto shapePtr: shapes){
    //         cout
    //     }
    // }
};

void initialize(AdobeImageEditor* editor){
    Rectangle r1(10, 3, 4, 5, 6);
    cout<<"r1.GetColor"<<r1.GetColor()<<endl;
    Circle c1(20, 3.5, 8, 9);
    editor->AddShape(r1);
    editor->AddShape(c1);
    editor->shapes[0]->SetColor(5);
    
    cout<<"editor->shapes[0]->GetColor()"<<editor->shapes[0]->GetColor()<<endl;
}


int main(){

    AdobeImageEditor* editor = new AdobeImageEditor();
    initialize(editor);
    editor->Draw();

return 0;
}
