#include "Singlylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    address F1, F2, F3, F4, F5 = Nil;

    CreateList(L);

    F1 = alokasi(2);
    insertFirst(L, F1);

    F2 = alokasi(0);
    insertFirst(L, F2);

    F3 = alokasi(8);
    insertFirst(L, F3);

    F4 = alokasi(12);
    insertFirst(L, F4);

    F5 = alokasi(9);
    insertFirst(L, F5);

    // Sekarang list = 9 -> 12 -> 8 -> 0 -> 2
    deleteFirst(L);             // hapus 9
    deleteLast(L);              // hapus 2
    deleteAfter(L, L.First);    // hapus setelah 12, yaitu 8

    printInfo(L);               // hasil: 12 0
    cout << "Jumlah node : " << nbList(L) << endl;

    deleteList(L);              // hapus semua node
    cout << endl << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
