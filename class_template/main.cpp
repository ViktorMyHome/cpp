#include <iostream>
#include <functional>
#include <memory>
using namespace std;

template<typename T, int SIZE>
struct MyQueue{
    T arr[SIZE];
    int pos;
    MyQueue(){pos=0;}
    MyQueue(T param_arr[], int len){
        for(int i=0; i<len;++i)
            arr[i] = param_arr[i];
        pos = len;
    }
    void add_front(T elem){
        arr[pos++] = elem;
    }
    template<typename Type>
    void sum_and_add(Type a, Type b){
        arr[pos++] = a+b;
    }
    void print(){
        for(int i=0; i<pos; ++i)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
};

void f2(int &a){
    cout<<a<<endl;
}


int main() {

    MyQueue<string, 100> q_str;
    q_str.add_front("mostafa");
    q_str.add_front("saad");
    q_str.print();

    MyQueue<int, 100> q_dob;
    q_dob.add_front(3);
    q_dob.add_front(2);
    q_dob.print();

    //Convertion
    int a = 20;
    int b = 30;
    cout<<a-b<<endl;

    //f2(5); // Compilation Error: expected L-value, but we try Pr-value

    //a++ = 10; // CE: a++ returns Pr-value
    cout<<a<<endl;

    return 0;
}
