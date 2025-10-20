#include <iostream>
#include "Singlylist.h"
#include <stdlib.h> 

using namespace std; 

int main() {
    List L;
    address P_temp;
    
    createList(L);

    P_temp = alokasi(2);
    insertFirst(L, P_temp);
    P_temp = alokasi(0);
    insertFirst(L, P_temp);
    P_temp = alokasi(8);
    insertFirst(L, P_temp);
    P_temp = alokasi(12);
    insertFirst(L, P_temp);
    P_temp = alokasi(9);
    insertFirst(L, P_temp);
    
    address P_hapus;
    
    deleteFirst(L, P_hapus);
    dealokasi(P_hapus);
    deleteLast(L, P_hapus);
    dealokasi(P_hapus);

    address Prec = FindElm(L, 12);
    if (Prec != Nil && Prec->next != Nil) {
        deleteAfter(L, Prec, P_hapus);
        dealokasi(P_hapus);
    }

    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;
    deleteList(L);
    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}