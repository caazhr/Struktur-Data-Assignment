#include "listFilm.h"
#include <iostream>
using namespace std;

int main() {
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataFilm dtFilm;

    nodeA = alokasi("Venom: Let There Be Carnage", "Action", 8.3);
    nodeB = alokasi("The Call", "Thriller", 9.6);
    nodeC = alokasi("Exhuma", "Thriller", 8.9);
    nodeD = alokasi("Train to Busan", "Thriller", 9.0);
    nodeE = alokasi("The Chronicles of Narnia", "Fiksi fantasi", 9.8);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- DAFTAR FILM SETELAH INSERT ---" << endl;
    printList(List);
    cout << "Jumlah film: " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "--- DAFTAR FILM SETELAH UPDATE ---" << endl;
    printList(List);
    cout << "Jumlah film: " << nbList(List) << endl;
    cout << endl;

    FindNodeByData(List, "Exhuma");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 7.5, 9.0);

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- DAFTAR FILM SETELAH DELETE ---" << endl;
    printList(List);
    cout << "Jumlah film: " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- DAFTAR FILM SETELAH HAPUS LIST ---" << endl;
    printList(List);
    cout << "Jumlah film: " << nbList(List) << endl;
    cout << endl;

    return 0;
}