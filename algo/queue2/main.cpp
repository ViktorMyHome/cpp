#include <iostream>
#include <assert.h>
using namespace std; 
// Queue: First In First Out
// enqueue - add at the end (rear) of the queue
// dequeue - delete from the front of the queue
// Rear

//Circular queue
//use added_elements or rear
class Queue{
public:
    int* Array;
    int front{0};
    int rear{0};
    int added_elements{0};
    int size{0};

    Queue(int Size){
        added_elements = 0;
        front = rear = 0;
        Array = new int[Size];
        size = Size;
    }

    ~Queue(){
        delete[] Array;
    }

    int next(int pos){
        ++pos;
        if(pos == size)
            pos = 0;
        return pos;
    }

    bool isEmpty(){
        return front == rear;;
    }

    bool isFull(){
        return next(rear) == front;
    }

    void enqueue(int val){
        if(!isFull()){
            added_elements++;
            Array[rear] = val;
            rear = next(rear);
        }
    }

    int dequeue(){
        if(!isEmpty()){
            added_elements--;
            int val = Array[front];
            front = next(front);
            return val;
        }
        return -1;
    }

    void print(){
        int i=0;
        while(i<added_elements){
            std::cout<<Array[i++]<<" ";
        }
        std::cout<<endl;
    }
};


class PrioQueue{
    Queue q1, q2, q3;
    int size{0};
public:
    PrioQueue(int Size): q1(Size), q2(Size), q3(Size){
    }

    bool isFull(){
        return q1.isFull() | q2.isFull() | q3.isFull();
    }

    void enqueue(int task, int prio){
        switch(prio){
            case 1:
                q1.enqueue(task);
                break;
            case 2:
                q2.enqueue(task);
                break;
            case 3:
                q3.enqueue(task);
                break;
            default:
                break;
        }
    }

    int dequeue(){

        if(!q1.isEmpty()){
            return q1.dequeue();
        } else if(!q2.isEmpty()){
            return q2.dequeue();
        } else if(!q3.isEmpty()){
            return q3.dequeue();
        }
    }

    void display(){
        for (int i=0;i<q1.added_elements;i++){
            cout<<" Prio 1 task "<<i<<" : "<< q1.Array[i];
        }
        cout<<endl;
        for (int i=0;i<q2.added_elements;i++){
            cout<<" Prio 2 task "<<i<<" : "<< q2.Array[i];
        }
        cout<<endl;
        for (int i=0;i<q3.added_elements;i++){
            cout<<" Prio 3 task "<<i<<" : "<< q3.Array[i];
        }
        cout<<endl;
    }
};

class Last_k_numbers_sum_stream{
public:
    Queue q;
    int size{0};
    Last_k_numbers_sum_stream(int k) : q(1000), size{k}{
    }
    ~Last_k_numbers_sum_stream(){
    }

     int next(int new_num){
        int sum=0;
        if(q.added_elements == size)
            cout<<" dequeue "<<q.dequeue()<<endl;
        q.enqueue(new_num);
        for(int i=0; i<q.added_elements; i++){
            sum += q.Array[q.front + i];
        }
        return sum;
    }
};


int main(){

    // Queue q(5);
    // q.enqueue(1);
    // q.enqueue(2);
    // q.enqueue(3);
    // q.enqueue(4);
    // q.enqueue(5);
    // q.enqueue(6);
    // std::cout<<"dequeue " <<q.dequeue()<<std::endl;
    // q.print();

    // PrioQueue pq1(5);
    // pq1.enqueue(101,1);
    // pq1.enqueue(102,1);
    // pq1.enqueue(201,2);
    // pq1.enqueue(202,2);
    // pq1.enqueue(301,3);
    // pq1.enqueue(302,3);

    // pq1.dequeue();
    // pq1.dequeue();

    // pq1.display();

    
    Last_k_numbers_sum_stream processor(4);
    int num;
    while(cin >> num){
        cout <<" "<< processor.next(num);
    }

}