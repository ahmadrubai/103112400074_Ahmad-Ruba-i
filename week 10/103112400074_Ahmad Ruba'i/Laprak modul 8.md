# <h1 align="center">Laporan Praktikum Modul 8 - queue (Bagian Pertama)</h1>
<p align="center">Ahmad Ruba'i - 103112400074</p>

## Dasar Teori
Queue atau dalam bahasa Indonesia yang berarti antrean adalah struktur data yang menyusun elemen-elemen data dalam urutan linier. Prinsip dasar dari struktur data ini adalah First In, First Out (FIFO) yang berarti elemen data yang pertama dimasukkan ke dalam antrean akan menjadi yang pertama pula untuk dikeluarkan.

## Jenis-jenis Queue
Jenis struktur data ini dapat diklasifikasikan berdasarkan cara implementasinya, maupun berdasarkan penggunaannya. Di antara jenis-jenis tersebut adalah sebagai berikut.

### Berdasarkan Implementasinya <br/>
1. Linear/Simple Queue: Elemen-elemen data disusun dalam barisan linear dan penambahan serta penghapusan elemen hanya terjadi pada dua ujung barisan tersebut.
2. Circular Queue: Mirip dengan jenis linear, tetapi ujung-ujung barisan terhubung satu sama lain, menciptakan struktur antrean yang berputar.
### Berdasarkan Penggunaan <br/>
1. Priority Queue: Setiap elemen memiliki prioritas tertentu. Elemen dengan prioritas tertinggi akan diambil terlebih dahulu.
2. Double-ended Queue (Dequeue): Elemen dapat ditambahkan atau dihapus dari kedua ujung antrean.


## Guided 

### 1. queue

```C++ queue.h
#ifndef QUEUE_H
#define QUEUE_H
#define NIL NULL  

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct queue{
    address head;
    address tail;
};

bool isEmpty(queue Q);
void createQueue(queue &Q);
address alokasi(int angka);
void dealokasi(queue &node);

void enQueue(queue &Q, address nodeBaru);
void deQueue(queue &Q);
void updateQueue(queue &Q, int posisi);
void viewQueue(queue Q);
void searchData(queue Q, int data);

#endif
```
```c++ queue.cpp

#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == NIL){
        return true;
    } else {
        return false;
    }
}

void createQueue(queue &Q){
    Q.head =  Q.tail = NIL;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = NIL;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = NIL;
    delete node;
}

void enQueue(queue &Q, address nodeBaru){
    if(isEmpty(Q) == true){
        Q.head = Q.tail = nodeBaru;
    } else {
        Q.tail->next = nodeBaru;
        Q.tail = nodeBaru;
    }
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q){
    address nodeHapus;
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        nodeHapus = Q.head;
        Q.head = Q.head->next;
        nodeHapus->next = NIL;
        if(Q.head == NIL){
            Q.tail = NIL;
        }
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari queue!" << endl;
    }
}

void updateQueue(queue &Q, int posisi){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = Q.head;
            int count = 1;
            bool found = false;
            while(nodeBantu != NIL){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        while(nodeBantu != NIL){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(queue Q, int data){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != NIL){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam queue!" << endl;
            cout << endl;
        }
    }
}
```
```C++ main.cpp
#include "queue.h"
#include<iostream>

using namespace std;

int main(){
    queue Q;
    address nodeA, nodeB, nodeC, nodeD, nodeE = NIL;
    createQueue(Q);

    nodeA = alokasi (1);
    nodeB = alokasi (2);
    nodeC = alokasi (3);
    nodeD = alokasi (4);
    nodeE = alokasi (5);

    enQueue (Q, nodeA);
    enQueue (Q, nodeB);
    enQueue (Q, nodeC);
    enQueue (Q, nodeD);
    enQueue (Q, nodeE);
    cout << endl;

    cout << "--- Queue setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Queue setelah deQueue 2 kali ---" << endl;
    viewQueue(Q);
    cout << endl;

    updateQueue (Q, 2);
    updateQueue (Q, 1);
    updateQueue (Q, 4);
    cout << endl;

    cout << "--- Queue setelah update ---" << endl;
    viewQueue(Q);
    cout << endl;

    searchData(Q, 4);
    searchData(Q, 9);

    return 0;
}
```
Program ini adalah implementasi queue dalam bahasa C++ menggunakan singly linked list. Kode ini mendefinisikan struktur data antrean dengan operasi enQueue (menambah data ke belakang) dan deQueue (menghapus data dari depan). Selain itu, program ini juga menyertakan fungsi tambahan untuk melihat (viewQueue), memperbarui (updateQueue), dan mencari (searchData) data di dalam antrean.

### 2. queue

