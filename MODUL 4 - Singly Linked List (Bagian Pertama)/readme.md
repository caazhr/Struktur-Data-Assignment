
# <h1 align="center">Laporan Praktikum Modul Abstract Data Type (ADT)</h1>
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

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas.

mahasiswa.h
```C++
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts, uas, tugas, nilaiAkhir;
};

void inputMahasiswa(Mahasiswa &m);
float hitungNilaiAkhir(Mahasiswa m);
void tampilMahasiswa(Mahasiswa m);

#endif
```

mahasiswa.cpp
```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;

void inputMahasiswa(Mahasiswa &m) {
    cout << "Nama   : "; getline(cin, m.nama);
    cout << "NIM    : "; getline(cin, m.nim);
    cout << "UTS    : "; cin >> m.uts;
    cout << "UAS    : "; cin >> m.uas;
    cout << "Tugas  : "; cin >> m.tugas;
    cin.ignore();
    m.nilaiAkhir = hitungNilaiAkhir(m);
}

float hitungNilaiAkhir(Mahasiswa m) {
    return 0.3 * m.uts + 0.4 * m.uas + 0.3 * m.tugas;
}

void tampilMahasiswa(Mahasiswa m) {
    cout << "\nNama: " << m.nama
         << "\nNIM: " << m.nim
         << "\nNilai Akhir: " << m.nilaiAkhir << endl;
}
```

main.cpp
```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main() {
    Mahasiswa data[10];
    int n;
    cout << "Masukkan jumlah mahasiswa (max 10): ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << endl;
        inputMahasiswa(data[i]);
    }

    cout << "\n---- Data Mahasiswa ----" << endl;
    for (int i = 0; i < n; i++) {
        tampilMahasiswa(data[i]);
    }
    return 0;
}
```
#### Output:
<img width="647" height="642" alt="Image" src="https://github.com/user-attachments/assets/f5689ea1-2996-4257-ae19-c2e8ca3f3819" />

Program diatas terdiri atas tiga file dan berfungsi untuk mengolah data beberapa mahasiswa. user akan diminta memasukkan jumlah mahasiswa dengan max 10, lalu mengisi nama, NIM, serta nilai UTS, UAS, dan tugas untuk masing-masing mahasiswa sebagai input. Program akan menghitung nilai akhir berdasarkan bobot tertentu, kemudian menampilkan hasil berupa nama, NIM, dan nilai akhir setiap mahasiswa sebagai output.

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/159e28e8-78ff-4613-8783-300fe1c7e259" />

### 2. 
<img width="947" height="577" alt="Image" src="https://github.com/user-attachments/assets/63ec5a45-4d0f-4112-9134-6fb73b8eeb05" />

pelajaran.h
```C++
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED
#include <string>
using namespace std;

struct Pelajaran {
    string namaMapel;
    string kodeMapel;
};

Pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(Pelajaran pel);

#endif
```

pelajaran.cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

Pelajaran create_pelajaran(string namapel, string kodepel) {
    Pelajaran p;
    p.namaMapel = namapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampil_pelajaran(Pelajaran pel) {
    cout << "Nama Mata Pelajaran : " << pel.namaMapel << endl;
    cout << "Kode Mata Pelajaran : " << pel.kodeMapel << endl;
}
```

main.cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    Pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}

```

#### Output:
<img width="822" height="162" alt="Image" src="https://github.com/user-attachments/assets/90578e96-e989-4a3d-84f3-0b03a3dc2353" />

Program diatas terdiri dari tiga file dan berfungsi untuk menampilkan data mata pelajaran. Program secara otomatis membuat data berupa nama mata pelajaran dan kode mata pelajaran, kemudian menyimpannya dalam struktur Pelajaran. Setelah data dibuat, program menampilkan hasil berupa nama mata pelajaran dan kode pelajaran sebagai output.

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/d387614e-fca8-4182-92b6-092982c8b27d" />


### 3. Buatlah program dengan ketentuan :
- 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
- fungsi/prosedur yang menampilkan isi sebuah array integer 2D
- fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
- fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer 

array2d.h
```C++
#ifndef ARRAY2D_H_INCLUDED
#define ARRAY2D_H_INCLUDED
void tampilArray(int A[3][3]);
void tukarPosisi(int A[3][3], int B[3][3], int baris, int kolom);
void tukarPointer(int *x, int *y);
#endif
```

array2d.cpp
```C++
#include <iostream>
#include "array2d.h"
using namespace std;

void tampilArray(int A[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarPosisi(int A[3][3], int B[3][3], int baris, int kolom) {
    int temp = A[baris][kolom];
    A[baris][kolom] = B[baris][kolom];
    B[baris][kolom] = temp;
}

void tukarPointer(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
```

main.cpp
```C++
#include <iostream>
#include "array2d.h"
using namespace std;

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {9, 8, 7},
        {6, 0, 4}, 
        {3, 2, 1}
    };

    int x = 10;
    int y = 20;
    int *px = &x;
    int *py = &y;

    cout << "Array A:\n"; tampilArray(A);
    cout << "\nArray B:\n"; tampilArray(B);

    cout << "\nMenukar posisi (1,1) antara A dan B...\n";
    tukarPosisi(A, B, 1, 1);

    cout << "\nSetelah penukaran posisi (1,1):\n";
    cout << "Array A:\n"; tampilArray(A);
    cout << "\nArray B:\n"; tampilArray(B);

    cout << "\nSebelum tukar pointer: x=" << x << " y=" << y << "\n";
    tukarPointer(px, py);
    cout << "Setelah tukar pointer: x=" << x << " y=" << y << "\n";

    return 0;
}
```
#### Output:
<img width="637" height="706" alt="Image" src="https://github.com/user-attachments/assets/0ed1c79e-b4b1-40f9-bf4d-e777c849f23c" />


Program diatas terdiri dari tiga file dan digunakan untuk menampilkan serta menukar data pada dua array berukuran 3x3. Pertama, program menampilkan isi dari masing-masing array. Lalu, program menukar elemen pada posisi tertentu di antara kedua array tersebut(program di atas posisi penukarannya ada di [1][1]). Selain itu, program juga menukar nilai dua variabel menggunakan pointer. Di akhir, hasil penukaran pada array dan variabel ditampilkan ke layar.

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/77ee0673-4ac9-4046-acaa-35c55fe5d744" />


## Kesimpulan
Ringkasan dan interpretasi pandangan saya adalah setelah mempelajari modul ini saya belajar menulis kode lebih terstruktur, dan efisien.


## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
