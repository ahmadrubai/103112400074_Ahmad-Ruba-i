#ifndef StackMahasiswa_H
#define StackMAhasiswa_H

#include <string>
using namespace std;

struct Mahasiswa {
    string Nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
};

const int MAX = 6;

struct StackMahasiswa {
    Mahasiswa dataMahasiswa[MAX];
    int Top;
};

bool isEmpty(StackMahasiswa S);
bool isFull(StackMahasiswa S);
void createStack(StackMahasiswa &S);
void Push(StackMahasiswa &S, Mahasiswa data);
void Pop(StackMahasiswa &S);
void View(StackMahasiswa S);
void Update(StackMahasiswa &S, int posisi, Mahasiswa data);
void SearchNilaiAkhir(StackMahasiswa S, float NilaiAkhirMin, float NilaiAkhirMax);
void MaxNilaiAkhir(StackMahasiswa S);

#endif