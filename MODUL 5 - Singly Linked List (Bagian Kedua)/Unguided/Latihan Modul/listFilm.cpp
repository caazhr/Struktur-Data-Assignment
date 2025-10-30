#include "listFilm.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if (List.first == Nil){
         return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
}

address alokasi(string judul, string genre, float rating) {
    address nodeBaru = new node;
    nodeBaru->isidata.judul = judul;
    nodeBaru->isidata.genre = genre;
    nodeBaru->isidata.rating = rating;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void delFirst(linkedlist &List) {
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil dihapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { 
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.judul << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List))
        cout << "List kosong." << endl;
    else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Judul Film : " << nodeBantu->isidata.judul
                 << ", Genre : " << nodeBantu->isidata.genre
                 << ", Rating : " << nodeBantu->isidata.rating << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

void deleteList(linkedlist &List) {
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while (nodeBantu != Nil) {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "Seluruh list berhasil dihapus!" << endl;
}

void updateFirst(linkedlist List) {
    if (isEmpty(List) == true){
           cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama Judul : ";
        cin >> List.first->isidata.judul;
        cout << "Genre : ";
        cin >> List.first->isidata.genre;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List) {
    if (isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama Judul : ";
        cin >> nodeBantu->isidata.judul;
        cout << "Genre : ";
        cin >> nodeBantu->isidata.genre;
        cout << "Rating : ";
        cin >> nodeBantu->isidata.rating;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev) {
    if (isEmpty(List) == true){
        cout << "List kosong!" << endl;
    }else {
       if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.judul << " : " << endl;
            cout << "Nama Judul : ";
            cin >> nodeBantu->isidata.judul;
            cout << "Genre : ";
            cin >> nodeBantu->isidata.genre;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void FindNodeByData(linkedlist list, string judul) {
    if (isEmpty(list)== true){
        cout << "List kosong!" << endl;
    } else {
    address nodeBantu = list.first;
    int posisi = 0;

    bool found = false;
    while (nodeBantu != Nil) {
        posisi++;
        if (nodeBantu->isidata.judul == judul) {
            cout << "Film \"" << judul << "\" ditemukan di posisi ke-" << posisi << "!" << endl;
            cout << "Nama Judul : " << nodeBantu->isidata.judul
                << ", Genre : " << nodeBantu->isidata.genre
                << ", Rating : " << nodeBantu->isidata.rating << endl;
            found = true;
            break;
        }
        nodeBantu = nodeBantu->next;
    }

    if(found == false){
            cout << "Node dengan data " << judul << " tidak ditemukan!" << endl;
        }
    }
     cout << endl;
}

void FindNodeByAddress(linkedlist list, address node) {
    if (isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if (nodeBantu == node) {
                cout << "Node ditemukan di posisi ke-" << posisi << "!" << endl;
                cout << "Judul Film : " << nodeBantu->isidata.judul
                    << ", Genre : " << nodeBantu->isidata.genre
                    << ", Rating : " << nodeBantu->isidata.rating << endl;
                    found = true;
                    break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;

}

void FindNodeByRange(linkedlist list, float ratingAwal, float ratingAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Film dengan rating antara " << ratingAwal << " dan " << ratingAkhir << " ---" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float rating = nodeBantu->isidata.rating;
            if (rating >= ratingAwal && rating <= ratingAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Judul : " << nodeBantu->isidata.judul << ", Genre : " << nodeBantu->isidata.genre << ", Rating : " << nodeBantu->isidata.rating << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada film dalam rentang rating tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}