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



class StackList{
public:
    struct Node{
        int data{};
        Node* next{};
        Node(int data): data(data){
            next = nullptr;
        }
    };
    Node* head{};

    int isEmpty(){
        return !head;
    }

    void push(int value){
        // By design: always new node = head
        Node* item = new Node(value);
        if(item == NULL)
            printf("Problem with quantity of memory\n");

        if(isEmpty()) {
            head = item;
            item->next = nullptr;
        } else {
            item->next = head;
            head = item;
        }
    }

    int pop() {
        assert(!isEmpty());
        int element = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        return element;
    }

    int peek() {
        assert(!isEmpty());
        int element = head->data;
        return element;
    }

    void display(){
        for(Node* cur = head; cur; cur = cur->next)
            cout<<cur->data<<" ";
        cout<<endl;
    }


};






int main(){
    StackList sl1;
    sl1.push(10);
    sl1.push(20);
    sl1.push(30);
    sl1.display();

}