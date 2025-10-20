#include "Singlylist.h"

void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new Elmlist;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

void printInfo(List L) {
    address P = L.First;
    
    if (P == Nil) {
        cout << "List kosong" << endl;
    } else {
        while (P != Nil) {
            cout << P->info;
            P = P->next;
            
            if (P != Nil) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void deleteFirst(List &L, address &P) {
    P = L.First;
    L.First = P->next;
    P->next = Nil;
}

void deleteLast(List &L, address &P) {
    address Prec = Nil;
    P = L.First;

    while (P->next != Nil) {
        Prec = P;
        P = P->next;
    }

    if (Prec == Nil) { 
        L.First = Nil;
    } else {
        Prec->next = Nil;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    P = Prec->next;
    Prec->next = P->next;
    P->next = Nil;
}

int nbList(List L) {
    int hitung = 0;
    address P = L.First;
    
    while (P != Nil) {
        hitung++;
        P = P->next;
    }
    return hitung;
}

void deleteList(List &L) {
    address P;
    while (L.First != Nil) {
        deleteFirst(L, P);
        dealokasi(P);
    }
}

address FindElm(List L, infotype x) {
    address P = L.First;
    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}