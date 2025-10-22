
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

// Deklarasi tipe data sesuai soal
typedef int infotype;          // tipe data yang disimpan
typedef struct ElmtList *address; // pointer ke node

// Struktur node (ElmtList)
struct ElmtList {
    infotype info;  // data
    address next;   // pointer ke node berikutnya
};

// Struktur List (menyimpan pointer pertama)
struct List {
    address First;
};

// Deklarasi fungsi dan prosedur
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif
