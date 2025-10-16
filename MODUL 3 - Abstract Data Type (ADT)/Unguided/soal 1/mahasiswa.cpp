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
