# <h1 align="center">Laporan Praktikum Modul 5 - Linked list (Bagian kedua)</h1>
<p align="center">Ahmad Ruba'i - 103112400074</p>

## Dasar Teori
Linked list adalah salah satu struktur data dasar dalam pemrograman yang terdiri dari serangkaian elemen data yang terhubung satu sama lain menggunakan referensi atau pointer. Setiap elemen dalam linked list, yang disebut node, Setiap node dalam linked list terdiri dari dua komponen utama: data dan pointer. Komponen data menyimpan nilai atau informasi yang ingin kita simpan dalam linked list. Node pertama dalam linked list disebut head, dan node terakhir disebut tail. Head menyimpan referensi ke node pertama, sedangkan tail menyimpan referensi ke node terakhir. Dengan menggunakan head, kita dapat mengakses elemen pertama dalam linked list dan melakukan operasi seperti penambahan, penghapusan, atau pencarian data.

Salah satu keunggulan utama linked list adalah kemampuannya untuk mengatasi perubahan ukuran secara dinamis. Ketika kita ingin menambahkan atau menghapus elemen dari linked list, kita dapat melakukannya dengan mudah tanpa mempengaruhi elemen-elemen lain dalam struktur data tersebut.

1. Singly linked list struktur data di mana setiap elemen (node) memiliki dua bagian: data yang disimpan dan referensi ke node berikutnya dalam urutan. Node terakhir memiliki nilai NULL sebagai referensi akhir. Operasi seperti penambahan dan penghapusan bisa cepat di awal (head), tetapi lambat di akhir (tail).

Linear search
Algoritma ini bekerja dengan melakukan iterasi secara berurutan melalui seluruh array atau daftar dari satu ujung hingga elemen target ditemukan. Jika elemen ditemukan, ia akan mengembalikan indeksnya, jika tidak, -1.

Binary search
Algoritma pencarian jenis ini digunakan untuk menemukan posisi nilai tertentu yang terdapat dalam array yang telah diurutkan . Algoritma pencarian biner bekerja berdasarkan prinsip bagi dan taklukkan dan dianggap sebagai algoritma pencarian terbaik karena lebih cepat dijalankan.

## Guided 

### 1. bauh

```C++ listBuah.h
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil nullptr

#include <iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah;
    float harga;
};
typedef buah dataBuah;
typedef struct node *address;
struct node{
    dataBuah isidata;
    address next;
};

struct linkedList{
    address first;
};

bool listEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedList List);
void insertFirst(linkedList &List, address nodebaru);
void insertAfter(linkedList &List, address nodebaru, address Prev);
void insertLast(linkedList &List, address nodebaru);
void deleteFirst(linkedList &List);
void delLast(linkedList &List);
void deleteAfter(address &List, address &nodehapus, address nodeprev);
int nbList(linkedList List);
void deletelist(linkedList &List);

//materi modul 5 (part 1 update)
void updateFirst(linkedList List);
void updateLast(linkedList List);
void updateAfter(linkedList List, address prev);

#endif
```
```C++ listBuah.cpp

#include "listbuah.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedList List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedList &List) {
    List.first = Nil;
}

address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedList &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedList &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedList &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printList(linkedList List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedList List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

void deleteList(linkedList &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

//Materi Modul 5 - Update Operations
void updateFirst(linkedList List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedList List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedList List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```
```C++ main.cpp
#include "listbuah.h"
#include <iostream>
using namespace std;

int main(){
    linkedList List;
    address nodeA, nodeB, nodeC,nodeD,nodeE;   
    createList(List);

    nodeA=alokasi("jeruk",100,3000);
    nodeB=alokasi("apel",75,4000);
    nodeC=alokasi("pir",87,5000);
    nodeD=alokasi("semangka",43,11500); 
    nodeE=alokasi("durian",15,31450);

    insertFirst(List,nodeA);
    insertLast(List,nodeB);
    insertAfter(List,nodeC,nodeA);
    insertAfter(List,nodeD,nodeC);
    insertLast(List,nodeE);

    cout<<" isi list buat dilakukan insert"<<endl;
    printList(List);
    cout<<"jumlah node:"<<nbList(List)<<endl;
    cout<<endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List,nodeD);

    cout<<" isi list buah setelah dilakukan update"<<endl;
    printList(List);
    cout<<"jumlah node:"<<nbList(List)<<endl;
    cout<<endl;

    return 0;
}   
```
Program C++ ini adalah contoh linked list yang dipakai untuk mencatat data buah (nama, jumlah, harga). Kode utamanya membuat sebuah list, memasukkan lima data buah, kemudian mengubah data di posisi pertama, terakhir, dan satu data di tengah list, lalu menampilkannya.

