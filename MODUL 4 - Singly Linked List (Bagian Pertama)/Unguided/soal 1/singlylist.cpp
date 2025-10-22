#include "Singlylist.h"
#include <iostream>
using namespace std;

// Membuat list kosong
void CreateList(List &L) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    L.First = Nil;
}

// Mengalokasikan node baru
address alokasi(infotype x) {
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan info = x dan next = Nil */
    address P = new ElmtList;
    if (P != Nil) {
        P->info = x;
        P->next = Nil;
    }
    return P;
}

// Menghapus node dari memori
void dealokasi(address &P) {
    /* I.S. P terdefinisi
       F.S. memori node dikembalikan ke sistem */
    delete P;
    P = Nil;
}

// Menampilkan isi list
void printInfo(List L) {
    /* I.S. list mungkin kosong
       F.S. jika tidak kosong, tampilkan semua info di list */
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

// Menyisipkan node di awal list
void insertFirst(List &L, address P) {
    /* I.S. list L mungkin kosong, P sudah dialokasikan
       F.S. menambahkan P di awal list */
    P->next = L.First;
    L.First = P;
}
