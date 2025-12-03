# <h1 align="center">Laporan Praktikum Modul Tree (bagian pertama)</h1>
<p align="center">Neisya Azzahra Rasin</p>

## Dasar Teori

Pada modul diawali dengan membahas konsep rekursif, yaitu teknik ketika sebuah fungsi memanggil dirinya sendiri untuk menyelesaikan suatu masalah secara bertahap. Metode ini membantu menyederhanakan masalah besar menjadi langkah-langkah kecil dengan pola yang sama. Walaupun rekursif membuat program lebih mudah dipahami, teknik ini kurang efisien dalam penggunaan memori dan waktu, sehingga perlu digunakan secara bijak.

Kemudian membahas materi Tree,yaitu struktur data yang bersifat hierarkis, bukan linear seperti array atau linked list. Sebuah tree tersusun atas node-node yang saling terhubung. Node paling atas disebut root. Node yang memiliki node lain di bawahnya disebut parent, sementara node yang berada di bawahnya disebut child. Node tanpa anak dinamakan leaf. Beberapa istilah lain yang penting dalam tree adalah degree (jumlah anak), path (urutan hubungan antarnode), dan height atau depth (kedalaman level tree).

Jenis-jenis tree juga dijelaskan pada modul, dimulai dari Ordered Tree, di mana susunan child diperhatikan, kemudian Binary Tree yang membatasi jumlah child maksimal dua. Ada pula Complete Binary Tree yang terisi rapi dari kiri, serta Extended Binary Tree yang setiap node-nya hanya memiliki dua atau nol child. Tree yang paling sering digunakan adalah Binary Search Tree (BST). Pada BST, setiap nilai di subtree kiri harus lebih kecil dari parent dan setiap nilai di subtree kanan harus lebih besar. Aturan sederhana ini membuat proses pencarian data menjadi lebih cepat dan terstruktur. Selain itu, modul menyinggung AVL Tree dan Heap Tree sebagai variasi tree lainnya.

Operasi dasar di BST mencakup insert, search, dan delete. Insert dan search dilakukan dengan aturan umum: nilai yang lebih kecil masuk ke kiri, dan yang lebih besar masuk ke kanan. Untuk delete, terutama jika node punya dua anak, modul menjelaskan bahwa nilai node diganti dengan nilai paling kecil di subtree kanan atau paling besar di subtree kiri, lalu node penggantinya dihapus. Modul juga menyinggung cara mencari most-left dan most-right untuk mendapatkan nilai terkecil atau terbesar di tree. Selain itu, modul menjelaskan operasi update, yaitu mengganti nilai sebuah node. Jika setelah diganti posisinya jadi tidak sesuai aturan BST, maka node perlu diregenerasi. Caranya adalah menghapus node tersebut lalu memasukkannya kembali supaya struktur BST tetap benar.

Tree juga dapat ditelusuri menggunakan tiga metode utama, yaitu preorder (mengunjungi root terlebih dahulu), inorder (menghasilkan urutan terurut pada BST), dan postorder (mengunjungi root terakhir). Masing-masing traversal memiliki kegunaannya sendiri dalam pemrosesan data tree.



## Guided 

### 1. [Program BST]

bst.h
```C++
#ifndef BST_H
#define BST_H
#define Nil NULL 

using namespace std;

typedef struct BST *node; //alias pointer = node

struct BST{ //nama struct nya BST
    int angka;
    node left;
    node right;
};

typedef node BinTree; //alias tree = BinTree (merujuk ke node root dari BST)

bool isEmpty(BinTree tree);
void createTree(BinTree &tree);
node alokasi(int angka);
void dealokasi(node nodeHapus);

void insertNode(BinTree &tree, node nodeBaru);
void searchByData(BinTree tree, int angka);
void preOrder(BinTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

bool deleteNode(BinTree &tree, int angka);
node mostRight(BinTree tree);
node mostLeft(BinTree tree);
void deleteTree(BinTree &tree);
int size(BinTree tree);
int height(BinTree tree);

#endif
```

