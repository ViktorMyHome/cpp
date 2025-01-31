#include <iostream>
#include <assert.h>
#include <vector>
#include <memory>
using namespace std;

// class unique_ptr{
// private:
//     int* data;
//     ~unique_ptr(){

//     }
// };

void print1(unique_ptr<int> p){
    cout<<*p<<endl;
}

void print10(unique_ptr<int> p){
    cout<<" "<<*p<<endl;
}

void print2(unique_ptr<int> &p){
    cout<<*p<<endl;
    p.reset();
}

void print3(const unique_ptr<int> &p){
    cout<<*p<<endl;
    *p = 10;
}


struct Point{
    int x,y;
    Point(){
        x=0;
        y=0;
    }
    Point(int xx, int yy){
        cout<<" Point(x,y)"<<endl;
        x=xx;
        y=yy;
    }
    ~Point(){
        cout<<"~Point()"<<endl;
    }
    Point(const Point& p){
        x=p.x;
        y=p.y;
    }
    Point& operator=(const Point& p){
        x = p.x;
        y = p.y;
        return *this;
    }
    Point operator+(const Point& p){
        Point temp(0,0);
        temp.x = x+p.x;
        temp.y = y+p.y;
        return temp;
    }
    Point operator+(const int& val){
        Point temp(0,0);
        temp.x = val;
        temp.y = val;
        return temp;
    }
    void print(){
        cout<<" X = "<<x<<endl;
        cout<<" Y = "<<y<<endl;
    }
    Point& operator++(){//++x
        this->x += 1;
        this->y += 1;
        return *this;
    }
    
    Point operator++(int){//x++
        Point temp(*this);
        x+=1;
        y+=1;
        return temp;    
    }
};


int main(){
    unique_ptr<int> p1{new int {20}};
    unique_ptr<int> &p2 = p1;//Alias
    print1(move(p1));
    p1.reset(new int {25});
    print1(move(p1));
    p1.reset(new int {30});
    print10(move(p1));//segmentation fault
    // p2.reset(new int {30});
    // print2(p2);
    // print3(move(p2));
    int* a;
    int b[4]={0,1,2,3};
    a = &b[0];
    a = a+2;
    cout<<"+++ "<<*a<<endl;


    Point A(1,1);
    Point B(2,2);
    //Point C(0,0);
    Point C=A+B;
    C.print();
    (++C).print();
    C++.print();
    C.print();



return 0;
}
