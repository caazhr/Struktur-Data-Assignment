#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    infotype x;

    pushAscending(S, {3, "tiga"});
    pushAscending(S, {4, "empat"});
    pushAscending(S, {8, "delapan"});
    pushAscending(S, {2, "dua"});
    pushAscending(S, {3, "tiga(2)"});
    pushAscending(S, {9, "sembilan"});

    printInfo(S);                 

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);                

    return 0;
}
