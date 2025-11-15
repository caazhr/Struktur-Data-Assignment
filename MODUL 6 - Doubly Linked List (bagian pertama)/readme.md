# <h1 align="center">Laporan Praktikum Modul Doubly linked List (bagian pertama)</h1>
<p align="center">Neisya Azzahra Rasin</p>

## Dasar Teori
Doubly Linked List adalah linked list yang masing-masing elemennya memiliki 2 successor, yaitu successor yg menunjuk pada elemen sebelumnya (prev) dan successor yg menunjuk pada elemen sesudahnya (next).
Komponen-komponen dalam doubly linked list:
- First    : pointer pada list yg menunjuk pada elemen pertama list
- Last    : Pointer pada list yg menunjuk pada element terakhir list
- Next    : Pointer pada elemen sebagai succesor yg menunjuk pada elemen didepannya
- Prev    : pointer pada elemen sebagai successor yg menunjuk pada elemen dibelakangnya.
  
**Operasi Insert**<br>
- insert first -> menyisipkan node baru di depan list
- insert last -> menyisipkan node baru di akhir list
- insert after -> menyisipkan node baru setelah node tertentu 
- insert before -> kebalikan dari insert after. perbedaan dari insert after dan before terletak pada pencarian elemennya

**Operasi Delete**<br>
- delete first -> menghapus node pertama 
- delete last -> menghapus node terakhir 
- delete after -> menghapus node yg berada setelah node tertentu
- delete before -> kebalikan dari delete after. perbedaan delete after dan before terletak pada pencarian elemennya. 

**Update, View, dan Searching**<br>
Proses pencarian, update data dan view data pada dasarnya sama dengan proses pada Singly linked
list. Hanya saja pada Doubly linked list lebih mudah dalam melakukan proses akses elemen, karena
bisa melakukan iterasi maju dan mundur.
Seperti halnya Singly linked list, Doubly linked list juga mempunyai ADT yang pada dasarnya sama
dengan ADT yang ada pada Singly linked list.

Keunggulan Doubly Linked List 
- mendukung traversal dua arah
- penghapusan dan penyisipan lebih efisien karena pointer ke node sebelumnya tersedia
- lebih fleksibel dibanding singly linked list 
   

## Guided 

### 1. [Operasi Delete]

```C++
// dll_hapus.cpp
#include <iostream> 
using namespace std; 
#define Nil NULL 

typedef int infotype; // Definisikan tipe data infotype sebagai integer untuk menyimpan informasi elemen
typedef struct elmlist *address; // Definisikan tipe address sebagai pointer ke struct elmlist

struct elmlist { 
    infotype info; // Deklarasikan field info untuk menyimpan data elemen
    address next;   
    address prev; 
}; 

struct List { 
    address first; 
    address last;
}; 

address alokasi(infotype x) { // Definisikan fungsi alokasi untuk membuat elemen baru
    address P = new elmlist; // Alokasikan memori baru untuk elemen
    P->info = x; P->next = Nil; P->prev = Nil; return P; // Set nilai info, next, prev, dan kembalikan pointer
} 
void dealokasi(address &P) { delete P; P = Nil; } // Definisikan fungsi dealokasi untuk mengosongkan memori elemen
void insertFirst(List &L, address P) { 
    P->next = L.first; P->prev = Nil; // Set pointer next P ke first saat ini dan prev ke Nil
    if (L.first != Nil) L.first->prev = P; else L.last = P; // Jika list tidak kosong, update prev first; jika kosong, set last ke P
    L.first = P; // Update first list menjadi P
}

void printInfo(List L) { 
    address P = L.first; while (P != Nil) { cout << P->info << " "; P = P->next; } cout << endl; // Loop melalui list dan cetak info setiap elemen
} 
void deleteFirst(List &L, address &P) { 
    P = L.first; L.first = L.first->next; // Set P ke first dan update first ke next-nya
    if (L.first != Nil) L.first->prev = Nil; else L.last = Nil; // Jika list tidak kosong, set prev first baru ke Nil; jika kosong, set last ke Nil
    P->next = Nil; P->prev = Nil; // Kosongkan pointer next dan prev P
}

void deleteLast(List &L, address &P) { 
    P = L.last; L.last = L.last->prev; // Set P ke last dan update last ke prev-nya
    if (L.last != Nil) L.last->next = Nil; else L.first = Nil; // Jika list tidak kosong, set next last baru ke Nil; jika kosong, set first ke Nil
    P->prev = Nil; P->next = Nil; // Kosongkan pointer prev dan next P
} 
    
void deleteAfter(List &L, address &P, address R) { 
    P = R->next; R->next = P->next; // Set P ke next R dan update next R ke next P
    if (P->next != Nil) P->next->prev = R; else L.last = R; // Jika ada next P, update prev-nya ke R; jika tidak, set last ke R
    P->prev = Nil; P->next = Nil; // Kosongkan pointer prev dan next P
} 

int main() { 
    List L; L.first = Nil; L.last = Nil; 
    insertFirst(L, alokasi(1)); insertFirst(L, alokasi(2)); insertFirst(L, alokasi(3)); // Sisipkan elemen 1, 2, 3 di awal list
    printInfo(L);
    address P; deleteFirst(L, P); dealokasi(P); // Deklarasikan P, hapus first, dealokasi P
    deleteAfter(L, P, L.first); dealokasi(P); // Hapus setelah first, dealokasi P
    printInfo(L); 
    return 0; 
}
```
Kode di atas digunakan untuk untuk menghapus elemen pada struktur data Doubly Linked List. Program ini menyisipkan beberapa elemen ke dalam list, kemudian menghapus elemen pertama dan elemen setelahnya menggunakan fungsi deleteFirst dan deleteAfter. Hasil perubahan list ditampilkan ke layar menggunakan fungsi cout.

