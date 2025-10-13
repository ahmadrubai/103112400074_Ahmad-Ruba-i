#include <iostream>
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
