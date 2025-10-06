# <h1 align="center">Laporan Praktikum Modul 2 -Pengenalan Bahas C++ (Bagian kedua)</h1>
<p align="center">Ahmad Ruba'i - 103112400074</p>

## Dasar Teori
Array adalah struktur basis data yang digunakan untuk menyimpan sekumpulan nilai atau elemen dalam satu variabel tunggal. Elemen-elemen ini biasanya memiliki tipe data yang sama, seperti semua angka, semua string, atau semua boolean. 

Array satu dimensi adalah bentuk array paling sederhana. Data dalam array ini tersusun secara linear atau lurus ke satu arah. Biasanya digunakan untuk menyimpan daftar nilai yang tidak memiliki relasi baris dan kolom, seperti daftar nama, daftar harga barang, atau kumpulan angka.

Array dua dimensi memiliki struktur yang mirip dengan tabel, yaitu terdiri dari baris dan kolom. Jenis array ini berguna untuk menyimpan data yang saling berkaitan dalam dua arah, seperti data nilai siswa dalam berbagai mata pelajaran, koordinat dalam grafik, atau matriks dalam perhitungan matematika.

## Guided 

### 1. 

```C++ #include <iostream>
using namespace std;
int main (){
    int arr[5];

    for(int i = 0; i < 5; i++){
        cout << "masukan value indeks ke-" << i << ":";
        cin >> arr[i];
    }
    int j = 0;
    while(j < 5){
        cout << "isi indeks ke-" << ":" << arr[j] << endl;
        j++;
    }
    return 0;
}
```
Program ini digunakan untuk membaca dan menampilkan elemen array satu dimensi. Program akan meminta pengguna untuk memasukkan lima nilai ke dalam array, kemudian program menampilkan kembali isi setiap indeks menggunakan perulangan while.

### 2. 

```C++ #include <iostream>
using namespace std;

void tampilkanHasil(int arr[2][2]){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arrA[2][2] = {
        {1, 2},
        {3, 4}
    };
    int arrB[2][2] = {
        {2, 3},
        {4, 5}
    };
    int arrC[2][2] = {0};
    int arrD[2][2] = {0};

    //penjumlahan matriks 2x2
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "hasil penjumlahan : " << endl;
    tampilkanHasil(arrC);

    cout << endl;

    //perkalian matriks 2x2
    for(int i = 0; i < 2; i++){         //perulangan baris
        for(int j = 0; j < 2; j++){     //perulangan kolom
            for(int k = 0; k < 2; k++){ //perulangan perkalian
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }
    cout << "hasil perkalian : " << endl;
    tampilkanHasil(arrD);

    return 0;
}
```
Program ini digunakan untuk melakukan penjumlahan dan perkalian dua matriks berukuran 2x2. Dua matriks (arrA dan arrB) dijumlahkan dan dikalikan menggunakan perulangan bersarang, lalu hasilnya disimpan dalam arrC dan arrD. Fungsi tampilkanHasil() digunakan untuk menampilkan hasil operasi matriks ke layar.

### 3. 

```C++ #include <iostream>
using namespace std;

int main(){
    int arr[]={10,20,30,40,50};
    int*ptr=arr; //pointer yang menunjuk ke elemen pertama array

    //mengakses elemen array menggunakan pointer
    for (int i = 0; i < 5; i++){
        cout<<"eleem array ke-0"<< i+1<<"menggunakan pointer"<<*(ptr+i)<<endl;
    }

    //mengakses elemen array menggunakan indeks
    for (int i = 0; i < 5; i++){
        cout<<"Elemen array ke-"<< i+1 <<"menggunakan indeks"<<arr[i]<<endl;
    }
    return 0;
    
}
```
Program ini digunakan untuk menampilkan elemen-elemen array menggunakan pointer dan indeks. Array arr berisi lima nilai, dan pointer ptr digunakan untuk menunjuk ke elemen pertama array. Program akan menampilkan isi array dua kali: pertama dengan mengakses elemen melalui pointer (*(ptr+i)), dan kedua dengan indeks biasa (arr[i]).

