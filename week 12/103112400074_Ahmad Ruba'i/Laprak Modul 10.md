# <h1 align="center">Laporan Praktikum Modul 12 - tree(Bagian Pertama)</h1>
<p align="center">Ahmad Ruba'i - 103112400074</p>

## Dasar Teori
Tree merupakan bentuk struktur data yang membentuk hierarki melalui hubungan antar simpul (node) yang terhubung oleh jalur (edge). Dimulai dari simpul utama yang disebut root, setiap node bisa memiliki satu atau lebih node turunan (child), sedangkan node yang tidak memiliki turunan disebut sebagai daun (leaf).

Karena sifatnya yang tidak memiliki urutan linear tetap, tree memungkinkan representasi data yang lebih fleksibel dan cocok untuk berbagai aplikasi kompleks, seperti struktur direktori sistem file, parser compiler, dan pohon keputusan dalam AI.

### Istilah Dalam Tree
1. Root: Node utama paling atas dalam tree.
2. Parent & Child: Node yang memiliki koneksi ke node lain disebut induk (parent), sedangkan node   yang berada di bawahnya dinamakan anak (child).
3. Leaf: Node yang tidak memiliki anak.
4. Edge: Garis penghubung antara dua node.
5. Path: Jalur dari satu node ke node lainnya melalui edge.
6. Height: Panjang maksimum dari root ke leaf terdalam.
7. Depth: Jarak dari root ke suatu node.
8. Subtree: Pohon kecil yang merupakan bagian dari tree utama.

### Jenis Jenis Tree Dalam Struktur Data
1. Binary Tree
Pada pohon biner, sebuah node dibatasi maksimal memiliki dua turunan, masing-masing berada di sisi kiri dan kanan. Ini adalah dasar dari banyak jenis tree lainnya.

2. Binary Search Tree (BST)
Merupakan binary tree di mana:

Node kiri selalu < nilai root
Node kanan selalu > nilai root
BST efisien untuk operasi pencarian dan penyisipan.
3. AVL Tree
Jenis BST yang menjaga keseimbangan tinggi sub-tree kiri dan kanan secara otomatis untuk mencegah degenerasi.

4. B-Tree dan B+ Tree
Digunakan dalam sistem basis data dan file system. Memungkinkan banyak anak dalam satu node dan cocok untuk data besar dalam disk.

5. Heap Tree
Struktur ini sering dimanfaatkan dalam antrian prioritas, dengan nilai tertinggi atau terendah ditempatkan di posisi puncak (root) untuk diakses terlebih dahulu.

6. Trie (Prefix Tree)
Digunakan untuk pencarian string, cocok untuk kamus, autocomplete, dan sistem pencocokan kata.

- Teknik Traversal Tree (Penyeberangan)
Traversal adalah proses mengunjungi setiap node dalam tree. Metode utamanya meliputi:

Traversal pada Binary Tree:
- Preorder: root → left → right
- Inorder: left → root → right (digunakan dalam evaluasi ekspresi)
- Postorder: left → right → root
Traversal Level Order:
- Mengunjungi node berdasarkan level, biasanya menggunakan queue.


## Guided 

### 1. BST1

```C++ BST1.h
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
#endif
```
```C++ BST1.cpp
#include "BST1.h"
#include <iostream>

using namespace std;

//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}
```
```C++ main.cpp
#include <iostream>
#include "BST1.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "Binary Search Tree Insert & Traversal" << endl;
    cout << endl;

    root = insertNode(root, 20); // Root awal
    insertNode(root, 10);
    insertNode(root, 35);
    insertNode(root, 5);
    insertNode(root, 18);
    insertNode(root, 40);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << "Hasil PreOrder Traversal : ";
    preOrder(root);
    cout << endl;

    cout << "Hasil PostOrder Traversal : ";
    postOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;


    return 0;
}
```
Program ini berfungsi untuk menyusun angka-angka ke dalam bentuk pohon biner (Binary Search Tree). Program ini berfokus pada cara memasukkan data dan membacanya kembali dalam tiga urutan berbeda (PreOrder, InOrder, dan PostOrder). Selain itu, program ini dapat memberi tahu pengguna berapa banyak angka yang telah dimasukkan dan seberapa dalam tingkatan tree yang terbentuk.

### 2. BST2

