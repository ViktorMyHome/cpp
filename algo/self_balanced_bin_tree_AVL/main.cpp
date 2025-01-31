#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;

// AVL tree - self balanced Binary Search Tree. Where the difference
// between heights of left and right subtrees for any node can not
// be more than one.
// Balance Factor - difference between the heights of the left subtree
// and the right subtrees. Named as AVL due to its inventors Adelson-Velsky
// and Landis
// Self-balansing BST trees follow change and fix approach to keep it BBST
// Tree rotation changes the structure without affecting the order of the elements
// use the height change for rebalancing

class AVLTree{
private:
    struct BinaryNode{
        int data{};
        int height{};
        BinaryNode* left{};
        BinaryNode* right{};

        BinaryNode(int Data):data(data){}

        int ch_height(BinaryNode* node){
            if(!node)
                return -1;       //-1 for null
            return node->height; //0 for leaf
        }

        int update_height(){
            return height = 1 + max(ch_height(left), ch_height(right));
        }

        int balance_factor(){
            return ch_height(left) - ch_height(right);
        }
    };
public:
    AVLTree* right_rotation(AVLTree* Q){
        AVLTree* P = Q->left;
        Q->left = P->right;
        P->right = Q;
        Q->update_height();
        P->update_height();
        return P;
    }

};




int main(){




    return 0;
}
