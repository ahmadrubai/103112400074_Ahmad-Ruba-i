#include <iostream>
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
