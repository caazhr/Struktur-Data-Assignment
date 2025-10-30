# <h1 align="center">Laporan Praktikum Modul Singly Linked List(bagian dua)</h1>
<p align="center">Neisya Azzahra Rasin</p>

## Dasar Teori

Operasi dasar yang dibahas pada modul ini mencakup pembuatan list kosong, alokasi dan dealokasi node, penambahan elemen pada awal list, serta penelusuran atau pencetakan isi list. Proses alokasi digunakan untuk menyediakan memori bagi node baru secara dinamis, sedangkan dealokasi berfungsi menghapus node agar memori tidak terbuang sia-sia. Operasi insertFirst menempatkan node baru di depan list, dan printInfo digunakan untuk menelusuri seluruh node dari awal hingga akhir guna menampilkan isi datanya.

Selain operasi dasar, modul ini juga menjelaskan operasi lanjutan seperti pencarian data (searching) dan penghitungan total nilai. Fungsi findElm digunakan untuk mencari node dengan nilai tertentu melalui penelusuran dari awal list sampai akhir. Jika nilai ditemukan, fungsi mengembalikan alamat node tersebut, dan jika tidak, hasilnya adalah NULL. Sementara itu, fungsi totalInfo berfungsi menjumlahkan seluruh nilai yang terdapat pada setiap node di dalam list.

Secara keseluruhan, materi ini menekankan pemahaman terhadap cara kerja pointer dan pengelolaan memori dinamis dalam mengelola data secara efisien menggunakan Singly Linked List.

## Guided 1

listBuah.h
```C++
//Header guard digunakan untuk mencegah file header yg sama
// di-include lebih dari sekali dalam satu program 
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL 

#include <iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah; //memberikan nama alias dataBuah untuk struct buah

typedef struct node *address; //mendefinisikan alias address sebagai pointer ke struct node

struct node{ //node untuk isi linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{//ini linked listnya 
    address first;
};

//semua function &prosedur yg akan dipakai 
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
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

//materi modul 5 (part 1 - update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5 (part 2 - searching)
void FindNodeByData(linkedlist List, string data);
void FindNodeByAddress(linkedlist List, address node);
void FindNodeByRange(linkedlist List, float hargaAwal, float HargaAkhir);

#endif
```

listBuah.cpp
```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

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
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
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
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
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
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
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
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 2 (SEARCHING) -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;

        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```

main.cpp
```C++
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

   updateFirst(List);
   updateLast(List);
   updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData (List, "Kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);

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
//unguide temanya bebas tp gabole singlylist, list buah, mahasiswa (BUAT LAPRAK)

```
Program diatas memungkinkan user untuk mengelola data beberapa mahasiswa yang mencakup nama, NIM, dan umur. Langkah-langkah yang dilakukan meliputi pembuatan daftar kosong, penambahan data pada bagian awal, tengah, maupun akhir daftar, serta penampilan seluruh data secara terurut. Tujuan utama program diatas adalah untuk menunjukkan penerapan konsep penyimpanan data secara dinamis menggunakan pointer dan keterkaitan antar node dalam pengelolaan data mahasiswa.




## Unguided 

### 1. Modifikasi soal guided dengan tema listFilm 

listFilm.h
```C++
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
```

listFilm.cpp
```C++
#include "listFilm.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if (List.first == Nil){
         return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
}

address alokasi(string judul, string genre, float rating) {
    address nodeBaru = new node;
    nodeBaru->isidata.judul = judul;
    nodeBaru->isidata.genre = genre;
    nodeBaru->isidata.rating = rating;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
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

void delFirst(linkedlist &List) {
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil dihapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
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
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { 
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.judul << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List))
        cout << "List kosong." << endl;
    else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Judul Film : " << nodeBantu->isidata.judul
                 << ", Genre : " << nodeBantu->isidata.genre
                 << ", Rating : " << nodeBantu->isidata.rating << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

void deleteList(linkedlist &List) {
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while (nodeBantu != Nil) {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "Seluruh list berhasil dihapus!" << endl;
}

void updateFirst(linkedlist List) {
    if (isEmpty(List) == true){
           cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama Judul : ";
        cin >> List.first->isidata.judul;
        cout << "Genre : ";
        cin >> List.first->isidata.genre;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List) {
    if (isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama Judul : ";
        cin >> nodeBantu->isidata.judul;
        cout << "Genre : ";
        cin >> nodeBantu->isidata.genre;
        cout << "Rating : ";
        cin >> nodeBantu->isidata.rating;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev) {
    if (isEmpty(List) == true){
        cout << "List kosong!" << endl;
    }else {
       if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.judul << " : " << endl;
            cout << "Nama Judul : ";
            cin >> nodeBantu->isidata.judul;
            cout << "Genre : ";
            cin >> nodeBantu->isidata.genre;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void FindNodeByData(linkedlist list, string judul) {
    if (isEmpty(list)== true){
        cout << "List kosong!" << endl;
    } else {
    address nodeBantu = list.first;
    int posisi = 0;

    bool found = false;
    while (nodeBantu != Nil) {
        posisi++;
        if (nodeBantu->isidata.judul == judul) {
            cout << "Film \"" << judul << "\" ditemukan di posisi ke-" << posisi << "!" << endl;
            cout << "Nama Judul : " << nodeBantu->isidata.judul
                << ", Genre : " << nodeBantu->isidata.genre
                << ", Rating : " << nodeBantu->isidata.rating << endl;
            found = true;
            break;
        }
        nodeBantu = nodeBantu->next;
    }

    if(found == false){
            cout << "Node dengan data " << judul << " tidak ditemukan!" << endl;
        }
    }
     cout << endl;
}

void FindNodeByAddress(linkedlist list, address node) {
    if (isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if (nodeBantu == node) {
                cout << "Node ditemukan di posisi ke-" << posisi << "!" << endl;
                cout << "Judul Film : " << nodeBantu->isidata.judul
                    << ", Genre : " << nodeBantu->isidata.genre
                    << ", Rating : " << nodeBantu->isidata.rating << endl;
                    found = true;
                    break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;

}

void FindNodeByRange(linkedlist list, float ratingAwal, float ratingAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Film dengan rating antara " << ratingAwal << " dan " << ratingAkhir << " ---" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float rating = nodeBantu->isidata.rating;
            if (rating >= ratingAwal && rating <= ratingAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Judul : " << nodeBantu->isidata.judul << ", Genre : " << nodeBantu->isidata.genre << ", Rating : " << nodeBantu->isidata.rating << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada film dalam rentang rating tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```

