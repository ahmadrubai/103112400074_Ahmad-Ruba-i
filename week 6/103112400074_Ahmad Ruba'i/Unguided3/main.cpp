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