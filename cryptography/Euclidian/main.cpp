#include <iostream>
#include <math.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "BigNumber.h"

const int size=100;

/*
if b/a then GCD(a,b)=b
else GCD(a,b) = GCD(b, a mod b)
*/
int greatCommonDiv(int a, int b) {
    if(a%b == 0) {
        return b;
    } else {
        greatCommonDiv(b,a%b);
    }
}

//exponential running time
int modular_inverse(unsigned long long a, unsigned long long m) {
    for(unsigned long long i=0;i<m;i++) {
        if((a*i)%m==1)
            return i;
    }
    std::cout<<"No module inverse for "<<a<<std::endl;
}

//a<b
// void extEuclidianGreatCommDiv(int a, int b, int *x, int *y) {
//     //gcd(0,b)=b a*x+b*y=b, so x=0, y=1
    
//     if(a==0) {
//         *x = 0;
//         *y = 1;
//         return;
//     } else {
//         extEuclidianGreatCommDiv(b%a, a, *x, *y);
//         *x=*y-(b/a)
//     }
// }

bool is_prime(int num) {
    if(num < 2)
        return false;
    if(num==2)
        return true;
    //even numbers can not be primes
    if(num%2 == 0)
        return false;
    for(int i=3;i<=sqrt(num);i++) {
        if(num%i == 0)
            return false;
    }
    return true;
}

int generate_large_number() {
    int rand_value;
    do {
        rand_value = rand()%10;
        if(rand_value < 3)
            rand_value += 3;
    } while(!is_prime(rand_value));

    return rand_value;
}

void generate_rsa_key(int *d, int *n, int *e) {
    int p = generate_large_number();
    int q = generate_large_number();
    //trapdoor function
    *n = p * q;
    //Euler's totient phi function
    int phi = (p-1)*(*n-1);

    *e = rand()%phi;
    if (*e<1)
        *e++;

    while(greatCommonDiv(*e, phi)!=1) {
        *e = rand()%phi;
        if (*e<1)
            *e++;
    }
    //d is modular inverse of e
    *d = modular_inverse(*e, phi);

}


void encrypt(int e, int n, std::string &plain_text, int cipher_text[]) {
//use ASCII representation for the character

    int digits1[] = {1, 2, 3, 4, 5};
    for(int i=0; i <size; i++) {
        int int_text = static_cast<int>(plain_text[i]);
        std::cout<<"int_text "<<int_text<<std::endl;

        int digits1[] = {1, 2, 3, 4, 5};
        BigNumber *bn1 = createAndSetBigNumber(digits1, 5);

        unsigned long long pow_text=static_cast<unsigned long long>(int_text);
        for(int j=0;j<e;j++)
            pow_text = pow_text*pow_text;
        std::cout<<pow_text<<std::endl;
        pow_text = pow_text%static_cast<unsigned long long>(n);
        cipher_text[i] = static_cast<int>(pow_text);
    }

}

void decrypt(int d, int n, int cipher_text[], std::string plain_text) {
    for(int i=0;i<size; i++) {
        int int_text = cipher_text[i];
        int pow_text = pow(int_text, d);
        pow_text = pow_text%n;
        plain_text[i] = static_cast<char>(pow_text);
    }
    std::cout<<"decrypt = "<<plain_text<<std::endl;
}

int main() {

/*
    int d, n, e;
    generate_rsa_key(&d, &n, &e);

    std::cout<<"d="<<d<<" n="<<n<<" e="<<e<<std::endl;

    int cipher_text[100]={0};
    std::string plain_text;

    std::string message{"This is example message with RSA"};
    std::cout<<"original message: "<<message<<std::endl;

    encrypt(e, n, message, cipher_text);

    std::cout<<"encrypted message: ";
    for(int i=0;i<size; i++)
    std::cout<<cipher_text[i]<<" ";
    std::cout<<std::endl;

    decrypt(d, n, cipher_text, plain_text);

    std::cout<<"decrypted message: "<<plain_text<<std::endl;
    */

    int digits1[] = {1, 2, 3, 4, 5, 0, 0, 0, 0};
    BigNumber *bn1 = createAndSetBigNumber(digits1, 9);
    printf("bn1 = createBigNumber: ");
    printBigNumber(bn1);
    printf("\n");

    // createBigNumber
    printf("bn2 = createBigNumber: ");
    BigNumber *bn2 = createBigNumber(5);
    printBigNumber(bn2);
    printf("\n");

    // setBigNumber
    printf("bn2 = setBigNumber: ");
    int digits2[] = {1, 2, 3, 4, 5, 0, 0, 0, 0};
    setBigNumber(bn2, digits2, 9);
    printBigNumber(bn2);
    printf("\n");

    // addBigNumbers
    printf("bn3 = addBigNumbers bn1, bn2: ");
    BigNumber *bn3 = addBigNumbers(bn1, bn2);
    printBigNumber(bn3);
    printf("\n");

    // copyBigNumber
    printf("bn4 = copyBigNumber bn1: ");
    BigNumber *bn4 = copyBigNumber(bn1);
    printBigNumber(bn4);
    printf("\n");

    // destroyBigNumber
    // printf("destroyBigNumber bn1: ");
    // destroyBigNumber(bn1);
    // printBigNumber(bn1);
    // printf("\n");

    // multiplyBigNumbers
    printf("bn5 = multiplyBigNumbers bn2, bn3: ");
    BigNumber *bn5 = multiplyBigNumbers(bn2, bn3);
    printBigNumber(bn5);
    printf("\n");
    
    // minusBigNumbers
    printf("bn6 = minusBigNumbers bn5, bn4: ");
    BigNumber *bn6 = minusBigNumbers(bn5, bn4);
    printBigNumber(bn6);
    printf("\n");

    // divideBigNumbers
    printf("bn7 = divideBigNumbers bn5, bn6: ");
    BigNumber *bn7 = divideBigNumbers(bn5, bn6);
    printBigNumber(bn7);
    printf("\n");

    // remainderBigNumbers
    printf("bn8 = remainderBigNumbers bn5, bn6: ");
    BigNumber *bn8 = remainderBigNumbers(bn5, bn6);
    printBigNumber(bn8);
    printf("\n");


    return 0;
}