```C++ BST2.h
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
```
```C++ BST2.cpp
#include "BST2.h"
#include <iostream>

using namespace std;

//FUNCTION & PROSEDUR SEBELUMNYA
//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}


//FUNCTION & PROSEDUR BARU
//searching
void searchByData(address root, infotype x) { //function untuk melakukan searching data tertentu
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        address nodeBantu = root;
        address parent = NULL;
        bool ketemu = false;
        while(nodeBantu != NULL){
            if(x < nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(x > nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(x == nodeBantu->info){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam BST!" << endl;
            cout << "Data Angka : " << nodeBantu->info << endl;

            //menampilkan parentnya & pengecekan sibling
            address sibling = NULL;
            if(parent != NULL){
                cout << "Parent : " << parent->info << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != NULL){
                cout << "Sibling : " << sibling->info << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != NULL){
                cout << "Child kiri : " << nodeBantu->left->info << endl;
            } else if(nodeBantu->left == NULL){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != NULL){
                cout << "Child kanan : " << nodeBantu->right->info << endl;
            } else if(nodeBantu->right == NULL){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}


//mostleft & mostright
address mostLeft(address root) { //function untuk menampilkan mostleft atau node paling kiri (node dengan nilai terkecil) didalam BST
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}

address mostRight(address root) { //function untuk menampilkan mostright atau node paling kanan (node dengan nilai terbesar) didalam BST
    while (root->right != NULL){
        root = root->right;
    }
    return root;
}


//delete
bool deleteNode(address &root, infotype x) { //function untuk menghapus node tertentu didalam BST (menghapus berdasarkan parameter infotype)
    if (root == NULL) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (x < root->info) {
            return deleteNode(root->left, x);
        } else if (x > root->info) {
            return deleteNode(root->right, x);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (root->left == NULL && root->right == NULL) {
                address temp = root;
                root = NULL;
                delete temp;
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (root->left == NULL) {
                address temp = root;
                root = root->right;
                delete temp;
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (root->right == NULL) {
                address temp = root;
                root = root->left;
                delete temp;
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                address successor = mostLeft(root->right);
                //salin data successor ke node saat ini
                root->info = successor->info;
                //hapus successor pada subtree kanan
                return deleteNode(root->right, successor->info);
            }
            return true; //berhasil dihapus
        }
    }
}

void deleteTree(address &root) { //prosedur untuk menghapus BST (menghapus seluruh node BST)
    if(root == NULL){
        return;
    } else {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = NULL;
    }
}
```
```C++ main.cpp
#include <iostream>
#include "BST2.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "=== Binary Search Tree ==" << endl;
    cout << endl;

    root = insertNode(root, 30); // Root awal
    insertNode(root, 15);
    insertNode(root, 35);
    insertNode(root, 11);
    insertNode(root, 17);
    insertNode(root, 20);
    insertNode(root, 38);
    insertNode(root, 16);
    insertNode(root, 22);
    insertNode(root, 33);
    insertNode(root, 18);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;

    cout << endl;
    searchByData(root, 17);
    
    cout << endl;
    cout << "Node mostleft : " << mostLeft(root)->info << endl;
    cout << "Node mostright : " << mostRight(root)->info << endl;

    cout << endl;
    infotype angkaHapus;
    cout << "Masukkan angka yang ingin dihapus: ";
    cin >> angkaHapus;
    //misal angka yang dihapus adalah angka 17
    if(deleteNode(root, angkaHapus)){
        cout << "Data " << angkaHapus << " berhasil dihapus!" << endl;
    } else {
        cout << "Data " << angkaHapus << " tidak ditemukan!" << endl;
    }
    cout << endl;

    searchByData(root, 17);
    cout << endl;
    searchByData(root, 18);

    cout << endl;
    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    deleteTree(root);
    cout << "Seluruh tree berhasil dihapus!" << endl;

    cout << endl;
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        cout << "Hasil InOrder Traversal : ";
        inOrder(root);
    }

    return 0;
}
```
Program ini merupakan implementasi struktur data Binary Search Tree (BST) menggunakan bahasa C++. di program ini ada operasi lengkap manajemen tree, mulai dari pembentukan tree kosong, penyisipan data (insertNode) yang menjaga aturan urutan BST (nilai lebih kecil ke kiri, lebih besar ke kanan), hingga berbagai metode penelusuran (traversal) seperti PreOrder, InOrder, dan PostOrder. Selain itu, program dilengkapi fitur utilitas untuk menghitung jumlah node, mengukur kedalaman tree, serta pencarian data (searchByData) yang mendetail karena menampilkan informasi parent, sibling, dan child dari node yang dicari. Fitur penghapusan (deleteNode) digunakan untuk menangani tiga skenario (menghapus leaf, node dengan satu anak, dan node dengan dua anak menggunakan teknik successor), serta kemampuan untuk membersihkan seluruh tree dari memori (deleteTree).


## Unguided 

### 1. bstree

