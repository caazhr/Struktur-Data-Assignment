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