main.cpp
```C++
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
```
#### Output:
<img width="691" height="824" alt="Image" src="https://github.com/user-attachments/assets/53ae9367-a47d-44d5-a6cf-12aaebaa9a5c" />
<img width="559" height="715" alt="Image" src="https://github.com/user-attachments/assets/d9cf9514-31be-4d36-8c37-25293f460996" />

Program ini memungkinkan user untuk melakukan berbagai operasi terhadap kumpulan data film, seperti menambahkan, memperbarui, mencari, dan menghapus data film secara dinamis. Setiap elemen dalam list menyimpan informasi tentang judul film, genre, dan rating. User dapat menambahkan data di awal, tengah, atau akhir list, memperbarui isi data tertentu, mencari film berdasarkan judul, alamat node, atau rentang rating; serta menghapus satu atau seluruh data dalam list.

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/a89f08e4-1a03-4d4b-bf26-2a599dd2b2be" />

### 2. Latihan 5.2 Modul
<img width="609" height="742" alt="Image" src="https://github.com/user-attachments/assets/6b975bf3-2534-4138-8a59-8baba3a14d10" />
<img width="549" height="271" alt="Image" src="https://github.com/user-attachments/assets/8349ae9d-add6-47f2-9ca2-3d3ecfb1918b" />

Singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL 

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct ElmList *address; 

struct ElmList{
   infotype info;
   address next;
};

struct List{
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void printInfo(List L);

address findElm(List L, infotype x);
int totalInfo(List L);
#endif
```

Singlylist.cpp
```C++
#include "Singlylist.h"
#include <iostream>
using namespace std;

bool isEmpty(List L) {
    if(L.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(List &L) {
    L.first = Nil;
}


address alokasi(infotype x) {
    address P = new ElmList;
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

void insertFirst(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

void printInfo(List L) {
    if (L.first == Nil) {
        cout << "List kosong" << endl;
    } else {
        address P = L.first;
        while (P != Nil) {
            cout << P->info << " ";
            P = P->next;
        }
        cout << endl;
    }
}

address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return Nil; 
}

int totalInfo(List L) {
    int total = 0;
    address P = L.first;
    while (P != Nil) {
        total += P->info;
        P = P->next;
    }
    return total;
}
```

main.cpp
```C++
#include "Singlylist.h"

#include<iostream>
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    createList(L);

    P1 = alokasi(2);  insertFirst(L, P1);
    P2 = alokasi(0);  insertFirst(L, P2);
    P3 = alokasi(8);  insertFirst(L, P3);
    P4 = alokasi(12); insertFirst(L, P4);
    P5 = alokasi(9);  insertFirst(L, P5);

    printInfo(L); 
   address found = findElm(L, 8);
    if (found != Nil)
        cout << "8 ditemukan dalam list" << endl;
    else
        cout << "8 tidak ditemukan dalam list" << endl;

    cout << "Total info dari kelima elemen adalah " << totalInfo(L) << endl;

    return 0;
}
```

#### Output:
<img width="577" height="93" alt="Image" src="https://github.com/user-attachments/assets/bf2de8ef-ad99-48ad-bc6e-df28d628a746" />

Program diatas menunjukkan cara kerja Singly Linked List dalam mengelola data bertipe integer secara dinamis. Melalui operasi seperti penambahan, penghapusan, dan penampilan elemen list. 

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/0256e151-aa96-4576-94a9-3cc5f9d08c53" />





## Kesimpulan
Ringkasan dan interpretasi pandangan saya adalah Praktikum ini menunjukkan bagaimana Singly Linked List memungkinkan pengelolaan data secara dinamis menggunakan pointer. Saya menyadari pentingnya manajemen memori saat menambah atau menghapus elemen, serta fleksibilitas list dibanding array. Praktikum ini memberikan pemahaman dasar yang berguna untuk struktur data yang lebih kompleks di program nyata.


## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
