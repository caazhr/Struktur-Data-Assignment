#include "bstree.h"
#include <iostream>
using namespace std;

address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = Nil;
    p->right = Nil;
    return p;
}
void PreOrder(address root) {
    if (root == Nil) return;
    cout << root->info << " - ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void PostOrder(address root) {
    if (root == Nil) return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->info << " - ";
}