### 2. [Operasi Insert]

```C++
// dll_insert.cpp
#include <iostream>
#define Nil NULL
using namespace std;

typedef int infotype; // Definisikan tipe data infotype sebagai integer untuk menyimpan informasi elemen
typedef struct elmlist *address; // Definisikan tipe address sebagai pointer ke struct elmlist


struct elmlist {
    infotype info; // Deklarasikan field info untuk menyimpan data elemen
    address next;
    address prev;
};


struct List { 
    address first; 
    address last; 
}; 


void insertFirst(List &L, address P) { 
    P->next = L.first; // Set pointer next dari P ke elemen pertama saat ini
    P->prev = Nil; // Set pointer prev dari P ke Nil karena menjadi elemen pertama
    if (L.first != Nil) L.first->prev = P; // Jika list tidak kosong, set prev elemen pertama lama ke P
    else L.last = P; // Jika list kosong, set last juga ke P
    L.first = P; // Update first list menjadi P
} 


void insertLast(List &L, address P) { 
    P->prev = L.last; // Set pointer prev dari P ke elemen terakhir saat ini
    P->next = Nil; // Set pointer next dari P ke Nil karena menjadi elemen terakhir
    if (L.last != Nil) L.last->next = P; // Jika list tidak kosong, set next elemen terakhir lama ke P
    else L.first = P; // Jika list kosong, set first juga ke P
    L.last = P; // Update last list menjadi P
} 


void insertAfter(List &L, address P, address R) { // Definisikan fungsi insertAfter untuk menyisipkan elemen setelah R
    P->next = R->next; // Set pointer next dari P ke elemen setelah R
    P->prev = R; // Set pointer prev dari P ke R
    if (R->next != Nil) R->next->prev = P; // Jika ada elemen setelah R, set prev elemen tersebut ke P
    else L.last = P; // Jika R adalah terakhir, update last menjadi P
    R->next = P; // Set next dari R ke P
}


address alokasi(infotype x) { // Definisikan fungsi alokasi untuk membuat elemen baru
    address P = new elmlist; // Alokasikan memori baru untuk elemen
    P->info = x; // Set info elemen dengan nilai x
    P->next = Nil; // Set next elemen ke Nil
    P->prev = Nil; // Set prev elemen ke Nil
    return P; 
} 


void printInfo(List L) { // Definisikan fungsi printInfo untuk mencetak isi list
    address P = L.first; // Set P ke elemen pertama list
    while (P != Nil) { // Loop selama P tidak Nil
        cout << P->info << " "; // Cetak info dari P 
        P = P->next; // Pindah ke elemen berikutnya
    } 
    cout << endl; 
}


int main() { 
    List L; 
    L.first = Nil; 
    L.last = Nil;
    address P1 = alokasi(1); 
    insertFirst(L, P1); 
    address P2 = alokasi(2); 
    insertLast(L, P2); 
    address P3 = alokasi(3); 
    insertAfter(L, P3, P1); 
    printInfo(L); 
    return 0; 
}
```
Kode di atas digunakan untuk menyisipan elemen pada struktur data Doubly Linked List. Program ini menambahkan elemen di awal list, di akhir list, dan setelah elemen tertentu menggunakan fungsi insertFirst, insertLast, dan insertAfter. Hasil akhir dari penyisipan elemen ditampilkan ke layar menggunakan fungsi cout melalui prosedur printInfo.


