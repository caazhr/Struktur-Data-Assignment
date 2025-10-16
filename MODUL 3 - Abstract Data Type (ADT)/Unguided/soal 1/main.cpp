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
