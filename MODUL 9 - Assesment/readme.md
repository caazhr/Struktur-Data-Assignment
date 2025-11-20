# <h1 align="center">Laporan Assesment</h1>
<p align="center">Neisya Azzahra Rasin</p>

### 1. 

SLLInventory.h
```C++
#ifndef SLLINVENTORY_H
#define SLLINVENTORY_H

#include <string>
using namespace std;

struct Product {
    string Nama;
    string SKU;
    int Jumlah;
    float HargaSatuan;
    float DiskonPersen;
};

struct Node {
    Product info;
    Node* next;
};

struct List {
    Node* head;
};
bool isEmpty(List L);
void createList(List &L);
Node* allocate(Product P);
void deallocate(Node* p);
void insertFirst(List &L, Product P);
void insertLast(List &L, Product P);
void insertAfter(List &L, Node* Q, Product P);
void deleteFirst(List &L, Product &P);
void deleteLast(List &L, Product &P);
void deleteAfter(List &L, Node* Q, Product &P);
void updateAtPosition(List &L, int pos, Product dataBaru);
void viewList(List L);
void searchByFinalPriceRange(List L, float minPrice, float maxPrice);
void MaxHargaAkhir(List L);

#endif

```
SLLInventory.cpp
```C++
#include "SLLInventory.h"
#include <iostream>
using namespace std;

bool isEmpty(List L) {
    return L.head == NULL;
}

void createList(List &L) {
    L.head = NULL;
}

Node* allocate(Product P) {
    Node* p = new Node;
    p->info = P;
    p->next = NULL;
    return p;
}

void deallocate(Node* p) {
    delete p;
}

void insertFirst(List &L, Product P) {
    Node* p = allocate(P);
    p->next = L.head;
    L.head = p;
}

void insertLast(List &L, Product P) {
    Node* p = allocate(P);
    if (isEmpty(L)) {
        L.head = p;
    } else {
        Node* q = L.head;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
    }
}

void insertAfter(List &L, Node* Q, Product P) {
    if (Q != NULL) {
        Node* p = allocate(P);
        p->next = Q->next;
        Q->next = p;
    }
}

void deleteFirst(List &L, Product &P) {
    if (!isEmpty(L)) {
        Node* p = L.head;
        P = p->info;
        L.head = p->next;
        deallocate(p);
    }
}

void deleteLast(List &L, Product &P) {
    if (!isEmpty(L)) {
        if (L.head->next == NULL) {
            deleteFirst(L, P);
        } else {
            Node* q = L.head;
            while (q->next->next != NULL) {
                q = q->next;
            }
            Node* p = q->next;
            P = p->info;
            q->next = NULL;
            deallocate(p);
        }
    }
}

void deleteAfter (List &L, Node* Q, Product &P) {
    if (Q != NULL && Q->next != NULL) {
        Node* p = Q->next;
        P = p->info;
        Q->next = p->next;
        deallocate(p);
    }
}

void updateAtPosition(List &L, int pos, Product dataBaru){
    Node* p = L.head;
    int i = 1;
    while(p != NULL && i < pos){
        p = p->next;
        i++;
    }
    if(p != NULL){
        p->info = dataBaru;
    }
}

float hargaAkhir(Product P){
    return P.HargaSatuan * (1 - P.DiskonPersen / 100);
}

void viewList(List L){
    Node* p = L.head;
    int i = 1;

    while(p != NULL){
        cout << "Posisi: " << i << endl;
        cout << "Nama: " << p->info.Nama << endl;
        cout << "SKU: " << p->info.SKU << endl;
        cout << "Jumlah: " << p->info.Jumlah << endl;
        cout << "Harga Satuan: " << p->info.HargaSatuan << endl;
        cout << "Diskon: " << p->info.DiskonPersen << "%" << endl;
        cout << "Harga Akhir: " << hargaAkhir(p->info) << endl;
          cout << "------------------------\n";

        p = p->next;
        i++;
    }
}

void searchByFinalPriceRange(List L, float minPrice, float maxPrice){
    Node* p = L.head;
    int pos = 1;
    bool found = false;

    while(p != NULL){
        float h = hargaAkhir(p->info);
        if(h >= minPrice && h <= maxPrice){
            found = true;
            cout << "Ditemukan pada posisi " << pos << endl;
            cout << p->info.Nama << " - Harga Akhir: " << h << endl;
        }
        p = p->next;
        pos++;
    }

    if(!found){
        cout << "Tidak ada produk dalam range harga.\n";
    }
}

void MaxHargaAkhir(List L){
    if(isEmpty(L)) return;

    float maxH = hargaAkhir(L.head->info);
    Node* p = L.head->next;

    while(p != NULL){
        float h = hargaAkhir(p->info);
        if(h > maxH) maxH = h;
        p = p->next;
    }

    cout << "\n--- Produk Dengan Harga Akhir Tertinggi ---\n";
    p = L.head;
    int pos = 1;

    while(p != NULL){
        if(hargaAkhir(p->info) == maxH){
            cout << "Posisi: " << pos << endl;
            cout << "Nama: " << p->info.Nama << endl;
            cout << "Harga Akhir: " << maxH << endl;
            cout << "------------------------\n";
        }
        p = p->next;
        pos++;
    }
}
```
main.cpp
```C++
#include "SLLInventory.h"
#include <iostream>
using namespace std;

int main(){
    List L;
    createList(L);


    Product P1 = {"Pulpen", "A001", 20, 2500, 0};
    Product P2 = {"Buku Tulis", "A002", 15, 5000, 10};
    Product P3 = {"Penghapus", "A003", 30, 1500, 0};

    insertLast(L, P1);
    insertLast(L, P2);
    insertLast(L, P3);

    cout << "\n--- List Awal ---\n";
    viewList(L);

    Product removed;
    deleteFirst(L, removed);
    cout << "\nDeleteFirst: " << removed.Nama << " dihapus.\n";

    cout << "\n--- List Setelah DeleteFirst ---\n";
    viewList(L);
   
    Product Baru = {"Stabilo", "A010", 40, 9000, 5};
    updateAtPosition(L, 2, Baru);

    cout << "\n--- Setelah Update Posisi Ke-2 ---\n";
    viewList(L);
  
    cout << "\n--- Searching Harga 2000 - 7000 ---\n";
    searchByFinalPriceRange(L, 2000, 7000);

    MaxHargaAkhir(L);

    return 0;
}
```
Output 
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/11a7b547-5230-49d6-a883-9167aa7961d5" />
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/222ab834-ca52-4b01-8e4d-9910006e1779" />

