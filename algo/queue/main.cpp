#include <iostream>
#include <assert.h>
using namespace std; 
// Queue: First In First Out
// enqueue - add at the end (rear) of the queue
// dequeue - delete from the front of the queue
// Rear

struct StackArrayInt{
    int size{};
    int top{};
    int* array{};

    StackArrayInt(int size):size(size), top(-1){
        array = new int[size];
    }

    ~StackArrayInt() {
        delete array;
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

struct queue2stacks{
    StackArrayInt st1;
    StackArrayInt st2;
    int front{0};
    int rear{0};
    int added_elements{0};

    queue2stacks(int size):st1(size), st2(size){
        added_elements = 0;
        front = 0;
        rear = 0;
    }   
    //           _____
    //enqueue-> |3|2|1| ->dequeue
    //           
    void enqueue_rear(int val){
        if(added_elements<st1.size){
            st1.push(val);
        }
        if(added_elements == st1.size){//if st1 is full, move everything to st1.
            while(st1.top>=0){
                st2.push(st1.pop());
            }
        }
        if(added_elements < (st2.size + st1.size) && added_elements >= st1.size) {
            //st2.push(st1.pop());
            st1.push(val);
        }
        added_elements++;
    }
    int dequeue(){
        if(added_elements > st1.size){
            added_elements--;
            return st2.pop();
        } else if(added_elements == st1.size){
            while(st1.top>=0){
                st2.push(st1.pop());
            }
        }
        if(added_elements <= st1.size && added_elements > 0){
            added_elements--;
            return st2.pop();
        }else {
            return 0;
        }
    }

    void print(){
        st1.print();
        st2.print();
    }

};

class dequeue{
public:
    int size{};
    int front{0};
    int rear{0};
    int added_elements{};
    int* array{};
    dequeue(int size):size(size){
        array = new int[size];
    }
    ~dequeue(){
        delete array;
    }
    int next(int pos){
        ++pos;
        if(pos == size)
            pos = 0;
        return pos;
    }
    int prev(int pos){
        --pos;
        if(pos == -1)
            pos = size-1;
        return pos;
    }
    bool isEmpty(){
        return added_elements == 0;
    }
    bool isFull(){
        return added_elements == size;
    }
    void enqueue_rear(int value){
        assert(!isFull());
        array[rear] = value;
        rear = next(rear);
        added_elements++;
    }
    void enqueue_front(int value){
        assert(!isFull());
        array[front] = value;
        front = prev(front);
        added_elements++;
    }
    int dequeue_rear(){
        assert(!isEmpty());
        rear = prev(rear);
        int value = array[rear];
        added_elements--;
        return value;
    }
    int dequeue_front(){
        assert(!isEmpty());
        int value = array[front];
        front = next(front);
        --added_elements;
        return value;
    }

    void display(){
        std::cout<<" Front "<<front<<" Rear "<<rear<<std::endl;
        if(isFull()){
            std::cout<<" Full "<<std::endl;
        } else if(isEmpty()) {
            std::cout<<" Empty "<<std::endl;
        }
        for(int cur=front, step=0; step < added_elements; ++step, cur=next(cur)) {
            std::cout<<array[cur]<<" ";
        }
    }

};



int main(){

queue2stacks qe1(5);
qe1.enqueue_rear(1);
qe1.enqueue_rear(2);
qe1.enqueue_rear(3);
qe1.enqueue_rear(4);
qe1.enqueue_rear(5);
qe1.enqueue_rear(6);
qe1.enqueue_rear(7);
qe1.enqueue_rear(8);
qe1.enqueue_rear(9);
qe1.enqueue_rear(10);
std::cout<<"deque = "<<qe1.dequeue()<<std::endl;
std::cout<<"deque = "<<qe1.dequeue()<<std::endl;
std::cout<<"deque = "<<qe1.dequeue()<<std::endl;
std::cout<<"deque = "<<qe1.dequeue()<<std::endl;
std::cout<<"deque = "<<qe1.dequeue()<<std::endl;
std::cout<<"deque = "<<qe1.dequeue()<<std::endl;
std::cout<<"deque = "<<qe1.dequeue()<<std::endl;
qe1.print();



}