## Unguided 

### <img width="879" height="513" alt="Image" src="https://github.com/user-attachments/assets/edc8c89f-8313-4973-9746-d73ea20fd5be" />
<img width="753" height="218" alt="Image" src="https://github.com/user-attachments/assets/e0d780ce-d594-486f-8aca-05f3f6d685bd" />
<img width="689" height="409" alt="Image" src="https://github.com/user-attachments/assets/02cd8684-d758-4f1a-be47-8551d072eb37" />

doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <string>
#define Nil NULL
using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int   thnBuat;
};

typedef kendaraan infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address &P, address Prec);
address findElm(List L, infotype x);
void printInfo(List L);

#endif
```

doublylist.cpp
```C++
#include <iostream>
#include "Doublylist.h"
using namespace std;

void createList(List &L) {
    L.first = Nil;
    L.last  = Nil;
}

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    P->prev = Nil;

    if (L.first != Nil) {
        L.first->prev = P;
    } else {
        L.last = P;
    }
    L.first = P;
}

void deleteFirst(List &L, address &P) {
    if (L.first == Nil) {
        P = Nil;
        return;
    }

    P = L.first;
    L.first = P->next;

    if (L.first != Nil) {
        L.first->prev = Nil;
    } else {
        L.last = Nil;
    }

    P->next = Nil;
    P->prev = Nil;
}

void deleteLast(List &L, address &P) {
    if (L.last == Nil) {
        P = Nil;
        return;
    }

    P = L.last;
    L.last = P->prev;

    if (L.last != Nil) {
        L.last->next = Nil;
    } else {
        L.first = Nil;
    }

    P->next = Nil;
    P->prev = Nil;
}

void deleteAfter(List &L, address &P, address Prec) {
    if (Prec == Nil || Prec->next == Nil) {
        P = Nil;       
        return;
    }

    P = Prec->next;          
    Prec->next = P->next;

    if (P->next != Nil) {
        P->next->prev = Prec;
    } else {
         L.last = Prec;
    }

    P->next = Nil;
    P->prev = Nil;
}

address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil && P->info.nopol != x.nopol) {
        P = P->next;
    }
    return P;   
}

void printInfo(List L) {
    address P = L.first;

    cout << endl;
    cout << "DATA LIST 1" << endl << endl;

    while (P != Nil) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
        P = P->next;
    }
}

```

main.cpp
```C++

#include <iostream>
#include "Doublylist.h"

using namespace std;

int main() {
    List L;
    createList(L);

    for (int i = 0; i < 4; i++) {
        infotype x;

        cout << "masukkan nomor polisi: ";
        cin  >> x.nopol;
        cout << "masukkan warna kendaraan: ";
        cin  >> x.warna;
        cout << "masukkan tahun kendaraan: ";
        cin  >> x.thnBuat;

        infotype kunci;
        kunci.nopol = x.nopol;
        address q = findElm(L, kunci);

        if (q != Nil) {
            cout << "nomor polisi sudah terdaftar" << endl;
        } else {
            address P = alokasi(x);
            insertFirst(L, P); 
        }

        cout << endl;
    }

    printInfo(L);
    
    infotype cari;
    cout << "Masukkan Nomor Polisi yang dicari : ";
    cin  >> cari.nopol;

    address Q = findElm(L, cari);
    cout << endl;

    if (Q != Nil) {
        cout << "Nomor Polisi : " << Q->info.nopol << endl;
        cout << "Warna        : " << Q->info.warna << endl;
        cout << "Tahun        : " << Q->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }

    infotype hapusKey;
    cout << endl;
    cout << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin  >> hapusKey.nopol;

    address target = findElm(L, hapusKey);
    address Pdel;

    if (target == Nil) {
        cout << "Data dengan nomor polisi " << hapusKey.nopol
             << " tidak ditemukan." << endl;
    } else {
        if (target == L.first) {
            deleteFirst(L, Pdel);
        } else if (target == L.last) {
            deleteLast(L, Pdel);
        } else {
            deleteAfter(L, Pdel, target->prev);
        }
        cout << "Data dengan nomor polisi " << hapusKey.nopol
             << " berhasil dihapus." << endl;
        dealokasi(Pdel);
    }

    printInfo(L);

    return 0;
}

```
#### Output:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/58e2faab-57f3-431b-bf9e-ab6024bae203" />

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/41e9641c-ad4e-4e50-9ca4-a0215e336b04)


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
