#include "Singlylist.h"
#include <iostream>
using namespace std;

void CreateList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmtList;
    if (P != Nil) {
        P->info = x;
        P->next = Nil;
    }
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    if (L.First == Nil) {
        cout << "List kosong." << endl;
    } else {
        address P = L.First;
        while (P != Nil) {
            cout << P->info << " ";
            P = P->next;
        }
        cout << endl;
    }
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

void deleteFirst(List &L) {
    if (L.First != Nil) {
        address P = L.First;
        L.First = L.First->next;
        dealokasi(P);
    }
}
void deleteLast(List &L) {
    if (L.First != Nil) {
        if (L.First->next == Nil) {
            dealokasi(L.First);
            L.First = Nil;
        } else {
            address prec = Nil;
            address last = L.First;
            while (last->next != Nil) {
                prec = last;
                last = last->next;
            }
            prec->next = Nil;
            dealokasi(last);
        }
    }
}

void deleteAfter(List &L, address Prec) {
    if (Prec != Nil && Prec->next != Nil) {
        address P = Prec->next;
        Prec->next = P->next;
        dealokasi(P);
    }
}

int nbList(List L) {
    int count = 0;
    address P = L.First;
    while (P != Nil) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteList(List &L) {
    address P = L.First;
    while (P != Nil) {
        address temp = P;
        P = P->next;
        dealokasi(temp);
    }
    L.First = Nil;
}
