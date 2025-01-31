#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;
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

    void print_postoder(Node* current){
        if(!current)
            return;
        print_postoder(current->left);
        print_postoder(current->right);
        std::cout<<current->value<<" ";
    }

    // void delete_postoder(Node* current){
    //     if(!current)
    //         return;
    //     delete_postoder(current->left);
    //     delete_postoder(current->right);
    //     delete current;
    // }

};



class BinaryTree{
public:
    struct Node{
        int data{};
        Node* left{};
        Node* right{};
        Node(int data):data(data){

        }
    };
    Node* root{};
public:
    BinaryTree(int root_value): root(new Node(root_value)){
    }
private:
    void print_inorder(Node* current){
        if(!current)
            return;
        print_inorder(current->left);
        std::cout<<current->data<<" ";
        print_inorder(current->right);
    }
public:
    void print_inorder(){
        print_inorder(root);
        std::cout<<std::endl;
    }
    void add(int target, Node* node) {
        if(target < node->data) {
            if(!node->left)
                node->left = new Node(target);
            else
                add(target, node->left);
        } else if(target > node->data) {
            if(!node->right)
                node->right = new Node(target);
            else
                add(target,node->right);
        }
    }

    int tree_max(Node* node){
        static int max = node->data;

        if(node->right){
            if(max < tree_max(node->right))
                max = node->right->data;
        } 
        if(node->left){
            if(max < tree_max(node->left))
                max = node->left->data;
        }
        if(node->data > max)
            max = node->data;
        return max;
    }

    int total_nodes(Node* node, bool reset){
        static int count=0;
        if(reset)
            count = 0;
        if(!node)
            return count;
        if(node->left){
            total_nodes(node->left, false);
        }
        if(node->right){
            total_nodes(node->right, false);
        }
        count++;
        //cout<<" value = "<<node->data<<" "<<" count = "<<count;
        return count;
    }

    bool is_exist(Node* node, int val){
        if(node->left){
            if(is_exist(node->left, val))
                return true;
        }
        if(node->right){
            if(is_exist(node->right, val))
                return true;
        }
        if(node->data == val){
            return true;
        }
        return false;
    }

    Node* search_BST(int val, Node* node){
        if(val == node->data)
            return node;

        if(node->data > val){
            if(node->left)
                return search_BST(val, node->left);
            else 
                return nullptr;
        } else {
            if(node->right)
                return search_BST(val, node->right);
            else
                return nullptr;
        }
    }

    Node* search_previous_BST(int val, Node* node){
        if(node->left)
            if(val == node->left->data)
                return node;

        if(node->right)
            if(val == node->right->data)
                return node;

        if(node->data > val){
            if(node->left)
                return search_previous_BST(val, node->left);
            else 
                return nullptr;
        } else {
            if(node->right)
                return search_previous_BST(val, node->right);
            else
                return nullptr;
        }
    }

    void add(vector<int> values, vector<char> direction){
        assert(values.size() == direction.size());
        Node* current = this->root;
        for(int i=0;i<values.size();++i){
            if(direction[i] == 'L'){
                if(!current->left)
                    current->left = new Node(values[i]);
                // else
                //     assert(current->left->data == values[i]);
                current = current->left;
            } else {
                if(!current->right)
                    current->right = new Node(values[i]);
                // else
                //     assert(current->right->data == values[i]);
                current = current->right;
            }
        }
    }

    void clear(Node* node){

        if(!node)
            return;
        if(node->left){
            std::cout<<" delete node->left "<<node->left->data<<std::endl;
            clear(node->left);
        } 
        if(node->right){
            std::cout<<" delete node->right "<<node->right->data<<std::endl;
            clear(node->right);
        }
        std::cout<<" delete node->dat "<<node->data<<std::endl;

        node->left = nullptr;
        node->right = nullptr;
        delete node;
        //node = nullptr;
    }

    bool remove(int val, Node* node){
        Node* targetNode = search_BST(val, node);
        Node* leftNode;
        Node* prevNode;
        Node* rightNode;
        Node* right_leftNode;
        prevNode =  search_previous_BST(targetNode->data, node);
        if(targetNode->right && targetNode->left){
            leftNode = targetNode->left;
            rightNode = targetNode->right;
            if(rightNode->left){
                right_leftNode = rightNode->left;
                while(right_leftNode->left)
                    right_leftNode = right_leftNode->left;
            }

            prevNode->right = rightNode;
            if(rightNode->left){
                right_leftNode->left = leftNode;
            } else {
                rightNode->left = leftNode;
            }
            delete targetNode;
        } else if((targetNode->left && !targetNode->right) || 
                  (!targetNode->left && targetNode->right)){
            if(prevNode->data >= targetNode->data) {
                if(targetNode->left)
                    prevNode->left = targetNode->left;
                if(targetNode->right)
                    prevNode->left = targetNode->right;
            } else {
                if(targetNode->left)
                    prevNode->right = targetNode->left;
                if(targetNode->right)
                    prevNode->right = targetNode->right;
            }
            delete targetNode;
        }
        
        return true;
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

BT.print_postoder(&BT);


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
std::cout<<std::endl;


// int array[]={1,2,3,4,5};
// for(const auto & x: array){
//     std::cout<<x<<std::endl;
// }

BinaryTree bt3(30);
bt3.add(25, bt3.root);
bt3.add(35, bt3.root);
bt3.add(20, bt3.root);
bt3.add(40, bt3.root);
bt3.add(10, bt3.root);
bt3.add(100, bt3.root);
int max = bt3.tree_max(bt3.root);
std::cout<<" max value = "<<max<<std::endl;
int count = bt3.total_nodes(bt3.root, true);
std::cout<<" count = "<<count<<std::endl;
int is = bt3.is_exist(bt3.root, 40);
std::cout<<" is exist "<<is<<std::endl;

// BinaryTree bt4(1);
// bt4.add({2,4,7}, {'L', 'L', 'L'});
// bt4.add({2,4,8}, {'L', 'L', 'R'});
// bt4.add({2,5,9}, {'L', 'L', 'R'});
// bt4.add({3,6,10}, {'R', 'R', 'L'});
// bt4.print_inorder();

// bt4.clear(bt4.root);

// if(!bt4.root->left || !bt4.root->right)
//     std::cout<<"cleared"<<std::endl;
cout<<" search 40 "<<bt3.search_BST(39, bt3.root)<<endl;

//bt3.clear(bt3.root);
cout<<endl;

BinaryTree bt5(50);
bt5.add(51, bt5.root);
bt5.add(70, bt5.root);
bt5.add(73, bt5.root);
bt5.add(20, bt5.root);
bt5.add(45, bt5.root);
bt5.add(35, bt5.root);
bt5.add(36, bt5.root);
bt5.add(47, bt5.root);
bt5.add(46, bt5.root);
count = bt5.total_nodes(bt5.root, true);
std::cout<<" count bt5 = "<<count<<std::endl<<std::endl;
//if(bt5.search_BST(39, bt5.root))
cout<<" found "<<bt5.search_BST(20, bt5.root)->data<<endl;
cout<<" found previous "<<bt5.search_previous_BST(36, bt5.root)->data<<endl;

bt5.print_inorder();
bt5.remove(45, bt5.root);
bt5.print_inorder();
count = bt5.total_nodes(bt5.root, true);
std::cout<<" count bt5 = "<<count<<std::endl<<std::endl;

bt5.remove(35, bt5.root);
bt5.print_inorder();
count = bt5.total_nodes(bt5.root, true);
std::cout<<" count bt5 = "<<count<<std::endl<<std::endl;

return 0;
}