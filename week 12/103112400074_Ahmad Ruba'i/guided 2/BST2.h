#ifndef BST1_H
#define BST1_H

#include <iostream>

using namespace std;

typedef int infotype;// alias infotype untuk data integer
typedef struct Node*address;// alias address sebagai pointer

struct Node {
    infotype info; // info data yang disimpan (integer)
    address left; // pointer left 
    address right; // pointer right
};

//isEmpty & createTree
bool isEmpty(address root);
//BST kosong atau tidak
void createTree(address &root);//function untuk membuat BST nya (root di set sebagai NULL)

//alokasi & insert 
address newNode(infotype x);//function untuk memasukan data (infotype) kedalam node
address insertNode(address root, infotype x);//function untuk memasukan node kedalam BST

//Traversal
void preOrder(address root);//function traversal tree secara pre-Order(tengah - kiri - kanan atau root - child kiri - child kanan)
void inOrder(address root);//function traversal tree secara in-Order(kiri - tengah - kanan atau child kiri - root - child kanan)
void postOrder(address root);//function traversal tree secara post-Order(kiri - kanan - tengah atau child kiri - child kanan - root)

//Utilities
int countNodes(address root);//function untuk menghitung size atau ukuran atau jumlah node pada BST
int treeDepth(address root);//function untuk menghitung kedalaman tree pada BST

//searching
void searchByData(address root, infotype x);//function unutk melakukan searching data tertentu
address mostLeft(address rott);//function untuk menampilkan mostLeft atau node paling kiri(node dengan nilai terkecil) didalam BST
address mostRight(address root);//function untuk menampilkan mostRight atau node paling kanan(node dengan nilai terbesar) didalam BST

//delete
bool deleteNode(address &root, infotype x);//function untuk menghapus node tertentu pada BST(menghapus berdasarkan parameter infotype)
void deleteTree(address &root);//function untuk menghapus BST(menghapus seluruh node pada BST)
#endif