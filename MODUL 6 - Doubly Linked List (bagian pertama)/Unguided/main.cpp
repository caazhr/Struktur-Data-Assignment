
#include <iostream>
#include "Doublylist.h"

using namespace std;

int main() {
    List L;
    createList(L);

    for (int i = 0; i < 4; i++) {
        infotype x;

        cout << "masukkan nomor polisi: ";
        cin  >> x.nopol;
        cout << "masukkan warna kendaraan: ";
        cin  >> x.warna;
        cout << "masukkan tahun kendaraan: ";
        cin  >> x.thnBuat;

        infotype kunci;
        kunci.nopol = x.nopol;
        address q = findElm(L, kunci);

        if (q != Nil) {
            cout << "nomor polisi sudah terdaftar" << endl;
        } else {
            address P = alokasi(x);
            insertFirst(L, P); 
        }

        cout << endl;
    }

    printInfo(L);
    
    infotype cari;
    cout << "Masukkan Nomor Polisi yang dicari : ";
    cin  >> cari.nopol;

    address Q = findElm(L, cari);
    cout << endl;

    if (Q != Nil) {
        cout << "Nomor Polisi : " << Q->info.nopol << endl;
        cout << "Warna        : " << Q->info.warna << endl;
        cout << "Tahun        : " << Q->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }

    infotype hapusKey;
    cout << endl;
    cout << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin  >> hapusKey.nopol;

    address target = findElm(L, hapusKey);
    address Pdel;

    if (target == Nil) {
        cout << "Data dengan nomor polisi " << hapusKey.nopol
             << " tidak ditemukan." << endl;
    } else {
        if (target == L.first) {
            deleteFirst(L, Pdel);
        } else if (target == L.last) {
            deleteLast(L, Pdel);
        } else {
            deleteAfter(L, Pdel, target->prev);
        }
        cout << "Data dengan nomor polisi " << hapusKey.nopol
             << " berhasil dihapus." << endl;
        dealokasi(Pdel);
    }

    printInfo(L);

    return 0;
}
