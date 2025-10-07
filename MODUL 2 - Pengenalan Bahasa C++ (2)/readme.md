
# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (2)</h1>
<p align="center">Arvinanto Bahtiar</p>

## Dasar Teori

Pada modul 2 ini melanjutkan pengenalan mengenai C++. Pada modul ini akan membahas mengenai Array, Pointer, Fungsi, Prosedur, Parameter Fungsi.

- Array -> Kumpulan data yg memiliki nama dan tipe data yg sama. Array memiliki beberapa jenis yaitu:
  1. Array satu dimensi -> array yg hanya terdiri dari satu larik data aja.
  2. Array dua dimensi -> bisa digunakan untuk menyimpan data dalam bentuk tabel.
  3. Array berdimensi banyak -> array yg punya indeks banyak, lebih dari dua.

- Pointer -> untuk menyimpan alamat memori.
  1. Data dan Memori -> semua data disimpan di dalam RAM, yg dapat digambarkan sebagai array 1 dimensi yg sangat besar. setiap cell memori punya indeks unik sebagai identitas yg biasa disebut address
  2. Pointer dan Alamat -> pointer menyimpan alamat memori variabel lain dan dapat mengakses nilai dari variabel yg ditunjuk. Pointer juga dasar tipe var yg isinya integer dalam bentuk heksadesimal
  3. Pointer dan Array -> ada keterkaitan yg kuat antara pointer dan array. Nama array tanpa indeks merujuk pada alamat elemen ke-0 dari array.
  4. Pointer dan String -> pada C++, string itu array dari karakter yg diakhiri dengan karakter null. saat konstanta string ("  ") dipakai dengan pointer karakter, pointer itu hanya menunjuk ke string dan bukan menyalin seluruh string.

- Fungsi -> Tujuannya itu biar program lebih terstruktur dan mengurangi duplikasi kode.

- Prosedur -> pada C++, digunakan untuk merujuk pada fungsi yg tidak mengembalikan nilai, di kenal dengan fungsi void. Fungsi void melakukan tugas tertentu tanpa memberikan return value kepada pemanggilnya

- Parameter Fungsi -> parameter dibagi menjadi dua jenis yaitu :
  1. Parameter Formal : Var yg ada pada daftar parameter saat mendefinisikan fungsi.
  2. Parameter Aktual : parameter bisa berupa var, konstanta atau ungkapan yg dipakai untuk manggil fungsi

Ada tiga cara melewatkan parameter
1. Pemanggilan dengan Nilai (Call by value)
2. Pemanggilan dengan Pointer (Call by pointer)
3. Pemanggilan dengan Refrensi (Call by refrence).
   
## Guided 

### 1. [Array]

```C++
#include <iostream>
using namespace std;

int main() {
    // Array  1 dimensi
    int arr1D[5] = {10, 20, 30, 40, 50};
    cout << "Array 1 dimensi:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "arr[" << i << ":] = " << arr1D[i] << endl;
    }
    cout << endl;

    // Array 2 dimensi
    int arr2D[3][4] = {
        {1, 2, 3},
        {4, 5, 6},
    };
    cout << "Array 2 dimensi:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "arr2D[" << i << "][" << j << "] = " << arr2D[i][j]
            << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Array Multi Dimensi (3D)
    int arr3D[2][2][3] = {
        { {1, 2, 3}, {4, 5, 6} },
        { {7, 8, 9}, {10, 11, 12} } 
    };
    cout << "Array 3 dimensi:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                cout << "arr3D[" << i << "][" << j << "]["
                << k << "] = "<< arr3D[i][j][k] << endl;
            }
        }
    }

    return 0;
    
}
```
Kode di atas digunakan untuk mendeklarasikan, mendemonstrasikan, dan mengakses elemen-elemen dari array satu dimensi, dua dimensi, dan tiga dimensi.

### 2. [FunctionProcedure]

```C++
#include <iostream>
using namespace std;

void tulis (int x) {
    for (int i = 0; i < x; i++) {
        cout << "Baris ke -:" << i+1 << endl;
    }
}

int main() {
    int jum;
    cout << "Jumlah baris kata: ";
    cin >> jum;
    tulis(jum);
    return 0;
}
```
Kode di atas digunakan untuk mencetak teks berulang dengan jumlah pengulangan yg di input oleh user. Jadi kode ini minta inputan angka dari user, lalu menggunakan sebuah fungsi tulis untuk ngejalanin perulangan dan cetak baris teks sesuai dengan angka yg dimasukin user.
### 3. [Pointer]

```C++
#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
} 

int main() {
    int a =20, b =30;
    int *ptr;

    ptr = &a;

    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    cout << "Value stored in ptr (Address of a): " << ptr << endl;
    cout << "Value pointes to by ptr: " << *ptr << endl;

    tukar(&a, &b);
    cout << "After swapping, value of a = " << a << " and b = " << b << endl;

    return 0;
    
}
```
Kode di atas digunakan untuk menunjukan cara kerja pointer untuk mengakses alamat memori dan mengubah nilai variabelnya secara langsung, termasuk menukar nilai dua var menggunakan fungsi dengan parameter pointer.

### 4. [Reference]

```C++
#include <iostream>
using namespace std;

void tukar (int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 20, b = 30;
    int& ref = a;

    cout << "Nilai a: " << a << endl;
    cout << "Alamat a (&a): " << &a << endl;
    cout << "Nilai ref (alias a): " << ref << endl; 
    cout << "Alamat ref (&ref): " << &ref << endl; 

    //Mengubah nilai a lewat reference
    ref = 50;
    cout << "\nSetelah ref = 50;" << endl;
    cout << "Nilai a: " << a << endl;
    cout << "Nilai ref: " << ref << endl;

    tukar(a, b);
    cout << "After swapping, value of a=" << a << " and b=" << b << endl; 

    return 0;
}
```
Kode di atas digunakan untuk menunjukan penggunaan refrence. Refrence ini berfungsi sebagai alias dari variabel lain, jadi setiap perubahan pada refrence juga akan mengubah nilai var aslinya. Selain itu, fungsi "tukar ()" menggunakan parameter refrence agar dapat menukar nilai dua var secara langsung tanpa pointer.

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
