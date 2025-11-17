# <h1 align="center">Laporan Praktikum Modul STACK</h1>
<p align="center">Neisya Azzahra Rasin</p>

## Dasar Teori
Stack adalah salah satu struktur data yang cara kerjanya seperti tumpukan barang, di mana yang paling atas adalah yang paling dulu diambil. Prinsip ini dikenal sebagai LIFO (Last In First Out). Stack hanya punya satu akses, yaitu bagian TOP, yang selalu menunjuk ke elemen paling atas. Kalau stack masih kosong, TOP biasanya bernilai –1 (untuk array) atau NULL (untuk pointer).

Di dalam stack ada dua operasi utama. Push dipakai untuk menambah data ke bagian atas stack, sedangkan pop digunakan untuk mengambil sekaligus menghapus data teratas. Selain itu, ada juga fungsi-fungsi pendukung seperti createStack untuk menyiapkan stack kosong, isEmpty/isFull untuk mengecek keadaan stack, dan printInfo untuk menampilkan isi stack dari atas ke bawah.

Stack bisa dibuat dengan dua cara: memakai array, yang sederhana tapi ukurannya tetap, atau memakai pointer, yang lebih fleksibel karena jumlah elemennya bisa bertambah selama memori masih cukup. Di modul ini juga ada beberapa fitur tambahan seperti balikStack untuk membalik isi stack, pushAscending untuk memasukkan data dengan posisi terurut, dan getInputStream untuk membaca input karakter satu per satu lalu memasukkannya ke stack.


## Guided 

### 1. [Stack menggunakan linked list]

stack.h
```C++
#ifndef STACK 
#define STACK
#define Nil NULL

#include <iostream>
using namespace std;

typedef struct node*address;

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty (stack listStack);
void createStack (stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);

void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif
```

stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```

main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);
    
    return 0;
}
```

Program ini adalah contoh cara membuat dan memakai stack dengan linked list. Di dalamnya ada fitur untuk menambah data (push), menghapus data (pop), melihat isi stack, mengubah data tertentu, dan mencari data.Fungsi–fungsi tersebut dijalankan lewat main, lalu hasilnya ditampilkan ke layar memakai cout.


### 2. [Stack menggunakan array]

stack.h
```C++
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

// Ubah kapasitas sesuai kebutuhan
const int MAX = 10;

struct stackTable {
    int data[MAX];
    int top; // -1 = kosong
};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);

void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);

#endif
```

stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stackTable s){
    return s.top == -1;
}

bool isFull(stackTable s){
    return s.top == MAX - 1;
}

void createStack(stackTable &s){
    s.top = -1;
}

void push(stackTable &s, int angka){
    if(isFull(s)){
        cout << "Stack penuh!" << endl;
    } else {
        s.top++;
        s.data[s.top] = angka;
        cout << "Data " << angka << " berhasil ditambahkan kedalam stack!" << endl;
    }
}

void pop(stackTable &s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        int val = s.data[s.top];
        s.top--;
        cout << "Data " << val << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stackTable &s, int posisi){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }
    if(posisi <= 0){
        cout << "Posisi tidak valid!" << endl;
        return;
    }

    // index = top - (posisi - 1)
    int idx = s.top - (posisi - 1);
    if(idx < 0 || idx > s.top){
        cout << "Posisi " << posisi << " tidak valid!" << endl;
        return;
    }

    cout << "Update data posisi ke-" << posisi << endl;
    cout << "Masukkan angka : ";
    cin >> s.data[idx];
    cout << "Data berhasil diupdate!" << endl;
    cout << endl;
}

void view(stackTable s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        for(int i = s.top; i >= 0; --i){
            cout << s.data[i] << " ";
        }
    }
    cout << endl;
}

void searchData(stackTable s, int data){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }
    cout << "Mencari data " << data << "..." << endl;
    int posisi = 1;
    bool found = false;

    for(int i = s.top; i >= 0; --i){
        if(s.data[i] == data){
            cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
            cout << endl;
            found = true;
            break;
        }
        posisi++;
    }

    if(!found){
        cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
        cout << endl;
    }
}
```

main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stackTable s;
    createStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(s);
    cout << endl;

    pop(s);
    pop(s);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(s);
    cout << endl;

    // Posisi dihitung dari TOP (1-based)
    update(s, 2);
    update(s, 1);
    update(s, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(s);
    cout << endl;

    searchData(s, 4);
    searchData(s, 9);

    return 0;
}
```

Program ini adalah contoh penggunaan stack yang dibuat menggunakan array. Di dalamnya terdapat beberapa operasi dasar seperti menambah data ke bagian atas stack (push), menghapus data teratas (pop), mengubah data pada posisi tertentu, menampilkan seluruh isi stack, dan mencari data. Semua proses tersebut dijalankan melalui fungsi main, lalu hasilnya ditampilkan dengan cout.

