#include "bstree.h"

address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = Nil;
    p->right = Nil;
    return p;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else {
        if (x < root->info) {
            insertNode(root->left, x);
        } else if (x > root->info) {
            insertNode(root->right, x);
        }
    }
}

void printPreOrder(address root) {
    if (root != Nil) {
        cout << root->info << " ";     
        printPreOrder(root->left);      
        printPreOrder(root->right);    
    }
}

void printPostOrder(address root) {
    if (root != Nil) {
        printPostOrder(root->left);     
        printPostOrder(root->right);    
        cout << root->info << " ";     
    }
}