### 2. search

```C++ binary.cpp
#include <iostream>
using namespace std;

//Definisi node untuk linked list
struct Node { 
    int data;      // Menyimpan nilai data
    Node* next;    // Pointer ke node selanjutnya
};

// Fungsi untuk menghitung panjang linked list
int getLength(Node* head) {
    int count = 0;
    Node* temp = head;
    while(temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Fungsi binary search untuk linked list (data harus terurut)
// Parameter: head (pointer awal list), key (nilai yang dicari)
// Return: pointer ke node jika ditemukan, nullptr jika tidak
Node* binarySearch(Node* head, int key) {
    int length = getLength(head);      // Hitung panjang list
    int left = 0;
    int right = length - 1;
    
    while(left <= right) {
        int mid = left + (right - left) / 2;  // Cari posisi tengah
        
        // Traverse ke posisi mid
        Node* temp = head;
        for(int i = 0; i < mid; i++) {
            temp = temp->next;
        }
        
        if(temp->data == key) {           // Jika ditemukan
            return temp;
        }
        else if(temp->data < key) {       // Cari di bagian kanan
            left = mid + 1;
        }
        else {                            // Cari di bagian kiri
            right = mid - 1;
        }
    }
    return nullptr;                       // Tidak ditemukan
}

// Fungsi untuk menambahkan node baru di akhir list
void append(Node* &head, int value){
    Node *newNode = new Node{value, nullptr};
    if(!head) head = newNode;
    else{
        Node *temp = head;
        while(temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr;  // Inisialisasi linked list kosong

    // Menambahkan elemen terurut ke linked list (penting untuk binary search!)
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    
    int key = 30;  // Nilai yang dicari
    Node* result = binarySearch(head, key); // Panggil fungsi binary search

    if(result != nullptr) {
        cout << "Nilai " << key << " ditemukan dalam linked list." << endl;
    } else {
        cout << "Nilai " << key << " tidak ditemukan dalam linked list." << endl;
    }

    return 0;
}
```
```C++ linear.cpp
#include <iostream>
using namespace std;

struct Node { 
    int data;
    Node* next;
};

Node *linearSearch(Node* head, int key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void append(Node* &head, int value){
    Node *newNode = new Node{value, nullptr};
    if(!head) head = newNode;
    else{
        Node *temp = head;
        while(temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr;

    append(head, 10);
    append(head, 20);
    append(head, 30);
    
    Node* result = linearSearch(head, 20);

    cout << (result ? "Found" : "Not Found") << endl;

    return 0;
}
```
Kedua program C++ ini mengilustrasikan perbedaan antara pencarian linier dan biner pada singly linked list. Program linear.cpp mengimplementasikan linear search, yang merupakan metode paling efisien dan praktis untuk list. Ia bekerja dengan mengunjungi setiap node satu per satu dari head dan tidak mengharuskan data terurut. Sebaliknya, program binary.cpp mencoba mengadaptasi binary search. Meskipun algoritma ini secara logis membagi rentang pencarian, implementasinya menjadi tidak efisien karena linked list tidak memiliki akses acak. Akibatnya, untuk menemukan node tengah di setiap iterasi, program terpaksa melakukan perulangan dari head, yang membuat total kinerjanya lebih lambat daripada linear search sederhana.

## Unguided 

### 1. linear

