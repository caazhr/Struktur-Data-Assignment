#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    infotype x;

    x.value = 3; x.label = "tiga";      push(S, x);
    x.value = 4; x.label = "empat";     push(S, x);
    x.value = 8; x.label = "delapan";   push(S, x);
    pop(S);                           
    x.value = 2; x.label = "dua";       push(S, x);
    x.value = 3; x.label = "tiga";      push(S, x);
    pop(S);                           
    x.value = 9; x.label = "sembilan";  push(S, x);

    printInfo(S);                      

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);                      

    return 0;
}
