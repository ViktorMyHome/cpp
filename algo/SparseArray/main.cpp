#include <iostream>
#include <assert.h>


struct Node{
    int data{};
    int index{};
    Node* next{};
    Node* prev{};

    Node(int val, int index) : data(val), index(index){
        next = nullptr;
        prev = nullptr;
    }

    void set(Node* next, Node* prev){
        this->next = next;
        this->prev = prev;
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

class ArrayLinkedList{
public:
    Node *head{};
    Node *tail{};
    int length = 0; // total number of nodes
    int array_length {};  //total number of array elements

    void link(Node* first, Node* second) {
        if(first)
            first->next = second;
        if(second)
            second->prev = first;
    }

    ArrayLinkedList(){
        Node *head = nullptr;
        Node* tail = nullptr;
    }



    void AddNode(int data){
        Node* node = new Node(data);
        Node* temp;
        if(!head)
            head = tail = node;
        else if(head==tail){
            head->next = node;
            head->prev = nullptr;
            tail = node;
            tail->next = nullptr;
            tail->prev = head;
        } else{
            temp = tail;
            temp->next = node;
            tail = node;
            tail->prev= temp;
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
    void link(Node* node1, Node* node2){
        if(node1)
            node1->next = node2;
        if(node2)
            node2->next = node1;
    }
    void insert_front(int val){
        if(!head)
            head = tail = new Node(val);
        else{
            Node* temp = new Node(val);
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }

    Node* embed_after(Node* node_before, int value, int index){
        Node* middle = new Node(value, index);
        ++length;

        Node* node_after = node_before->next;
        link(node_before, middle);

        if(!node_after)
            tail = middle;
        else
            link(middle, node_after);

        return middle;
    }

    void reverse(){
        Node* temp;
        Node* Next;

        Next = head;

        for(;Next;Next = Next->prev){
            temp = Next->prev;
            Next->prev = Next->next;
            Next->next = temp;
        }

        temp = head;
        head = tail;
        tail = temp;

        tail->next = nullptr;
        head->prev = nullptr;
    }

    void insert_in_previous(Node* node_to_insert, Node* before_to_insert){
        Node* temp;
        temp = head;
        Node* prev = before_to_insert->prev;

        node_to_insert->next = before_to_insert;
        before_to_insert->prev = node_to_insert;
        if(before_to_insert == head){
            node_to_insert->prev = nullptr;
        } else{
            node_to_insert->prev = prev;
        }
    }

    void merge(ArrayLinkedList* list){
        Node* ptr = head;
        Node* ptr2 = list->head;
        Node* curr;
        Node* begin;
        begin = new Node(0);
        curr = begin;
        for(;ptr && ptr2;){
                if(ptr->data < ptr2->data){
                    curr->next = ptr;
                    ptr->prev = curr;
                    curr = ptr;
                    ptr = ptr->next;
                } else {
                    curr->next = ptr2;
                    ptr2->prev = curr;
                    curr = ptr2;
                    ptr2 = ptr2->next;
                }

        }
            if(ptr && !ptr2){
                while(ptr){
                    curr->next = ptr;
                    ptr->prev = curr;
                    curr = ptr;
                    ptr = ptr->next;
                }
            } else if(ptr2 && !ptr){
                tail = list->tail;
                while(ptr2){
                    curr->next = ptr2;
                    ptr2->prev = curr;
                    curr = ptr2;
                    ptr2 = ptr2->next;
                }
            }


        head = begin->next;
        head->prev = nullptr;
        delete begin;
    }

};




int main(){

    LinkedList list;
    list.AddNode(5);
    list.AddNode(6);
    list.AddNode(9);
    list.insert_front(2);
    //list.printRecursive(list.head);
    list.print(list.head);

    //list.reverse();//debugged
    std::cout<<std::endl;
    //list.print(list.head);
    LinkedList  list2;
    list2.AddNode(3);
    list2.AddNode(7);
    list2.AddNode(11);
    list.merge(&list2);
    list.print(list.head);
    std::cout<<std::endl;
    LinkedList list3;
    list3.AddNode(10);
    list3.AddNode(20);
    list3.AddNode(30);
    list3.AddNode(40);
    list3.AddNode(50);
    LinkedList list4;
    list4.AddNode(15);
    list4.AddNode(17);
    list4.AddNode(22);
    list4.AddNode(24);
    list4.AddNode(35);
    list3.merge(&list4);
    list3.print(list3.head);    

return 0;
}