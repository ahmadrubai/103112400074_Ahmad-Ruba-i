#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    cout << "Alternatif 3 (Head dan Tail Berputar)" << endl;
    cout << "-------------------------" << endl;
    cout << "H - T : Queue Info" << endl;
    cout << "-------------------------" << endl;

    Queue Q;
    createQueue(Q);
    
    enqueue(Q, 10); printInfo(Q);
    enqueue(Q, 20); printInfo(Q);
    enqueue(Q, 30); printInfo(Q);
    enqueue(Q, 40); printInfo(Q);
    enqueue(Q, 50); printInfo(Q); 
    
    cout << "--- Dequeue 2 elemen ---" << endl;
    dequeue(Q);     printInfo(Q);
    dequeue(Q);     printInfo(Q); 
    
    cout << "--- Enqueue lagi (Circular) ---" << endl;
    enqueue(Q, 60); printInfo(Q); 
    enqueue(Q, 70); printInfo(Q); 

    return 0;
}