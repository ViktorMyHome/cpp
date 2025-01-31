#include <iostream>
#include <assert.h>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
// Stack: First In Last Out
// push() add the top of the stack
// pop() remove the top of the stack
// peek() what is the top, without removing



struct StackArrayChar{
    int size{};
    int top{};
    char* array{};

    StackArrayChar(int size):size(size), top(-1){
        array = new char[size];
    }

    ~StackArrayChar(){
        delete array;
    }

    void push(char data){
        array[++top] = data;
    }

    char pop(){
        if(top>=0)
            return array[top--];
        else
            return -1;
    }

    char peek(int index){
        if(index>=0){
            return array[index];
        } else {
            return '\0';
        }
    }

};

struct StackArrayInt{
    int size{};
    int top{};
    int* array{};

    StackArrayInt(int size):size(size), top(-1){
        array = new int[size];
    }

    void push(int data){
        array[++top] = data;
    }

    int pop(){
        if(top>=0)
            return array[top--];
        else
            return -1;
    }

    int peek(int index){
        if(index>=0){
            return array[index];
        } else {
            return '\0';
        }
    }

    void insert_at_bottom(int x){
        int temp = peek(top);
        this->push(temp);
        int i = top-1;
        for(; i>0; i--){

            this->array[i] = this->array[i-1];
        }
        array[0] = x;
    }

    void insert_at_bottom_recursia(int x){
        if(top == -1)
            push(x);
        else{
            int cur = pop();
            insert_at_bottom_recursia(x);
            push(cur);
        }
    }

    void reverse(){
        int size = top;
        for(int i=1;i<size*2;i=i+2){
            int temp = this->peek(i);
            this->insert_at_bottom_recursia(temp);
        }
        for(int i=size; i<size*2; i++)
            this->pop();
    }



    void print(){
        cout<<endl;
        for(int i=0;i<=top;i++){
            cout<<peek(i)<<endl;
        }
    }

};


string reverse_word(string line){
    int i=0;
    StackArrayChar sa(100);
    while(line[i]!='\0'){
        sa.push(line[i]);
        i++;
    }
    string str("");
    while(sa.top>=0){
        str += sa.pop();
    }
    return str;
}


string reverse_subword(string line){
    stringstream ss(line);
    string str;
    string strout("");
    while(getline(ss, str, ' ')){
        str = reverse_word(str);
        strout.append(str);
        strout+=' ';
    }
    return strout;
}

int reverse_number(int num){
    int value = 0;
    StackArrayInt sa(100);
    int i;
    int temp;
    for(i=1; num > pow(10, i); i++){
        temp = num % static_cast<int>(pow(10, i));
        temp /= static_cast<int>(pow(10, i-1));
        sa.push(temp);
        num = num - num % static_cast<int>(pow(10, i));
    }
    temp = num % static_cast<int>(pow(10, i));
    temp /= static_cast<int>(pow(10, i-1));
    sa.push(temp);

    StackArrayInt sa2(100);
    while(sa.top>=0){
        sa2.push(sa.pop());
    }
    while(sa2.top>=0){
        int temp = static_cast<int>(pow(10, sa2.top));
        int temp2 = sa2.pop();
        value += temp * temp2;
    }
    return value;
}

bool check_stack_duplicates(StackArrayChar* sa) {
    int i = 0;
    char temp;
    for(;i < sa->top; i++){
        if(sa->peek(i) == sa->peek(i+1))
            return true;
    }
    return false;
}

string remove_duplicates(string s) {
    StackArrayChar sa1(100);
    StackArrayChar sa2(100);
    char temp1;
    int i=0;
    while(s[i] != '\0'){
        sa1.push(s[i]);
        ++i;
    }
    sa1.push('\0');
    while(check_stack_duplicates(&sa1)) {
        for(i=0; sa1.top > 0; ) {
            temp1 = sa1.pop();

            if(temp1 != sa1.peek(sa1.top)) {
                sa2.push(temp1);
            } else {
                if(sa1.top > 0)
                    sa1.pop();
            }
        }
        for(i=0; sa2.top > 0; ) {
            sa1.push(sa2.pop());
        }
    }
    string str("");
    for(;sa1.top>0;){
        sa2.push(sa1.pop());
    }
    for(;sa2.top>0;){
        str+=sa2.pop();
    }
    return str;
}

char get_open_match(char ch){
    if(ch == ')')
        return '(';
    if(ch == ']')
        return '[';
    if(ch == '}')
        return '{';
}

bool is_valid(string str){
    StackArrayChar sa(str.size());
    for(int i=0;i<(int)str.size(); ++i){
        char ch = str[i];
        if(ch == '(' || ch == '[' || ch == '{'){
            sa.push(ch);
        } else if (sa.top==-1 || sa.pop()!=get_open_match(ch))
            return false;
    }
    return sa.top == -1;
}




int main(){

StackArrayChar sa1(100);
std::string str("abc d efg xy");

string str2 = reverse_subword(str);

cout<<str2<<endl;

int a = 1234567;

cout<<reverse_number(a)<<endl;

string stri = "abbacaac";

cout<<remove_duplicates(stri)<<endl;

cout<<is_valid("(()[())])")<<endl;//false

StackArrayInt sai1(100);
sai1.push(1);
sai1.push(2);
sai1.push(3);
sai1.push(4);
sai1.push(5);
sai1.push(6);
sai1.print();
sai1.reverse();
sai1.print();
}