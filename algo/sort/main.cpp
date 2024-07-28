#include <iostream>

//45 steps
void sort(int arr[], int size) {
    int count=0;
    for(int i=0;i<size;i++) {
        for(int j=0;j<i;j++) {
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp; 
            
            }
            count++;

        }
    }
    std::cout<<" count: "<<count<<std::endl;
}

void inserting_sort(int arr[], int size) {
    for(int i=1;i<size;i++){

        int j=i-1;

        if(arr[i] < arr[j] && j==0){
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i]=temp;
        }
        
        while(arr[i] < arr[j] && j>0){
            j--;
            std::cout<<"after decrease j="<<j<<std::endl;
        }

        //insert arr[i] to arr[j]
        // std::cout<<"arr[i]="<<arr[i]<<std::endl;
        // std::cout<<"arr[j]="<<arr[j]<<std::endl;
        // std::cout<<"i="<<i<<std::endl;
        // std::cout<<"j="<<j<<std::endl;

        int temp = arr[i];
        std::cout<<"temp="<<temp<<std::endl;

        int s=0;
        while((i-s-1) >= j){
            arr[i-s] = arr[i-1-s];
            std::cout<<"s="<<s<<std::endl;
            s++;
        }
        arr[j+1]=temp;



        for(int k=0;k<10;k++)
        std::cout<<arr[k]<<" ";
        std::cout<<std::endl;

    }
}

//100 steps
void sort_bubble(int arr[], int size) {
    int count=0;
    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp; 
            }
            count++;

        }
    }
    std::cout<<" count: "<<count<<std::endl;
}

typedef struct OSRTDListNode{
    void* data;
    struct OSRTDListNode* next;
    struct OSRTDListNode* prev;
} OSRTDListNode;

typedef struct OSRTDList{
    uint32_t count;
    OSRTDListNode* head;
    OSRTDListNode* tail;
} OSRTDList;

int main(){

    int myarray[10] = {9,0,6,44,55,23,43,78,2,9};

    for(int i=0;i<10;i++)
    std::cout<<myarray[i]<<" ";
    std::cout<<std::endl;

    inserting_sort(myarray,10);



}