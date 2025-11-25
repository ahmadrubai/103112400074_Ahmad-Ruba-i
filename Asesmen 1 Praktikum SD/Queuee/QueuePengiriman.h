#ifndef QueuePengiriman_H
#define QueuePengiriman_H

#include <string>
using namespace std;

struct Paket {
   string KodeResi;
   string NamaPengirim;
   int BeratBarang;
   string AlamatTujuan;
};

const int MAX = 5;

struct QueueEkspedisi {
    Paket dataPaket[MAX];
    int Head;
    int Tail;
};

bool isEmpty(QueueEkspedisi Q);
bool isFull(QueueEkspedisi Q);
void createQueue(QueueEkspedisi &Q);
void enqueue(QueueEkspedisi &Q, Paket data);
void dequeue(QueueEkspedisi &Q);
void view(QueueEkspedisi Q);
#endif