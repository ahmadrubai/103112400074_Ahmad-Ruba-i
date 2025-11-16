# <h1 align="center">Laporan Praktikum Modul 7 (Stack)</h1>
<p align="center">Ahmad Ruba'i - 103112400074

## Dasar Teori
stack adalah struktur data linier yang digunakan untuk menyimpan sekumpulan objek atau variabel. Setiap penambahan data (push) dan penghapusan data (pop) terjadi di ujung atas tumpukan. Sifat khas stack adalah LIFO (Last In, First Out): data terakhir yang masuk akan menjadi data pertama yang keluar.
- Push: Menambahkan elemen baru ke bagian atas stack. Misalnya, menumpuk buku baru di atas tumpukan.
- Pop: Menghapus elemen di puncak stack dan mengembalikan nilainya. Artinya, buku yang paling atas diambil keluar.
- Peek/Top: Melihat (mengintip) elemen teratas tanpa menghapusnya. Seperti mengintip buku paling atas tanpa mengambilnya.
- IsEmpty: Memeriksa apakah stack kosong atau tidak. Cocok seperti mengecek apakah masih ada piring di tumpukan.
- Size: Mengembalikan jumlah elemen dalam stack. Berguna untuk mengetahui seberapa tinggi tumpukan saat ini.

## Implementasi Stack dengan Array
Implementasi stack dengan array adalah salah satu yang paling sederhana. Kita menggunakan array dengan ukuran tetap untuk menampung elemen stack, serta variabel top untuk menunjuk indeks elemen teratas.

## Implementasi Stack dengan Linked List
Sebaliknya, stack dapat juga diimplementasikan menggunakan linked list. Setiap elemen stack menjadi node pada linked list, dan puncak stack disimpan di head (simpul pertama) linked list.


## Guided 

### 1. Stack List

```C++ stack.h 
#ifndef STACK_H
#define STACK_H
#define Nil NULL 

#include <iostream>
using namespace std;

typedef struct node *address;

struct node {
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi (address &node);
void push (stack  &listStack, address nodeBaru);
void pop (stack &listStack);
void update( stack &listStack, int posisi);
void view (stack listStack);
void searchData (stack listStack, int data);

#endif
```
```C++ stack.cpp
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        int data = nodeHapus->dataAngka;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  data << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi <= 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
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

void view(stack listStack){ //mencetak dari tumpukan paling atas ke tumpukan paling bawah
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
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
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```
```C++ main.cpp
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```
Program ini mengimplementasikan struktur data stack (tumpukan) menggunakan singly linked list. Program ini mencakup push (menambahkan elemen ke puncak) dan pop (menghapus elemen dari puncak). Selain itu, program ini juga menyediakan fungsi tambahan seperti update untuk mengubah nilai elemen pada posisi tertentu dan searchData untuk mencari data di dalam tumpukan, main.cpp digunakan untuk menjalankan semua fungsi tersebut, mulai dari membuat stack, mengisi data, menghapus, memperbarui, hingga mencari data.

### 2. Stack Array

