#include <iostream>
#include "StackMahasiswa.h"

using namespace std;

int main() {
    StackMahasiswa StackMHS;
    
    createStack(StackMHS);

    Mahasiswa m1 = {"Venti", "11111", 75.7, 82.1, 65.5};
    Push(StackMHS, m1);

    Mahasiswa m2 = {"Xiao", "22222", 87.4, 88.9, 81.9};
    Push(StackMHS, m2);

    Mahasiswa m3 = {"Kazuha", "33333", 92.3, 88.8, 82.4};
    Push(StackMHS, m3);

    Mahasiswa m4 = {"Wanderer", "44444", 95.5, 85.5, 90.5};
    Push(StackMHS, m4);

    Mahasiswa m5 = {"Lynette", "55555", 77.7, 65.4, 79.9};
    Push(StackMHS, m5);

    Mahasiswa m6 = {"Chasca", "66666", 99.9, 93.6, 87.3};
    Push(StackMHS, m6);

    cout << "stack awal" << endl;
    View(StackMHS);

    cout << "\npop 1x" << endl;
    Pop(StackMHS);

    cout << "\ndata setelah pop" << endl;
    View(StackMHS);

    cout << "\nupdate data posisi 3" << endl;
    Mahasiswa mUpdate = {"Heizou", "77777", 99.9, 88.8, 77.7};
    Update(StackMHS, 3, mUpdate);

    cout << "\nstack setalah update" << endl;
    View(StackMHS);

    SearchNilaiAkhir(StackMHS, 85.5, 95.5);

    MaxNilaiAkhir(StackMHS);

    return 0;
}