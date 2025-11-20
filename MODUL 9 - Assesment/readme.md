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
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/897d68f9-fbca-45b1-8c76-fd7a12516962" />
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/55d55243-6dc9-4ace-ac3c-5e3a7d19d906" />

### 3. 

StackMahasiswa.h
```C++
#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H

#include <string>
using namespace std;

struct Mahasiswa {
    string Nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
};

const int MAX = 6;

struct StackMahasiswa {
    Mahasiswa dataMahasiswa[MAX];
    int Top;
};

bool isEmpty(StackMahasiswa S);
bool isFull(StackMahasiswa S);
void createStack(StackMahasiswa &S);
void Push(StackMahasiswa &S, Mahasiswa M);
void Pop(StackMahasiswa &S, Mahasiswa &M);
void Update(StackMahasiswa &S, int posisi, Mahasiswa M);
void View(StackMahasiswa S);
void SearchNilaiAkhir(StackMahasiswa S, float NilaiAkhirMin, float NilaiAkhirMax);
void MaxNilaiAkhir(StackMahasiswa S); 

#endif

```

StackMahasiswa.cpp
```C++
#include <iostream>
#include "StackMahasiswa.h"
using namespace std;

bool isEmpty(StackMahasiswa S){
    return S.Top == -1;
}

bool isFull(StackMahasiswa S){
    return S.Top == MAX - 1;
}

void createStack(StackMahasiswa &S){
    S.Top = -1;
}

void Push(StackMahasiswa &S, Mahasiswa M){
    if(isFull(S)){
        cout << "Stack penuh!\n";
    } else {
        S.Top++;
        S.dataMahasiswa[S.Top] = M;
    }
}

void Pop(StackMahasiswa &S, Mahasiswa &M){
    if(isEmpty(S)){
        cout << "Stack kosong!\n";
    } else {
        M = S.dataMahasiswa[S.Top];
        S.Top--;
    }
}

void Update(StackMahasiswa &S, int posisi, Mahasiswa M){
    int index = S.Top - posisi + 1;

    if(index >= 0 && index <= S.Top){
        S.dataMahasiswa[index] = M;
    } else {
        cout << "Posisi tidak valid!\n";
    }
}

void View(StackMahasiswa S){
    if(isEmpty(S)){
        cout << "Stack kosong.\n";
        return;
    }

    cout << "--- Stack TOP → BOTTOM ---\n";

    for(int i = S.Top; i >= 0; i--){
        float NilaiAkhir =
            0.2 * S.dataMahasiswa[i].NilaiTugas +
            0.4 * S.dataMahasiswa[i].NilaiUTS +
            0.4 * S.dataMahasiswa[i].NilaiUAS;

        cout << "Posisi: " << (S.Top - i + 1) << endl;
        cout << "Nama: " << S.dataMahasiswa[i].Nama << endl;
        cout << "NIM: " << S.dataMahasiswa[i].NIM << endl;
        cout << "Nilai Tugas: " << S.dataMahasiswa[i].NilaiTugas << endl;
        cout << "Nilai UTS: " << S.dataMahasiswa[i].NilaiUTS << endl;
        cout << "Nilai UAS: " << S.dataMahasiswa[i].NilaiUAS << endl;
        cout << "Nilai Akhir: " << NilaiAkhir << endl;
        cout << "---------------------------\n";
    }
}

void SearchNilaiAkhir(StackMahasiswa S, float NilaiAkhirMin, float NilaiAkhirMax){
    bool found = false;

    cout << "\n--- Searching NilaiAkhir --- " 
         << NilaiAkhirMin << " - " << NilaiAkhirMax << " ===\n";

    for(int i = S.Top; i >= 0; i--){
        float NA =
            0.2 * S.dataMahasiswa[i].NilaiTugas +
            0.4 * S.dataMahasiswa[i].NilaiUTS +
            0.4 * S.dataMahasiswa[i].NilaiUAS;

        if(NA >= NilaiAkhirMin && NA <= NilaiAkhirMax){
            found = true;
            cout << "Posisi: " << (S.Top - i + 1) << endl;
            cout << "Nama: " << S.dataMahasiswa[i].Nama << endl;
            cout << "Nilai Akhir: " << NA << endl;
            cout << "----------------------\n";
        }
    }

    if(!found){
        cout << "Tidak ada mahasiswa pada rentang tersebut.\n";
    }
}

void MaxNilaiAkhir(StackMahasiswa S){
    if(isEmpty(S)){
        cout << "Stack kosong.\n";
        return;
    }

    float maxNA = 0;

    for(int i = S.Top; i >= 0; i--){
        float NA =
            0.2 * S.dataMahasiswa[i].NilaiTugas +
            0.4 * S.dataMahasiswa[i].NilaiUTS +
            0.4 * S.dataMahasiswa[i].NilaiUAS;

        if(NA > maxNA){
            maxNA = NA;
        }
    }

    
    cout << "\n--- Mahasiswa dengan NilaiAkhir Tertinggi ---\n";
    for(int i = S.Top; i >= 0; i--){
        float NA =
            0.2 * S.dataMahasiswa[i].NilaiTugas +
            0.4 * S.dataMahasiswa[i].NilaiUTS +
            0.4 * S.dataMahasiswa[i].NilaiUAS;

        if(NA == maxNA){
            cout << "Posisi: " << (S.Top - i + 1) << endl;
            cout << "Nama: " << S.dataMahasiswa[i].Nama << endl;
            cout << "Nilai Akhir: " << NA << endl;
            cout << "----------------------\n";
        }
    }
}

```
main.cpp
```C++
#include "StackMahasiswa.h"
#include <iostream>
using namespace std;

int main(){
    StackMahasiswa S;
    createStack(S);

    Mahasiswa M1 = {"Venti", "11111", 75.7, 82.1, 65.5};
    Mahasiswa M2 = {"Xiao", "22222", 87.4, 88.9, 81.9};
    Mahasiswa M3 = {"Kazuha", "33333", 92.3, 88.8, 82.4};
    Mahasiswa M4 = {"Wanderer", "44444", 95.5, 85.5, 90.5};
    Mahasiswa M5 = {"Lynette", "55555", 77.7, 65.4, 79.9};
    Mahasiswa M6 = {"Chasca", "66666", 99.9, 93.6, 87.3};

    Push(S, M1);
    Push(S, M2);
    Push(S, M3);
    Push(S, M4);
    Push(S, M5);
    Push(S, M6);

    cout << "\n--- Stack Setelah Input ---\n";
    View(S);

    Mahasiswa removed;
    Pop(S, removed);
    cout << "\nPop 1x: " << removed.Nama << " dihapus.\n";

    cout << "\n--- Stack Setelah Pop ---\n";
    View(S);

    Mahasiswa M7 = {"Heizou", "77777", 99.9, 88.8, 77.7};
    Update(S, 3, M7);

    cout << "\n--- Stack Setelah Update Posisi ke-3 ---\n";
    View(S);

    SearchNilaiAkhir(S, 85.5, 95.5);

    MaxNilaiAkhir(S);

    return 0;
}
```
output 
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/57575c79-e13d-4ca4-b09b-c5b7ded11e71" />
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/d3a1bcbd-4122-4919-b9f4-d53e42829db3" />
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/ccbafd05-23f4-48d3-a5bb-6b22fde25ac5" />
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/22cc9ae6-9c53-4cb2-89cd-659af2dcb414" />
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/e08d5747-7b43-4593-863c-ef38cc5321eb" />

