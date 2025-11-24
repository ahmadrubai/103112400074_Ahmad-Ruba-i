#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    cout << "Alternatif 2 (Head Bergerak dan Tail Bergerak)" << endl;
    cout << "-------------------------" << endl;
    cout << "H - T : Queue Info" << endl;
    cout << "-------------------------" << endl;

    Queue Q;
    createQueue(Q);
    printInfo(Q); 

    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    
    dequeue(Q);    printInfo(Q); 
    dequeue(Q);    printInfo(Q); 
    
    enqueue(Q, 4); printInfo(Q);
    
    dequeue(Q);    printInfo(Q); 
    dequeue(Q);    printInfo(Q); 

    return 0;
}