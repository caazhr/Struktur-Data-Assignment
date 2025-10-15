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
