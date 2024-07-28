#include <iostream>
#include <algorithm>
#include <math.h>

void print_(int level) {
    if(level > 1) {
        for(int i=0;i<level;i++)
            std::cout<<"*";
        std::cout<<std::endl;
        print_(level-1);
    }
    else {
        std::cout<<"*";
        std::cout<<std::endl;
    }
}

int my_pow(int value, int p) {
    if(p==0)
        return 1;


    return my_pow(value, p-1) * value;

}

int arr_max(int arr[], int len) {
    int max = arr[0];
    // for(int i=1;i<len;i++) {
    //     if(arr[i]>max)
    //         max = arr[i];
    // }
    // return max;
    if (len == 1)
        return arr[0];

    if (len > 2)
        return arr_max(arr, len-1 ) > arr[len-1] ? arr_max(arr, len-1 ) : arr[len-1];

    else
        return arr[0]>arr[1] ? arr[0] : arr[1];
}

void array_increment(int arr[], int len) {
    if(len > 2) {

        for(int i=0;i<(len-1);i++)
            arr[len-1] += arr[i];
        array_increment(arr, len-1);
    }
    else {
        arr[1] += arr[0];
    }
}

void left_max(int arr[], int len, int start_pos = 0) {
    if(len == 1)
        return;
    if(start_pos <= (len-2)) {
        if(arr[len-2] < arr[len-1])
            arr[len-2] = arr[len-1];
    }
    left_max(arr, len-1, start_pos);
}

int count_primes(int from, int till) {
    static int count=0;
    if(till > from) {
        count_primes(from, till-1);
        if(static_cast<int>(pow(2,till-1))%till == 1) {
            std::cout<<" count ++ "<<till<<std::endl;
            count++;
        }
        return count;
    }
    else if(from==count){
        if(static_cast<int>(pow(2,from-1))%from == 1)
            count++;
        return count;
    }
}

int fibonacci(int n) {
    if(n<0)
        return 0;
    if(n==0)
        return 1;
    if(n==1)
        return 1;

    if(n>1) {
        return fibonacci(n-1)+fibonacci(n-2);
    }
}


int main() {
    print_(5);

    std::cout<<my_pow(7, 2)<<std::endl;

    int my_array[5] = {1,8,2,10,3};
    std::cout<<arr_max(my_array,5)<<std::endl;

    array_increment(my_array, 5);

    for(int i=0;i<5;i++)
    std::cout<<my_array[i]<<" ";
    std::cout<<std::endl;

    int my_array2[6] = {1,3,5,7,4,2};
    left_max(my_array2, 6, 1);
    for(int i=0;i<6;i++)
    std::cout<<my_array2[i]<<" ";
    std::cout<<std::endl;

    std::cout<<count_primes(10,50)<<std::endl;


    std::cout<<"fibonacci: "<<fibonacci(40)<<std::endl;
}
