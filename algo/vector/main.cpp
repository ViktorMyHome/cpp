#include <iostream>
#include <assert.h>
#include <vector>

class Vector{
private:
    int* arr = nullptr;
    int size = 0;

public:
 Vector(int Size){
    arr = (int*)malloc(Size*sizeof(int));//new int[Size];
    size = Size;
 }
 ~Vector(){
    //delete[] arr;
    free(arr);
    arr = nullptr;
 }

 int get_front(){
    if(size>0){
        return arr[0];
    } else {
        return -1;
    }
 }

 int get_back(){
    if(size>0){
        return arr[size-1];
    } else {
        return -1;
    }
 }

 int get(int i){
    return arr[i];
 }

 void push_back(int value){
    int* arr_new = (int*)malloc(sizeof(int)*(size+1));//new int[size+1];
    for(int i=0;i<size;i++){
        arr_new[i] = arr[i];
    }
    arr_new[size++] = value;
    int* tmp = arr;
    arr = arr_new;
    //this->print();
    arr_new = tmp;
    //delete[] arr_new;
    free(arr_new);
 }

 void insert(int value, uint idx){
    int *arr_new = new int[++size];
    for(int i=0;i<size;++i){
        if(i<idx){
            arr_new[i] = arr[i];
        } else if(i==idx) {
            arr_new[i] = value;
        } else {
            arr_new[i] = arr[i-1];
        }
    }
    int* tmp = arr;
    arr = arr_new;
    arr_new = tmp;
    delete[] arr_new;
 }

 void print(){
    for(int i=0;i<size;i++)
        printf("arr[%d]=%d\n",i, arr[i]);
 }

};






int main(){

    std::vector<int>vec;
    vec.push_back(34);


    Vector V(1);
    V.push_back(1);
    V.push_back(2);
    V.push_back(3);
    V.push_back(4);
    V.push_back(5);
    V.push_back(6);

    printf("get_front = %d\n", V.get_front());
    printf("get_back = %d\n", V.get_back());
    V.print();

    printf("insert\n");
    V.insert(99,2);
    V.print();

    Vector V2(1);
    printf("insert\n");
    V.insert(99,0);
    V.print();
return 0;
}