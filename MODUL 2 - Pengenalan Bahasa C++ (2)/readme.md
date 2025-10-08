
# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (2)</h1>
<p align="center">Neisya Azzahra Rasin</p>

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

### 1. [Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3]

```C++
#include <iostream>
using namespace std;

int main() {
    int A[3][3], B[3][3], C[3][3];

    cout << "\nMasukkan angka matriks A (3x3):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> A[i][j];
        }
    }

    cout << "\nMasukkan angka matriks B (3x3):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> B[i][j];
        }
    }

    cout << "\nHasil Penjumlahan Matriks (A + B):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = A[i][j] + B[i][j];
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nHasil Pengurangan Matriks (A - B):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = A[i][j] - B[i][j];
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nHasil Perkalian Matriks (A x B):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}

```
#### Output:
<img width="1098" height="579" alt="Image" src="https://github.com/user-attachments/assets/9df9336d-0089-4d70-ad7d-ef1774cd812f" />

Kode di atas digunakan untuk menghitung Penjumlahan, pengurangan, dan perkalian dari 2 matriks yang diinput user.

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/5c15915e-54fc-434b-bcba-3c3b383d684e" />

### 2. [Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel]

```C++
#include <iostream>
using namespace std;

void tukar3_ptr(int *a, int *b, int *c) {
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

void tukar3_ref(int &a, int &b, int &c) {
    int temp = a;
    a = b;
    b = c;
    c = temp;
}

int main() {
    int a = 10, b = 20, c = 30;

    cout << "Sebelum Penukaran:" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    tukar3_ptr(&a, &b, &c);
    cout << "\nSetelah Penukaran (pointer):" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    tukar3_ref(a, b, c);
    cout << "\nSetelah Penukaran (refrence):" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    return 0;
}

```
#### Output:
<img width="1117" height="200" alt="Image" src="https://github.com/user-attachments/assets/1b9fa623-403d-4d33-8173-d88a3da3a9d0" />

Kode di atas digunakan untuk menukar nilai tiga variabel (a, b, c) menggunakan dua cara: pointer dan reference.
Fungsi tukar3_ptr() menukar nilai melalui alamat memori variabel, sedangkan tukar3_ref() menukar langsung lewat alias variabel.

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/5a1f30a9-cffd-418f-9715-f9d3e787d013" />

### 3. [Diketahui sebuah array 1 dimensi sebagai berikut : arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55}
Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur hitungRataRata() untuk menghitung nilai rata – rata! Buat program menggunakan menu switch-case seperti berikut ini :
--- Menu Program Array ---

1. Tampilkan isi array
2. cari nilai maksimum
3. cari nilai minimum
4. Hitung nilai rata - rata]

```C++
#include <iostream>
using namespace std;

int cariMaksimum(int arr[], int n) {
    int maks = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maks)
            maks = arr[i];
    }
    return maks;
}

int cariMinimum(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

void hitungRataRata(int arr[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    float rata = total / n;
    cout << "Nilai rata-rata = " << rata << endl;
}

int main() {
    int arrA[] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int n = sizeof(arrA) / sizeof(arrA[0]);
    int pilihan;

    do {
        cout << "\n--- Menu Program Array ---\n";
        cout << "1. Tampilkan isi array\n";
        cout << "2. Cari nilai maksimum\n";
        cout << "3. Cari nilai minimum\n";
        cout << "4. Hitung nilai rata-rata\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Isi array: ";
                for (int i = 0; i < n; i++)
                    cout << arrA[i] << " ";
                cout << endl;
                break;

            case 2:
                cout << "Nilai maksimum = " << cariMaksimum(arrA, n) << endl;
                break;

            case 3:
                cout << "Nilai minimum = " << cariMinimum(arrA, n) << endl;
                break;

            case 4:
                hitungRataRata(arrA, n);
                break;

            case 5:
                cout << "Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);

    return 0;
}

```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Program ini digunakan untuk mengolah data array 1 dimensi dengan berbagai operasi dasar, yaitu menampilkan isi array, mencari nilai maksimum dan minimum, serta menghitung nilai rata-rata.
Fungsi cariMaksimum() dan cariMinimum() masing-masing mencari nilai terbesar dan terkecil dengan membandingkan setiap elemen array. Prosedur hitungRataRata() menjumlahkan semua elemen dan membaginya dengan jumlah data.
Di dalam main(), program menampilkan menu menggunakan switch-case agar pengguna bisa memilih operasi yang ingin dijalankan, dan perulangan do-while membuat menu terus muncul sampai pengguna memilih keluar.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/41e9641c-ad4e-4e50-9ca4-a0215e336b04)


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
