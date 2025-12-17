# <h1 align="center">Laporan Praktikum Modul Graph</h1>
<p align="center">Neisya Azzahra Rasin</p>

## Dasar Teori
Graph merupakan struktur data yang terdiri dari sekumpulan node (vertex) dan edge yang berfungsi untuk menghubungkan antar node tersebut. Struktur data graph banyak digunakan untuk merepresentasikan berbagai bentuk hubungan atau keterkaitan antar objek di dunia nyata, seperti hubungan antar lokasi, keterkaitan mata kuliah dengan mata kuliah prasyarat, maupun alur pekerjaan dalam suatu proyek yang memiliki urutan tertentu.

Berdasarkan arah dari edge yang dimiliki, graph dibedakan menjadi graph berarah (directed graph) dan graph tidak berarah (undirected graph). Pada graph berarah, setiap edge memiliki arah yang jelas dari satu node menuju node lainnya, sehingga hubungan yang terbentuk bersifat satu arah. Sebaliknya, pada graph tidak berarah, hubungan antar node bersifat dua arah, yang berarti jika suatu node terhubung dengan node lain maka keduanya saling terhubung.

Dalam implementasinya, graph dapat direpresentasikan dalam beberapa bentuk, di antaranya menggunakan matriks ketetanggaan (adjacency matrix) dan multi linked list. Pada modul ini, representasi graph yang digunakan adalah multi linked list karena bersifat dinamis, sehingga lebih fleksibel dalam menangani perubahan jumlah node dan edge. Dengan representasi ini, setiap node menyimpan pointer yang mengarah ke edge-edge yang terhubung dengan node tersebut.

Modul ini juga membahas topological sort, yaitu suatu metode pengurutan node pada graph berarah yang memiliki keterurutan parsial sehingga dapat dihasilkan urutan linear. Topological sort sering digunakan dalam berbagai permasalahan seperti penjadwalan pekerjaan, penyusunan kurikulum mata kuliah berdasarkan prasyarat, serta pengelolaan dependensi dalam suatu sistem.

Selain itu, dibahas pula metode penelusuran graph yaitu Breadth First Search (BFS) dan Depth First Search (DFS). BFS melakukan penelusuran graph dengan mengunjungi node berdasarkan tingkat atau level kedalamannya, sedangkan DFS menelusuri graph secara mendalam hingga mencapai node terdalam sebelum kembali dan melanjutkan ke node lain. Kedua metode ini digunakan untuk menelusuri seluruh node dalam graph secara sistematis dan terstruktur.

## Guided 

### 1. Implementasi ADT Graph Menggunakan Adjacency List

graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info; //Menyimpan data node (misal: char/int).
    int visited; //Penanda untuk traversal (0/1) (Penanda apakah node sudah dikunjungi)
    adrEdge firstEdge; //Pointer ke edge pertama yang terhubung.
    adrNode Next; // Pointer ke node berikutnya dalam graph
};

struct ElmEdge {
    adrNode Node; //Pointer yang menunjuk ke lokasi node tujuan.
    adrEdge Next; //Pointer ke edge berikutnya (jika satu node memiliki banyak cabang).
};

struct Graph {
    adrNode First; //Pointer ke node pertama dalam list graph.
};

void CreateGraph(Graph &G); //prosedur untuk mengeset first dari graph sebagai NOUL
adrNode AlokasiNode(infoGraph data); //alokasi Node baru
adrEdge AlokasiEdge(adrNode nodeTujuan); //alokasi Edge baru

void InsertNode(Graph &G, infoGraph data); //Menambahkan Node ke dalam Graph
adrNode FindNode(Graph G, infoGraph data); //function untuk mencari alamat Node berdasarkan infonya
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2); //prosedur untuk menghubungkan dua Node (Undirected Graph)
void DisconnectNode(adrNode node1, adrNode node2); //prosedur untuk memutuskan hubungan dua node
void DeleteNode(Graph &G, infoGraph X); //prosedur untuk menghapus Rode X beserta semua edge yang berhubungan dengannya

void PrintInfoGraph(Graph G); //Menampilkan isi Graph (Adjacency List)
void ResetVisited(Graph &G); //Reset status visited sebelum traversal
void PrintBFS(Graph G, infoGraph StartInfo); //traversal Breadth First Search / BFS (Menggunakan Queue)
void PrintDFS(Graph G, infoGraph StartInfo); //Traversal Depth First Search / DFS (Menggunakan Stack)

#endif
```

graph.cpp
```C++
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

//prosedur untuk mengeset first dari graph sebagai NULL
void CreateGraph(Graph &G) {
    G.First = NULL;
}

//alokasi Node baru
adrNode AlokasiNode(infoGraph data) {
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = data;
    nodeBaru->visited = 0; //isinya 0/1
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;
    return nodeBaru;
}

