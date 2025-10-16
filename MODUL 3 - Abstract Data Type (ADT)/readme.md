
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

### 1.[Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array
dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI
dengan rumus 0.3*uts+0.4*uas+0.3*tugas.]

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

### 2. [
<img width="947" height="577" alt="Image" src="https://github.com/user-attachments/assets/63ec5a45-4d0f-4112-9134-6fb73b8eeb05" />]

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


### 3. [Buatlah program dengan ketentuan: 
-) 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
-) fungsi/prosedur yang menampilkan isi sebuah array integer 2D
-) fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
-) fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer]

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
<img width="1106" height="152" alt="Image" src="https://github.com/user-attachments/assets/6ea97fb3-a91e-4610-8bc1-7263438af34b" />


Kode di atas digunakan untuk menghasilkan output angka dengan pola simetris berbentuk piramida

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/f2885f52-e5d2-47f6-83d3-0e3942608387" />




## Kesimpulan
Ringkasan dan interpretasi pandangan saya adalah setelah mempelajari modul ini saya makin memahami bahwa codingan itu kuncinya ada di logika, bukan hanya menghafal sintaks.

saya juga jadi belajar mengenai struktur dasar pemrograman C++. Menurut saya penguasaan konsep dasar C++ sangat penting krna menjadi fondasi untuk mempelajari C++ dipertemuan selanjutnya.


## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
