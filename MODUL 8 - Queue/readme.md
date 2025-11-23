
# <h1 align="center">Laporan Praktikum Modul Queue</h1>
<p align="center">Neisya Azzahra Rasin</p>

## Dasar Teori

Queue cara kerjanya mirip antrean sehari-hari: siapa yang datang duluan, dia yang dilayani duluan FIFO (First In First Out). Data baru selalu masuk lewat bagian belakang antrian lewat operasi enqueue, dan data yang keluar selalu diambil dari bagian depan lewat dequeue. Dalam implementasinya menggunakan array, ada beberapa cara untuk mengatur posisi head dan tail supaya antrian bekerja dengan benar.

Cara pertama adalah yang paling sederhana. Pada metode ini, head selalu berada di posisi awal array, sementara tail terus bergerak maju setiap kali ada data baru. Ketika dequeue dilakukan, semua elemen digeser ke kiri supaya head tetap berada di depan. Walaupun mudah, cara ini kurang efisien karena proses shifting terus dilakukan.

Cara kedua lebih baik karena head dan tail bisa sama-sama bergerak tanpa harus menggeser elemen. Namun ada satu kelemahan: bisa muncul kondisi “penuh semu”, yaitu tail sudah berada di ujung array, padahal sebenarnya masih ada ruang kosong di bagian depan akibat head yang sudah maju.

Cara ketiga adalah circular queue, dan ini yang paling efisien. Pada metode ini, head dan tail bisa “muter” kembali ke indeks awal ketika mencapai batas array. Dengan begitu, ruang kosong di depan bisa digunakan kembali tanpa perlu shifting. Metode ini jauh lebih efisien dan umum dipakai ketika membangun antrian berbasis array karena benar-benar memanfaatkan ruang yang ada.
## Guided 

### 1. [Implementasi Queue menggunakan Linked List Guided 1]

queue.h 
```C++
// guided 1 queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

struct queue {
    Node* head;
    Node* tail;
};

void CreateQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
void enQueue(queue &Q, const string &nama);
void deQueue(queue &Q);
void viewQueue(queue Q);
void clearQueue(queue &Q);

#endif
```

queue.cpp
```C++
// guided 1 queue.cpp
#include "queue.h"
using namespace std;

void CreateQueue(queue &Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmpty(queue Q) {
    return Q.head == nullptr;
}

bool isFull(queue) {
    return false;
}

void enQueue(queue &Q, const string &nama) {
    Node* baru = new Node{nama, nullptr};
    if (isEmpty(Q)) {
        Q.head = Q.tail = baru;
    } else {
        Q.tail->next = baru;
        Q.tail = baru;
    }
    cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    Node* hapus = Q.head;
    cout << "Menghapus data " << hapus->nama << "..." << endl;
    Q.head = Q.head->next;
    if (Q.head == nullptr) {
        Q.tail = nullptr;
    }
    delete hapus;
}

void viewQueue(queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    int i = 1;
    for (Node* p = Q.head; p != nullptr; p = p->next) {
        cout << i++ << ". " << p->nama << endl;
    }
}

void clearQueue(queue &Q) {
    while (!isEmpty(Q)) {
        deQueue(Q);
    }
}
```

main.cpp
```C++
// guided 1 main.cpp
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    queue Q;
    CreateQueue(Q);

    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    clearQueue(Q);
    return 0;
}
```
Program ini menunjukkan bagaimana queue bekerja dengan memanfaatkan linked list. Setiap data yang masuk disimpan sebagai node yang berisi nama dan penunjuk ke node berikutnya. Operasi dasar yang digunakan adalah enqueue untuk menambah data baru ke bagian belakang antrian, dequeue untuk menghapus data dari bagian depan, viewQueue untuk menampilkan seluruh isi antrian, dan clearQueue untuk mengosongkan semua elemen. Pada fungsi utama, beberapa nama dimasukkan ke dalam queue lalu ditampilkan, kemudian beberapa elemen dihapus dan hasilnya ditampilkan kembali. Dari proses itu terlihat jelas cara kerja FIFO, yaitu data yang masuk lebih awal akan diambil lebih dulu.

