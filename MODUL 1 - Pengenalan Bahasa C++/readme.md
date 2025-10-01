# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (1)</h1>
<p align="center">Neisya Azzahra Rasin</p>

## Dasar Teori

Pada Modul 1 ini berisi panduan untuk menginstal dan menggunakan code blocks dan mempelajari dasar-dasar dan pengenalan mengenai bahasa pemrograman C++.

Dimulai dengan pengenalan code bloks, instalasi code bloks, cara menggunakannya.
selanjutnya membahas sekilas mengenai C++
jadi C++ diciptakan oleh Bjarne Stroustrup di AT&T Bell Laboratories awal tahun 1980-an didasarkan pada C ANSI,.

Pada modul 1 ini membahas mengenai struktur program C++.
Selanjutnya membahas pengenal(identifier) -> nama yang digunakan untuk variabel, konstanta, fungsi, atau objek lain. Dalam modul ini membahas juga mengenai tipe dasar, dari yang saya pelajari dalam modul ini data berdasarkan jenisnya dibagi ke dalam 5 kelompok, yaitu: 
1. Bil bulat(integer),
2. Bil real [resisi-tunggal,
3. Bil real presisi-ganda,
4. Karakterr,
5. Tak bertipe.
Adapun daftar tipe data, yaitu: char, int, long, float, double.

lalu membahas variabel, jadi variabel merupakan program yang digunakan untuk menyimpan nilai. 
lalu membahas konstanta -> menyatakan nilai yang selalu tetap dan mempunyai tipe. 
input/output -> merupakan masukan dan keluaran. 
operator -> simbol yang digunakan untuk melakukan suatu operasi atau manipulasi.
Bahasa C++ merupakan bahasa yang kaya dengan operator yaitu:
1. operator Aritmatika
2. Operator Pengerjaan (Assigment)
3. Operator Logika
4. Operator Unary
5. Operator Sizeof
6. Operator Increment dan Decrement

Kondisional -> (if, if-else, switch)
Perulangan (Looping) -> Perulangan digunakan untuk menjalankan satu pernyataan berulang kali selama kondisi terpenuhi
Struct -> merupakan tipe data bentukan yang isinya kumpulan dari variabel yang dinyatakan sebuah nama, variabelnya bisa memiliki tipe yang berbeda-beda. Jadi struct digunakan untuk mengelompokan informasi yang saling berkaitan.

## Guided 

### 1. [Hello Word]

```C++
#include <iostream>
using namespace std;

int main() {
    // Write C++ code here
   cout << "Hello world!";
    return 0;
}
```
Kode di atas digunakan untuk menamplkan teks ke layar dengan output "Hello World!"

### 2. [inputOutput]

```C++
#include <iostream> 
using namespace std; 
int main() {
    int n;
    const float phi = 3.14;

    cout << "Masukkan Angka: ";
    cin >> n;

    cout << "Angka Dikeluarkan: " << n << endl;
    cout << "Nilai Konstanta Phi: " << phi << endl;
    return 0;
}
```
Kode diatas digunakan dengan cara memasukkan input angka dari user, menyimpannya dalam variabel, dan kemudian menampilkan angka bersama dengan nilai phi. 

### 3. [Operator]

```C++
#include <iostream>
using namespace std;

int main() {
   int a;
   int b;

   cout << "Masukkan Angka1: ";
    cin >> a;
    cout << "Masukkan Angka2: ";
    cin >> b;

    //operator aritmatika
    cout << "a + b = " << (a + b) << endl;
    cout << "a - b = " << (a - b) << endl;
    cout << "a * b = " << (a * b) << endl;
    cout << "a / b = " << (a / b) << endl;
    cout << "a % b = " << (a % b) << endl;

    // Operator Logika
    cout << "a > b = " << (a > b) << endl;
    cout << "a < b = " << (a < b) << endl;
    cout << "a >= b = " << (a >= b) << endl;
    cout << "a <= b = " << (a <= b) << endl;
    cout << "a == b = " << (a == b) << endl;
    cout << "a != b = " << (a != b) << endl;
    return 0;

}
```
Kode diatas digunakan untuk demonstrasi operator aritmatika dan operator logika, dengan menginput dua angka (a dan b), kemudian menghitung dan menampilkan hasil dari operasi aritmatika dan perbandingan logis antara kedua angka tersebut.

### 4. [Percabangan]

```C++
#include <iostream>
using namespace std;
int main() {
    int angka1 = 10;
    int angka2 = 20;

    if (angka1 > angka2) {
        cout << "Angka 1 lebih besar dari Angka 2" << endl;
    } else if (angka1 < angka2) {
        cout << "Angka 1 lebih kecil dari Angka 2" << endl;
    } else {
        cout << "Angka 1 sama dengan Angka 2" << endl; 
    }
    return 0;
}

```
Kode diatas digunakan untuk menguji, memandingkan dua nilai yang telah ditetapkan(angka1=10 dan angka2=20), menggunakan if-else if-else.

### 5. [Perulangan Do While]

```C++
#include <iostream>
using namespace std;

int main() {
   int i = 0;
   int j = 20;

   while (i <= 10) {
         cout << i <<  "-";
         i++;
      }
      cout << endl;

    do {
        cout << j << "-";
        j++;
    } while (j <= 10);

    return 0;
   }
```
kode diatas digunakan untuk mendemostrasikan dua jenis perulangan yaitu while dan do-while. Untuk output pada baris pertama berisi angka 0-10 dengan tanda (-) ditengah tengah angka, kemudian untuk baris kedua berisi nilai 20

### 6. [Perulangan For Do while]

```C++
#include <iostream>
using namespace std;
int main() {
   int i ;
   int j = 0;

   for (int i = 0; i < 10; i++) {
         cout << i <<  "-";
      }
      cout << endl;

    do {
        cout << j << "-";
        j++;
    } while (j < 10);

    return 0;
   }

```
Kode diatas digunakan untuk menampilkan deretan angka 0-9, dengan tanda (-) diantara angka, kode ini menggunakan dua jenis perulangan yaitu perulangan for, dan do while. jadi outputnya akan menampilkan deretan angka 0-9 sebanyak 2 kali.

### 7. [Struktur]

```C++
#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    int umur;
    
};

int main() {
  int jumlah;

  cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlah;

    Mahasiswa mhs[jumlah];

    //input data  menggunakan loop
    for (int i = 0; i < jumlah; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Masukkan Nama: ";
        cin >> mhs[i].nama;
        cout << "Masukkan Umur: ";
        cin >> mhs[i].umur;
    }
    //Tampilkan data
    cout << "\n=== Data Mahasiswa ===\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "Mahasiswa ke-" << i + 1 
             << " | Nama: " << mhs[i].nama 
             << " | Umur: " << mhs[i].umur << endl;
    }

    return 0;
}
```
kode diatas digunakan untuk mencatat nama dan umur mahasiswa yang jumlahnya ditentukan oleh user

## Unguided 

### 1. [Aritmatika]

```C++
#include <iostream>
using namespace std;

int main() {
   float a, b;

   cout << "Masukkan Angka1: ";
    cin >> a;
    cout << "Masukkan Angka2: ";
    cin >> b;

    cout << "Hasil Penjumlahan = " << (a + b) << endl;
    cout << "Hasil Pengurangan = " << (a - b) << endl;
    cout << "Hasil Perkalian = " << (a * b) << endl;
    cout << "Hasil Pembagian = " << (a / b) << endl;
   

    return 0;
}
```
#### Output:
<img width="1156" height="167" alt="Image" src="https://github.com/user-attachments/assets/8b29d765-f55f-4393-941a-fd6a09b42399" />

Kode di atas digunakan untuk menghitung penjumlahan, pengurangan, pembagian, dan perkalian. Dengan 2 buah inputan bertipe float

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/05a0004d-aac1-4679-a50a-df68b23e5c4b" />

### 2. [Angka]

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


### 3. [mirror]

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

## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