```C++
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

    Node* getMiddle(Node* start, Node* end) {
        if (start == nullptr) {
            return nullptr;
        }

        Node* slow = start;
        Node* fast = start; 

        while (fast != end) {
            fast = fast->next;
            if (fast != end) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        return slow;
    }

public:
    LinkedList() : head(nullptr) {}

    void append(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }

        last->next = newNode;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    Node* binarySearch(int value) {
        Node* start = head;
        Node* end = nullptr;
        int iterasi = 1;

        cout << "\nProses Pencarian:" << endl;

        while (start != end && start->next != end) {
            Node* mid = getMiddle(start, end);

            if (mid == nullptr) {
                break;
            }
            
            cout << "Iterasi " << iterasi++ << ": Mid = " << mid->data << " (indeks tengah)";

            if (mid->data == value) {
                cout << " - DITEMUKAN!" << endl;
                return mid;
            } else if (mid->data < value) {
                cout << " -> Cari di bagian kanan" << endl;
                start = mid->next;
            } else {
                cout << " -> Cari di bagian kiri" << endl;
                end = mid;
            }
        }

        if (start != nullptr && start != end && start->data == value) {
             cout << "Iterasi " << iterasi++ << ": Mid = " << start->data << " (indeks tengah)";
             cout << " - DITEMUKAN!" << endl;
             return start;
        }

        cout << "Tidak ada elemen tersisa" << endl;
        return nullptr;
    }

    void printSearchResult(int value, Node* result) {
        if (result != nullptr) {
            cout << "\nHasil: Nilai " << value << " DITEMUKAN pada linked list!" << endl;
            cout << "Alamat node: " << result << endl;
            cout << "Data node: " << result->data << endl;
            
            if (result->next != nullptr) {
                cout << "Node berikutnya: " << result->next->data << endl;
            } else {
                cout << "Node berikutnya: NULL" << endl;
            }
        } else {
            cout << "\nHasil: Nilai " << value << " TIDAK DITEMUKAN dalam linked list!" << endl;
        }
    }
};

int main() {
    cout << "BINARY SEARCH PADA LINKED LIST" << endl;

    LinkedList list;
    
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(50);
    list.append(60);

    cout << "Linked List yang dibuat: ";
    list.display();

    int cari1 = 40;
    cout << "Mencari nilai: " << cari1 << endl;
    Node* hasil1 = list.binarySearch(cari1);
    list.printSearchResult(cari1, hasil1);

    int cari2 = 25;
    cout << "Mencari nilai: " << cari2 << endl;
    Node* hasil2 = list.binarySearch(cari2);
    list.printSearchResult(cari2, hasil2);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1](https://github.com/ahmadrubai/103112400074_Ahmad-Ruba-i/blob/main/week%205/Output%20Unguided%201.png
)

Program ini menunjukkan bagaimana Pencarian Biner dilakukan pada Linked List yang sudah berurutan. Ini adalah cara yang jauh lebih cepat daripada Pencarian Linier. Program menggunakan getMiddle untuk melompat langsung ke tengah list. Dengan membandingkan nilai, program langsung membuang separuh list yang tidak mungkin berisi angka yang dicari. Proses pemotongan separuh list ini diulang terus-menerus hingga angka ditemukan.

### 2. binary

```C++ #include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void append(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = newNode;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    Node* linearSearch(int value) {
        Node* current = head;
        int nodeNum = 1;

        cout << "\nProses Pencarian:" << endl;

        while (current != nullptr) {
            cout << "Memeriksa node " << nodeNum << ": " << current->data;

            if (current->data == value) {
                cout << " (SAMA) - DITEMUKAN!" << endl;
                return current;
            }
            
            cout << " (tidak sama)" << endl;
            
            current = current->next;
            nodeNum++;
        }

        cout << "Tidak ada node lagi yang tersisa" << endl;
        return nullptr;
    }

    void printSearchResult(int value, Node* result) {
        if (result != nullptr) {
            cout << "\nHasil: Nilai " << value << " DITEMUKAN pada linked list!" << endl;
            cout << "Alamat node: " << result << endl;
            cout << "Data node: " << result->data << endl;
            
            if (result->next != nullptr) {
                cout << "Node berikutnya: " << result->next->data << endl;
            } else {
                cout << "Node berikutnya: NULL" << endl;
            }
        } else {
            cout << "\nHasil: Nilai " << value << " TIDAK DITEMUKAN dalam linked list!" << endl;
        }
    }
};

int main() {
    cout << "LINEAR SEARCH PADA LINKED LIST" << endl;

    LinkedList list;
    
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(50);

    cout << "Linked List yang dibuat: ";
    list.display();

    int cari1 = 30;
    cout << "Mencari nilai: " << cari1 << endl;
    Node* hasil1 = list.linearSearch(cari1);
    list.printSearchResult(cari1, hasil1);

    int cari2 = 25;
    cout << "Mencari nilai: " << cari2 << endl;
    Node* hasil2 = list.linearSearch(cari2);
    list.printSearchResult(cari2, hasil2);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2](https://github.com/ahmadrubai/103112400074_Ahmad-Ruba-i/blob/main/week%205/Output%20Unguided%202.png
)

Ini adalah program yang menunjukkan Linear Search pada Linked List. List dibuat, dan kemudian nilai dicari dengan mengecek semua elemen secara berurutan dari node pertama hingga node terakhir. Program ini berfungsi untuk memvisualisasikan proses pencarian satu per satu di dalam struktur data yang terhubung.

## Kesimpulan
dari modul ini saya bisa tahu cara kerja linear dan binary.

## Referensi
[1] https://terapan-ti.vokasi.unesa.ac.id/post/memahami-konsep-dan-jenis-jenis-linked-list-dalam-struktur-data#:~:text=Node%20pertama%20dalam%20linked%20list,dan%20node%20terakhir%20disebut%20tail.
<br>[2] https://www.freecodecamp.org/news/search-algorithms-linear-and-binary-search-explained/
<br>...