### 2. [Implementasi Circular Queue Menggunakan Array Guided 2]

queue.h 
```C++
// guided2 queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
using namespace std;

const int MAKSIMAL = 5;

struct queue{
    string nama[MAKSIMAL];
    int head;
    int tail;
};

bool isFull(queue Q);
bool isEmpty(queue Q);
void CreateQueue(queue &Q); //terbentuk queue dengan head = -1 dan tail = -1 
void enQueue(queue &Q, string nama);
void deQueue(queue &Q);
void viewQueue(queue Q);

#endif
```

queue.cpp
```C++
// guided2 queue.cpp
#include "queue.h"
#include <iostream>

using namespace std;

// NOTE : 
// Implementasi 1 = head diam, tail bergerak (Queue Linear Statis, kerana head nya tetap diam)
// Implementasi 2 = head bergerak, tail bergerak (Queue Linear Dinamis, karena head & tail nya sama-sama bergerak)
// Implementasi 3 = head dan tail berputar (Queue Circular, karena jika udh mentok tapi masih ada space, diputar sehingga tail bisa ada didepan head)

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

// //isFull implmenetasi 1 & 2
// bool isFull(queue Q){
//     if(Q.tail == MAKSIMAL - 1){
//         return true;
//     } else {
//         return false;
//     }
// }

//isFull implementasi 3
bool isFull(queue Q){
    if((Q.tail + 1) % MAKSIMAL == Q.head){
        return true;
    } else {
        return false;
    }
}

void CreateQueue(queue &Q){ //terbentuk queue dengan head = -1 dan tail = -1 
    Q.head = -1;
    Q.tail = -1;
}
 
// //enqueue implementasi 1 & 2
// void enQueue(queue &Q, string nama){
//     if(isFull(Q) == true){
//         cout << "Queue sudah penuh!" << endl;
//     } else {
//         if(isEmpty(Q) == true){
//             Q.head = Q.tail = 0;
//         } else {
//             Q.tail++;
//         }
//         Q.nama[Q.tail] = nama;
//         cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
//     }
// }

//enQueue implementasi 3
void enQueue(queue &Q, string nama){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % MAKSIMAL; // bergerak melingkar
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

// //dequeue implementasi 1
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         for(int i = 0; i < Q.tail; i++){
//             Q.nama[i] =  Q.nama[i+1];
//         }
//         Q.tail--;
//         if(Q.tail < 0){ //kalo semua isi queue nya udh dikelaurin, set head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

// //dequeue implementasi 2
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         Q.head++;
//         if(Q.head > Q.tail){ //kalo elemennya udh abis (head akan lebih 1 dari tail), maka reset ulang head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

//deQueue implementasi 3
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head = (Q.head + 1) % MAKSIMAL; // bergerak melingkar
        }
    }
}

// //viewQueue implementasi 1 & 2
// void viewQueue(queue Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         for(int i = Q.head; i <= Q.tail; i++){
//             cout << i -  Q.head + 1 << ". " << Q.nama[i] << endl;
//         }
//     }
//     cout << endl;
// }

//viewQueue implementasi 3
void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        int i = Q.head;
        int count = 1;
        while(true){
            cout << count << ". " << Q.nama[i] << endl;
            if(i == Q.tail){
                break;
            }
            i = (i + 1) % MAKSIMAL;
            count++;
        }   
    }
}
```

