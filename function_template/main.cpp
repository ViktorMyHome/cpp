#include <iostream>
using namespace std;

// Unary right fold
template<typename...Args>
auto sum_unary_right_fold(Args...args){
    return (args + ...);
}

// Binary right fold allow you to have empty list.
template<typename...Args>
auto sum_binary_right_fold(Args...args){
    return (args +...+ 0);
}

// Left fold
template<typename...Args>
auto sum_unary_left_fold(Args...args){
    return (... + args);
    //((1+2)+3)+4
}

template<typename...Args>
auto sum_binary_left_fold(Args...args){
    return (0 + ... + args);
    //(((0+1)+2)+3)+4
}

int main() {
    int xr = sum_unary_right_fold(1,2,3,4);
    cout<<"sum_unary_right_fold ="<<xr<<endl;
    xr = sum_binary_right_fold();
    cout<<"sum_binary_right_fold ="<<xr<<endl;
    return 0;
}
