#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>

using namespace std;

struct NodeChild;
struct NodeParent;

typedef NodeParent* adrParent;
typedef NodeChild* adrChild;

struct NodeChild {
    string IDFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
    adrChild next;
    adrChild prev;
};

struct ListChild {
    adrChild first;
    adrChild last;
};

struct NodeParent {
    string IDGenre;
    string namaGenre;
    ListChild childList;
    adrParent next;
    adrParent prev;
};

struct ListParent {
    adrParent first;
    adrParent last;
};

void createListParent(ListParent &L);
void createListChild(ListChild &L);
adrParent alokasiNodeParent(string id, string nama);
adrChild alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating);
void dealokasiNodeParent(adrParent P);
void dealokasiNodeChild(adrChild C);
void insertFirstParent(ListParent &L, adrParent P);
void insertLastChild(ListChild &L, adrChild C);
void deleteAfterParent(ListParent &L, adrParent prec);
void hapusListChild(adrParent P);
void searchFilmByRatingRange(ListParent L, float minRate, float maxRate);
void printStrukturMLL(ListParent L);
adrParent findParent(ListParent L, string idGenre);

#endif