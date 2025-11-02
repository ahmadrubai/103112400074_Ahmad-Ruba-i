# <h1 align="center">Laporan Praktikum Modul 6 - Double Linked List (Bagian Pertama)</h1>
<p align="center">Ahmad Ruba'i - 103112400074</p>

## Dasar Teori
Linked list adalah struktur data linear yang terdiri dari serangkaian elemen yang disebut “node”, di mana setiap node terhubung ke node berikutnya dalam urutan tertentu. Setiap node terdiri dari dua bagian utama: data yang disimpan dan referensi ke node berikutnya dalam urutan. Ini memungkinkan alokasi memori yang dinamis dan tidak perlu alokasi memori yang bersifat statis seperti yang terjadi pada array.

### Double Linked list
 Double linked list adalah perluasan dari single linked list di mana setiap node memiliki dua referensi: satu ke node sebelumnya dan satu ke node berikutnya dalam urutan. Dengan memiliki referensi ke node sebelumnya, double linked list memungkinkan navigasi maju dan mundur, yang membuatnya lebih fleksibel daripada single linked list. Namun, ini juga memerlukan alokasi memori tambahan untuk menyimpan referensi tambahan, sehingga dapat meningkatkan overhead memori.

## Guided 

### 1. Guided 1

```C++ listMakanan.h
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

#endif
```
```C++ listMakanan.cpp
#include "listMakanan.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node selanjutnya (nodeNext) tidak valid!" << endl;
        }
    }
}
```
```C++ main.cpp
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeC);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    return 0;
}
```
Program ini berfungsi untuk membuat dan mengelola daftar menu makanan. Program ini bisa menambahkan data makanan baru (berisi nama, jenis, harga, and rating) ke bagian awal, akhir, atau posisi tertentu dalam daftar. Program ini juga bisa digunakan untuk mengubah data makanan yang sudah ada di dalam daftar, baik yang di awal, di akhir, atau di posisi lain. Fungsi main menunjukkan cara kerja program dengan menambahkan lima menu makanan, menampilkannya, lalu mengubah beberapa data makanan tersebut, dan menampilkannya lagi setelah diubah.

### 2. Guided 2