main.cpp
```C++
// guided2 main.cpp
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;

    CreateQueue(Q);
    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    // deQueue(Q);
    // deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    return 0;
}
```
Program ini menunjukkan cara kerja Circular Queue yang dibuat menggunakan array dengan ukuran tetap. Setiap data disimpan di dalam array, lalu posisi head dan tail bisa “muter” kembali ke awal menggunakan operasi modulo. Program ini punya fungsi dasar antrian seperti menambah data ke bagian belakang lewat enQueue, menghapus data dari bagian depan dengan deQueue, mengecek apakah antrian penuh atau kosong, dan menampilkan seluruh isi antrian dengan viewQueue. Di bagian utama program, beberapa nama dimasukkan sampai queue penuh, lalu beberapa data dihapus, dan hasilnya ditampilkan lagi. Dari alur tersebut terlihat bagaimana konsep FIFO (First In First Out) berjalan, dan bagaimana circular queue bisa memakai ruang array secara lebih efisien tanpa perlu menggeser elemen.
## Unguided 

### 1. 
<img width="920" height="769" alt="Image" src="https://github.com/user-attachments/assets/c321aaf1-ad3f-4cef-b5cf-1e5d32edc72b" />

queue.h
```C++
#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <iostream>
using namespace std;

const int MAX = 5;          
typedef int infotype;

struct Queue {
    infotype info[MAX];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

queue.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAX - 1);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail++;
    }
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    infotype dummy = 0;

    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return dummy;
    }

    infotype val = Q.info[Q.head];

    if (Q.head == Q.tail) {
        createQueue(Q);
    } else {
        for (int i = Q.head; i < Q.tail; i++) {
            Q.info[i] = Q.info[i + 1];
        }
        Q.tail--;
    }

    return val;
}

void printInfo(Queue Q) {
    if (isEmptyQueue(Q)) {
        cout << Q.head << "  -  " << Q.tail << "  | empty queue" << endl;
        return;
    }

    cout << Q.head << "  -  " << Q.tail << "    | ";

    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i];
        if (i < Q.tail) cout << " ";
    }

    cout << endl;
}
```

main.cpp
```C++
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello World!" << endl;

    Queue Q;
    createQueue(Q);

    cout << "----------------------------" << endl;
    cout << "H  -  T    | Queue Info" << endl;
    cout << "----------------------------" << endl;

    printInfo(Q);

    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q); printInfo(Q);   
    dequeue(Q); printInfo(Q);   
    enqueue(Q, 4); printInfo(Q); 
    dequeue(Q); printInfo(Q);   
    dequeue(Q); printInfo(Q);   

    return 0;
}

```
#### Output:
<img width="646" height="365" alt="Image" src="https://github.com/user-attachments/assets/f89ae572-acff-4cb6-926e-ad59d89376da" />

Kode ini dipakai untuk membuat queue sederhana pakai array sesuai aturan Alternatif 1. Pada cara ini, posisi head nggak pernah pindah dari indeks awal, sementara tail terus maju setiap kali ada data baru yang dimasukkan. Waktu melakukan dequeue, semua elemen di dalam array digeser ke kiri supaya head tetap ada di depan. Programnya sendiri melakukan beberapa operasi seperti menambah data (enqueue), mengambil data dari depan (dequeue), dan menampilkan isi antrian lewat printInfo. Dengan urutan operasi pada fungsi main, kita bisa lihat jelas gimana queue bekerja dengan konsep FIFO—data yang masuk duluan bakal keluar duluan juga.

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/afe741a8-d17c-423b-a2fa-e23a771cbff8" />

### 2. [Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme
queue Alternatif 2 (head bergerak, tail bergerak)]

queue.h
```C++
#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <iostream>
using namespace std;

const int MAX = 5;          
typedef int infotype;

struct Queue {
    infotype info[MAX];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

queue.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAX - 1);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail++;
    }

    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return 0;
    }

    infotype val = Q.info[Q.head];

    if (Q.head == Q.tail) {
        createQueue(Q);
    } else {
        Q.head++;  
    }

    return val;
}

void printInfo(Queue Q) {
    if (isEmptyQueue(Q)) {
        cout << Q.head << "  -  " << Q.tail << "  | empty queue" << endl;
        return;
    }

    cout << Q.head << "  -  " << Q.tail << "    | ";

    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i];
        if (i < Q.tail) cout << " ";
    }

    cout << endl;
}
```