### 4. ...
``` C++ #include <iostream>
using namespace std;

int cariMAX(int arr[], int ukuran){
    int MAX = arr[0];
    for (int i = 1; i < ukuran; i++)
    {
        if(arr[i] > MAX){
            MAX = arr[i];
        }
    }
    return MAX;
}

void operasiAritmatika(int arr[],  int ukuran){
    int totalJumlah = 0;
    for (int i = 0; i < ukuran; i++)
    {
        totalJumlah += arr[i];
    }
    cout << "total penjumlahan : " << totalJumlah << endl;

    int totalKali = 1;
    for (int i = 0; i < ukuran; i++)
    {
        totalKali *= arr[i];
    }
    cout << "total perkalian : " << totalKali << endl;
}
int main(){
        const int ukuran = 5;
        int arr[ukuran];
        for (int i = 0; i < ukuran; i++){
            cout << "masukan nilai array ke-" << i << " : ";
            cin >> arr[i];
        }
        cout << endl;
        cout << "nilai terbesar dalam array : " << cariMAX(arr, ukuran) << endl;

        operasiAritmatika(arr, ukuran);
        return 0;
        
}
```
Program ini digunakan untuk menentukan nilai terbesar dan menghitung total penjumlahan dan perkalian elemen-elemen array. Program akan meminta pengguna untuk memasukkan lima nilai ke dalam array, kemudian program akan mencari nilai maksimum menggunakan fungsi cariMAX() dan melakukan operasi aritmatika (penjumlahan dan perkalian) menggunakan fungsi operasiAritmatika().

## Unguided 

### 1. (matriks 3x3)

```C++ #include <iostream>
using namespace std;

void tampilMatriks(int matriks[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriks[i][j] << "\t";
        }
        cout << endl;
    }
}

void jumlahMatriks(int A[3][3], int B[3][3], int C[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void kurangMatriks(int A[3][3], int B[3][3], int C[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void kaliMatriks(int A[3][3], int B[3][3], int C[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int matriksA[3][3] = {
        {7, 12, 22},
        {31, 6, 41},
        {15, 19, 36}
    };
    int matriksB[3][3] = {
        {11, 34, 7},
        {3, 25, 41},
        {5, 18, 33}
    };
    int hasil[3][3];
    int pilihan;

    do {
        cout << endl;
        cout << "--- Menu Program Matriks ---" << endl;
        cout << "1. Penjumlahan matriks" << endl;
        cout << "2. Pengurangan matriks" << endl;
        cout << "3. Perkalian matriks" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu : ";
        cin >> pilihan;
        cout << endl;

        switch (pilihan) {
            case 1:
                jumlahMatriks(matriksA, matriksB, hasil);
                cout << "Hasil Penjumlahan Matriks:" << endl;
                tampilMatriks(hasil);
                cout << endl;
                break;
            case 2:
                kurangMatriks(matriksA, matriksB, hasil);
                cout << "Hasil Pengurangan Matriks:" << endl;
                tampilMatriks(hasil);
                cout << endl;
                break;
            case 3:
                kaliMatriks(matriksA, matriksB, hasil);
                cout << "Hasil Perkalian Matriks:" << endl;
                tampilMatriks(hasil);
                cout << endl;
                break;
            case 4:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
        }
    } while (pilihan != 4);

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

Program di atas adalah program operasi matriks dua dimensi berukuran 3x3. Program ini di gunakan untuk melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3. Program akan meminta pengguna untuk memilih menu yang ada (kalau menu yang dipilih tidak ada program akan menampilkan teks "pilihan tidak valid"), kemudian program akan menghitung hasilnya dan program akan menampilkan matriks hasilnya.

### 2. (luas dan keliling persegi panjang)

```C++ #include <iostream>
using namespace std;

int main() {

    int panjang = 10, lebar = 5, luas = 0;

    int *ptrPanjang = &panjang;
    int *ptrLebar = &lebar;

    cout << "--- Nilai Awal ---" << endl;
    cout << "Panjang: " << panjang << endl;
    cout << "Lebar: " << lebar << endl << endl;

    luas = (*ptrPanjang) * (*ptrLebar);
    int keliling = 2 * ((*ptrPanjang) + (*ptrLebar));

    cout << "--- Hasil Perhitungan ---" << endl;
    cout << "Luas Persegi Panjang: " << luas << endl;
    cout << "Keliling Persegi Panjang: " << keliling << endl << endl;

    *ptrPanjang = 12;
    *ptrLebar = 6;

    luas = (*ptrPanjang) * (*ptrLebar);
    keliling = 2 * ((*ptrPanjang) + (*ptrLebar));

    cout << "--- Nilai Setelah Diubah Melalui Pointer ---" << endl;
    cout << "Panjang Baru: " << panjang << endl;
    cout << "Lebar Baru: " << lebar << endl;
    cout << "Luas Baru: " << luas << endl;
    cout << "Keliling Baru: " << keliling << endl;

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

Program ini digunakan untuk menghitung luas dan keliling persegi panjang menggunakan pointer. program akan mengakses pointer untuk mengambil variabel panjang dan lebar. Kemudian program akan menghitung dan menampilkan hasil luas dan keliling berdasarkan nilai awal, kemudian mengubah nilai variabel melalui pointer dan menampilkan hasil perhitungan baru setelah perubahan tersebut.

## Kesimpulan
dari modul ini saya belajar tentang array 1D, 2D, Array Pointer, dan function Prosedur.

## Referensi
[1] [Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN](https://nevacloud.com/blog/apa-itu-array/). 
<br>