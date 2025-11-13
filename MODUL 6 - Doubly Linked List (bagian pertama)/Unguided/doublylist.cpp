#include <iostream>
#include "Doublylist.h"
using namespace std;

void createList(List &L) {
    L.first = Nil;
    L.last  = Nil;
}

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    P->prev = Nil;

    if (L.first != Nil) {
        L.first->prev = P;
    } else {
        L.last = P;
    }
    L.first = P;
}

void deleteFirst(List &L, address &P) {
    if (L.first == Nil) {
        P = Nil;
        return;
    }

    P = L.first;
    L.first = P->next;

    if (L.first != Nil) {
        L.first->prev = Nil;
    } else {
        L.last = Nil;
    }

    P->next = Nil;
    P->prev = Nil;
}

void deleteLast(List &L, address &P) {
    if (L.last == Nil) {
        P = Nil;
        return;
    }

    P = L.last;
    L.last = P->prev;

    if (L.last != Nil) {
        L.last->next = Nil;
    } else {
        L.first = Nil;
    }

    P->next = Nil;
    P->prev = Nil;
}

void deleteAfter(List &L, address &P, address Prec) {
    if (Prec == Nil || Prec->next == Nil) {
        P = Nil;       
        return;
    }

    P = Prec->next;          
    Prec->next = P->next;

    if (P->next != Nil) {
        P->next->prev = Prec;
    } else {
         L.last = Prec;
    }

    P->next = Nil;
    P->prev = Nil;
}

address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil && P->info.nopol != x.nopol) {
        P = P->next;
    }
    return P;   
}

void printInfo(List L) {
    address P = L.first;

    cout << endl;
    cout << "DATA LIST 1" << endl << endl;

    while (P != Nil) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
        P = P->next;
    }
}