bst.cpp
```C++
#include "bst.h"
#include <iostream>

using namespace std;

//NOTE : parameter tree disini maksudnya merujuk ke node; baik itu node root atau node lain dari tree

bool isEmpty(BinTree tree){
    if(tree == Nil){
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &tree){
    tree = Nil;
}

node alokasi(int angkaInput){
    node nodeBaru = new BST;
    nodeBaru->angka = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus){
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan ke dalam tree!" << endl;
        return;
    } else if(nodeBaru->angka < tree->angka){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->angka > tree->angka){
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree tree, int angkaCari){
    if(isEmpty(tree) == true){
        cout << "Tree kosong!" << endl;
    } else {
        node nodeBantu = tree;
        node parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(angkaCari < nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(angkaCari > nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(angkaCari == nodeBantu->angka){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data Angka : " << nodeBantu->angka << endl;

            //menampilkan parentnya & pengecekan sibling
            node sibling = Nil;
            if(parent != Nil){
                cout << "Parent : " << parent->angka << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != Nil){
                cout << "Sibling : " << sibling->angka << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != Nil){
                cout << "Child kiri : " << nodeBantu->left->angka << endl;
            } else if(nodeBantu->left == Nil){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != Nil){
                cout << "Child kanan : " << nodeBantu->right->angka << endl;
            } else if(nodeBantu->right == Nil){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}

void preOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    cout << tree->angka << " - ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    inOrder(tree->left);
    cout << tree->angka << " - ";
    inOrder(tree->right);
}

void postOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->angka << " - ";
}



bool deleteNode(BinTree &tree, int angka) {
    if (tree == Nil) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (angka < tree->angka) {
            return deleteNode(tree->left, angka);
        } else if (angka > tree->angka) {
            return deleteNode(tree->right, angka);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (tree->left == Nil && tree->right == Nil) {
                node tmp = tree;
                tree = Nil;
                dealokasi(tmp);
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (tree->left == Nil) {
                node tmp = tree;
                tree = tree->right;
                dealokasi(tmp);
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (tree->right == Nil) {
                node tmp = tree;
                tree = tree->left;
                dealokasi(tmp);
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                node successor = mostLeft(tree->right);
                //salin data successor ke node saat ini
                tree->angka = successor->angka;
                //hapus successor pada subtree kanan
                return deleteNode(tree->right, successor->angka);
            }
            return true; //berhasil dihapus
        }
    }
}

node mostRight(BinTree tree){
    while (tree->right != Nil){
        tree = tree->right;
    }
    return tree;    
}

node mostLeft(BinTree tree){
    while (tree->left != Nil){
        tree = tree->left;
    }
    return tree;
}

void deleteTree(BinTree &tree){
    if(tree == Nil){
        return;
    } else {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree){ //mengembalikan jumlah semua node
    if(isEmpty(tree) == true){
        return 0;
    } else {
        return 1 + size(tree->left) + size(tree->right);
    }
    cout << endl;
}

int height(BinTree tree){ //mengembalikan jumlah level tree
    if(isEmpty(tree) == true){
        return -1; //tree kosong jika height = -1
    } else {
        int hl = height(tree->left);
        int hr = height(tree->right);
        int maxHeight;
        if (hl > hr){
            maxHeight = hl;
        } else {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
    cout << endl;
}
```

main.cpp
```C++
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    BinTree tree;
    createTree(tree);

    int pilih, angka;

    do {
        cout << "========= MENU BST =========" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Data" << endl;
        cout << "4. Tampilkan PreOrder" << endl;
        cout << "5. Tampilkan InOrder" << endl;
        cout << "6. Tampilkan PostOrder" << endl;
        cout << "7. Size Tree (jumlah node)" << endl;
        cout << "8. Height Tree (tinggi level)" << endl;
        cout << "9. Tampilkan mostright" << endl;
        cout << "10. Tampilkan mostleft" << endl;
        cout << "11. Delete Seluruh Tree" << endl;
        cout << "0. Keluar" << endl;
        cout << "pilihan anda : ";
        cin >> pilih;
        cout << endl;

        switch (pilih){
        case 1:
            cout << "Masukkan angka: ";
            cin >> angka;
            insertNode(tree, alokasi(angka));
            cout << endl;
            break;

        case 2:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dihapus: ";
                cin >> angka;
                if(deleteNode(tree, angka)){
                    cout << "Data " << angka << " berhasil dihapus!" << endl;
                } else {
                    cout << "Data " << angka << " tidak ditemukan!" << endl;
                }
            }
            cout << endl;
            break;

        case 3:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dicari: ";
                cin >> angka;
                searchByData(tree, angka);
            }
            cout << endl;
            break;

        case 4:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PreOrder : ";
                preOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 5:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "InOrder : ";
                inOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 6:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PostOrder : ";
                postOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 7:
            cout << "Size Tree = " << size(tree) << endl;
            cout << endl;
            break;

        case 8:
            cout << "Height Tree = " << height(tree) << endl;
            cout << endl;
            break;

        case 9: 
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostright : " << mostRight(tree)->angka << endl;
                cout << endl;
            }
            break;
        
        case 10:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostleft : " << mostLeft(tree)->angka << endl;
                cout << endl;
            }
            break;

        case 11:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                deleteTree(tree);
                cout << "Seluruh tree berhasil dihapus!" << endl;
            }
            cout << endl;
            break;

        case 0:
            cout << "Keluar dari program..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }

    } while (pilih != 0);

    return 0;
}
```
Kode pada guided ini dipakai untuk nunjukin cara kerja Binary Search Tree (BST). Di dalamnya ada fungsi buat bikin node, masukin data ke tree, nyari data, hapus data, sampai nampilin isi tree dengan beberapa cara. Di bagian main, sudah disediain menu supaya kita bisa milih operasi yang mau dijalankan. Intinya, guided ini kasih contoh lengkap gimana BST dipakai dan dijalankan dalam satu program.

