#include "MultiLL.h"

int main() {
    listParent LP;
    createListParent(LP);

    NodeParent P1 = allocNodeParent("G001", "Aves");
    insertLastParent(LP, P1);

    NodeParent P2 = allocNodeParent("G002", "Mamalia");
    insertLastParent(LP, P2);

    NodeParent P3 = allocNodeParent("G003", "Pisces");
    insertLastParent(LP, P3);

    NodeParent P4 = allocNodeParent("G004", "Amfibi");
    insertLastParent(LP, P4);

    NodeParent P5 = allocNodeParent("G005", "Reptil");
    insertLastParent(LP, P5);

    insertLastChild(P1->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(P1->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2));

    insertLastChild(P2->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200));
    insertLastChild(P2->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160));
    insertLastChild(P2->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4));

    insertLastChild(P4->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));

    searchHewanByEkor(LP, false);

    return 0;
}