```C++ stack.h
#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5

struct Queue{
    int info[MAX_QUEUE];
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x);
int dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```
```C++ queue.cpp
#include "queue.h" 
#include <iostream>

using namespace std;

void createQueue(Queue &Q) {
    Q.head = 0; 
    Q.tail = 0; 
    Q.count = 0;
}

bool isEmpty(Queue Q) {
    return Q.count == 0; //Kembalikan true jika jumlah elemen adalah 0
}

bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE; // Kembalikan true jika jumlah elemen sama dengan maks
}

// Definisi prosedur untuk menambahkan elemen (enqueue)
void enqueue(Queue &Q, int x) {
    if (!isFull(Q)) { 
        Q.info[Q.tail] = x; // Masukkan data (x) ke posisi ekor (tail)
        // Pindahkan ekor secara circular (memutar)
        Q.tail = (Q.tail + 1) % MAX_QUEUE; 
        Q.count++; //Tambah jumlah elemen
    } else { 
        cout << "Antrean Penuh!" << endl;
    }
}

//Definisi fungsi untuk menghapus elemen (dequeue)
int dequeue(Queue &Q) {
    if (!isEmpty(Q)) { 
        int x = Q.info[Q.head]; // Ambil data di posisi  (head)
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--; // Kurangi jumlah elemen
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}

// Definisi prosedur untuk menampilkan isi queue 
void printInfo(Queue Q) {
    cout << "Isi Queue: [ ";
    if (!isEmpty(Q)) { 
        int i = Q.head; // Mulai dari head
        int n = 0; //Penghitung elemen yang sudah dicetak
        while (n < Q.count) { // Ulangi sebanyak jumlah elemen
            cout << Q.info[i] << " "; // Cetak info
            i = (i + 1) % MAX_QUEUE; // Geser i secara circular
            n++; // Tambah penghitung
        }
    }
    cout << "]" << endl;
}
```
```C++ main.cpp
#include<iostream>
#include "queue.h"

using namespace std;

//fungsi utama program
int main(){
    Queue Q;

    createQueue(Q);
    printInfo(Q);

    cout << "\n Enqueue 3 Elemen" << endl;
    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 7);
    printInfo(Q);

    cout << "\n Dequeue 1 Elemen" << endl;
    cout << "Elemen keluar:" << dequeue(Q) << endl;
    printInfo(Q);
    
    cout << "\n Enqueue 1 Elemen" << endl;
    enqueue(Q,4);
    printInfo(Q);

    cout << "\n Dequeue 2 Elemen" << endl;
    cout << "Elemen keluar:" << dequeue(Q) << endl;
    cout << "Elemen keluar:" << dequeue(Q) << endl;

    return 0;
}
```
Program ini adalah implementasi circular queue dalam bahasa C++ yang menggunakan array statis dengan ukuran tetap. Implementasi ini menggunakan array info[] serta tiga variabel: head, tail, dan count. Operasi enqueue dan dequeue secara efisien menggunakan operator modulus (%) untuk memindahkan head dan tail sehingga array dapat "berputar" dan mengisi ulang slot yang kosong.

## Unguided 

### 1. Unguided 1

```C++ queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAX_SIZE = 5;
typedef int infotype;

struct Queue {
    infotype info[MAX_SIZE];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```
```C++ queue.cpp
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAX_SIZE - 1);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue Full!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
            Q.info[0] = x;
        } else {
            Q.tail++;
            Q.info[Q.tail] = x;
        }
    }
}

infotype dequeue(Queue &Q) {
    infotype val = -1;
    
    if (isEmptyQueue(Q)) {
        cout << "Queue Underflow!" << endl;
    } else {
        val = Q.info[Q.head];
        
        if (Q.head == Q.tail) {
            Q.head = -1;
            Q.tail = -1;
        } else {
            for (int i = 0; i < Q.tail; i++) {
                Q.info[i] = Q.info[i + 1];
            }
            Q.tail--;
        }
    }
    return val;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " : ";
    
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
    }
    cout << endl;
}
```
```C++ main.cpp
#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    cout << "-------------------------" << endl;
    cout << "H - T : Queue Info" << endl;
    cout << "-------------------------" << endl;

    Queue Q;
    createQueue(Q);
    printInfo(Q);

    enqueue(Q, 5); printInfo(Q); 
    enqueue(Q, 2); printInfo(Q); 
    enqueue(Q, 7); printInfo(Q);
    
    dequeue(Q);    printInfo(Q); 
    dequeue(Q);    printInfo(Q); 
    
    enqueue(Q, 4); printInfo(Q);
    
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q); 

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 1_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Program ini membuat simulasi queue menggunakan bahasa C++. Cara kerjanya seperti antrean di kasir: jika orang paling depan keluar, semua orang di belakangnya harus maju satu langkah ke depan. Karena itu, posisi paling depan (Head) akan selalu tetap di indeks 0, sementara ujung belakang antrean (Tail) akan berubah-ubah.

### 2. Unguided 2

```C++ queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAX_SIZE = 5;
typedef int infotype;

