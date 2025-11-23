
# <h1 align="center">Laporan Praktikum Modul Queue</h1>
<p align="center">Neisya Azzahra Rasin</p>

## Dasar Teori

Queue cara kerjanya mirip antrean sehari-hari: siapa yang datang duluan, dia yang dilayani duluan FIFO (First In First Out). Data baru selalu masuk lewat bagian belakang antrian lewat operasi enqueue, dan data yang keluar selalu diambil dari bagian depan lewat dequeue. Dalam implementasinya menggunakan array, ada beberapa cara untuk mengatur posisi head dan tail supaya antrian bekerja dengan benar.

Cara pertama adalah yang paling sederhana. Pada metode ini, head selalu berada di posisi awal array, sementara tail terus bergerak maju setiap kali ada data baru. Ketika dequeue dilakukan, semua elemen digeser ke kiri supaya head tetap berada di depan. Walaupun mudah, cara ini kurang efisien karena proses shifting terus dilakukan.

Cara kedua lebih baik karena head dan tail bisa sama-sama bergerak tanpa harus menggeser elemen. Namun ada satu kelemahan: bisa muncul kondisi “penuh semu”, yaitu tail sudah berada di ujung array, padahal sebenarnya masih ada ruang kosong di bagian depan akibat head yang sudah maju.

Cara ketiga adalah circular queue, dan ini yang paling efisien. Pada metode ini, head dan tail bisa “muter” kembali ke indeks awal ketika mencapai batas array. Dengan begitu, ruang kosong di depan bisa digunakan kembali tanpa perlu shifting. Metode ini jauh lebih efisien dan umum dipakai ketika membangun antrian berbasis array karena benar-benar memanfaatkan ruang yang ada.
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