```C++ Stack.h
#ifndef STACK_H
#define STACK_H

#include<iostream>
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack{
    infotype info[MaxEl];
    int top;
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
```
```C++ Stack.cpp
#include "stack.h"
using namespace std;
// Fungsi untuk membuat stack baru dengan menginisialisasi top = Nil
void CreateStack(Stack &S) {
    S.top = Nil;  // Inisialisasi top dengan nilai Nil mendakan stack kosong
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(Stack S) {
    return S.top == Nil;  // Mengembalikan true jika top bernilai Nil, false jika tidak
}

// Fungsi untuk mengecek apakah stack penuh
bool isFull(Stack S) {
    return S.top == MaxEl - 1;  // Mengembalikan true jika top mencapai batas maksimum (MaxEl-1)
}

// Fungsi untuk menambah elemen ke dalam stack (push)
void push(Stack &S, infotype x) {
    if (!isFull(S)) {  // Cek apakah stack belum penuh
        S.top++;  // Increment nilai top
        S.info[S.top] = x;  // Masukkan nilai x ke array info pada indeks top
    } else {
        cout << "Stack Penuh!" << endl;  // Tampilkan pesan jika stack penuh
    }
}

// Fungsi untuk mengambil elemen teratas dari stack (pop)
infotype pop(Stack &S) {
    infotype x = -999;  // Inisialisasi nilai default jika stack kosong
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        x = S.info[S.top];  // Ambil nilai teratas
        S.top--;  // Decrement nilai top
    } else {
        cout << "Stack Kosong!" << endl;  // Tampilkan pesan jika stack kosong
    }
    return x;  // Kembalikan nilai yang diambil
}

// Fungsi untuk menampilkan isi stack
void printInfo(Stack S) {
    if (isEmpty(S)) {  // Cek apakah stack kosong
        cout << "Stack Kosong" << endl;  // Tampilkan pesan jika kosong
    } else {
        cout << "[TOP] ";  // Tampilkan penanda posisi top
        for (int i = S.top; i >= 0; i--) {  // Loop dari top sampai dasar stack
            cout << S.info[i] << " ";  // Tampilkan setiap elemen
        }
        cout << endl;  // Pindah baris setelah selesai
    }
}

// Fungsi untuk membalik urutan elemen dalam stack
void balikStack(Stack &S) {
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        Stack temp1, temp2;  // Deklarasi dua stack temporary
        CreateStack(temp1); CreateStack(temp2);  // Inisialisasi kedua stack temporary

        while (!isEmpty(S)) { push(temp1, pop(S)); }  // Pindahkan semua elemen ke temp1 (urutan terbalik)

        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }  // Pindahkan ke temp2 (urutan terbalik lagi)

        while (!isEmpty(temp2)) { push(S, pop(temp2)); }  // Kembalikan ke stack asal (urutan sudah benar)
    }
}
```
```C++ main.cpp
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    cout << "Stack Awal:" << endl;
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    cout << "Stack Setelah dibalik:" << endl;
    printInfo(S);

    return 0;
}
```
Program C++ ini mengimplementasikan struktur data stack menggunakan array dengan ukuran yang tetap. Implementasi ini melacak elemen teratas menggunakan indeks integer (top). Program ini mencakup operasi dasar stack LIFO seperti push , pop , serta fungsi bantu isEmpty dan isFull untuk memeriksa kondisi tumpukan. Selain itu, terdapat fungsi balikStack yang membalikkan urutan seluruh elemen di dalam stack dengan memanfaatkan dua stack temporer. File main.cpp berfungsi untuk menguji semua fungsionalitas ini, dengan melakukan beberapa operasi push dan pop, lalu mencetak kondisi stack sebelum dan sesudah pemanggilan fungsi balikStack.

## Unguided 

### 1. (isi dengan soal unguided 1)

```C++ stack.h
#ifndef STACK_H
#define STACK_H

#define maxElmt 20

typedef int infotype;

struct Stack {
    infotype info[maxElmt];
    int top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void Push(Stack &S, infotype x);
infotype Pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif 
```
```C++ stack.cpp
#include "stack.h"
#include <iostream>

using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

bool isFull(Stack S) {
    return S.top == maxElmt - 1;
}

void Push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh" << endl;
    }
}

infotype Pop(Stack &S) {
    if (!isEmpty(S)) {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    } else {
        return -999;
    }
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    if (!isEmpty(S)) {
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
    }
    cout << endl;
}

void balikStack(Stack &S) {
    if (!isEmpty(S)) {
        infotype tempArray[maxElmt];
        int count = 0;

        while (!isEmpty(S)) {
            tempArray[count] = Pop(S);
            count++;
        }

        for (int i = 0; i < count; i++) {
            Push(S, tempArray[i]);
        }
    }
}
```
```C++ main.cpp
#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    Push(S, 3);
    Push(S, 4);
    Push(S, 8);
    Pop(S);
    Push(S, 2);
    Push(S, 3);
    Pop(S);
    Push(S, 9);

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    printInfo(S);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Program ini membuat dan mengelola sebuah stack yang menyimpan bilangan bulat menggunakan array. Program menyediakan operasi dasar stack seperti push, pop, mengecek apakah stack kosong atau penuh, menampilkan isi stack, dan membalik urutan elemen dengan fungsi balikStack. Pada main, beberapa data dimasukkan dan dihapus dari stack menggunakan push dan pop sesuai urutan. Setelah itu, isi stack ditampilkan, kemudian dibalik dan ditampilkan kembali.

### 2.

```C++ stack.h
#ifndef STACK_H
#define STACK_H

#define maxElmt 20

typedef int infotype;

struct Stack {
    infotype info[maxElmt];
    int top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void Push(Stack &S, infotype x);
infotype Pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);

#endif 
```
```C++ stack.cpp
#include "stack.h"
#include <iostream>

using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

bool isFull(Stack S) {
    return S.top == maxElmt - 1;
}