struct Queue {
    infotype info[MAX_SIZE];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```
```C++ queue.cpp
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAX_SIZE - 1);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue Full!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
            Q.info[0] = x;
        } else {
            Q.tail++;
            Q.info[Q.tail] = x;
        }
    }
}

infotype dequeue(Queue &Q) {
    infotype val = -1;
    
    if (isEmptyQueue(Q)) {
        cout << "Queue Underflow!" << endl;
    } else {
        val = Q.info[Q.head];
        
        if (Q.head == Q.tail) {
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head++; 
        }
    }
    return val;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " : ";
    
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
    }
    cout << endl;
}
```
```C++ main.cpp
#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    cout << "Alternatif 2 (Head Bergerak)" << endl;
    cout << "-------------------------" << endl;
    cout << "H - T : Queue Info" << endl;
    cout << "-------------------------" << endl;

    Queue Q;
    createQueue(Q);
    printInfo(Q); 

    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    
    dequeue(Q);    printInfo(Q); 
    dequeue(Q);    printInfo(Q); 
    
    enqueue(Q, 4); printInfo(Q);
    
    dequeue(Q);    printInfo(Q); 
    dequeue(Q);    printInfo(Q); 

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Program ini mengimplementasikan queue menggunakan Array di mana indeks Head dan Tail sama-sama bergerak ke kanan (bertambah). Saat operasi dequeue dilakukan, data tidak digeser, melainkan indeks Head dimajukan satu langkah (head++). Ini membuat proses pengambilan data lebih cepat (efisien) karena tidak ada proses perulangan (looping) untuk menggeser elemen array, namun memiliki kelemahan yaitu ruang array di bagian depan (sebelum Head) tidak bisa digunakan kembali sampai antrean benar-benar kosong dan di-reset.

### 3. Unguided 3

```C++ queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAX_SIZE = 5;
typedef int infotype;

struct Queue {
    infotype info[MAX_SIZE];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```
```C++ queue.cpp
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1);
}

bool isFullQueue(Queue Q) {
    return ((Q.tail + 1) % MAX_SIZE == Q.head);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue Full!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
            Q.info[0] = x;
        } else {
            Q.tail = (Q.tail + 1) % MAX_SIZE;
            Q.info[Q.tail] = x;
        }
    }
}

infotype dequeue(Queue &Q) {
    infotype val = -1;
    
    if (isEmptyQueue(Q)) {
        cout << "Queue Underflow!" << endl;
    } else {
        val = Q.info[Q.head];
        
        if (Q.head == Q.tail) {
            createQueue(Q);
        } else {
            Q.head = (Q.head + 1) % MAX_SIZE;
        }
    }
    return val;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " : ";
    
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        int i = Q.head;
        while (i != Q.tail) {
            cout << Q.info[i] << " ";
            i = (i + 1) % MAX_SIZE;
        }
        cout << Q.info[i];
    }
    cout << endl;
}
```
```C++ main.cpp
#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    cout << "Alternatif 3 (Head dan Tail Berputar)" << endl;
    cout << "-------------------------" << endl;
    cout << "H - T : Queue Info" << endl;
    cout << "-------------------------" << endl;

    Queue Q;
    createQueue(Q);
    
    enqueue(Q, 10); printInfo(Q);
    enqueue(Q, 20); printInfo(Q);
    enqueue(Q, 30); printInfo(Q);
    enqueue(Q, 40); printInfo(Q);
    enqueue(Q, 50); printInfo(Q); 
    
    cout << "--- Dequeue 2 elemen ---" << endl;
    dequeue(Q);     printInfo(Q);
    dequeue(Q);     printInfo(Q); 
    
    cout << "--- Enqueue lagi (Circular) ---" << endl;
    enqueue(Q, 60); printInfo(Q); 
    enqueue(Q, 70); printInfo(Q); 

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Program ini menerapkan mekanisme Circular Queue. Metode ini menghubungkan ujung belakang array (indeks terakhir) kembali ke ujung depan (indeks 0). Hal ini memungkinkan kita memanfaatkan ruang kosong di awal array yang ditinggalkan oleh data yang sudah di-dequeue. Dengan menggunakan operasi modulo (%), indeks Head dan Tail akan "berputar" kembali ke 0 setelah mencapai batas maksimum array, sehingga penggunaan memori menjadi jauh lebih efisien tanpa perlu menggeser data

## Kesimpulan
queue adalah struktur data yang menyusun elemen-elemen data dalam urutan linier. Prinsip dasar dari struktur data ini adalah First In, First Out (FIFO) yang berarti elemen data yang pertama dimasukkan ke dalam antrean akan menjadi yang pertama pula untuk dikeluarkan.

## Referensi
[1] https://www.dicoding.com/blog/struktur-data-queue-pengertian-fungsi-dan-jenisnya/
<br>
