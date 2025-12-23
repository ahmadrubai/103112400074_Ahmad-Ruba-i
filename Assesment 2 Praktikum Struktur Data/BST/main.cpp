#include <iostream>
#include "BST.h"

using namespace std;

int main() {
    BinarySearchTree tree;
    
    tree.createTree();

    tree.insertNode("Rizkina Azizah", 60, "Basic");
    tree.insertNode("Hakan Ismail", 50, "Bronze");
    tree.insertNode("Olivia Saevali", 65, "Silver");
    tree.insertNode("Felix Pedrosa", 47, "Gold");
    tree.insertNode("Gamel Al Ghifari", 56, "Platinum");
    tree.insertNode("Hanif Al Faiz", 70, "Basic");
    tree.insertNode("Mutiara Fauziah", 52, "Bronze");
    tree.insertNode("Davi Ilyas", 68, "Silver");
    tree.insertNode("Abdad Mubarok", 81, "Gold");

    cout << "Binary Search Tree berhasil dibuat.\n" << endl;

    tree.inOrder();
    
    tree.mostLeft();
    tree.mostRight();
    cout << endl;

    tree.searchByBeratBadan(70);

    return 0;
}