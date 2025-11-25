#include <iostream>
#include "StackMahasiswa.h"

using namespace std;

float hitungNA(float tugas, float uts, float uas) {
    return (0.2 * tugas) + (0.4 * uts) + (0.4 * uas);
}

bool isEmpty(StackMahasiswa S) {
    return S.Top == -1;
}

bool isFull(StackMahasiswa S) {
    return S.Top == MAX - 1;
}

void createStack(StackMahasiswa &S) {
    S.Top = -1;
}

void Push(StackMahasiswa &S, Mahasiswa data) {
    if (isFull(S)) {
        cout << "Stack Penuh!" << endl;
    } else {
        S.Top++;
        S.dataMahasiswa[S.Top] = data;
    }
}

void Pop(StackMahasiswa &S) {
    if (isEmpty(S)) {
        cout << "Stack Kosong!" << endl;
    } else {
        S.Top--;
    }
}

void View(StackMahasiswa S) {
    if (isEmpty(S)) {
        cout << "Stack Kosong." << endl;
    } else {
        cout << "--------------------------------------------------" << endl;
        for (int i = S.Top; i >= 0; i--) {
            float na = hitungNA(S.dataMahasiswa[i].NilaiTugas, S.dataMahasiswa[i].NilaiUTS, S.dataMahasiswa[i].NilaiUAS);
            cout << "Posisi " << (i + 1) << ":" << endl;
            cout << "Nama       : " << S.dataMahasiswa[i].Nama << endl;
            cout << "NIM        : " << S.dataMahasiswa[i].NIM << endl;
            cout << "--------------------------------------------------" << endl;
        }
    }
}

void Update(StackMahasiswa &S, int posisi, Mahasiswa data) {
    int index = posisi - 1;
    if (index >= 0 && index <= S.Top) {
        S.dataMahasiswa[index] = data;
        cout << "Data pada posisi " << posisi << " berhasil diupdate." << endl;
    } else {
        cout << "Posisi tidak valid atau data tidak ada." << endl;
    }
}

void SearchNilaiAkhir(StackMahasiswa S, float NilaiAkhirMin, float NilaiAkhirMax) {
    cout << "\n>>> Hasil Searching (Range " << NilaiAkhirMin << " - " << NilaiAkhirMax << ") <<<" << endl;
    bool found = false;
    for (int i = S.Top; i >= 0; i--) {
        float na = hitungNA(S.dataMahasiswa[i].NilaiTugas, S.dataMahasiswa[i].NilaiUTS, S.dataMahasiswa[i].NilaiUAS);
        if (na >= NilaiAkhirMin && na <= NilaiAkhirMax) {
            cout << "Ditemukan: " << S.dataMahasiswa[i].Nama 
                 << " (Posisi " << (i + 1) << ") - NA: " << na << endl;
            found = true;
        }
    }
    if (!found) cout << "Data tidak ditemukan dalam rentang tersebut." << endl;
}

void MaxNilaiAkhir(StackMahasiswa S) {
    if (isEmpty(S)) return;
    
    float maxVal = -1;
    int maxIdx = -1;
    
    for (int i = 0; i <= S.Top; i++) {
        float na = hitungNA(S.dataMahasiswa[i].NilaiTugas, S.dataMahasiswa[i].NilaiUTS, S.dataMahasiswa[i].NilaiUAS);
        if (na > maxVal) {
            maxVal = na;
            maxIdx = i;
        }
    }
    
    cout << "\n>>> Mahasiswa dengan Nilai Akhir Terbesar <<<" << endl;
    cout << "Nama   : " << S.dataMahasiswa[maxIdx].Nama << endl;
    cout << "Nilai  : " << maxVal << endl;
    cout << "Posisi : " << (maxIdx + 1) << endl;
}