```C++ Doublylist.h
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

// Tipe data info (kendaraan)
struct kendaraan { //struktur untuk menyimpan info kendaraan
    string nopol; 
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;

// Tipe address dan elemen list
typedef struct ElmList *address;
struct ElmList {
    infotype info; // info kendaraan
    address next;
    address prev;
};

// Tipe list
struct List {
    address first; //pointer ke elemen pertama
    address last;  //pointer ke elemen terakhir
};

// Prototypes
void CreateList(List &L); //ngebuat list kosong
address alokasi(infotype x); //alokasi elemen baru/nambah elemen baru
void dealokasi(address &P); //dealokasi elemen/hapus elemen

// Insert Last
void insertLast(List &L, address P);

// Searching
address findElm(List L, string nopol);

// Delete
void deleteByNopol(List &L, string nopol);

// Tampilkan isi list
void printInfo(List L);

#endif
```
```C++ Doublylist.cpp
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) { //blm ada elemen
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) { //fs alokasi elemen baru
    address P = new ElmList; //alokasi memori untuk elemen baru
    P->info = x; //mengisi bagian info dengan data x
    P->next = Nil; //ini jadi nill karena gak terhubung ke list manapun
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P; //menghapus elemen yang ditunjuk oleh P dan mengembalikan memori ke sistem
}

void insertLast(List &L, address P) {
    if (L.first == Nil) { // List kosong
        L.first = P; // elemen pertama dan terakhir sama dengan P
        L.last = P;
    } else { // List ada isi
        P->prev = L.last; // prev P menunjuk ke elemen terakhir saat ini
        (L.last)->next = P; // next elemen terakhir saat ini menunjuk ke P
        L.last = P; // update last menjadi P
    }
}

// Searching
address findElm(List L, string nopol) {
    address P = L.first; // mulai dari elemen pertama
    while (P != Nil) {
        //Bandingkan nopol yang dicari dengan nopol di elemen saat ini
        if (P->info.nopol == nopol) {
            return P; // Ketemu
        }
        P = P->next; // Lanjut ke elemen berikutnya kalau g cocok
    }
    return Nil; // Tidak ketemu
}

// Delete
void deleteByNopol(List &L, string nopol) {
    // Cari elemen dengan nopol yang sesuai
    address P = findElm(L, nopol);
    if (P == Nil) { // Tidak ditemukan
        cout << "Nomor polisi " << nopol << " tidak ditemukan.\n";
    } else { // Ditemukan
        if (P == L.first && P == L.last) { // Kasus 1: Hanya 1 elemen di list
            L.first = Nil; L.last = Nil;
        } else if (P == L.first) { // Kasus 2: Hapus elemen pertama tapi bukan satu-satunya
            L.first = P->next; // update first ke elemen berikutnya
            (L.first)->prev = Nil; // update prev elemen pertama barumenjadi nil
        } else if (P == L.last) { // Kasus 3: Hapus elemen terakhir
            L.last = P->prev; // update last ke elemen sebelumnya
            (L.last)->next = Nil; P->prev = Nil; // update next elemen terakhir baru menjadi nil
        } else { // Kasus 4: Hapus elemen di tengah
            address Prec = P->prev; // elemen sebelum P
            address Succ = P->next; // elemen setelah P
            Prec->next = Succ; Succ->prev = Prec; // hubungkan Prec ke Succ
            P->next = Nil; P->prev = Nil; // putuskan hubungan P dari list
        }
        dealokasi(P); // dealokasi elemen P
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
    }
}


void printInfo(List L) { //menampilkan isi list
    address P = L.first; //mulai dari elemen pertama
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi: " << P->info.nopol << endl;
            cout << "warna    : " << P->info.warna << endl;
            cout << "tahun    : " << P->info.thnBuat << endl << endl;
            P = P->next;
        }
    }
}
```
```C++ main.cpp
#include "Doublylist.h"

using namespace std;

int main() { // penggunaan fungsi-fungsi dalam Doublylist
    List L; // deklarasi list
    CreateList(L); // buat list kosong
    address P; // deklarasi pointer elemen list
    infotype data; // deklarasi variabel info kendaraan

    data = {"D001", "hitam", 90}; P = alokasi(data); insertLast(L, P);
    data = {"D003", "putih", 70}; P = alokasi(data); insertLast(L, P);
    data = {"D004", "kuning", 90}; P = alokasi(data); insertLast(L, P);

    cout << "DATA LIST AWAL" << endl;
    printInfo(L);


    string cariNopol = "D001";
    cout << "MENCARI NOPOL " << cariNopol << " -" << endl;
    address found = findElm(L, cariNopol); //Manggil fungsi pencarian di Doublylist.cpp
    if (found != Nil) { // Ketemu
        cout << "Ditemukan: " << found->info.nopol << ", Warna: " << found->info.warna << endl << endl;
    } else {
        cout << cariNopol << " tidak ditemukan." << endl << endl;
    }

    string hapusNopol = "D003";
    cout << "MENGHAPUS NOPOL " << hapusNopol << " -" << endl;
    deleteByNopol(L, hapusNopol); //Manggil fungsi delete di Doublylist.cpp
    cout << endl;

    cout << "DATA LIST SETELAH HAPUS" << endl;
    printInfo(L);

    // Contoh delete elemen pertama
    cout << "MENGHAPUS ELEMEN PERTAMA " << endl;
    deleteByNopol(L, L.first->info.nopol); //Menghapus elemen pertama
    cout << endl;
    printInfo(L);


    return 0;
}
```
Program ini berfungsi untuk mengelola daftar data kendaraan seperti: nomor polisi, warna, dan tahun. Program ini menggunakan struktur data doubly linked list, Setiap data terhubung ke data sebelum dan sesudahnya. Fungsi utamanya adalah untuk menambahkan data kendaraan baru ke akhir daftar, mencari data berdasarkan nomor polisi, dan menghapus data berdasarkan nomor polisi. Program main menunjukkan contoh penggunaannya dengan memasukkan tiga data kendaraan, mencetak daftar, mencari satu kendaraan, menghapus kendaraan lain, lalu mencetak daftar akhir setelah penghapusan.

