
# <h1 align="center">Laporan Praktikum Modul Singly Linked List(bagian pertama)</h1>
<p align="center">Neisya Azzahra Rasin</p>

## Dasar Teori

pada modul 4 pada praktikum struktur data ini membahas tentang Singly Linked List (bagian pertama).
Singly Linked List adalah salah satu bentuk struktur data dinamis, dimana elemen-elemennya disebut node, dan setiap node berisi data(info) serta penunjuk(pointer) ke node berikutnya.
Beda dengan array yang memiliki ukuran tetap, linked list dapat bertambah atau berkurang selama program dijalankan.
Elemen-elemen dalam linked list tidak disimpan secara berurutan di memori, tetapi saling terhubung menggunakan pointer.

Struktur Dasar Singly Linked List 
umumnya terdiri dari tiga komponen :
- Node (ElmList) -> isinya data dan penunjuk ke node berikutnya.
- Address -> tipe data pointer yg menunjuk ke node.
- List -> nyimpen alamat node pertama dalam linked list.

beberapa operasi utama yg dipelajari di modul 4 ini :
- createList() -> dipakai untuk membuat list kosong dengan mengatur pointer first -> null, sehingga list siap digunakan.
- alokasi() -> untuk membuat node baru di memori dengan menggunakan new.
- dealokasi() -> menghapus node dari memori menggunakan delete, agar ruang yg digunakan node dapat dikembvalikan ke sistem.
- insertFirst() -> menambah node baru di bagian depan list.
- printInfo() -> menelusuri seluruh node mulai dri node pertama-mode trakhir, lalu menampilkan isi datanya ke layar.

intinya itu Singly Linked List adalah struktur data dinamis yang memungkinkan penyimpanan data secara efisien tanpa batasan ukuran tetap.
Setiap node hanya mengetahui alamat node setelahnya, sehingga penelusuran bersifat satu arah.
Meskipun tidak bisa diakses secara langsung seperti array, linked list unggul dalam fleksibilitas dan efisiensi saat melakukan penambahan serta penghapusan data. 


## Guided 1

list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```

list.h
```C++
//Header guard digunakan untuk mencegah file header yg sama

#ifndef LIST_H
#define LIST_H
#define Nil NULL 

#include <iostream>
using namespace std;

// deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //mendefinisikan alias address sebagai pointer ke struct node

struct node{ //node untuk isi linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{//ini linked listnya 
    address first;
};

//semua function &prosedur yg akan dipakai 
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodebaru);
void insertAfter(linkedlist &List, address nodebaru, address prev);
void insertLast(linkedlist &List, address nodebaru);

#endif

```

main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```
Program diatas memungkinkan user untuk mengelola data beberapa mahasiswa yang mencakup nama, NIM, dan umur. Langkah-langkah yang dilakukan meliputi pembuatan daftar kosong, penambahan data pada bagian awal, tengah, maupun akhir daftar, serta penampilan seluruh data secara terurut. Tujuan utama program diatas adalah untuk menunjukkan penerapan konsep penyimpanan data secara dinamis menggunakan pointer dan keterkaitan antar node dalam pengelolaan data mahasiswa.


## Guided 2

list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    /* I.S. list tidak kosong
    F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    /* I.S. list tidak kosong
    F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    /* I.S. list tidak kosng, Prev alamat salah satu elemen list
    F.S. nodeBantu adalah alamat dari Prev→next, menghapus Prev→next dari list */
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}
```

list.h
```C++
//Header guard digunakan untuk mencegah file header yg sama

#ifndef LIST_H
#define LIST_H
#define Nil NULL 

#include <iostream>
using namespace std;

// deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //mendefinisikan alias address sebagai pointer ke struct node

struct node{ //node untuk isi linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{//ini linked listnya 
    address first;
};

