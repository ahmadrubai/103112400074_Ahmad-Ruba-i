# <h1 align="center">Laporan Praktikum Modul 4 - Singly linked list (Bagian Pertama)</h1>
<p align="center">Ahmad Ruba'i_103112400074</p>

## Dasar Teori
Linked list adalah salah satu struktur data dasar dalam pemrograman yang terdiri dari serangkaian elemen data yang terhubung satu sama lain menggunakan referensi atau pointer. Setiap elemen dalam linked list, yang disebut node, Setiap node dalam linked list terdiri dari dua komponen utama: data dan pointer. Komponen data menyimpan nilai atau informasi yang ingin kita simpan dalam linked list. Node pertama dalam linked list disebut head, dan node terakhir disebut tail. Head menyimpan referensi ke node pertama, sedangkan tail menyimpan referensi ke node terakhir. Dengan menggunakan head, kita dapat mengakses elemen pertama dalam linked list dan melakukan operasi seperti penambahan, penghapusan, atau pencarian data.

Salah satu keunggulan utama linked list adalah kemampuannya untuk mengatasi perubahan ukuran secara dinamis. Ketika kita ingin menambahkan atau menghapus elemen dari linked list, kita dapat melakukannya dengan mudah tanpa mempengaruhi elemen-elemen lain dalam struktur data tersebut.

1. Singly linked list
struktur data di mana setiap elemen (node) memiliki dua bagian: data yang disimpan dan referensi ke node berikutnya dalam urutan. Node terakhir memiliki nilai NULL sebagai referensi akhir. Operasi seperti penambahan dan penghapusan bisa cepat di awal (head), tetapi lambat di akhir (tail).


## Guided 

### 1. ...

```C++ //Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif
```
```C++ #include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List) == true) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List) == true) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```
```C++ #include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```
Program di atas digunakan untuk mengimplementasi struktur data Linked List dalam bahasa C++. Program menggunakan tipe (struct) untuk menyimpan data mahasiswa yang terdiri dari nama, NIM, dan umur. Setiap elemen (node) dalam linked list berisi data mahasiswa dan pointer menuju node berikutnya. Melalui beberapa fungsi dan prosedur seperti createList, alokasi, insertFirst, insertAfter, dan insertLast, program dapat membuat list kosong, menambahkan node baru di awal, tengah, maupun akhir list. Fungsi printList digunakan untuk menampilkan seluruh isi list. Pada fungsi main, lima data mahasiswa dimasukkan ke dalam list menggunakan kombinasi berbagai operasi insert, kemudian seluruh isi list ditampilkan sebagai hasil akhir. Program ini bertujuan untuk memperkenalkan konsep dasar linked list dan operasi manipulasi datanya secara dinamis menggunakan pointer.

### 2. ...

```C++ 
//Header guard digunakan untuk mencegah file header yang sama
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif
```
```C++ 
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {

    List.first = Nil;
}

//pembuatan node baru
address alokasi(string nama, string nim, int umur) { 

    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {

    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {

    if (Prev != Nil) { //Previous (sebelumnya) tidak boleh NULL
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {

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
void delFirst(linkedlist &List){

    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){

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
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){

    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {

    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {

    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){

    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}
```
```C++ 
#include "list.h"
#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "ISI LIST SETELAH DILAKUKAN INSERT" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "ISI LIST SETELAH DILAKUKAN DELETE" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "ISI LIST SETELAH DILAKUKAN HAPUS LIST" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Program ini merupakan implementasi lengkap dari struktur data Linked List dalam bahasa C++ yang mencakup operasi penyisipan (insert), penghapusan (delete), dan penghitungan jumlah elemen. Setiap node menyimpan data mahasiswa berupa nama, NIM, dan umur. Program menggunakan berbagai prosedur seperti insertFirst, insertAfter, dan insertLast untuk menambahkan node di berbagai posisi, serta delFirst, delAfter, dan delLast untuk menghapus node dari awal, tengah, atau akhir list. Fungsi nbList digunakan untuk menghitung jumlah node, sementara deleteList berfungsi menghapus seluruh isi list. Pada fungsi main, program membuat beberapa node mahasiswa, menambahkannya ke dalam list, menampilkan hasilnya, kemudian menghapus beberapa node dan akhirnya mengosongkan seluruh list. Program ini menunjukkan cara kerja linked list secara dinamis menggunakan pointer dengan operasi manipulasi data yang lengkap.

## Unguided 

### 1. (isi dengan soal unguided 1)

```C++ singlylist.h
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream> 
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct Elmlist* address;

struct Elmlist {
    infotype info;
    address next;
};