```C++ bstree.h
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>

#define Nil NULL

using namespace std;

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void printInorder(address root);

#endif
```
```C++ bstree.cpp
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
    } 
    else {
        if (x < root->info) {
            insertNode(root->left, x);
        } 
        else if (x > root->info) {
            insertNode(root->right, x);
        }
    }
}

address findNode(infotype x, address root) {
    if (root == Nil) {
        return Nil;
    }
    if (root->info == x) {
        return root;
    } 
    else if (x < root->info) {
        return findNode(x, root->left);
    } 
    else {
        return findNode(x, root->right);
    }
}

void printInorder(address root) {
    if (root != Nil) {
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}
```
```C++ main.cpp
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "Hello World" << endl;
    address root = Nil;
    
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);
    
    printInorder(root);
    
    cout << endl;
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Program ini merupakan implementasi dasar dari struktur data Binary Search Tree (BST) menggunakan bahasa C++. Program berfokus pada pembentukan struktur pohon melalui fungsi penyisipan (insertNode) yang menyusun data secara otomatis berdasarkan nilainya (lebih kecil ke kiri, lebih besar ke kanan), serta menyediakan fungsi pencarian (findNode). Hasil akhir data ditampilkan secara terurut dari terkecil ke terbesar menggunakan metode penelusuran InOrder.

### 2. bstree

```C++ bstree.h
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>

using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void printInorder(address root);

int hitungJumlahNode(address root);
int hitungTotalInfo(address root, int start);
int hitungKedalaman(address root, int start);

#endif
```
```C++ bstree.cpp
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

address findNode(infotype x, address root) {
    if (root == Nil) {
        return Nil;
    }
    if (root->info == x) {
        return root;
    } else if (x < root->info) {
        return findNode(x, root->left);
    } else {
        return findNode(x, root->right);
    }
}

void printInorder(address root) {
    if (root != Nil) {
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}

int hitungJumlahNode(address root) {
    if (root == Nil) {
        return 0;
    }
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root, int start) {
    if (root == Nil) {
        return start;
    }
    return hitungTotalInfo(root->right, hitungTotalInfo(root->left, start + root->info));
}

int hitungKedalaman(address root, int start) {
    if (root == Nil) {
        return start;
    }
    int leftDepth = hitungKedalaman(root->left, start + 1);
    int rightDepth = hitungKedalaman(root->right, start + 1);
    
    if (leftDepth > rightDepth) {
        return leftDepth;
    } else {
        return rightDepth;
    }
}
```
```C++ main.cpp
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    
    address root = Nil;
    
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);
    
    printInorder(root);
    
    cout << endl;
    
    cout << "kedalaman : " << hitungKedalaman(root, 0) << endl;
    cout << "jumlah node : " << hitungJumlahNode(root) << endl;
    cout << "total : " << hitungTotalInfo(root, 0) << endl;
    
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Program ini adalah implementasi struktur data Binary Search Tree (BST) dalam bahasa C++ yang dirancang untuk mengelola data bilangan bulat. Program tidak hanya menyusun dan menampilkan angka secara terurut (InOrder), tetapi juga dilengkapi dengan fitur komputasi rekursif untuk menganalisis tree. Fitur analisis tersebut meliputi penghitungan kedalaman atau level maksimum pohon (hitungKedalaman), perhitungan jumlah total node yang tersimpan (hitungJumlahNode), serta penjumlahan total dari seluruh nilai angka yang ada di dalam tree (hitungTotalInfo).

### 3. bstree

```C++ bstree.h
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>

#define Nil NULL

using namespace std;

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
void printPreOrder(address root);   
void printPostOrder(address root);
#endif
```
```C++ bstree.cpp
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
```
```C++ main.cpp
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    address root = Nil;

    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 7);
    insertNode(root, 2);
    insertNode(root, 5);
    insertNode(root, 1);
    insertNode(root, 3);

    cout << "Pre-Order Traversal  : ";
    printPreOrder(root);
    cout << endl;

    cout << "Post-Order Traversal : ";
    printPostOrder(root);
    cout << endl;

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)


Program ini diguanakan untuk menyusun sekumpulan angka ke dalam struktur Binary Search Tree (BST) dan menampilkannya kembali menggunakan dua metode penelusuran yang berbeda. Setelah data dimasukkan ke dalam tree, program menggunakan fungsi Pre-Order untuk mencetak data mulai dari node induk (root) ke anak-anaknya, dan fungsi Post-Order untuk mencetak data mulai dari anak-anaknya terlebih dahulu sebelum ke node induk.

## Kesimpulan
Struktur data tree merupakan bagian fundamental dalam pemrograman dan ilmu komputer. Kemampuannya merepresentasikan data hierarkis, mendukung operasi pencarian efisien, dan adaptif terhadap berbagai aplikasi menjadikannya tak tergantikan dalam desain sistem modern.

## Referensi
[1]https://bse.telkomuniversity.ac.id/tree-data-structure/ 
<br>
