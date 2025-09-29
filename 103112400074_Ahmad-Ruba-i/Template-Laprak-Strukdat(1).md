# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Ahmad Ruba'i-103112400074</p>

## Dasar Teori
isi dengan penjelasan dasar teori disertai referensi jurnal (gunakan kurung siku [] untuk pernyataan yang mengambil refernsi dari jurnal).
contoh :
Linked list atau yang disebut juga senarai berantai adalah Salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas[1]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer.


## Guided 

### 1. 

```C++ #include <iostream>
using namespace std;

int main (){
    int angka;
    cout<< "masukan angka : ";
    cin >> angka;
    cout << "angka yang dimasukan "<< angka << endl;
    return 0;
}

```
penjelasan singkat guided 1
Program akan meminta pengguna untuk memasukkan angka, kemudian program akan mencetak angka yang dimasukkan.

### 2. ...

```C++ #include<iostream>
using namespace std;

int main(){
    int angka1, angka2;
    cout << "masukkan angka 1 :";
    cin >> angka1;
    cout << "masukkan angka 2 :";
    cin >> angka2;

    cout << "penjumlahan : " << angka1 + angka2 << endl;
    cout << "pengurangan : " << angka1 - angka2 << endl;
    cout << "perkalian : " << angka1 * angka2 << endl;
    cout << "pembagian : " << angka1 / angka2 << endl;
    cout << "sisa bagi : " << angka1 % angka2 << endl;

    return 0;
}
```
penjelasan singkat guided 2
Program ini digunakan untuk menghitung aritmatika dasar. program akan meminta pengguna untuk memasukkan dua angka, kemudian program akan menampilkan hasil operasi aritmatika dasar berdasarkan kedua angka yang telah di berikan. Operasi yang dihitung adalah penjumlahan, pengurangan, perkalian, pembagian, dan sisa bagi.

### 3. ...

```C++ #include<iostream>
using namespace std;

int main(){
    int angka1, angka2;
    cout << "masukkan angka 1 :";
    cin >> angka1;
    cout << "masukkan angka 2 :";
    cin >> angka2;

    if (angka1 < angka2){
        cout << angka1 << " kurang dari " << angka2 << endl;
    } else {
        cout << angka1 << " lebih dari " << angka2 << endl;
    }

    if (angka1 == angka2){
        cout << angka1 << " sama dengan " << angka2 << endl;
    } else if (angka1 != angka2) {
        cout << "angka berbeda" << endl;
    }

    int pilihan;
    cout << "MENU" << endl;
    cout << "1. penjumlahan" << endl;
    cout << "2. pengurangan" << endl;
    cout << "masukkan pilihan: " << endl;
    cin >> pilihan;

    switch(pilihan){
        case 1:
        cout << "penjumlahan : " << angka1 + angka2 << endl;
        break;
        case 2:
        cout << "pengurangan : " << angka1 - angka2 << endl;
        cout << endl;
        break;
        default :
        cout << "pilihan salah" << endl;

    }
    return 0;
}
```
penjelasan singkat guided 3
Program ini akan meminta pengguna untul memasukkan dua angka, kemudian program akan membandingkan keduanya apakah lebih kecil, lebih besar, atau sama. Setelah itu, program akan menampilkan menu sederhana dengan pilihan penjumlahan atau pengurangan. Jika pengguna memilih 1, program akan menghitung penjumlahan dua angka, sedangkan jika memilih 2, program akan menghitung pengurangannya. Jika input menu tidak sesuai, program menampilkan teks "pilihan salah".

### 4. ...
```C++ #include <iostream>
using namespace std;

 int main(){
    int angka1;
    cout << "masukan angka1 : ";
    cin >> angka1;

    for (int i = 0; i  < angka1; i++){
      cout << i << " - ";
    }
    cout << endl;


    int j = 10;
    while (j > angka1){
      cout << j << " - ";
      j--;
    }

    cout << endl;
    int k = 10;
    do {
      cout << k << " - ";
    }while (k < angka1);

     return  0;
    
}
```
penjelasan singkat guided 4
Program ini digunakan menampilkan deretan angka dengan tiga jenis perulangan: for, while, dan do-while. For mencetak angka naik dimulai dari angka 0, while mencetak angka turun dimulai dari angka 10, sedangkan do-while selalu mencetak angka 10 minimal sekali.