### 2. 

DLLPlaylist.h
```C++
#ifndef DLLPLAYLIST_H
#define DLLPLAYLIST_H

#include <string>
using namespace std;

struct Song {
    string Title;
    string Artist;
    int DurationSec;
    int PlayCount;
    float Rating;
};

struct Node {
    Song info;
    Node* prev;
    Node* next;
};

struct List {
    Node* head;
    Node* tail;
};

bool isEmpty(List L);
void createList(List &L);
Node* allocate(Song S);
void deallocate(Node* P);
void insertFirst(List &L, Song S);
void insertLast(List &L, Song S);
void insertAfter(List &L, Node* Q, Song S);
void insertBefore(List &L, Node* Q, Song S);
void deleteFirst(List &L, Song &S);
void deleteLast(List &L, Song &S);
void deleteAfter(List &L, Node* Q, Song &S);
void deleteBefore(List &L, Node* Q, Song &S);
void updateAtPosition(List &L, int pos, Song S);
void viewList(List L);
void searchByPopularityRange(List L, float minScore, float maxScore);
float getPopularity(Song S);

#endif
```

DLLPlaylist.cpp
```C++
#include "DLLPlaylist.h"
#include <iostream>
using namespace std;

bool isEmpty(List L){
    return (L.head == NULL);
}

void createList(List &L){
    L.head = NULL;
    L.tail = NULL;
}

Node* allocate(Song S){
    Node* P = new Node;
    P->info = S;
    P->prev = NULL;
    P->next = NULL;
    return P;
}

void deallocate(Node* P){
    delete P;
}

void insertFirst(List &L, Song S){
    Node* P = allocate(S);
    if(isEmpty(L)){
        L.head = L.tail = P;
    } else {
        P->next = L.head;
        L.head->prev = P;
        L.head = P;
    }
}

void insertLast(List &L, Song S){
    Node* P = allocate(S);
    if(isEmpty(L)){
        L.head = L.tail = P;
    } else {
        L.tail->next = P;
        P->prev = L.tail;
        L.tail = P;
    }
}

void insertAfter(List &L, Node* Q, Song S){
    if(Q != NULL){
        if(Q == L.tail){
            insertLast(L, S);
        } else {
            Node* P = allocate(S);
            P->next = Q->next;
            P->prev = Q;
            Q->next->prev = P;
            Q->next = P;
        }
    }
}

void insertBefore(List &L, Node* Q, Song S){
    if(Q != NULL){
        if(Q == L.head){
            insertFirst(L, S);
        } else {
            Node* P = allocate(S);
            P->next = Q;
            P->prev = Q->prev;
            Q->prev->next = P;
            Q->prev = P;
        }
    }
}

void deleteFirst(List &L, Song &S){
    if(!isEmpty(L)){
        Node* P = L.head;
        S = P->info;

        if(L.head == L.tail){
            L.head = L.tail = NULL;
        } else {
            L.head = P->next;
            L.head->prev = NULL;
        }
        deallocate(P);
    }
}

void deleteLast(List &L, Song &S){
    if(!isEmpty(L)){
        Node* P = L.tail;
        S = P->info;

        if(L.head == L.tail){
            L.head = L.tail = NULL;
        } else {
            L.tail = P->prev;
            L.tail->next = NULL;
        }
        deallocate(P);
    }
}

void deleteAfter(List &L, Node* Q, Song &S){
    if(Q != NULL && Q->next != NULL){
        Node* P = Q->next;
        S = P->info;

        Q->next = P->next;
        if(P->next != NULL){
            P->next->prev = Q;
        } else {
            L.tail = Q;
        }
        deallocate(P);
    }
}

void deleteBefore(List &L, Node* Q, Song &S){
    if(Q != NULL && Q->prev != NULL){
        Node* P = Q->prev;
        S = P->info;

        Q->prev = P->prev;
        if(P->prev != NULL){
            P->prev->next = Q;
        } else {
            L.head = Q;
        }
        deallocate(P);
    }
}

void updateAtPosition(List &L, int pos, Song S){
    Node* P = L.head;
    int i = 1;

    while(P != NULL && i < pos){
        P = P->next;
        i++;
    }

    if(P != NULL){
        P->info = S;
    }
}

float getPopularity(Song S){
    return 0.8 * S.PlayCount + 20 * S.Rating;
}

void viewList(List L){
    Node* P = L.head;
    int pos = 1;

    while(P != NULL){
        cout << "Posisi: " << pos << endl;
        cout << "Title: " << P->info.Title << endl;
        cout << "Artist: " << P->info.Artist << endl;
        cout << "Duration: " << P->info.DurationSec << " sec\n";
        cout << "PlayCount: " << P->info.PlayCount << endl;
        cout << "Rating: " << P->info.Rating << endl;
        cout << "PopularityScore: " << getPopularity(P->info) << endl;
        cout << "------------------------\n";

        P = P->next;
        pos++;
    }
}

void searchByPopularityRange(List L, float minScore, float maxScore){
    Node* P = L.head;
    int pos = 1;
    bool found = false;

    while(P != NULL){
        float score = getPopularity(P->info);
        if(score >= minScore && score <= maxScore){
            found = true;

            cout << "Posisi: " << pos << endl;
            cout << P->info.Title << " - Popularity: " << score << endl;
        }
        P = P->next;
        pos++;
    }

    if(!found){
        cout << "Tidak ada lagu dalam range Popularity tersebut.\n";
    }
}
```
main.cpp
```C++
#include "DLLPlaylist.h"
#include <iostream>
using namespace std;

int main(){
    List L;
    createList(L);

    Song S1 = {"Senja di Kota", "Nona Band", 210, 150, 4.2};
    Song S2 = {"Langkahmu", "Delta", 185, 320, 4.8};
    Song S3 = {"Hujan Minggu", "Arka", 240, 90, 3.9};

    insertLast(L, S1);
    insertLast(L, S2);
    insertLast(L, S3);

    cout << "\n--- List Awal ---\n";
    viewList(L);

    Song removed;
    deleteLast(L, removed);
    cout << "\nDeleteLast: " << removed.Title << " dihapus.\n";

    cout << "\n--- List Setelah DeleteLast ---\n";
    viewList(L);

    Song S4 = {"Pelita", "Luna", 200, 260, 4.5};
    updateAtPosition(L, 2, S4);

    cout << "\n--- List Setelah Update Posisi ke-2 ---\n";
    viewList(L);

    Song S5 = {"Senandung", "Mira", 175, 120, 4.0};

    Node* pos2 = L.head->next;
    insertBefore(L, pos2, S5);

    cout << "\n--- List Setelah insertBefore Posisi ke-2 ---\n";
    viewList(L);

    Song S6 = {"Sepatu", "Tulus", 300, 100, 4.7};
    insertBefore(L, pos2, S6);

    cout << "\n--- List Setelah updateBefore ---\n";
    viewList(L);

    Node* pos3 = L.head->next->next;
    deleteBefore(L, pos3, removed);

    cout << "\nDeleteBefore posisi ke-3: " << removed.Title << endl;

    cout << "\n--- List Setelah deleteBefore ---\n";
    viewList(L);

    cout << "\n--- Searching PopularityScore antara 150 - 300 ---\n";
    searchByPopularityRange(L, 150, 300);

    return 0;
}
```
Output 
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/50384595-23cb-4839-8926-4a79885c8b0c" />
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/0676828d-438c-4201-90df-7e0d195d39e7" />
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/412f5f87-8109-44ec-a058-5aacddae39ac" />


