#include "BST.h"

BinarySearchTree::BinarySearchTree() {
    createTree();
}

void BinarySearchTree::createTree() {
    root = NULL;
}

bool BinarySearchTree::isEmpty() {
    return root == NULL;
}

Node* BinarySearchTree::newNode(string nama, float berat, string tier) {
    Node* node = new Node();
    node->namaMember = nama;
    node->beratBadan = berat;
    node->tierMember = tier;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void BinarySearchTree::insert(Node* &node, string nama, float berat, string tier) {
    if (node == NULL) {
        node = newNode(nama, berat, tier);
    } else {
        if (berat < node->beratBadan) {
            insert(node->left, nama, berat, tier);
        } else {
            insert(node->right, nama, berat, tier);
        }
    }
}

void BinarySearchTree::insertNode(string nama, float berat, string tier) {
    insert(root, nama, berat, tier);
}

void BinarySearchTree::mostLeft() {
    if (isEmpty()) {
        return;
    }
    
    Node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    cout << "Node MostLeft : " << current->beratBadan << endl;
}

void BinarySearchTree::mostRight() {
    if (isEmpty()) {
        return;
    }

    Node* current = root;
    while (current->right != NULL) {
        current = current->right;
    }
    cout << "Node MostRight : " << current->beratBadan << endl;
}

void BinarySearchTree::inOrderTraversal(Node* node) {
    if (node != NULL) {
        inOrderTraversal(node->left);
        cout << node->beratBadan << " - ";
        inOrderTraversal(node->right);
    }
}

void BinarySearchTree::inOrder() {
    cout << "-- Traversal InOrder --" << endl;
    inOrderTraversal(root);
    cout << endl;
}

void BinarySearchTree::searchByBeratBadan(float targetBerat) {
    Node* current = root;
    Node* parent = NULL;
    bool found = false;

    while (current != NULL) {
        if (targetBerat == current->beratBadan) {
            found = true;
            break;
        }
        parent = current;
        if (targetBerat < current->beratBadan) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (found) {
        cout << "  Data ditemukan didalam BST!" << endl;
        cout << endl;
        
        cout << "  Data Node Yang Dicari" << endl;
        cout << "Nama Member  : " << current->namaMember << endl;
        cout << "Berat Badan  : " << current->beratBadan << endl;
        cout << "Tier Member  : " << current->tierMember << endl;
        cout << endl;

        cout << "  Data Parent" << endl;
        if (parent != NULL) {
            cout << "Nama Member  : " << parent->namaMember << endl;
            cout << "Berat Badan  : " << parent->beratBadan << endl;
            cout << "Tier Member  : " << parent->tierMember << endl;
            cout << endl;
        
            Node* sibling = NULL;
            if (parent->left == current) {
                sibling = parent->right; 
            } else {
                sibling = parent->left;
            }

            if (sibling != NULL) {
                cout << "  Data Sibling :" << endl;
                cout << "Nama Member  : " << sibling->namaMember << endl;
                cout << "Berat Badan  : " << sibling->beratBadan << endl;
                cout << endl;
            } else {
                cout << "Tidak Memiliki Sibling" << endl;
                cout << endl;
            }

        } else {
            cout << "Node adalah Root" << endl;
            cout << endl;
        }

        cout << "  Data Child Kiri" << endl;
        if (current->left != NULL) {
            cout << "Nama Member  : " << current->left->namaMember << endl;
            cout << "Berat Badan  : " << current->left->beratBadan << endl;
            cout << "Tier Member  : " << current->left->tierMember << endl;
        } 
        cout <<endl;

        cout << "  Data Child Kanan" << endl;
        if (current->right != NULL) {
            cout << "Nama Member  : " << current->right->namaMember << endl;
            cout << "Berat Badan  : " << current->right->beratBadan << endl;
            cout << "Tier Member  : " << current->right->tierMember << endl;
        } 
        cout <<endl;

    } else {
        cout << "Data tidak ditemukan." << endl;
    }
}