struct List {
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void printInfo(List L);

#endif
```
```C++ singlylist.cpp
#include "Singlylist.h"

void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new Elmlist;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

void printInfo(List L) {
    address P = L.First;
    
    if (P == Nil) {
        cout << "List kosong" << endl;
    } else {
        while (P != Nil) {
            cout << P->info;
            P = P->next;
            
            if (P != Nil) {
                cout << " ";
            }
        }
        cout << endl;
    }
}
```
```C++ main.cpp
#include <iostream>
#include "Singlylist.h"
#include <stdlib.h>
using namespace std; 

int main() {
    List L;
    address P1, P2, P3, P4, P5;
    
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Output Unguided 1](https://github.com/ahmadrubai/103112400074_Ahmad-Ruba-i/blob/main/week%204/103112400074_Ahmad%20Ruba'i/Output%20Unguided%201.png)

Program ini adalah contoh implementasi Single Linked List dalam  bahasa C++, yang membagi tugas ke dalam tiga file. File header SINGLYLIST_H berfungsi sebagai cetak biru, mendefinisikan struktur dasar list (seperti Elmlist dan List) dan mendeklarasikan semua fungsi yang dapat diakses publik. File implementasi singlylist.cpp berisi definisi aktual dari fungsi-fungsi dasar list seperti membuat list kosong, mengalokasikan node, menambahkan node di awal (insertFirst), dan mencetak isi list (printInfo). Terakhir, file main.cpp bertindak sebagai program pengujian, di mana sebuah list diinisialisasi, lima elemen dengan nilai 9, 12, 8, 0, dan 2 dimasukkan secara berurutan ke bagian depan list, menghasilkan urutan akhir 9 -> 12 -> 8 -> 0 -> 2, yang kemudian dicetak menjadi output.

### 2. (isi dengan soal unguided 2)

```C++ singlylist.h
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct Elmlist* address;

struct Elmlist {
    infotype info;
    address next;
};

struct List {
    address First;
};


void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void printInfo(List L);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
int nbList(List L);
void deleteList(List &L);

address FindElm(List L, infotype x);

#endif
```
```C++ singlylist.cpp
#include "Singlylist.h"

void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new Elmlist;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

void printInfo(List L) {
    address P = L.First;
    
    if (P == Nil) {
        cout << "List kosong" << endl;
    } else {
        while (P != Nil) {
            cout << P->info;
            P = P->next;
            
            if (P != Nil) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void deleteFirst(List &L, address &P) {
    P = L.First;
    L.First = P->next;
    P->next = Nil;
}

void deleteLast(List &L, address &P) {
    address Prec = Nil;
    P = L.First;

    while (P->next != Nil) {
        Prec = P;
        P = P->next;
    }

    if (Prec == Nil) { 
        L.First = Nil;
    } else {
        Prec->next = Nil;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    P = Prec->next;
    Prec->next = P->next;
    P->next = Nil;
}

int nbList(List L) {
    int hitung = 0;
    address P = L.First;
    
    while (P != Nil) {
        hitung++;
        P = P->next;
    }
    return hitung;
}

void deleteList(List &L) {
    address P;
    while (L.First != Nil) {
        deleteFirst(L, P);
        dealokasi(P);
    }
}

address FindElm(List L, infotype x) {
    address P = L.First;
    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}
```
```C++ main.cpp
#include <iostream>
#include "Singlylist.h"
#include <stdlib.h> 

using namespace std; 

int main() {
    List L;
    address P_temp;
    
    createList(L);

    P_temp = alokasi(2);
    insertFirst(L, P_temp);
    P_temp = alokasi(0);
    insertFirst(L, P_temp);
    P_temp = alokasi(8);
    insertFirst(L, P_temp);
    P_temp = alokasi(12);
    insertFirst(L, P_temp);
    P_temp = alokasi(9);
    insertFirst(L, P_temp);
    
    address P_hapus;
    
    deleteFirst(L, P_hapus);
    dealokasi(P_hapus);
    deleteLast(L, P_hapus);
    dealokasi(P_hapus);

    address Prec = FindElm(L, 12);
    if (Prec != Nil && Prec->next != Nil) {
        deleteAfter(L, Prec, P_hapus);
        dealokasi(P_hapus);
    }

    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;
    deleteList(L);
    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Output Unguided 2](https://github.com/ahmadrubai/103112400074_Ahmad-Ruba-i/blob/main/week%204/103112400074_Ahmad%20Ruba'i/Output%20Unguided%202.png)

Program ini adalah implementasi Single Linked List dalam C++ untuk menyimpan dan memanipulasi serangkaian bilangan bulat. Setelah membuat list kosong, program menyisipkan lima elemen (9, 12, 8, 0, 2) sehingga urutan list menjadi 9 -> 12 -> 8 -> 0 -> 2. Selanjutnya, ada operasi untuk modifikasi: menghapus elemen pertama (9), menghapus elemen terakhir (2), dan menghapus elemen setelah 12 (yaitu 8). Setelah semua operasi ini, list tersisa hanya 12 -> 0. Program kemudian mencetak urutan list tersebut, menunjukkan bahwa total ada 2 node yang tersisa, sebelum akhirnya menghapus seluruh struktur list tersebut hingga kosong.

## Kesimpulan
dari modul ini saya bisa mengetahui cara menghapus node dan membuat node kosong

## Referensi
[1] https://terapan-ti.vokasi.unesa.ac.id/post/memahami-konsep-dan-jenis-jenis-linked-list-dalam-struktur-data#:~:text=Node%20pertama%20dalam%20linked%20list,dan%20node%20terakhir%20disebut%20tail. 
<br>
