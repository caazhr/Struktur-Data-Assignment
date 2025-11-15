# <h1 align="center">Laporan Praktikum Modul Doubly linked List (bagian pertama)</h1>
<p align="center">Neisya Azzahra Rasin</p>

## Dasar Teori
Doubly Linked List adalah linked list yang masing-masing elemennya memiliki 2 successor, yaitu successor yg menunjuk pada elemen sebelumnya (prev) dan successor yg menunjuk pada elemen sesudahnya (next).
Komponen-komponen dalam doubly linked list:
- First    : pointer pada list yg menunjuk pada elemen pertama list
- Last    : Pointer pada list yg menunjuk pada element terakhir list
- Next    : Pointer pada elemen sebagai succesor yg menunjuk pada elemen didepannya
- Prev    : pointer pada elemen sebagai successor yg menunjuk pada elemen dibelakangnya.
  
**Operasi Insert**
a. insert first -> menyisipkan node baru di depan list
b. insert last -> menyisipkan node baru di akhir list
c. insert after -> menyisipkan node baru setelah node tertentu 
d. insert before -> kebalikan dari insert after. perbedaan dari insert after dan before terletak pada pencarian elemennya

**Operasi Delete**
a. delete first -> menghapus node pertama 
b. delete last -> menghapus node terakhir 
c. delete after -> menghapus node yg berada setelah node tertentu
d. delete before -> kebalikan dari delete after. perbedaan delete after dan before terletak pada pencarian elemennya. 

**Update, View, dan Searching **
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

### 1. [Nama Topik]

```C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code guided praktikan" << endl;
    return 0;
}
```
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Unguided 

### 1. [Soal]

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
