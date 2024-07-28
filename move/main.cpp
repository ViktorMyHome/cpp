#include "source.h"
#include <iostream>


//R-value reference

// //return r-value
// int Add(int x, int y) {
//     return x + y;
// }
// //return l-value
// int & Transform(int &x) {
//     x *= x;
//     return x;
// }


Integer Add(const Integer &a, const Integer &b) {
    Integer temp;
    temp.SetValue(a.GetValue()+b.GetValue());
}


int main() {
    
    //int &&r1 = 10;


    //Integer a(1), b(3);
   // a.SetValue(Add(a,b).GetValue());

   //Integer a=3;//Integer(int); -> copy is omited - copy ellision!!!!
   Integer b(3);//integer(int)
   Integer a = b;//Integer(const &Integer);

    return 0;
}