### 5. ...
```C++ #include <iostream>
using namespace std;

int main(){
    const int MAX = 3;
    struct rapot{
        char nama [3];
        float nilai;
    };
    rapot siswa[MAX];

    for(int i = 0; i < MAX; i++){
        cout << "masukan nama siswa : ";
        cin >> siswa[i].nama;
        cout << endl;
        cout << "masukan nilai siswa : ";
        cin >> siswa[i].nilai;
    }
    int j = 0;
    while(j < MAX){
        cout << "nama siswa : " << siswa[j].nama << ", Nilai : " << siswa[j].nilai << endl;
        j++;
    }
    return 0;
}
```
penjelasan singkat guided 5
Program ini digunakan untuk menyimpan dan menampilkan nama dan nilai siswa. Program memakai struct rapot yang berisi dua data yaitu nama dan nilai. Jumlah siswa ditentukan sebanyak tiga orang. program akan meminta pengguna untuk memasukkan nama dan nilai setiap siswa. Setelah semua dimasukkan, program akan menampilkan nama dan nilai masing-masing siswa.

## Unguided 

### 1. (isi dengan soal unguided 1)

```C++ #include<iostream>
using namespace std;

int main(){
    int angka1, angka2;
    cout << "masukkan angka 1 :";
    cin >> angka1;
    cout << "masukkan angka 2 :";
    cin >> angka2;

    cout << "penjumlahan : " << angka1 + angka2 << endl;
    cout << "pengurangan : " << angka1 - angka2 << endl;
    cout << "perkalian : " << angka1 * angka2 << endl;
    cout << "pembagian : " << angka1 / angka2 << endl;
    cout << "sisa bagi : " << angka1 % angka2 << endl;

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided1 2025-09-29 201240](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)


penjelasan unguided 1 
Program ini digunakan untuk menghitung aritmatika dasar. program akan meminta pengguna untuk memasukkan dua angka, kemudian program akan menampilkan hasil operasi aritmatika dasar berdasarkan kedua angka yang telah di berikan. Operasi yang dihitung adalah penjumlahan, pengurangan, perkalian, pembagian, dan sisa bagi.

### 2. (isi dengan soal unguided 2)

```C++  #include <iostream>
#include <string>
using namespace std;

string angkaKeTulisan(int n) {
    string satuan[] = {"nol", "satu", "dua", "tiga", "empat", "lima",
                       "enam", "tujuh", "delapan", "sembilan"};

    if (n < 10) {
        return satuan[n];
    } else if (n == 10) {
        return "sepuluh";
    } else if (n == 11) {
        return "sebelas";
    } else if (n > 11 && n < 20) {
        return satuan[n - 10] + " belas";
    } else if (n >= 20 && n < 100) {
        int puluhan = n / 10;
        int sisa = n % 10;
        string hasil = satuan[puluhan] + " puluh";
        if (sisa != 0) {
            hasil += " " + satuan[sisa];
        }
        return hasil;
    } else if (n == 100) {
        return "seratus";
    }
    return "Angka di luar cakupan";
}

int main() {
    int angka;
    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    if (angka < 0 || angka > 100) {
        cout << "Angka di luar rentang yang ditentukan." << endl;
    } else {
        cout << angka << " : " << angkaKeTulisan(angka) << endl;
    }
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided2 2025-09-29 202817](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 2
program ini digunakan untuk mengubah angka 0 sampai 100 menjadi tulisan. Program akan meminta pengguna untuk memasukan angka yang ingin di ubah menjadi tulisan, kemudian program akan mencetaknya dalam bentuk kata. Jika input lebih dari 100 program akan menampilkan teks "lebih dari yang ditentukan".

### 3. (isi dengan soal unguided 3)

```C++ #include <iostream>
using namespace std;

int main(){
    int n;
    int a = 1;
    cin >> n;

    for (int i = n; i >= 1; i--)
    {
        for (int j = i; j >= 1; j--) 
        {
            cout << j;
        }
        
        cout << "*";
        for (int j = 1; j <= i; j++)
        {
            cout << j ;
        }

        cout << endl;
        for (int j = 1; j <= a; j++)
        {
           cout << " ";
        }
        a = a + 1;

    }
    cout << "*";
    
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided3 2025-09-29 202934](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 3:
program ini digunakan untuk menghasilkan pola angka berdasarkan input yang di berikan oleh pengguna. Jika pengguna menginput angka 3, program akan mencetak baris pertama dengan angka menurun 321, kemudian diikuti tanda *, lalu angka menaik 123. pada baris ke dua, angka 3 di hapus dan ditambah satu spasi, program akan mencetak 21*12. Baris ketiga angka 3 dan 2 di hapus dan ditambah dua spasi, menghasilkan 1*1. Setelah semuanya selesai, program menambahkan satu tanda * pada baris terakhir.
## Kesimpulan
...

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
