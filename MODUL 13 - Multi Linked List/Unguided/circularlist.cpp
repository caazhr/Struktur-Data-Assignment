#include "circularlist.h"

void CreateList(List &L) {
    L.first = NIL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NIL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NIL;
}

static address lastNode(List L) {
    if (L.first == NIL) return NIL;
    address Q = L.first;
    while (Q->next != L.first) {
        Q = Q->next;
    }
    return Q;
}

void insertFirst(List &L, address P) {
    if (P == NIL) return;

    if (L.first == NIL) {
        L.first = P;
        P->next = P;
    } else {
        address Last = lastNode(L);
        P->next = L.first;
        L.first = P;
        Last->next = L.first;
    }
}

void insertLast(List &L, address P) {
    if (P == NIL) return;

    if (L.first == NIL) {
        insertFirst(L, P);
    } else {
        address Last = lastNode(L);
        Last->next = P;
        P->next = L.first;
    }
}

void insertAfter(List &L, address Prec, address P) {
    if (L.first == NIL || Prec == NIL || P == NIL) return;

    P->next = Prec->next;
    Prec->next = P;
}

void deleteFirst(List &L, address &P) {
    P = NIL;
    if (L.first == NIL) return;

    if (L.first->next == L.first) {
        P = L.first;
        L.first = NIL;
        P->next = NIL;
        return;
    }

    address Last = lastNode(L);
    P = L.first;
    L.first = L.first->next;
    Last->next = L.first;
    P->next = NIL;
}

void deleteLast(List &L, address &P) {
    P = NIL;
    if (L.first == NIL) return;

    if (L.first->next == L.first) {
        P = L.first;
        L.first = NIL;
        P->next = NIL;
        return;
    }

    address Prec = L.first;
    while (Prec->next->next != L.first) { 
        Prec = Prec->next;
    }

    P = Prec->next;      
    Prec->next = L.first; 
    P->next = NIL;
}

void deleteAfter(List &L, address Prec, address &P) {
    P = NIL;
    if (L.first == NIL || Prec == NIL) return;

    address target = Prec->next;
    if (target == NIL) return;

    if (target == L.first) {
        deleteFirst(L, P);
        return;
    }

    P = target;
    Prec->next = target->next;
    P->next = NIL;
}

address findElm(List L, infotype x) {
    if (L.first == NIL) return NIL;

    address P = L.first;
    do {
        if (P->info.nim == x.nim) return P;
        P = P->next;
    } while (P != L.first);

    return NIL;
}

void printInfo(List L) {
    if (L.first == NIL) {
        cout << "List kosong" << endl;
        return;
    }

    address P = L.first;
    do {
        cout << "Nama : " << P->info.nama << "\n";
        cout << "NIM  : " << P->info.nim << "\n";
        cout << "L/P  : " << P->info.jenis_kelamin << "\n";
        cout << "IPK  : " << P->info.ipk << "\n\n";
        P = P->next;
    } while (P != L.first);
}
