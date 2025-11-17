#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <string>
using namespace std;

const int MAX = 20;

struct infotype {
    int value;
    string label;
};

struct Stack {
    infotype info[MAX];
    int top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);

void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void getInputStream(Stack &S);

#endif
