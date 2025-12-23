#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>

using namespace std;

struct Node {
    string namaMember;
    float beratBadan;
    string tierMember;
    Node *left;
    Node *right;
};

struct BinarySearchTree {
    Node* root;
    void insert(Node* &node, string nama, float berat, string tier);
    void inOrderTraversal(Node* node);
    BinarySearchTree();
    bool isEmpty();
    void createTree();
    Node* newNode(string nama, float berat, string tier);
    void insertNode(string nama, float berat, string tier);
    void searchByBeratBadan(float targetBerat);
    void mostLeft();
    void mostRight();
    void inOrder();
};

#endif