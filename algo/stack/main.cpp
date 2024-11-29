#include <iostream>
#include <assert.h>
// Stack: First In Last Out
// push() add the top of the stack
// pop() remove the top of the stack
// peek() what is the top, without removing

// funcA->funcB->funcC
// funcC is top
// funcA mmust finish 

// Stack stk(3);
// stk.push(10);
// stk.push(20);
// stk.push(30);
// stk.isFull();
// stk.peek();
// stk.pop();

class Stack{
public:
    int size{};
    int top{};
    int* array{};

    Stack(int size):size(size), top(-1){
        array = new int[size];
    }

    void push(int a){
        assert(!isFull());
        array[++top] = a;
    }
    void pop(){
        assert(!isEmpty());
            array[top--]=0;
    }
    int peek(){
        return array[top];
    }
    bool isFull(){
        return top == size -1;
    }
    bool isEmpty(){
        return top == -1;
    }

};

struct Node{
    int el{};
    Node* next{};
    Node(int data): el(data){};
    };

class LinkedStack{
public:

    void push(int val){
        Node* item = new Node(val);
        item->next=head;
        head = item;
    }
    Node* head{};

    int pop(){
        int elem = head->el;
        Node* ptr = head;
        head = head->next;
        delete ptr;
        return elem;
    }

    void print(){
        Node* tmp;
        tmp = head;
        while(tmp!=nullptr){
            printf("el = %d\n",tmp->el);
            tmp = tmp->next;
        }
    }
};

int fact(int a){
    if(a == 1)
    return 1;
    else
    return a*fact(a-1);
}


int main(){

printf("%d\n", fact(5));


Stack stk(5);
stk.push(3);
stk.push(4);
stk.push(5);
printf("top = %d\n", stk.top);
printf("top element = %d\n", stk.peek());
stk.pop();
printf("top element = %d\n", stk.peek());
printf("top = %d\n", stk.top);

LinkedStack LS;
LS.push(1);
LS.push(2);
LS.push(3);
LS.print();
printf("first elem = %d\n",LS.pop());
LS.print();

}