//semua function &prosedur yg akan dipakai 
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodebaru);
void insertAfter(linkedlist &List, address nodebaru, address prev);
void insertLast(linkedlist &List, address nodebaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &list, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif
```

main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
program diatas sama seperti program sebelumnya tapi yang membedakan keduanya adalah Program sebelumnya fokus pada penambahan data, sedangkan program yang sekarang mencakup penambahan, penghapusan, dan pengelolaan total data.

## Unguided 

### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”
<img width="664" height="246" alt="Image" src="https://github.com/user-attachments/assets/54250c85-abdc-4423-97eb-6fc7090c9ac4" />
Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file “Singlylist.cpp”
Kemudian buat program utama didalam file “main.cpp” dengan implementasi sebagai berikut :
<img width="333" height="372" alt="Image" src="https://github.com/user-attachments/assets/28d8eae4-4161-4728-9e84-e236a0c99aac" />
<img width="706" height="316" alt="Image" src="https://github.com/user-attachments/assets/1bdc3640-36ba-46fc-8969-2522f2463286" />

singlylist.h
```C++


#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int infotype;         
typedef struct ElmtList *address; 

struct ElmtList {
    infotype info;  
    address next;   
};

struct List {
    address First;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif
```

singlylist.cpp
```C++
#include "Singlylist.h"
#include <iostream>
using namespace std;

void CreateList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmtList;
    if (P != Nil) {
        P->info = x;
        P->next = Nil;
    }
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
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

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

```

main.cpp
```C++
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

```
#### Output:
<img width="662" height="160" alt="Image" src="https://github.com/user-attachments/assets/12bf0241-131d-4bad-a218-d872eb577a17" />

Program di atas terdiri dari tiga file dan berfungsi untuk mengelola data berbentuk bilangan integer menggunakan konsep Singly Linked List. Pengguna tidak perlu menentukan jumlah data terlebih dahulu karena setiap elemen dapat ditambahkan secara dinamis ke dalam list. Program membuat list kosong terlebih dahulu, lalu menambahkan beberapa data ke bagian awal list, dan akhirnya menampilkan seluruh isi list secara berurutan. Melalui proses ini, program menunjukkan cara kerja penyimpanan data dinamis menggunakan pointer yang saling terhubung antar node. Dan hasil output sesuai dengan yang di minta pada soal.

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/904d33bb-6d48-44fc-8d08-abfda5eb1bcb" />

### 2. 
<img width="687" height="243" alt="Image" src="https://github.com/user-attachments/assets/4f21dbdd-ed38-48c4-ae02-3c2f551a4cc0" />

Singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct ElmtList *address;

struct ElmtList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, address Prec);
int nbList(List L);
void deleteList(List &L);

#endif

```

Singlylist.cpp
```C++
#include "Singlylist.h"
#include <iostream>
using namespace std;

void CreateList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmtList;
    if (P != Nil) {
        P->info = x;
        P->next = Nil;
    }
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
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

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

void deleteFirst(List &L) {
    if (L.First != Nil) {
        address P = L.First;
        L.First = L.First->next;
        dealokasi(P);
    }
}
void deleteLast(List &L) {
    if (L.First != Nil) {
        if (L.First->next == Nil) {
            dealokasi(L.First);
            L.First = Nil;
        } else {
            address prec = Nil;
            address last = L.First;
            while (last->next != Nil) {
                prec = last;
                last = last->next;
            }
            prec->next = Nil;
            dealokasi(last);
        }
    }
}

void deleteAfter(List &L, address Prec) {
    if (Prec != Nil && Prec->next != Nil) {
        address P = Prec->next;
        Prec->next = P->next;
        dealokasi(P);
    }
}

int nbList(List L) {
    int count = 0;
    address P = L.First;
    while (P != Nil) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteList(List &L) {
    address P = L.First;
    while (P != Nil) {
        address temp = P;
        P = P->next;
        dealokasi(temp);
    }
    L.First = Nil;
}
```

main.cpp
```C++
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

    deleteFirst(L);            
    deleteLast(L);              
    deleteAfter(L, L.First);    

    printInfo(L);             
    cout << "Jumlah node : " << nbList(L) << endl;

    deleteList(L);              
    cout << endl << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```

#### Output:
<img width="598" height="207" alt="Image" src="https://github.com/user-attachments/assets/c15e54d0-daec-4327-a634-af97317d0aed" />

Program diatas menunjukkan cara kerja Singly Linked List dalam mengelola data bertipe integer secara dinamis. Melalui operasi seperti penambahan, penghapusan, dan penampilan elemen list. 

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/0256e151-aa96-4576-94a9-3cc5f9d08c53" />





## Kesimpulan
Ringkasan dan interpretasi pandangan saya adalah Praktikum ini menunjukkan bagaimana Singly Linked List memungkinkan pengelolaan data secara dinamis menggunakan pointer. Saya menyadari pentingnya manajemen memori saat menambah atau menghapus elemen, serta fleksibilitas list dibanding array. Praktikum ini memberikan pemahaman dasar yang berguna untuk struktur data yang lebih kompleks di program nyata.


## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
