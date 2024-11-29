#include <iostream>
#include <assert.h>
// Deps - from the node to the root
// Heigh - from the node to the longest leave
// Binary search tree
// Expression tree: leaves are operands and others operators
// LRV left, right, value
// leaf_nodes = internal_nodes + 1
// min # of nodes = 2*h+1, h- heigh
// perfect binary tree - complete tree:
// all leaf nodes have the same level
// all other nodes have 2 children
// height = 3, level = 4
// balanced binary tree - difference between left
// and right subtree is not more than 1

// binary search tree
// 


#define SWAP(type, x, y) type tmp = x; x = y; y = tmp;

struct Node{
    Node* left{};
    Node* right{};
    int value{0};
    Node():value(0){};
    Node(int data){
        value = data;
        left = nullptr;
        right = nullptr;
    };
    Node(const Node &obj) {
        this->value = obj.value;
        left = nullptr;
        right = nullptr;
    }
    bool search(int target) {
        if(target == value) {
            printf("value found = %d\n", value);
            return true;
        }
        if(target < value){
            printf("value = %d\n", value);
            return left && left->search(target);
        } else {
            printf("value = %d\n", value);
            return right && right->search(target);
        }
    }
    void insert(int target) {
        if(target < value) {
            if(!left)
                left = new Node(target);
            else
                left->insert(target);
        } else if(target > value) {
            if(!right)
                right = new Node(target);
            else
                right->insert(target);
        }
    }


};




int main(){

Node BT(10);
Node BT2(BT);
BT.insert(5);
BT.insert(15);
BT.insert(4);
BT.insert(7);
BT.insert(14);
BT.insert(100);
BT.insert(2);
BT.insert(8);
BT.insert(12);
BT.insert(13);



BT2.insert(100);
BT2.insert(120);
BT2.insert(90);
BT2.insert(80);
BT2.insert(85);
BT2.insert(95);
BT2.insert(110);
BT2.insert(105);

BT.search(13);
BT2.search(110);
int a=2;
int b=3;

SWAP(int, a, b);

printf("a=%d\n",a);


int array[]={1,2,3,4,5};
for(const auto & x: array){
    std::cout<<x<<std::endl;
}


return 0;
}