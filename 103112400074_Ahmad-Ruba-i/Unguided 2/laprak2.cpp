#include <iostream>
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