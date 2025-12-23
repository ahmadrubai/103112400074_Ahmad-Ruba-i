#include <iostream>
#include "mll.h"

using namespace std;

int main() {
    ListParent LP;
    createListParent(LP);

    adrParent P4 = alokasiNodeParent("G004", "Romance");
    insertFirstParent(LP, P4);
    insertLastChild(P4->childList, alokasiNodeChild("FR001", "Habibie & Ainun", 118, 2012, 7.6));
    insertLastChild(P4->childList, alokasiNodeChild("FR002", "Dilan 1990", 110, 2018, 6.6));

    adrParent P3 = alokasiNodeParent("G003", "Horror");
    insertFirstParent(LP, P3);
    insertLastChild(P3->childList, alokasiNodeChild("FH001", "Pengabdi Setan", 107, 2017, 8.4));

    adrParent P2 = alokasiNodeParent("G002", "Comedy");
    insertFirstParent(LP, P2);
    insertLastChild(P2->childList, alokasiNodeChild("FC001", "Agak Laen", 119, 2024, 8.0));
    insertLastChild(P2->childList, alokasiNodeChild("FC002", "My Stupid Boss", 108, 2016, 6.8));

    adrParent P1 = alokasiNodeParent("G001", "Action");
    insertFirstParent(LP, P1);
    insertLastChild(P1->childList, alokasiNodeChild("FA001", "The Raid", 101, 2011, 7.6));

    printStrukturMLL(LP);
    cout << endl;

    searchFilmByRatingRange(LP, 8.0, 8.5);
    cout << endl;

    adrParent precNode = findParent(LP, "G001");
    if (precNode != NULL) {
        deleteAfterParent(LP, precNode);
    }

    printStrukturMLL(LP);

    return 0;
}