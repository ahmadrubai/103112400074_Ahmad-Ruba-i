#include "mll.h"

void createListParent(ListParent &L) {
    L.first = NULL;
    L.last = NULL;
}

void createListChild(ListChild &L) {
    L.first = NULL;
    L.last = NULL;
}

adrParent alokasiNodeParent(string id, string nama) {
    adrParent P = new NodeParent;
    P->IDGenre = id;
    P->namaGenre = nama;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->childList);
    return P;
}

adrChild alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating) {
    adrChild C = new NodeChild;
    C->IDFilm = id;
    C->judulFilm = judul;
    C->durasiFilm = durasi;
    C->tahunTayang = tahun;
    C->ratingFilm = rating;
    C->next = NULL;
    C->prev = NULL;
    return C;
}

void dealokasiNodeParent(adrParent P) {
    delete P;
}

void dealokasiNodeChild(adrChild C) {
    delete C;
}

void insertFirstParent(ListParent &L, adrParent P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastChild(ListChild &L, adrChild C) {
    if (L.first == NULL) {
        L.first = C;
        L.last = C;
    } else {
        C->prev = L.last;
        L.last->next = C;
        L.last = C;
    }
}

void deleteAfterParent(ListParent &L, adrParent prec) {
    if (prec != NULL && prec->next != NULL) {
        adrParent del = prec->next;
        hapusListChild(del);
        
        prec->next = del->next;
        if (del->next != NULL) {
            del->next->prev = prec;
        } else {
            L.last = prec;
        }
        
        del->next = NULL;
        del->prev = NULL;
        dealokasiNodeParent(del);
    }
}

void hapusListChild(adrParent P) {
    adrChild C = P->childList.first;
    adrChild temp;
    while (C != NULL) {
        temp = C;
        C = C->next;
        temp->next = NULL;
        temp->prev = NULL;
        dealokasiNodeChild(temp);
    }
    P->childList.first = NULL;
    P->childList.last = NULL;
}

void searchFilmByRatingRange(ListParent L, float minRate, float maxRate) {
    adrParent P = L.first;
    bool foundAny = false;
    int idxParent = 1;

    while (P != NULL) {
        adrChild C = P->childList.first;
        int idxChild = 1;
        while (C != NULL) {
            if (C->ratingFilm >= minRate && C->ratingFilm <= maxRate) {
                foundAny = true;
                cout << "Data Film ditemukan pada list child dari node parent " << P->namaGenre << " pada posisi ke-" << idxChild << "!" << endl;
                cout << "   Data Film " << endl;
                cout << "Judul Film : " << C->judulFilm << endl;
                cout << "Posisi dalam list child : posisi ke-" << idxChild << endl;
                cout << "ID Film : " << C->IDFilm << endl;
                cout << "Durasi Film : " << C->durasiFilm << " menit" << endl;
                cout << "Tahun Tayang : " << C->tahunTayang << endl;
                cout << "Rating Film : " << C->ratingFilm << endl;
                cout << endl;
                cout << "   Data Genre " << endl;
                cout << "ID Genre : " << P->IDGenre << endl;
                cout << "Posisi dalam list parent : posisi ke-" << idxParent << endl;
                cout << "Nama Genre : " << P->namaGenre << endl;
                cout << endl;
            }
            C = C->next;
            idxChild++;
        }
        P = P->next;
        idxParent++;
    }
    if (!foundAny) {
        cout << "Tidak ada film dalam rentang rating tersebut." << endl;
    }
}

void printStrukturMLL(ListParent L) {
    adrParent P = L.first;
    int i = 1;
    while (P != NULL) {
        cout << "--Parent " << i << "--" << endl;
        cout << "ID Genre : " << P->IDGenre << endl;
        cout << "Nama Genre : " << P->namaGenre << endl;
        
        adrChild C = P->childList.first;
        int j = 1;
        while (C != NULL) {
            cout << "  - Child " << j << " :" << endl;
            cout << "      ID Film : " << C->IDFilm << endl;
            cout << "      Judul Film : " << C->judulFilm << endl;
            cout << "      Durasi Film : " << C->durasiFilm << " menit" << endl;
            cout << "      Tahun Tayang : " << C->tahunTayang << endl;
            cout << "      Rating Film : " << C->ratingFilm << endl;
            C = C->next;
            j++;
        }
        cout << endl;
        P = P->next;
        i++;
    }
}

adrParent findParent(ListParent L, string idGenre) {
    adrParent P = L.first;
    while (P != NULL) {
        if (P->IDGenre == idGenre) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}