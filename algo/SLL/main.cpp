#include <iostream>
#include <assert.h>
// class that has 2 variables:
// int value
// pointer to the link ???

class Node{
public:
    int data;
    Node* next;

    Node(int data): data(data) {}
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
    Node *head{};// mandatory
    Node *tail{};// optional
    int length{0};//should be if we want to implement deleting of last node 
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
    ~LinkedList(){
        Node* tmp = head;
        while(tmp!=nullptr){
            head = head->next;
            //printf("~LinkedList data = %d\n", tmp->data);
            delete tmp;
            tmp = head;
            //printf("next data = %d\n", tmp->data);
        }
    }
    void insert_front(int value){
        Node* node = new Node(value);
        node->next = head;
        head = node;
    }
    void delete_front(){
        if(head!=nullptr){
            Node* tmp;
            tmp = head;
            head = head->next;
            delete tmp;
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
    bool delete_node_with_key(int value)
    {
        Node* tmp1 = head;
        Node* tmp2 = head;
        Node* tmp3 = head;
        bool result = false;

        assert(head!=tail);

        if(head->data == value){
            tmp3 = head->next;
            delete head;
            head = tmp3;
        }

        if(tail->data == value){
            tmp3 = head;
            tmp2 = head;

            tmp3 = tmp3 -> next;
            if(tmp3->next == tail){
                delete tail;
                tmp3 -> next = nullptr;
                tail = tmp3;
                return true;
            }

            while(tmp3->next!=tail){
                tmp2 = tmp2 -> next;
                tmp3 = tmp3 -> next;
            }
            delete tail;
            tail = tmp3;
            tail->next = nullptr;
            return true;
        }

        tmp1 = tmp1->next;
        if(tmp1->data == value){
            tmp3 = tmp1->next;
            delete tmp1;
            tmp2->next = tmp3;
            return true;
        }
        tmp2 = tmp1;
        tmp1 = tmp1->next;

        while(tmp1!=tail){
            if(tmp1->data == value){
                tmp3 = tmp1->next;
                delete tmp1;
                tmp2->next = tmp3;
                return true;
            }
            tmp2 = tmp1;
            tmp1 = tmp1->next;
        }
        return false;
    }

    void insert_sorted(int value){
        Node* tmp1;
        Node* tmp2;
        Node* tmp3;
        tmp3 = new Node(value);

        tmp1 = head;
        tmp2 = head;

        if(head->data > value){
            head = tmp3;
            tmp3->data = value;
            tmp3->next = tmp1;
            return;
        }

        if(tail->data < value){
            while(tmp1->next!=tail)
                tmp1 = tmp1->next;
            tail = tmp3;
            tmp3->data = value;
            tmp3->next = nullptr;
            tmp1->next = tail;
            return;
        }

        tmp1 = head;
        tmp2 = tmp2->next;
        if(tmp2->data>value){
            tmp3->data = value;
            tmp3->next = tmp2;
            tmp1->next = tmp3;
            return;
        }

        while(tmp2->data<value){
            tmp2 = tmp2->next;
            tmp1 = tmp1->next;
        }
        tmp3->data = value;
        tmp3->next = tmp2;
        tmp1->next = tmp3;
        return;
    }

    void swap_pairs(){
        Node* tmp1;
        Node* tmp2;
        int temp;
        tmp1 = head;
        tmp2 = tmp1->next;
        if(tmp2->next!=tail && tmp1->next!=tail){
            temp = tmp1->data;
            tmp1->data = tmp2->data;
            tmp2->data = temp;
        }
        for(;tmp2->next!=tail && tmp1->next!=tail;){
            tmp1 = tmp1->next->next;
            tmp2=tmp2->next->next;
            temp = tmp1->data;
            tmp1->data = tmp2->data;
            tmp2->data = temp;
        }
    }

    void delete_position(Node* ptr){
        if(ptr==head) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
        if(ptr==tail) {
            Node* tmp;
            while(tmp->next!=tail){
                tmp = tmp->next;
            }
            delete tail;
            tail = tmp;
            tail->next = nullptr;
        }
        Node* prev = head;
        while(prev->next!=ptr){
            prev = prev->next;
        }
        Node* next = prev;
        next = next->next;
        next = next->next;
        delete ptr;
        prev->next = next;
    }

    void remove_duplicated() {
        Node* ptr_el;
        Node* ptr_ch;
        ptr_el = head;
        Node* ptr_prev = head;
        Node* temp;
        ptr_ch = head->next;
        bool remove;
        bool remove2;
        while(ptr_el->next!=tail){
            ptr_ch = ptr_el->next;
            ptr_prev = ptr_el;
            remove = false;
            while(ptr_ch->next!=nullptr){
                remove2 = false;
                if(ptr_el->data == ptr_ch->data) {
                    if(ptr_ch == tail)
                        tail = ptr_prev;

                    remove2 = true;
                    temp = ptr_ch;
                    ptr_ch = ptr_ch->next;
                    delete_position(temp);
                    remove = true;
                }

                if(remove2){
                    temp = ptr_ch;
                    ptr_ch = ptr_ch->next;
                    delete temp;
                } else{
                ptr_ch = ptr_ch->next;
                ptr_prev = ptr_prev->next;
                }
            }
            if(remove){
                temp = ptr_el;
                ptr_el = ptr_el->next;
                delete temp;
            } else
            ptr_el = ptr_el->next;
        }
    }

    void delete_even_position(){
        Node* tmp;
        tmp=head;
        for(int i=0;tmp->next!=nullptr;tmp = tmp->next){
            if(i%2 == 0){
                delete_node_with_key(tmp->data);
            }
            i++;
        }
    }
};




int main(){

    LinkedList list;
    list.AddNode(3);
    list.AddNode(4);
    list.AddNode(5);
    list.AddNode(6);
    list.AddNode(7);
    list.AddNode(8);
    list.AddNode(9);
    list.AddNode(10);
    list.AddNode(11);
    list.AddNode(12);
    list.AddNode(10);
    list.AddNode(11);
    list.AddNode(5);
    list.AddNode(6);
    list.AddNode(11);
    list.AddNode(6);
    list.insert_front(2);

//    list.delete_front();
//    list.delete_node_with_key(5);
//    list.delete_node_with_key(2);
//    list.delete_node_with_key(8);
//    list.printRecursive(list.head);
    list.insert_sorted(5);
    list.insert_sorted(8);
    list.print(list.head);

//    list.swap_pairs();
    list.print(list.head);
    std::cout<<std::endl;
//    list.delete_even_position();
    list.remove_duplicated();
    list.print(list.head);

return 0;
}