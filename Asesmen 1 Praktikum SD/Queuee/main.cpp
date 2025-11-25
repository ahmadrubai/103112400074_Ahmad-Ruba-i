#include <iostream>
#include "QueuePengiriman.h"

using namespace std;
int main() {
    QueueEkspedisi Q;

    createQueue(Q);

    Paket p1 = {"KodeResi:123456", "Hutao", 14, "Sumeru"};
    enqueue(Q, p1);

    Paket p2 = {"KodeResi:234567", "Ayaka", 10, "Fontaine"};
    enqueue(Q, p2);

    Paket p3 = {"KodeResi:345678", "Bennet", 7, "Natlan"};
    enqueue(Q, p3);

    Paket p4 = {"KodeResi:456789", "Furinna", 16, "Liyue"};
    enqueue(Q, p4);

    Paket p5 = {"KodeResi:567890", "Nefer", 6, "Inazuma"};
    enqueue(Q, p5);

    cout << "\nData dalam Queue " << endl;
    view(Q);
    cout << "\nMelakukan dequeue 1x" << endl;
    dequeue(Q);
    cout << "\nData dalam Queue setelah dequeue" << endl;
    view(Q);
    return 0;
}