void Push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh" << endl;
    }
}

infotype Pop(Stack &S) {
    if (!isEmpty(S)) {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    } else {
        return -999;
    }
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    if (!isEmpty(S)) {
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
    }
    cout << endl;
}

void balikStack(Stack &S) {
    if (!isEmpty(S)) {
        infotype tempArray[maxElmt];
        int count = 0;

        while (!isEmpty(S)) {
            tempArray[count] = Pop(S);
            count++;
        }

        for (int i = 0; i < count; i++) {
            Push(S, tempArray[i]);
        }
    }
}

void pushAscending(Stack &S, infotype x) {
    Stack tempStack;
    createStack(tempStack);

    while (!isEmpty(S)) {
        infotype topElmt = Pop(S);
        if (topElmt > x) {
            Push(tempStack, topElmt);
        } else {
            Push(S, topElmt);
            break;
        }
    }

    Push(S, x);

    while (!isEmpty(tempStack)) {
        Push(S, Pop(tempStack));
    }
}
```
```C++ main.cpp
#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);

    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Program ini membuat sebuah stack yang menampung bilangan bulat dan menyediakan beberapa operasi seperti menambah data (push), mengambil data (pop), menampilkan isi stack, membalik urutan, dan menambah data secara urut naik melalui fungsi pushAscending. Saat program dijalankan, beberapa angka dimasukkan ke stack menggunakan aturan ascending sehingga stack otomatis tersusun dari kecil ke besar. Setelah itu, isi stack ditampilkan, kemudian dibalik menggunakan balikStack, dan hasilnya ditampilkan lagi. Program ini menunjukkan cara kerja stack dan bagaimana data bisa disimpan secara terurut dengan memanfaatkan operasi push dan pop.

### 3.

```C++ stack.h
#ifndef STACK_H
#define STACK_H

#define maxElmt 20

typedef char infotype;

struct Stack {
    infotype info[maxElmt];
    int top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void Push(Stack &S, infotype x);
infotype Pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void getInputStream(Stack &S);

#endif 
```
```C++ stack.cpp
#include "stack.h"
#include <iostream>

using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

bool isFull(Stack S) {
    return S.top == maxElmt - 1;
}

void Push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh" << endl;
    }
}

infotype Pop(Stack &S) {
    if (!isEmpty(S)) {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    } else {
        return '\0'; 
    }
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    if (!isEmpty(S)) {
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
    }
    cout << endl;
}

void balikStack(Stack &S) {
    if (!isEmpty(S)) {
        infotype tempArray[maxElmt];
        int count = 0;

        while (!isEmpty(S)) {
            tempArray[count] = Pop(S);
            count++;
        }

        for (int i = 0; i < count; i++) {
            Push(S, tempArray[i]);
        }
    }
}

void getInputStream(Stack &S) {
    infotype inputChar;
    inputChar = cin.get();

    while (inputChar != '\n') {
        if (!isFull(S)) {
            Push(S, inputChar);
        }
        inputChar = cin.get();
    }
}
```
```C++ main.cpp
#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);

    getInputStream(S);
    printInfo(S);
    
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    
    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Program ini adalah implementasi sederhana dari struktur data stack menggunakan bahasa C++. Stack disimpan dalam array berukuran tetap dengan pointer top sebagai penanda elemen teratas. Pengguna dapat memasukkan rangkaian karakter melalui getInputStream, yang kemudian disimpan ke dalam stack secara berurutan. Program juga menyediakan fungsi untuk menampilkan isi stack serta membalik urutan karakter di dalamnya melalui balikStack. Saat dijalankan, program membaca input, menampilkan isi stack, membaliknya, lalu menampilkan hasil yang sudah terbalik.

## Kesimpulan
stack adalah struktur data linier yang bekerja dengan prinsip LIFO, di mana elemen terakhir yang dimasukkan akan menjadi elemen pertama yang dikeluarkan. Operasi dasar seperti push, pop, peek, isEmpty, dan size memungkinkan stack digunakan secara efisien untuk pengelolaan data sementara. Implementasi stack dengan array sangat sederhana karena hanya membutuhkan ruang tetap dan penanda posisi teratas (top). Secara keseluruhan, stack memberikan cara yang mudah dan terstruktur untuk menyimpan serta mengambil data secara berurutan dari satu sisi tumpukan.

## Referensi
[1] https://www.codepolitan.com/blog/apa-itu-stack-dalam-ilmu-pemrograman/ 
<br>
