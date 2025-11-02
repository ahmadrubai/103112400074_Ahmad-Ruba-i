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

    data.nopol = "D003";
    data.warna = "putih";
    data.thnBuat = 70;
    P = alokasi(data);
    insertLast(L, P);

    data.nopol = "D001";
    data.warna = "merah";
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