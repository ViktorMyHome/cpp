#include <iostream>
#include <math.h>

bool isPrime(int value) {
    if(value%2 == 0)
        return false;
    for(int i=3;i<sqrt(value);i++) {
        if(value%i == 0)
            return false;
    }
    return true;
}

bool isPrimeFermi(int value, int k=10) {
    for(int i=0;i<k;i++) {
        int a = rand()%value;
        if(a<2)
            a++;
        if(a<2)
            a++;
        std::cout<<a<<std::endl;
        int s = static_cast<int>(pow(a, value-1));
        std::cout<<"s="<<s<<std::endl;
        if(s%value != 1)
            return false;
    }
    return true;
}
int main() {
    std::cout<<isPrime(5)<<std::endl;

    std::cout<<isPrimeFermi(5)<<std::endl;

    return 0;
}