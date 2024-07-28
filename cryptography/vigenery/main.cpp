#include <iostream>
#include <string.h>

const char *alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int find_index(char l) {
    for(int i=0;i<strlen(alph);i++) {
        if(l == alph[i]){
            //std::cout<<" found "<<alph[i]<<std::endl; 
            return i;
        }
    }
    return 0;
}

    
void encrypt(char *plain, char *key, char *cipher_text) {
    int key_index = 0;
    int plain_index = 0;
    for(int i=0;i<strlen(key);i++) {
        int temp = 0;
        key_index = find_index(key[i]);
        plain_index = find_index(plain[i]);
        temp = (key_index + plain_index)%26;
        //std::cout<<"index = "<<temp<<" key_index = "<<key_index<<" plain_index = "<<plain_index<<std::endl;
        cipher_text[i] = static_cast<char>(alph[temp]);
    }
}

int main() {

    int i = find_index('F');
    std::cout<<i<<std::endl;
    char cipher_text[100] = {'\0'};
    char key[] = "TABLETABLETABLETABLETABLETABLETABLE";
    char plain[] = "CRYPTOGRAPHYISQUITEIMPORTANTINCRYPTOCURRENCIES";
    encrypt(plain,key,cipher_text);

    std::cout<<cipher_text<<std::endl;
    return 0;
}