## Unguided 

### 1. 
<img width="707" height="687" alt="Image" src="https://github.com/user-attachments/assets/b4f8e3a1-a586-4296-bd3b-7f98e1ee6de1" />

bstree.h
```C++
#ifndef BSTREE_H
#define BSTREE_H
#define Nil NULL

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void printInorder(address root);

#endif
```

bstree.cpp
```C++
#include "bstree.h"
#include <iostream>
using namespace std;

address alokasi(infotype x) {
    address p = new Node;
    if (p != Nil) {
        p->info = x;
        p->left = Nil;
        p->right = Nil;
    }
    return p;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    }
    else if (x < root->info) {
        insertNode(root->left, x);
    }
    else if (x > root->info) {
        insertNode(root->right, x);
    }
}

address findNode(infotype x, address root) {
    if (root == Nil) {
        return Nil;
    } else if (x == root->info) {
        return root;
    } else if (x < root->info) {
        return findNode(x, root->left);
    } else {
        return findNode(x, root->right);
    }
}

void printInorder(address root) {
    if (root == Nil) return;

    printInorder(root->left);
    cout << root->info << " - ";
    printInorder(root->right);
}
```

main.cpp
```C++
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "Hello World!" << endl;

    address root = Nil;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);

    printInorder(root);   
    cout << endl;

    return 0;
}
```
#### Output:
<img width="549" height="69" alt="Image" src="https://github.com/user-attachments/assets/dca4faef-2b48-4538-b4e5-ef8332f8a7a4" />

Pada soal nomor 1 ini, program dibuat untuk membangun sebuah Binary Search Tree (BST) dan menampilkannya dalam urutan yang benar. Strukturnya dibuat menggunakan pointer, dan ada beberapa fungsi dasar seperti alokasi, insertNode, findNode, dan printInorder. Fungsi insertNode digunakan untuk memasukkan angka ke dalam tree sesuai aturan BST, yaitu jika angkanya lebih kecil maka masuk ke kiri, dan kalau lebih besar masuk ke kanan. Di bagian main.cpp, kita memasukkan beberapa data ke tree, yaitu 1, 2, 6, 4, 5, 3, 6, dan 7. Angka 6 muncul dua kali, namun karena BST tidak menyimpan data yang duplikat, angka 6 yang kedua otomatis tidak dimasukkan. Setelah semua data dimasukkan, fungsi printInorder dipanggil untuk menampilkan isi tree secara terurut. Hasil akhirnya muncul sebagai “1 - 2 - 3 - 4 - 5 - 6 - 7 -”, yang menunjukkan bahwa proses insert dan traversal pada BST sudah berjalan dengan benar.

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/e7304d98-c050-48e4-81ab-e71ca70cf861" />


### 2. 
<img width="748" height="782" alt="Image" src="https://github.com/user-attachments/assets/cacb830b-a93f-4217-8600-eea2138df9ec" />

bstree.h
```C++
#ifndef BSTREE_H
#define BSTREE_H

#define Nil NULL

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void printInorder(address root);
int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
int hitungKedalaman(address root, int start);


#endif
```

