#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <string>
#define Nil NULL
using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int   thnBuat;
};

typedef kendaraan infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address &P, address Prec);
address findElm(List L, infotype x);
void printInfo(List L);

#endif
