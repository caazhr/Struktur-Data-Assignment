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