## Unguided 

### 1. Unguided 1

```C++ Doublylist.h       
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

typedef struct { 
    string nopol; 
    string warna;
    int thnBuat;
} kendaraan;
typedef kendaraan infotype;

typedef struct ElmList *address;
typedef struct ElmList { 
    infotype info;
    address next;
    address prev;
} ElmList;

typedef struct { 
    address First;
    address Last;
} List;

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);

void insertLast(List &L, address P);
void printInfo(List L);

infotype inputKendaraan();
address findElm(List L, string nopol);
void deleteByNopol(List &L, string nopol); 

#endif
```
```C++ Doublylist.cpp
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

infotype inputKendaraan() {
    infotype data;
    cout << "masukkan nomor polisi: ";
    cin >> data.nopol;
    cout << "masukkan warna kendaraan: ";
    cin >> data.warna;
    cout << "masukkan tahun kendaraan: ";
    cin >> data.thnBuat;
    return data;
}

void insertLast(List &L, address P) {
    if (L.First == Nil) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last; 
        (L.Last)->next = P; 
        L.Last = P;
    }
}

address findElm(List L, string nopol) {
    address P = L.First; 
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next; 
    }
    return Nil;
}

void deleteByNopol(List &L, string nopol) {
    address P = findElm(L, nopol);
    if (P == Nil) {
        cout << "Nomor polisi " << nopol << " tidak ditemukan.\n";
    } else {
        if (P == L.First && P == L.Last) {
            L.First = Nil; L.Last = Nil;
        } else if (P == L.First) {
            L.First = P->next; 
            (L.First)->prev = Nil;
        } else if (P == L.Last) {
            L.Last = P->prev; 
            (L.Last)->next = Nil; P->prev = Nil;
        } else {
            address Prec = P->prev;
            address Succ = P->next;
            Prec->next = Succ; Succ->prev = Prec;
            P->next = Nil; P->prev = Nil;
        }
        dealokasi(P);
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
    }
}

void printInfo(List L) {
    address P = L.Last; 
    
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi: " << P->info.nopol << endl;
            cout << "warna    : " << P->info.warna << endl;
            cout << "tahun    : " << P->info.thnBuat << endl << endl;
            
            P = P->prev; 
        }
    }
}
```
```C++ main.cpp
#include "Doublylist.h"

using namespace std;

int main() {
    List L;
    CreateList(L);
    infotype data;
    address P;
    address found;

    data = inputKendaraan();
    found = findElm(L, data.nopol);
    if (found == Nil) {
        P = alokasi(data);
        insertLast(L, P);
    } else {
        cout << "nomor polisi sudah terdaftar" << endl;
    }
    cout << endl; 
    
    data = inputKendaraan();
    found = findElm(L, data.nopol);
    if (found == Nil) {
        P = alokasi(data);
        insertLast(L, P);
    } else {
        cout << "nomor polisi sudah terdaftar" << endl;
    }
    cout << endl; 

    data = inputKendaraan();
    found = findElm(L, data.nopol);
    if (found == Nil) {
        P = alokasi(data);
        insertLast(L, P);
    } else {
        cout << "nomor polisi sudah terdaftar" << endl;
    }
    cout << endl; 
    
    data = inputKendaraan();
    found = findElm(L, data.nopol);
    if (found == Nil) {
        P = alokasi(data);
        insertLast(L, P);
    } else {
        cout << "nomor polisi sudah terdaftar" << endl;
    }
    cout << endl;

    cout << "\nDATA LIST 1" << endl;
    
    printInfo(L); 
    
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Output Unguided 1](https://github.com/ahmadrubai/103112400074_Ahmad-Ruba-i/blob/main/week%206/103112400074_Ahmad%20Ruba'i/Output%20Unguided%201.png)

Program ini meminta pengguna unutk memasukkan empat data kendaraan. Setiap data akan dicek nomor polisinya; jika nomor itu baru, data akan disimpan. Jika nomornya sama dengan yang sudah ada, data itu akan diabaikan. Setelah selesai, program akan mencetak semua data yang berhasil disimpan, secara terbalik (dari yang terakhir Anda masukkan).

### 2. Unguided 2

```C++ Doublylist.h
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