## Unguided 

### 1. 
<img width="819" height="777" alt="Image" src="https://github.com/user-attachments/assets/c23ff45e-9321-41f4-921a-6c2fe42fa13b" />

stack.h
```C++
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <string>
using namespace std;

const int MAX = 20;

struct infotype {
    int value;      
    string label;   
};

struct Stack {
    infotype info[MAX]; 
    int top;            
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif

```

stack.cpp 
```C++
#include "stack.h"
#include <iostream>
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return (S.top == -1);
}

bool isFull(Stack S) {
    return (S.top == MAX - 1);
}

void push(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack penuh!" << endl;
        return;
    }
    S.top++;
    S.info[S.top] = x;
}

infotype pop(Stack &S) {
    infotype dummy;
    dummy.value = 0;
    dummy.label = "";

    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
        return dummy;
    }

    infotype x = S.info[S.top];
    S.top--;
    return x;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; --i) {
        cout << S.info[i].value << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack T;
    createStack(T);

    while (!isEmpty(S)) {
        infotype x = pop(S);
        push(T, x);
    }
    S = T;
}
```
main.cpp
```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    infotype x;

    x.value = 3; x.label = "tiga";      push(S, x);
    x.value = 4; x.label = "empat";     push(S, x);
    x.value = 8; x.label = "delapan";   push(S, x);
    pop(S);                           
    x.value = 2; x.label = "dua";       push(S, x);
    x.value = 3; x.label = "tiga";      push(S, x);
    pop(S);                           
    x.value = 9; x.label = "sembilan";  push(S, x);

    printInfo(S);                      

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);                      

    return 0;
}

```
#### Output:
<img width="612" height="202" alt="Image" src="https://github.com/user-attachments/assets/43df6448-5573-4070-afa2-2fdb2c699112" />

Program di atas bekerja dengan cara memasukkan beberapa data ke dalam stack menggunakan push, lalu menghapus beberapa data teratas dengan pop. Setelah itu, program menampilkan isi stack dari elemen paling atas hingga paling bawah melalui printInfo. Selanjutnya, program membalik urutan elemen dengan memindahkan seluruh isi stack ke stack lain menggunakan fungsi balikStack, kemudian menampilkan kembali hasil akhirnya. Setiap operasi yang dijalankan akan mengubah posisi elemen, dan hasilnya langsung ditampilkan ke layar menggunakan cout.

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/e8dd8c6a-ba79-4a3d-8b38-e887f538c18e" />

### 2. 
<img width="855" height="703" alt="Image" src="https://github.com/user-attachments/assets/73b9ebcd-110a-469a-8716-ca0d1a9ecd0c" />

stack.h
```C++
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <string>
using namespace std;

const int MAX = 20;

struct infotype {
    int value;
    string label;
};

struct Stack {
    infotype info[MAX];
    int top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);

#endif
```

stack.cpp 
```C++
#include "stack.h"
#include <iostream>
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return (S.top == -1);
}

bool isFull(Stack S) {
    return (S.top == MAX - 1);
}

void push(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack penuh!" << endl;
        return;
    }
    S.top++;
    S.info[S.top] = x;
}

infotype pop(Stack &S) {
    infotype dummy;
    dummy.value = 0;
    dummy.label = "";

    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
        return dummy;
    }

    infotype x = S.info[S.top];
    S.top--;
    return x;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; --i) {
        cout << S.info[i].value << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack T;
    createStack(T);

    while (!isEmpty(S)) {
        infotype x = pop(S);
        push(T, x);
    }
    S = T;
}

void pushAscending(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack penuh!" << endl;
        return;
    }

    Stack T;
    createStack(T);

    while (!isEmpty(S) && S.info[S.top].value > x.value) {
        push(T, pop(S));
    }

    push(S, x);

    while (!isEmpty(T)) {
        push(S, pop(T));
    }
}
```
main.cpp
```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    infotype x;

    pushAscending(S, {3, "tiga"});
    pushAscending(S, {4, "empat"});
    pushAscending(S, {8, "delapan"});
    pushAscending(S, {2, "dua"});
    pushAscending(S, {3, "tiga(2)"});
    pushAscending(S, {9, "sembilan"});

    printInfo(S);                 

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);                

    return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/41e9641c-ad4e-4e50-9ca4-a0215e336b04)

### 3. -
stack.h
```C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code unguided praktikan" << endl;
    return 0;
}
```

stack.cpp 
```C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code unguided praktikan" << endl;
    return 0;
}
```
main.cpp
```C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code unguided praktikan" << endl;
    return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/41e9641c-ad4e-4e50-9ca4-a0215e336b04)


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