//alokasi Edge baru
adrEdge AlokasiEdge(adrNode nodeTujuan) {
    adrEdge edgeBaru = new ElmEdge;
    edgeBaru->Node = nodeTujuan;
    edgeBaru->Next = NULL;
    return edgeBaru;
}

//Menambahkan Node ke dalam Graph
void InsertNode(Graph &G, infoGraph data) {
    adrNode nodeBaru = AlokasiNode(data);
    if (G.First == NULL) {
        G.First = nodeBaru;
    } else {
        //konsepnya insert last
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != NULL) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

//function untuk mencari alamat Node berdasarkan infonya
adrNode FindNode(Graph G, infoGraph data) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        if (nodeBantu->info == data) {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->Next;
    }
    return NULL;
}

//prosedur untuk menghubungkan dua Node (Undirected Graph)
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2) {
    adrNode node1 = FindNode(G, info1);
    adrNode node2 = FindNode(G, info2);

    if (node1 != NULL && node2 != NULL) {
        //Hubungkan node1 ke node2
        adrEdge Edge1 = AlokasiEdge(node2);
        Edge1->Next = node1->firstEdge; // Insert First pada list edge
        node1->firstEdge = Edge1;

        //Hubungkan node2 ke node1 (Karena Undirected/Bolak-balik)
        adrEdge Edge2 = AlokasiEdge(node1);
        Edge2->Next = node2->firstEdge;
        node2->firstEdge = Edge2;
    } else {
        cout << "Node tidak ditemukan!" << endl;
    }
}

//prosedur untuk memutuskan hubungan dua node
void DisconnectNode(adrNode node1, adrNode node2) {
    if (node1 != NULL && node2 != NULL) {
        adrEdge edgeBantu = node1->firstEdge;
        adrEdge PrevE = NULL;

        //Cari edge yang mengarah ke node2 di dalam list milik node1
        while (edgeBantu != NULL && edgeBantu->Node != node2) {
            PrevE = edgeBantu;
            edgeBantu = edgeBantu->Next;
        }

        if (edgeBantu != NULL) { //jika Edge ditemukan
            if (PrevE == NULL) {
                //Hapus edge pertama
                node1->firstEdge = edgeBantu->Next;
            } else {
                //Hapus edge di tengah/akhir
                PrevE->Next = edgeBantu->Next;
            }
            delete edgeBantu;
        }
    }
}

//prosedur untuk menghapus Node X beserta semua edge yang berhubungan dengannya
void DeleteNode(Graph &G, infoGraph X) {
    //1. Cari Node yang akan dihapus (nodeHapus)
    adrNode nodeHapus = FindNode(G, X);
    if (nodeHapus == NULL) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }

    //2. Hapus semua Edge yang MENGARAH ke nodeHapus (Incoming Edges)
    //cek setiap node di graph, apakah punya edge ke nodeHapus
    adrNode nodeLainnya = G.First;
    while (nodeLainnya != NULL) {
        DisconnectNode(nodeLainnya, nodeHapus); //putus hubungan nodeLainnya ke nodeHapus
        nodeLainnya = nodeLainnya->Next;
    }

    //3. Hapus semua Edge yang KELUAR dari nodeHapus (Outgoing Edges)
    //Deallokasi list edge milik nodeHapus
    adrEdge edgeBantu = nodeHapus->firstEdge;
    while (edgeBantu != NULL) {
        adrEdge tempE = edgeBantu;
        edgeBantu = edgeBantu->Next;
        delete tempE;
    }
    nodeHapus->firstEdge = NULL;

    //4. Hapus nodeHapus dari List Utama Graph
    if (G.First == nodeHapus) {
        //jika nodeHapus di awal
        G.First = nodeHapus->Next;
    } else {
        //jika nodeHapus di tengah/akhir
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != nodeHapus) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeHapus->Next;
    }

    //5. delete nodeHapus
    delete nodeHapus;
}

//Menampilkan isi Graph (Adjacency List) 
void PrintInfoGraph(Graph G) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        cout << "Node " << nodeBantu->info << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            cout << edgeBantu->Node->info << " "; //Akses info dari node tujuan
            edgeBantu = edgeBantu->Next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

//Reset status visited sebelum traversal
void ResetVisited(Graph &G) {
    adrNode nodeReset = G.First;
    while (nodeReset != NULL) {
        nodeReset->visited = 0;
        nodeReset = nodeReset->Next;
    }
}

