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