bstree.cpp
```C++
#include "bstree.h"
#include <iostream>
using namespace std;

address alokasi(infotype x) {
    address p = new Node;
    if (p != Nil) {
        p->info = x;
        p->left = Nil;
        p->right = Nil;
    }
    return p;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    }
    else if (x < root->info) {
        insertNode(root->left, x);
    }
    else if (x > root->info) {
        insertNode(root->right, x);
    }
}

address findNode(infotype x, address root) {
    if (root == Nil) {
        return Nil;
    }
    else if (x == root->info) {
        return root;
    }
    else if (x < root->info) {
        return findNode(x, root->left);
    }
    else {
        return findNode(x, root->right);
    }
}

void printInorder(address root) {
    if (root == Nil) return;

    printInorder(root->left);
    cout << root->info << " - ";
    printInorder(root->right);
}

int hitungJumlahNode(address root) {
    if (root == Nil) return 0;

    return 1 + 
           hitungJumlahNode(root->left) + 
           hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root) {
    if (root == Nil) return 0;

    return root->info + 
           hitungTotalInfo(root->left) + 
           hitungTotalInfo(root->right);
}

int hitungKedalaman(address root, int start) {
    if (root == Nil) return start;

    int kiri  = hitungKedalaman(root->left,  start + 1);
    int kanan = hitungKedalaman(root->right, start + 1);

    return (kiri > kanan ? kiri : kanan);
}
```

main.cpp
```C++
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {

    cout << "Hello World!" << endl;

    address root = Nil;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);

    printInorder(root);
    cout << endl;

    cout << "kedalaman : " << hitungKedalaman(root, 0) << endl;
    cout << "jumlah node : " << hitungJumlahNode(root) << endl;
    cout << "total : " << hitungTotalInfo(root) << endl;

    return 0;
}
```
#### Output:
<img width="553" height="141" alt="Image" src="https://github.com/user-attachments/assets/7ebe1266-9c21-4f35-b9e8-6ef98f431b1c" />

Pada soal nomor 2, program BST dari soal sebelumnya ditambah tiga fungsi baru, yaitu hitungJumlahNode, hitungTotalInfo, dan hitungKedalaman. Fungsi hitungJumlahNode dipakai untuk menghitung berapa banyak node yang ada di dalam tree. hitungTotalInfo digunakan untuk menjumlahkan semua nilai yang tersimpan pada node-node di BST. Sedangkan hitungKedalaman berfungsi untuk mengetahui seberapa dalam tree tersebut, atau level maksimal yang dimilikinya. Setelah memasukkan data 1, 2, 6, 4, 5, 3, 6, dan 7, program menampilkan hasil perhitungan tersebut. Hasil akhirnya menunjukkan bahwa tree memiliki kedalaman 3, jumlah node 7, dan total seluruh nilai node adalah 28. Dengan tambahan fungsi-fungsi ini, program bisa memberikan informasi lebih lengkap tentang struktur BST yang sudah dibuat.

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/d9407977-3382-4a37-9222-0db36a0b9ae5" />

### 3. 
<img width="555" height="341" alt="Image" src="https://github.com/user-attachments/assets/61d9fcdf-4115-4e04-b101-58ad443b396a" />

bstree.h
```C++
#ifndef BSTREE_H
#define BSTREE_H

#define Nil NULL

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);

void PreOrder(address root);
void PostOrder(address root);

#endif
```

bstree.cpp
```C++
#include "bstree.h"
#include <iostream>
using namespace std;

address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = Nil;
    p->right = Nil;
    return p;
}
void PreOrder(address root) {
    if (root == Nil) return;
    cout << root->info << " - ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void PostOrder(address root) {
    if (root == Nil) return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->info << " - ";
}
```

main.cpp
```C++
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {

    address root = alokasi(6);
    root->left = alokasi(4);
    root->right = alokasi(7);

    root->left->left = alokasi(2);
    root->left->right = alokasi(5);

    root->left->left->left = alokasi(1);
    root->left->left->right = alokasi(3);

    cout << "pre-order  : ";
    PreOrder(root);
    cout << endl;

    cout << "post-order : ";
    PostOrder(root);
    cout << endl;

    return 0;
}
```
#### Output:
<img width="599" height="88" alt="Image" src="https://github.com/user-attachments/assets/46ada2d9-a1a2-4710-8a7f-b84e1afd5b82" />

Program pada soal nomor 3 digunakan untuk menampilkan urutan data dari sebuah tree yang sudah ditentukan pada modul dengan menggunakan dua jenis traversal, yaitu preorder dan postorder. Jadi, program ini hanya bertujuan untuk membaca dan mencetak isi tree sesuai aturan kedua traversal tersebut.

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/5b5a8ef3-1f5a-484e-b21a-892d571f714f" />



## Kesimpulan
Praktikum ini memberikan pemahaman tentang cara kerja struktur data tree, khususnya Binary Search Tree, melalui penerapan operasi dasar seperti insert, pencarian, dan traversal untuk membaca isi tree.

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
