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
