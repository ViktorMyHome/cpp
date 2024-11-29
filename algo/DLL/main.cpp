#include <iostream>
#include <assert.h>


class Node{
public:
    int data{};
    Node* next{};
    Node* prev{};

    Node(int data): data(data) {}

    void set(Node* next, Node* prev){
        this->next = next;
        this->prev = next;
    }
    void print(Node* head){
        while(head!=nullptr){
            std::cout<<head->data<<std::endl;
            head = head->next;
        }
    }

    void printRecursive(Node* head){
        if(head == nullptr)
            return;
        printRecursive(head->next);
        std::cout<<head->data<<std::endl;
    }
    void addNode(Node* head, int data){
        while(head!=nullptr){
            head = head->next;
        }
        
    }
};

class LinkedList{
public:
    Node *head{};
    Node *tail{};
    LinkedList(){
        Node *head = nullptr;
        Node* tail = nullptr;
    }
    void AddNode(int data){
        Node* node = new Node(data);
        if(!head)
            head = tail = node;
        else{
            tail->next = node;
            tail = node;
        }
    }
    void printRecursive(Node* head){
        if(head == nullptr)
            return;
        printRecursive(head->next);
        std::cout<<head->data<<std::endl;
    }
    void print(Node* head){
            Node* tmp = head;
        while(tmp!=nullptr){
            std::cout<<tmp->data<<std::endl;
            tmp = tmp->next;
        }
    }
};




int main(){

    LinkedList list;
    list.AddNode(3);
    list.AddNode(4);
    list.AddNode(5);
    list.printRecursive(list.head);
    list.print(list.head);

return 0;
}