#include <iostream>
#include "QueuePengiriman.h"

using namespace std;

bool isEmpty(QueueEkspedisi Q) {
    return Q.Head == -1 && Q.Tail == -1;
}
bool isFull(QueueEkspedisi Q) {
    return Q.Tail == MAX - 1;
}
void createQueue(QueueEkspedisi &Q) {
    Q.Head = -1;
    Q.Tail = -1;
}
void enqueue(QueueEkspedisi &Q, Paket data) {
    if (isFull(Q)) {
        cout << "Queue penuh!" << endl;
    } else {
        if (isEmpty(Q)) {
            Q.Head = 0;
        }
        Q.Tail++;
        Q.dataPaket[Q.Tail] = data;
    }
}
void dequeue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
    } else {
        for (int i = Q.Head; i < Q.Tail; i++) {
            Q.dataPaket[i] = Q.dataPaket[i + 1];
        }
        Q.Tail--;
        if (Q.Tail < Q.Head) {
            Q.Head = -1;
            Q.Tail = -1;
        }
    }
}
void view(QueueEkspedisi Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong." << endl;
    } else {
        cout << "----------------------------------------" << endl;
        for (int i = Q.Head; i <= Q.Tail; i++) {
            cout << "Posisi " << (i + 1) << ":" << endl;
            cout << "Kode Resi     : " << Q.dataPaket[i].KodeResi << endl;
            cout << "Nama Pengirim : " << Q.dataPaket[i].NamaPengirim << endl;
            cout << "Berat Barang  : " << Q.dataPaket[i].BeratBarang << " kg" << endl;
            cout << "Alamat Tujuan : " << Q.dataPaket[i].AlamatTujuan << endl;
            cout << "----------------------------------------" << endl;
        }
    }
}