### 4. 

QueuePengiriman.h
```C++
#ifndef QUEUEPENGIRIMAN_H
#define QUEUEPENGIRIMAN_H

#include <string>
using namespace std;

struct Paket {
    string KodeResi;
    string NamaPengirim;
    int BeratBarang;
    string Tujuan;
};

const int MAX = 5;

struct QueueEkspedisi {
    Paket dataPaket[MAX];
    int Head;
    int Tail;
};

bool isEmpty(QueueEkspedisi Q);
bool isFull(QueueEkspedisi Q);
void createQueue(QueueEkspedisi &Q);
void enQueue(QueueEkspedisi &Q, Paket P);
void deQueue(QueueEkspedisi &Q, Paket &P);
void viewQueue(QueueEkspedisi Q);
int TotalBiayaPengiriman(QueueEkspedisi Q);

#endif
```

QueuePengiriman.cpp
```C++
#include "QueuePengiriman.h"
#include <iostream>
using namespace std;

bool isEmpty(QueueEkspedisi Q){
    return Q.Tail == -1;
}

bool isFull(QueueEkspedisi Q){
    return Q.Tail == MAX - 1;
}

void createQueue(QueueEkspedisi &Q){
    Q.Head = 0;
    Q.Tail = -1;
}

void enQueue(QueueEkspedisi &Q, Paket P){
    if(isFull(Q)){
        cout << "Queue penuh! Tidak bisa menambah data.\n";
    } else {
        Q.Tail++;
        Q.dataPaket[Q.Tail] = P;
    }
}

void deQueue(QueueEkspedisi &Q, Paket &P){
    if(isEmpty(Q)){
        cout << "Queue kosong! Tidak bisa mengambil data.\n";
        return;
    }

    P = Q.dataPaket[Q.Head]; 

    for(int i = Q.Head; i < Q.Tail; i++){
        Q.dataPaket[i] = Q.dataPaket[i + 1];
    }

    Q.Tail--; 
}

void viewQueue(QueueEkspedisi Q){
    if(isEmpty(Q)){
        cout << "Queue kosong.\n";
        return;
    }

    cout << "\n--- Daftar Paket dalam Queue ---\n";
    for(int i = Q.Head; i <= Q.Tail; i++){
        cout << "Posisi Antrian: " << i - Q.Head + 1 << endl;
        cout << "Kode Resi   : " << Q.dataPaket[i].KodeResi << endl;
        cout << "Pengirim    : " << Q.dataPaket[i].NamaPengirim << endl;
        cout << "Berat Barang: " << Q.dataPaket[i].BeratBarang << " kg\n";
        cout << "Tujuan      : " << Q.dataPaket[i].Tujuan << endl;
        cout << "----------------------------------\n";
    }
}

int TotalBiayaPengiriman(QueueEkspedisi Q){
    const int biayaPerKg = 8250;
    int total = 0;

    for(int i = Q.Head; i <= Q.Tail; i++){
        total += Q.dataPaket[i].BeratBarang * biayaPerKg;
    }

    return total;
}

```
main.cpp
```C++
#include "QueuePengiriman.h"
#include <iostream>
using namespace std;

int main(){
    QueueEkspedisi Q;
    createQueue(Q);

    Paket P1 = {"123456", "Hutao", 14, "Sumeru"};
    Paket P2 = {"234567", "Ayaka", 10, "Fontaine"};
    Paket P3 = {"345678", "Bennet", 7, "Natlan"};
    Paket P4 = {"456789", "Furina", 16, "Liyue"};
    Paket P5 = {"567890", "Nefer", 6, "Inazuma"};

    enQueue(Q, P1);
    enQueue(Q, P2);
    enQueue(Q, P3);
    enQueue(Q, P4);
    enQueue(Q, P5);

    cout << "\n--- Queue Setelah Input 5 Paket ---\n";
    viewQueue(Q);

    Paket removed;
    deQueue(Q, removed);
    cout << "\nPaket dengan resi " << removed.KodeResi
         << " telah dikeluarkan dari antrian.\n";

    cout << "\n--- Queue Setelah deQueue 1x ---\n";
    viewQueue(Q);

    int total = TotalBiayaPengiriman(Q);
    cout << "\n--- Total Biaya Pengiriman Semua Paket ---\n";
    cout << "Total Biaya : Rp " << total << endl;

    return 0;
}
```
