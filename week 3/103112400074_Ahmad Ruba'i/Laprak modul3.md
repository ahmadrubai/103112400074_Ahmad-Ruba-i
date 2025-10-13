# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type (Bagian ketiga)</h1>
<p align="center">Ahmad Ruba'i - 103112400074</p>

## Dasar Teori
tipe data abstrak ( ADT ) adalah model matematika untuk tipe data , yang didefinisikan oleh perilakunya ( semantik ) dari sudut pandang pengguna data, khususnya dalam hal nilai yang mungkin, operasi yang mungkin pada data tipe ini, dan perilaku operasi ini. Model matematika ini kontras dengan struktur data , yang merupakan representasi konkret dari data, dan merupakan sudut pandang pelaksana, bukan pengguna. Misalnya, tumpukan memiliki operasi push/pop yang mengikuti aturan Last-In-First-Out, dan dapat diimplementasikan secara konkret menggunakan daftar atau larik. Contoh lain adalah himpunan yang menyimpan nilai, tanpa urutan tertentu , dan tidak ada nilai yang berulang. Nilai itu sendiri tidak diambil dari himpunan; sebaliknya, seseorang menguji nilai untuk keanggotaan untuk mendapatkan Boolean "masuk" atau "tidak masuk".

ADT adalah konsep teoretis, yang digunakan dalam semantik formal dan verifikasi program dan, kurang ketat, dalam desain dan analisis algoritma , struktur data , dan sistem perangkat lunak . Sebagian besar bahasa komputer arus utama tidak secara langsung mendukung spesifikasi ADT secara formal. Namun, berbagai fitur bahasa sesuai dengan aspek-aspek tertentu dari penerapan ADT, dan mudah tertukar dengan ADT yang sebenarnya; ini termasuk tipe abstrak , tipe data buram , protokol , dan desain berdasarkan kontrak .

## Guided 

### 1. ...

```C++ #include <iostream>
#include "mahasiswa.h"

using namespace std;

//realisasi dari fungsi inputMhs
void inputMhs(mahasiswa & m){
    cout << "input NIM:";
    cin >> m.nim;
    cout << "input nilai 1 :";
    cin >> m.nilai1;
    cout << "input nilai 2 :";
    cin >> m.nilai2;
}

//realisasi dari fungsi rat2
float rata2(mahasiswa m){
    return(float)(m.nilai1 + m.nilai2)/2;
}
```

```C++ #ifndef MAHASISWA_H
#define MAHASISWA_H

//definisi tipe (struct)
struct mahasiswa
{
    char nim[10];
    int nilai1, nilai2;
};

//deklarasi primitif (fungsi)
void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

#endif
```

```C++ #include <iostream>
#include "mahasiswa.h"
#include <cstdlib>

using namespace std;

int main(){
    mahasiswa mhs;

    inputMhs(mhs);

    cout << "Rata-rata nilai adalah:"<<rata2
    (mhs)<<endl;
    system("pause");

    return 0;

}
```
Program ini digunakan untuk menghitung rata-rata nilai mahasiswa dengan menggunakan konsep struct dan fungsi dalam bahasa C++. Struct bernama mahasiswa digunakan untuk menyimpan data NIM dan dua nilai ujian. Fungsi inputMhs() berfungsi untuk menerima input data mahasiswa yang diberikan oleh pengguna, sedangkan fungsi rata2() digunakan untuk menghitung nilai rata-rata dari kedua nilai yang dimasukkan. Hasil perhitungan rata-rata tersebut kemudian akan ditampilkan melalui fungsi main().

### 2. ...

```C++ #include<iostream>
using namespace std;

struct mahasiswa {
    string nama;
    float nilai1, nilai2;
};

void inputMhs(mahasiswa &m) {
    cout << "masukkan nama mahasiswa: "; 
    cin >> m.nama;
    cout << "masukkan Nilai 1: "; 
    cin >> m.nilai1;
    cout << "masukkan Nilai 2: "; 
    cin >> m.nilai2;
}

float rata2(mahasiswa m) {
    return (float)(m.nilai1 + m.nilai2) / 2;
}

int main() {
    mahasiswa mhs;

    inputMhs(mhs);

    cout << "rata-rata nilai adalah: " << rata2 (mhs) << endl;
    system("pause");

    return 0;
}
```
Program ini digunakan untuk menghitung rata-rata dua nilai mahasiswa. Program ini menggunakan struktur data struct bernama mahasiswa yang berisi atribut nama, nilai1, dan nilai2. Melalui fungsi inputMhs, program akan meminta pengguna untuk memasukkan nama serta dua nilai mahasiswa. Kemudian, fungsi rata2 akan menghitung dan mengembalikan nilai rata-rata dari kedua nilai tersebut. Hasil perhitungan kemudian akan ditampilkan oleh fungsi main().

## Unguided 

### 1. 

