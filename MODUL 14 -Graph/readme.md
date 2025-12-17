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
<img width="906" height="803" alt="Image" src="https://github.com/user-attachments/assets/07dbafa6-1597-43a5-ad93-73c977304ec5" />
2. Buatlah prosedur untuk menampilkanhasil penelusuran DFS.<br>
3. Buatlah prosedur untuk menampilkanhasil penelusuran DFS.
prosedur PrintBFS (Graph G, adrNode N);<br>


graph.h
```C++
#ifndef GRAPH_H_INCLUDE
#define GRAPH_H_INCLUDE

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
adrNode FindNode(Graph G, infoGraph X);
void PrintInfoGraph(Graph G);

void PrintDFS(Graph G, adrNode N);
void PrintBFS(Graph G, adrNode N);

#endif
```

graph.cpp
```C++
#include "graph.h"
#include <queue>
#include <stack>

static adrNode AlokasiNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->Next = NULL;
    return P;
}

static adrEdge AlokasiEdge(adrNode tujuan) {
    adrEdge E = new ElmEdge;
    E->Node = tujuan;
    E->Next = NULL;
    return E;
}

static void ResetVisited(Graph &G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }
}

static bool HasEdge(adrNode from, adrNode to) {
    adrEdge e = from->firstEdge;
    while (e != NULL) {
        if (e->Node == to) return true;
        e = e->Next;
    }
    return false;
}

void CreateGraph(Graph &G) {
    G.first = NULL;
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) return P;
        P = P->Next;
    }
    return NULL;
}

void InsertNode(Graph &G, infoGraph X) {
    if (FindNode(G, X) != NULL) return;

    adrNode P = AlokasiNode(X);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->Next != NULL) Q = Q->Next;
        Q->Next = P;
    }
}

void ConnectNode(adrNode N1, adrNode N2) {
    if (N1 == NULL || N2 == NULL) return;
    if (N1 == N2) return;

    if (!HasEdge(N1, N2)) {
        adrEdge E1 = AlokasiEdge(N2);
        E1->Next = N1->firstEdge;    
        N1->firstEdge = E1;
    }
    if (!HasEdge(N2, N1)) {
        adrEdge E2 = AlokasiEdge(N1);
        E2->Next = N2->firstEdge;     
        N2->firstEdge = E2;
    }
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << P->info << " : ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}

void PrintDFS(Graph G, adrNode N) {
    if (N == NULL) return;

    ResetVisited(G);
    stack<adrNode> S;
    S.push(N);

    cout << "DFS: ";
    bool firstOut = true;

    while (!S.empty()) {
        adrNode u = S.top();
        S.pop();

        if (u->visited == 1) continue;
        u->visited = 1;

        if (!firstOut) cout << " ";
        cout << u->info;
        firstOut = false;

        adrEdge e = u->firstEdge;
        while (e != NULL) {
            if (e->Node->visited == 0) S.push(e->Node);
            e = e->Next;
        }
    }
    cout << endl;
}

void PrintBFS(Graph G, adrNode N) {
    if (N == NULL) return;

    ResetVisited(G);
    queue<adrNode> Q;
    Q.push(N);
    N->visited = 1;

    cout << "BFS: ";
    bool firstOut = true;

    while (!Q.empty()) {
        adrNode u = Q.front();
        Q.pop();

        if (!firstOut) cout << " ";
        cout << u->info;
        firstOut = false;

        adrEdge e = u->firstEdge;
        while (e != NULL) {
            if (e->Node->visited == 0) {
                e->Node->visited = 1;
                Q.push(e->Node);
            }
            e = e->Next;
        }
    }
    cout << endl;
}
```

main.cpp
```C++
#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    adrNode A = FindNode(G, 'A');
    adrNode B = FindNode(G, 'B');
    adrNode C = FindNode(G, 'C');
    adrNode D = FindNode(G, 'D');
    adrNode E = FindNode(G, 'E');
    adrNode F = FindNode(G, 'F');
    adrNode Gg = FindNode(G, 'G');
    adrNode H = FindNode(G, 'H');

    ConnectNode(A, B);
    ConnectNode(A, C);

    ConnectNode(B, D);
    ConnectNode(B, E);

    ConnectNode(C, F);
    ConnectNode(C, Gg);

    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(Gg, H);

    cout << "Adjacency List:\n";
    PrintInfoGraph(G);
    cout << endl;

    PrintDFS(G, A);
    PrintBFS(G, A);

    return 0;
}
```
#### Output:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/f5aef720-7ca9-44e7-a3bb-5fcee2741ece" />

Program ini dibuat untuk mengimplementasikan struktur data Graph tidak berarah menggunakan representasi Adjacency List berbasis multi linked list. Program menyediakan operasi pembuatan graph, penambahan node, serta penghubungan antar node menggunakan edge dua arah. Selain itu, program juga menampilkan struktur graph dalam bentuk adjacency list dan melakukan penelusuran graph menggunakan metode Depth First Search (DFS) dan Breadth First Search (BFS) yang masing-masing menggunakan stack dan queue.

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/4572e6a2-8c75-4643-9d06-73c9d2c849e5" />


## Kesimpulan
Melalui praktikum ini, dapat dipahami konsep dasar struktur data graph beserta cara merepresentasikannya menggunakan adjacency list. Praktikum ini juga membantu memahami proses penelusuran graph menggunakan metode DFS dan BFS serta penerapan struktur data stack dan queue dalam traversal graph.

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