typedef struct { 
    string nopol; 
    string warna;
    int thnBuat;
} kendaraan;
typedef kendaraan infotype;

typedef struct ElmList *address;
typedef struct ElmList { 
    infotype info;
    address next;
    address prev;
} ElmList;

typedef struct { 
    address First;
    address Last;
} List;

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);

void insertLast(List &L, address P);
void printInfo(List L);

infotype inputKendaraan();
address findElm(List L, string nopol);
void deleteByNopol(List &L, string nopol); 

#endif
```
```C++ Doublylist.cpp
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

infotype inputKendaraan() {
    infotype data;
    cout << "masukkan nomor polisi: ";
    cin >> data.nopol;
    cout << "masukkan warna kendaraan: ";
    cin >> data.warna;
    cout << "masukkan tahun kendaraan: ";
    cin >> data.thnBuat;
    return data;
}

void insertLast(List &L, address P) {
    if (L.First == Nil) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last; 
        (L.Last)->next = P; 
        L.Last = P;
    }
}

address findElm(List L, string nopol) {
    address P = L.First; 
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next; 
    }
    return Nil;
}

void deleteByNopol(List &L, string nopol) {
    address P = findElm(L, nopol);
    if (P == Nil) {
        cout << "Nomor polisi " << nopol << " tidak ditemukan.\n";
    } else {
        if (P == L.First && P == L.Last) {
            L.First = Nil; L.Last = Nil;
        } else if (P == L.First) {
            L.First = P->next; 
            (L.First)->prev = Nil;
        } else if (P == L.Last) {
            L.Last = P->prev; 
            (L.Last)->next = Nil; P->prev = Nil;
        } else {
            address Prec = P->prev;
            address Succ = P->next;
            Prec->next = Succ; Succ->prev = Prec;
            P->next = Nil; P->prev = Nil;
        }
        dealokasi(P);
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
    }
}

void printInfo(List L) {
    address P = L.Last; 
    
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi: " << P->info.nopol << endl;
            cout << "warna    : " << P->info.warna << endl;
            cout << "tahun    : " << P->info.thnBuat << endl << endl;
            
            P = P->prev; 
        }
    }
}
```
```C++ main.cpp
#include "Doublylist.h"
#include <iostream>

using namespace std;