//traversal Breadth First Search / BFS (Menggunakan Queue)
void PrintBFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    queue<adrNode> Qyu;
    
    //Enqueue start
    Qyu.push(StartNode);
    StartNode->visited = 1;

    cout << "BFS Traversal: ";
    while (!Qyu.empty()) {
        adrNode nodeBantu = Qyu.front();
        Qyu.pop();
        cout << nodeBantu->info << " - ";

        //Cek semua tetangga atau edge nya
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            if (edgeBantu->Node->visited == 0) {
                edgeBantu->Node->visited = 1;
                Qyu.push(edgeBantu->Node);
            }
            edgeBantu = edgeBantu->Next;
        }
    }
    cout << endl;
}

//Traversal Depth First Search / DFS (Menggunakan Stack)
void PrintDFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    stack<adrNode> Stak;
    
    Stak.push(StartNode);

    cout << "DFS Traversal: ";
    while (!Stak.empty()) {
        adrNode nodeBantu = Stak.top();
        Stak.pop();

        if (nodeBantu->visited == 0) {
            nodeBantu->visited = 1;
            cout << nodeBantu->info << " - ";

            //masukkan tetangga ke stack
            adrEdge edgeBantu = nodeBantu->firstEdge;
            while (edgeBantu != NULL) {
                if (edgeBantu->Node->visited == 0) {
                    Stak.push(edgeBantu->Node);
                }
                edgeBantu = edgeBantu->Next;
            }
        }
    }
    cout << endl;
}
```

main.cpp
```C++
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');

    //hubungkan antar node
    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'D');
    ConnectNode(G, 'B', 'C');
    ConnectNode(G, 'D', 'C');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'E', 'F');

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    //mulai traversal dari node A
    PrintBFS(G, 'A'); //BFS
    PrintDFS(G, 'A'); //DFS
    cout << endl;

    cout << "=== HAPUS NODE E ===" << endl;
    DeleteNode(G, 'E');
    if(FindNode(G, 'E') == NULL){
        cout << "Node E berhasil terhapus" << endl;
    } else {
        cout << "Node E tidak berhasil terhapus" << endl;
    }
    cout << endl;

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    //mulai traversal dari node A
    PrintBFS(G, 'A'); //BFS
    PrintDFS(G, 'A'); //DFS

    return 0;
}
```
program diatas digunakan untuk mengimplementasikan struktur data Graph tidak berarah dengan menggunakan representasi Adjacency List. Program diawali dengan pembuatan graph kosong, kemudian dilakukan penambahan node dan pembentukan hubungan antar node menggunakan edge dua arah. Struktur graph ditampilkan dalam bentuk adjacency list, lalu dilakukan penelusuran graph menggunakan metode Breadth First Search (BFS) dan Depth First Search (DFS). Selain itu, program juga menguji proses penghapusan node beserta seluruh edge yang terhubung dengannya untuk melihat perubahan struktur graph.


## Unguided 

### 1. 
<img width="790" height="594" alt="Image" src="https://github.com/user-attachments/assets/ce03becb-29f6-4304-8a3e-4d87f8a0ad09" />

Keterangan :
• fungsi findElm mencari elemen di dalam list L berdasarkan nim<br>
    o fungsi mengembalikan elemen dengan dengan info nim == x.nim jika ditemukan<br>
    o fungsi mengembalikan NIL jika tidak ditemukan<br>

<img width="701" height="708" alt="Image" src="https://github.com/user-attachments/assets/4aa3f176-a5fa-4890-b425-35f34860cc3b" />
<img width="479" height="264" alt="Image" src="https://github.com/user-attachments/assets/18dc3c96-d610-4f22-9ea1-f8dddf3a1e22" />
<img width="702" height="433" alt="Image" src="https://github.com/user-attachments/assets/1b030f24-479f-468f-8bb5-37626c8d11e5" />


circularlist.h
```C++
#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include <iostream>
#include <string>
using namespace std;

struct mahasiswa {
    string nama;
    string nim;
    char jenis_kelamin;
    float ipk;
};

typedef mahasiswa infotype;

struct ElmList;
typedef ElmList* address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

