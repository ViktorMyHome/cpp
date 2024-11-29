#include <iostream>
#include <assert.h>
// Queue: First In First Out
// enqueue - add at the end (rear) of the queue
// dequeue - delete from the front of the queue
// Rea

class QueueCircular{
public:
    int size{};
    int front{0};
    int rear{0};
    int added_elements{};
    int* array{};
    QueueCircular(int size):size(size){
        array = new int[size];
    }
    ~QueueCircular(){
        delete array;
    }
    int next(int pos){
        ++pos;
        if(pos == size)
            pos = 0;
        return pos;
    }
    bool isEmpty(){
        return added_elements == 0;
    }
    bool isFull(){
        return added_elements == size;
    }
    void enqueue(int value){
        assert(!isFull());
        array[rear] = value;
        rear = next(rear);
        added_elements++;
    }
    int dequeue(){
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

QueueCircular QC(5);
QC.enqueue(1);
QC.enqueue(2);
QC.enqueue(3);
printf("dequeue = %d\n", QC.dequeue());
QC.display();
QC.enqueue(4);
QC.enqueue(5);
QC.enqueue(6);
QC.display();

}