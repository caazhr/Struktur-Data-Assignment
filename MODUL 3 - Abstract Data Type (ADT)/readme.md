
# <h1 align="center">Laporan Praktikum Modul Abstract Data Type (ADT)</h1>
<p align="center">Neisya Azzahra Rasin</p>

## Dasar Teori

(blm diisi)

## Guided 

### 1. [program menghitung rata-rata nilai mahasiswa]
mahasiswa.cpp
```C++
#include <iostream>
using namespace std;
#include "mahasiswa.h"
void inputMhs (mahasiswa &m) {
cout << "input nim = ";
cin >> (m).nim;
cout << "input nilai = ";
cin >> (m).nilail;
cout << "input nilai2 = ";
cin >> (m).nilai2;
}
float rata2(mahasiswa m){
return (m.nilail + m.nilai2) / 2.0;
}
```

mahasiswa.h
```C++
#ifndef MAHASISWA H INCLUDED
#define MAHASISWA_H_INCLUDED
struct mahasiswa{
char nim[10];
int nilail, nilai2;
};
void inputMhs (mahasiswa &m);
float rata2(mahasiswa m);
#endif 
```

main.cpp
```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;
int main() {
mahasiswa mhs;
inputMhs (mhs);
cout << "rata-rata = " << rata2(mhs);
return 0;
}
```
Program untuk menghitung rata-rata nilai mahasiswa ini terdiri dari tiga file, yaitu : mahasiswa.h, mahasiswa.cpp, dan main.cpp.  program ini dibuat untuk mengolah data mahasiswa secara sederhana. Pengguna diminta memasukkan NIM serta dua nilai mahasiswa sebagai input. Program kemudian menghitung rata-rata dari kedua nilai tersebut dan menampilkan hasilnya sebagai output.


## Unguided 

### 1.** [Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array
dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI
dengan rumus 0.3*uts+0.4*uas+0.3*tugas.]
**
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
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/05a0004d-aac1-4679-a50a-df68b23e5c4b" />

### 2. [Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di-input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100. Contoh: 79 : tujuh puluh sembilan]

```C++
#include <iostream>
using namespace std;

string satuan[] = {"nol", "satu", "dua", "tiga", "empat", "lima", 
                   "enam", "tujuh", "delapan", "sembilan"};

string terbilang(int n) {
    if (n == 0) return "nol";
    else if (n == 10) return "sepuluh";
    else if (n == 11) return "sebelas";
    else if (n < 10) return satuan[n];
    else if (n < 20) return satuan[n % 10] + " belas";
    else if (n < 100) {
        int puluh = n / 10;
        int sisa = n % 10;
        string hasil = satuan[puluh] + " puluh";
        if (sisa > 0) hasil += " " + satuan[sisa];
        return hasil;
    } 
    else if (n == 100) return "seratus";
    return "";
}

int main() {
    int angka;
    cout << "Masukkan angka (0 - 100): ";
    cin >> angka;

    if (angka < 0 || angka > 100) {
        cout << "Masukkan bilangan bulat positif!";
    } else {
        cout << angka << " : " << terbilang(angka) << endl;
    }
    return 0;
}
```
#### Output:
<img width="1071" height="77" alt="Image" src="https://github.com/user-attachments/assets/4ca01138-10c6-4302-91bf-fc8ac16c003d" />


Kode di atas digunakan untuk Mengubah angka bilangan bulat positif (0-100) menjadi bentuk text menggunakan bahasa indonesia.

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/f859e8fb-3598-464b-b97f-74fc7cc55a39" />


### 3. [Buatlah program yang dapat memberikan input dan output sbb.
<img width="143" height="135" alt="Image" src="https://github.com/user-attachments/assets/d0a1336c-3a10-43fa-8269-d6e101374fe0" />]

```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input: ";
    cin >> n;

    cout << "Output:" << endl;

    for (int i = n; i >= 1; i--) {
        for (int s = n; s > i; s--) {
            cout << "  "; 
        }

        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        cout << "* ";

        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }

        cout << endl;
    }
   
    for (int s = 0; s < n; s++) {
        cout << "  ";
    }
    cout << "*" << endl;

    return 0;
}
```
#### Output:
<img width="1106" height="152" alt="Image" src="https://github.com/user-attachments/assets/6ea97fb3-a91e-4610-8bc1-7263438af34b" />


Kode di atas digunakan untuk menghasilkan output angka dengan pola simetris berbentuk piramida

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/f2885f52-e5d2-47f6-83d3-0e3942608387" />




## Kesimpulan
Ringkasan dan interpretasi pandangan saya adalah setelah mempelajari modul ini saya makin memahami bahwa codingan itu kuncinya ada di logika, bukan hanya menghafal sintaks.

saya juga jadi belajar mengenai struktur dasar pemrograman C++. Menurut saya penguasaan konsep dasar C++ sangat penting krna menjadi fondasi untuk mempelajari C++ dipertemuan selanjutnya.


## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