#define NIL NULL

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void insertAfter(List &L, address Prec, address P);
void insertLast(List &L, address P);
void deleteFirst(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
void deleteLast(List &L, address &P);
address findElm(List L, infotype x);   
void printInfo(List L);

#endif
```

circularlist.cpp
```C++
#include "circularlist.h"

void CreateList(List &L) {
    L.first = NIL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NIL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NIL;
}

static address lastNode(List L) {
    if (L.first == NIL) return NIL;
    address Q = L.first;
    while (Q->next != L.first) {
        Q = Q->next;
    }
    return Q;
}

void insertFirst(List &L, address P) {
    if (P == NIL) return;

    if (L.first == NIL) {
        L.first = P;
        P->next = P;
    } else {
        address Last = lastNode(L);
        P->next = L.first;
        L.first = P;
        Last->next = L.first;
    }
}

void insertLast(List &L, address P) {
    if (P == NIL) return;

    if (L.first == NIL) {
        insertFirst(L, P);
    } else {
        address Last = lastNode(L);
        Last->next = P;
        P->next = L.first;
    }
}

void insertAfter(List &L, address Prec, address P) {
    if (L.first == NIL || Prec == NIL || P == NIL) return;

    P->next = Prec->next;
    Prec->next = P;
}

void deleteFirst(List &L, address &P) {
    P = NIL;
    if (L.first == NIL) return;

    if (L.first->next == L.first) {
        P = L.first;
        L.first = NIL;
        P->next = NIL;
        return;
    }

    address Last = lastNode(L);
    P = L.first;
    L.first = L.first->next;
    Last->next = L.first;
    P->next = NIL;
}

void deleteLast(List &L, address &P) {
    P = NIL;
    if (L.first == NIL) return;

    if (L.first->next == L.first) {
        P = L.first;
        L.first = NIL;
        P->next = NIL;
        return;
    }

    address Prec = L.first;
    while (Prec->next->next != L.first) { 
        Prec = Prec->next;
    }

    P = Prec->next;      
    Prec->next = L.first; 
    P->next = NIL;
}

void deleteAfter(List &L, address Prec, address &P) {
    P = NIL;
    if (L.first == NIL || Prec == NIL) return;

    address target = Prec->next;
    if (target == NIL) return;

    if (target == L.first) {
        deleteFirst(L, P);
        return;
    }

    P = target;
    Prec->next = target->next;
    P->next = NIL;
}

address findElm(List L, infotype x) {
    if (L.first == NIL) return NIL;

    address P = L.first;
    do {
        if (P->info.nim == x.nim) return P;
        P = P->next;
    } while (P != L.first);

    return NIL;
}

void printInfo(List L) {
    if (L.first == NIL) {
        cout << "List kosong" << endl;
        return;
    }

    address P = L.first;
    do {
        cout << "Nama : " << P->info.nama << "\n";
        cout << "NIM  : " << P->info.nim << "\n";
        cout << "L/P  : " << P->info.jenis_kelamin << "\n";
        cout << "IPK  : " << P->info.ipk << "\n\n";
        P = P->next;
    } while (P != L.first);
}
```

main.cpp
```C++
#include "circularlist.h"

address createData(string nama, string nim, char jk, float ipk) {
    infotype x;
    x.nama = nama;
    x.nim = nim;
    x.jenis_kelamin = jk;
    x.ipk = ipk;
    return alokasi(x);
}

int main() {
    List L;
    address P1 = NIL, P2 = NIL;
    infotype x;

    CreateList(L);

    cout << "coba insert first, last, dan after" << endl;

    P1 = createData("Danu", "04", 'L', 4.0);
    insertFirst(L, P1);

    P1 = createData("Fahmi", "06", 'L', 3.45);
    insertLast(L, P1);

    P1 = createData("Bobi", "02", 'L', 3.71);
    insertFirst(L, P1);

    P1 = createData("Ali", "01", 'L', 3.3);
    insertFirst(L, P1);

    P1 = createData("Gita", "07", 'P', 3.75);
    insertLast(L, P1);

    x.nim = "07";
    P1 = findElm(L, x);
    P2 = createData("Cindi", "03", 'P', 3.5);
    if (P1 != NIL) insertAfter(L, P1, P2);

    x.nim = "02";
    P1 = findElm(L, x);
    P2 = createData("Hilmi", "08", 'P', 3.3); 
    if (P1 != NIL) insertAfter(L, P1, P2);

    x.nim = "04";
    P1 = findElm(L, x);
    P2 = createData("Eli", "05", 'P', 3.4);
    if (P1 != NIL) insertAfter(L, P1, P2);

    printInfo(L);

    return 0;
}
```
#### Output:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/f5aef720-7ca9-44e7-a3bb-5fcee2741ece" />

Program ini mengimplementasikan ADT Circular Linked List untuk mengelola data mahasiswa yang terdiri dari nama, NIM, jenis kelamin, dan IPK. Struktur data yang digunakan adalah single circular linked list, di mana elemen terakhir menunjuk kembali ke elemen pertama. Program menyediakan operasi pembuatan list, alokasi dan dealokasi node, penambahan data di awal, akhir, dan setelah elemen tertentu, penghapusan data, pencarian elemen berdasarkan NIM, serta penampilan seluruh data mahasiswa. Dengan penerapan circular linked list, program mampu mengelola data secara dinamis dan mendukung traversal data secara berulang dengan efisien sesuai spesifikasi ADT yang ditentukan.

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/4572e6a2-8c75-4643-9d06-73c9d2c849e5" />


## Kesimpulan
Praktikum ini memberikan pemahaman tentang penerapan ADT Circular Linked List dalam mengelola data mahasiswa secara dinamis melalui operasi penambahan, penghapusan, pencarian, dan penelusuran data.

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
