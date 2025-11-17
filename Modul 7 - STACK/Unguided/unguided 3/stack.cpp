#include "stack.h"
#include <iostream>
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return (S.top == -1);
}

bool isFull(Stack S) {
    return (S.top == MAX - 1);
}

void push(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack penuh!" << endl;
        return;
    }
    S.top++;
    S.info[S.top] = x;
}

infotype pop(Stack &S) {
    infotype dummy;
    dummy.value = 0;
    dummy.label = "";

    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
        return dummy;
    }

    infotype x = S.info[S.top];
    S.top--;
    return x;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; --i) {
        cout << S.info[i].value << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack T;
    createStack(T);

    while (!isEmpty(S)) {
        infotype x = pop(S);
        push(T, x);
    }
    S = T;
}

void getInputStream(Stack &S) {
    createStack(S);  
    char c;
    while (true) {
        c = cin.get();         
        if (c == '\n') break;   

        if (c >= '0' && c <= '9') {
            infotype x;
            x.value = c - '0';         
            x.label = string(1, c);    
            push(S, x);
        }
    }
}
