#ifndef LISTFILM_H
#define LISTFILM_H
#define Nil NULL 

#include <iostream>
using namespace std;

struct film {
    string judul;
    string genre;
    float rating;
};

typedef film dataFilm;
typedef struct node *address;

struct node {
    dataFilm isidata;
    address next;
};

struct linkedlist {
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string judul, string genre, float rating);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

void FindNodeByData(linkedlist List, string judul);
void FindNodeByAddress(linkedlist List, address node);
void FindNodeByRange(linkedlist List, float ratingAwal, float ratingAkhir);

#endif