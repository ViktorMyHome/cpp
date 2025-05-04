#include <iostream>
using namespace std;

// int SumArr(int arr[], int len){
//     if(len == 0)
//         return 0;
//     return arr[len-1] + SumArr(arr, len-1);
// }

int Sum(){
    return 0;
}

template<typename ... Args>
int Sum(int a, Args ... args){
    return a + Sum(args...);
}


int main() {

    // int a[5] = {1,2,3,4,5};
    // cout<<SumArr(a,5);

    cout<<Sum(1,2,3,4)<<endl;

    //sum(1,2,3,4)
    //1 + sum(2,3,4)
    //1 + 2 + sum(3,4)
    //1 + 2 + 3 + sum(4)
    //1 + 2 + 3 + 4 + sum()


    return 0;
}
