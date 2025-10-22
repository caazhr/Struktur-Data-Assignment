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

    printInfo(L);

    return 0;
}