```C++ #include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    Mahasiswa Mhs[10];
    int n;

    cout << "Masukkan jumlah mahasiswa (maks 10): ";
    cin >> n;

    if (n > 10) n = 10;

    for (int i = 0; i < n; i++) {
        cout << "Data mahasiswa ke-" << i + 1 << endl;
        cout << "Nama : ";
        cin.ignore();
        getline(cin, Mhs[i].nama);
        cout << "NIM : ";
        getline(cin, Mhs[i].nim);
        cout << "UTS : ";
        cin >> Mhs[i].uts;
        cout << "UAS : ";
        cin >> Mhs[i].uas;
        cout << "Tugas : ";
        cin >> Mhs[i].tugas;
        Mhs[i].nilaiAkhir = hitungNilaiAkhir(Mhs[i].uts, Mhs[i].uas, Mhs[i].tugas);
    }

    cout << "\nData Mahasiswa " << endl;
    for (int i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama : " << Mhs[i].nama << endl;
        cout << "NIM : " << Mhs[i].nim << endl;
        cout << "UTS : " << Mhs[i].uts << endl;
        cout << "UAS : " << Mhs[i].uas << endl;
        cout << "Tugas : " << Mhs[i].tugas << endl;
        cout << "Nilai Akhir : " << Mhs[i].nilaiAkhir << endl;
    }

    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Output Unguided 1](https://github.com/ahmadrubai/103112400074_Ahmad-Ruba-i/blob/main/week%203/103112400074_Ahmad%20Ruba'i/Output%20Unguided%201.png)

Program digunakan untuk menghitung dan menampilkan nilai akhir mahasiswa. Data mahasiswa akan disimpan dalam struktur yang berisi nama, NIM, nilai UTS, UAS, tugas, dan nilai akhir. Program akan meminta pengguna untuk memasukkan data setiap mahasiswa, kemudian program akan menghitung nilai akhirnya menggunakan rumus 30% UTS, 40% UAS, dan 30% tugas. Setelah semua data selesai diinput, program menampilkan hasil berupa daftar mahasiswa dan nilai akhir masing-masing mahasiswa.

### 2. 

```C++ #include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(string namaMapel, string kodeMapel) {
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodeMapel;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}

```

```C++ #ifndef PELAJARAN_H
#define PELAJARAN_H
#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namaMapel, string kodeMapel);
void tampil_pelajaran(pelajaran pel);

#endif
```

```C++ #include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namaPel = "Struktur Data";
    string kodePel = "STD";

    pelajaran pel = create_pelajaran(namaPel, kodePel);
    tampil_pelajaran(pel);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Output Unguided 2](https://github.com/ahmadrubai/103112400074_Ahmad-Ruba-i/blob/main/week%203/103112400074_Ahmad%20Ruba'i/Output%20Unguided%202.png)

Program ini digunakan untuk membuat dan menampilkan data pelajaran menggunakan struktur dan fungsi dalam bahasa C++. Data pelajaran terdiri dari nama dan kode pelajaran. Fungsi create_pelajaran() digunakan untuk membuat data baru dan tampil_pelajaran() digunakan untuk menampilkan hasilnya. Pada fungsi main(), program membuat satu pelajaran dengan nama “Struktur Data” dan kode “STD”, kemudian menampilkan informasi tersebut.

### 3. 

```C++ #include <iostream>
using namespace std;

const int baris = 3;
const int kolom = 3;

void tampilArray(int A[baris][kolom]) {
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarNilai(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void tukarArray(int A[baris][kolom], int B[baris][kolom], int baris, int kolom) {
    int *ptr1 = &A[baris][kolom];
    int *ptr2 = &B[baris][kolom];
    tukarNilai(ptr1, ptr2);
}

int main() {
    int A[baris][kolom] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[baris][kolom] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    cout << "Array A sebelum ditukar:\n";
    tampilArray(A);
    cout << "\nArray B sebelum ditukar:\n";
    tampilArray(B);

    int baris = 1, kolom = 2;
    tukarArray(A, B, baris, kolom);

    cout << "\nArray A setelah ditukar:\n";
    tampilArray(A);
    cout << "\nArray B setelah ditukar:\n";
    tampilArray(B);

    return 0;
}

```
### Output Unguided 3 :

##### Output 1
![Output Unguided 3](https://github.com/ahmadrubai/103112400074_Ahmad-Ruba-i/blob/main/week%203/103112400074_Ahmad%20Ruba'i/Output%20Unguided%203.png)


Program ini digunakan untuk menukar nilai elemen tertentu antara dua array dua dimensi berukuran 3x3. Kedua array, yaitu A dan B, masing-masing berisi kumpulan angka yang berbeda. Program akan menampilkan isi kedua array sebelum dan sesudah pertukaran dilakukan. Proses pertukaran nilai dilakukan melalui fungsi tukarNilai() yang menggunakan pointer untuk menukar isi dua variabel, sedangkan fungsi tukarArray() menentukan posisi elemen yang akan ditukar berdasarkan indeks baris dan kolom yang ditentukan pengguna.

## Kesimpulan
ADT membantu dalam merancang program yang lebih terstruktur, modular, dan cukup mudah dipahami. Dengan memisahkan definisi data dan operasinya, program menjadi lebih fleksibel serta cukup mudah untuk dikembangkan dan dipelihara.

## Referensi
[1] https://en.wikipedia.org/wiki/Abstract_data_type 
<br>