int main() {
    List L;
    CreateList(L);

    address P;
    infotype data;

    data.nopol = "D001";
    data.warna = "hitam";
    data.thnBuat = 90;
    P = alokasi(data);
    insertLast(L, P);

    data.nopol = "B1234";
    data.warna = "merah";
    data.thnBuat = 2020;
    P = alokasi(data);
    insertLast(L, P);

    data.nopol = "F5678";
    data.warna = "biru";
    data.thnBuat = 2018;
    P = alokasi(data);
    insertLast(L, P);

    string nopolCari;
    cout << "Masukkan Nomor Polisi yang dicari : ";
    cin >> nopolCari;

    address Ptemu = findElm(L, nopolCari);

    if (Ptemu != Nil) {
        cout << "Nomor Polisi : " << Ptemu->info.nopol << endl;
        cout << "Warna        : " << Ptemu->info.warna << endl;
        cout << "Tahun        : " << Ptemu->info.thnBuat << endl;
    } else {
        cout << "Data dengan nomor polisi " << nopolCari << " tidak ditemukan." << endl;
    }

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Output Unguided 2](https://github.com/ahmadrubai/103112400074_Ahmad-Ruba-i/blob/main/week%206/103112400074_Ahmad%20Ruba'i/Output%20Unguided%202.png)

Program ini adalah program pencarian data. Pertama, program secara otomatis membuat daftar berisi tiga data kendaraan. Setelah itu, program akan meminta pengguna memasukan satu nomor polisi. Program akan mencari nomor itu di dalam daftar yang sudah dibuat. Jika ketemu, ia akan menampilkan info kendaraan itu; jika tidak, program akan mencetak datanya tidak ada.

### 3. Unguided 3

```C++ Doublylist.h
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

typedef struct { 
    string nopol; 
    string warna;
    int thnBuat;
} kendaraan;
typedef kendaraan infotype;

typedef struct ElmList *address;
typedef struct ElmList { 
    infotype info;
    address next;
    address prev;
} ElmList;

typedef struct { 
    address First;
    address Last;
} List;

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);

void insertLast(List &L, address P);
void printInfo(List L);

infotype inputKendaraan();
address findElm(List L, string nopol);
void deleteByNopol(List &L, string nopol); 

#endif
```
```C++ Doublylist.cpp
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

infotype inputKendaraan() {
    infotype data;
    cout << "masukkan nomor polisi: ";
    cin >> data.nopol;
    cout << "masukkan warna kendaraan: ";
    cin >> data.warna;
    cout << "masukkan tahun kendaraan: ";
    cin >> data.thnBuat;
    return data;
}

void insertLast(List &L, address P) {
    if (L.First == Nil) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last; 
        (L.Last)->next = P; 
        L.Last = P;
    }
}

address findElm(List L, string nopol) {
    address P = L.First; 
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next; 
    }
    return Nil;
}

void deleteByNopol(List &L, string nopol) {
    address P = findElm(L, nopol);
    if (P == Nil) {
        cout << "Nomor polisi " << nopol << " tidak ditemukan.\n";
    } else {
        if (P == L.First && P == L.Last) {
            L.First = Nil; L.Last = Nil;
        } else if (P == L.First) {
            L.First = P->next; 
            (L.First)->prev = Nil;
        } else if (P == L.Last) {
            L.Last = P->prev; 
            (L.Last)->next = Nil; P->prev = Nil;
        } else {
            address Prec = P->prev;
            address Succ = P->next;
            Prec->next = Succ; Succ->prev = Prec;
            P->next = Nil; P->prev = Nil;
        }
        dealokasi(P);
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
    }
}

void printInfo(List L) {
    address P = L.Last; 
    
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi: " << P->info.nopol << endl;
            cout << "warna    : " << P->info.warna << endl;
            cout << "tahun    : " << P->info.thnBuat << endl << endl;
            
            P = P->prev; 
        }
    }
}
```
```C++ main.cpp
#include "Doublylist.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    List L;
    CreateList(L);
    infotype data;
    address P;

    data = {"D001", "hitam", 90};
    P = alokasi(data);
    insertLast(L, P);

    data = {"D003", "putih", 70};
    P = alokasi(data);
    insertLast(L, P);

    data = {"D004", "kuning", 90};
    P = alokasi(data);
    insertLast(L, P);

    string nopol_dihapus;
    cout << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin >> nopol_dihapus; 

    deleteByNopol(L, nopol_dihapus);
    cout << "\nDATA LIST 1" << endl;
    cout << endl;
    printInfo(L); 

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Output Unguided 3](https://github.com/ahmadrubai/103112400074_Ahmad-Ruba-i/blob/main/week%206/103112400074_Ahmad%20Ruba'i/Output%20Unguided%203.png)

Program ini adalah sistem sederhana untuk mengelola daftar data kendaraan menggunakan struktur data doubly linked list. Program utama (main.cpp) pertama-tama akan membuat sebuah daftar kosong, lalu menambahkan tiga data kendaraan ke dalam daftar tersebut. Setelah itu, program akan meminta pengguna untuk memasukkan nomor polisi dari kendaraan yang ingin dihapus. Program kemudian akan mencari data tersebut di dalam daftar dan menghapusnya. Terakhir, program akan mencetak sisa data kendaraan yang masih ada di dalam daftar.

## Kesimpulan
dari modul ini saya bisa mengetahui cara kerja dari double linked list

## Referensi
[1] https://rumahcoding.co.id/linked-list-pengertian-dan-implementasi-dasar/. 
<br>