main.cpp
```C++
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello World!" << endl;

    Queue Q;
    createQueue(Q);

    cout << "----------------------------" << endl;
    cout << "H  -  T    | Queue Info" << endl;
    cout << "----------------------------" << endl;

    printInfo(Q);

    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q); printInfo(Q);   
    dequeue(Q); printInfo(Q);   
    enqueue(Q, 4); printInfo(Q); 
    dequeue(Q); printInfo(Q);   
    dequeue(Q); printInfo(Q);   

    return 0;
}
```
#### Output:
<img width="596" height="358" alt="Image" src="https://github.com/user-attachments/assets/d7eae317-9c00-4a02-9e76-5df97919e077" />

kode ini masih membuat queue yang sama seperti sebelumnya, tapi ada perubahan di bagian file .cpp. kalau sebelumnya queue memakai cara Alternatif 1 yang harus menggeser elemen saat dequeue, sekarang sudah pakai Alternatif 2. di versi ini head cukup maju tanpa shifting, jadi proses dequeue jadi lebih simpel dan lebih cepat, tapi aturan FIFO tetap sama.
#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/68447362-336c-4b23-9386-1d29939fc70f" />

### 3. [Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme
queue Alternatif 3 (head dan tail berputar).]

queue.h
```C++
#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <iostream>
using namespace std;

const int MAX = 5;          
typedef int infotype;

struct Queue {
    infotype info[MAX];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

queue.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1);
}

bool isFullQueue(Queue Q) {
    return ((Q.tail + 1) % MAX == Q.head);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail = (Q.tail + 1) % MAX;
    }

    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return 0;
    }

    infotype val = Q.info[Q.head];

    if (Q.head == Q.tail) {
        createQueue(Q);
    } else {
        Q.head = (Q.head + 1) % MAX;
    }

    return val;
}

void printInfo(Queue Q) {
    if (isEmptyQueue(Q)) {
        cout << Q.head << "  -  " << Q.tail << "  | empty queue" << endl;
        return;
    }

    cout << Q.head << "  -  " << Q.tail << "    | ";

    int i = Q.head;
    while (true) {
        cout << Q.info[i];
        if (i == Q.tail) break;
        cout << " ";
        i = (i + 1) % MAX;
    }

    cout << endl;
}
```

main.cpp
```C++
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello World!" << endl;

    Queue Q;
    createQueue(Q);

    cout << "----------------------------" << endl;
    cout << "H  -  T    | Queue Info" << endl;
    cout << "----------------------------" << endl;

    printInfo(Q);

    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q); printInfo(Q);   
    dequeue(Q); printInfo(Q);   
    enqueue(Q, 4); printInfo(Q); 
    dequeue(Q); printInfo(Q);   
    dequeue(Q); printInfo(Q);   

    return 0;
}
```
#### Output:
<img width="592" height="370" alt="Image" src="https://github.com/user-attachments/assets/598549b8-60c4-4cf7-a4f8-27662b05eef6" />

Kode ini masih bikin queue yang sama kaya sebelumnya, tapi yang sekarang bedanya pakai sistem circular queue. Di versi ini, head dan tail bisa muter balik ke indeks awal kalau sudah sampai ujung array. Dengan cara ini, ruang penyimpanan jadi lebih kepakai dan nggak perlu shifting sama sekali. Saat enqueue, data ditaruh di posisi tail yang sudah berputar, dan saat dequeue, head tinggal maju satu langkah secara melingkar. Aturannya tetap sama data yang masuk pertama tetap keluar lebih dulu (FIFO).

#### Full code Screenshot:
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/ac1cfd02-7162-4e97-aa8c-68d46ac361a2" />


## Kesimpulan
Dari praktikum ini, saya menjadi memahami cara kerja queue, termasuk bagaimana data dimasukkan, diambil, dan bagaimana peran head serta tail dalam prosesnya. Praktikum ini membantu memperkuat pemahaman saya terhadap konsep FIFO dan cara penerapannya dalam program.

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
