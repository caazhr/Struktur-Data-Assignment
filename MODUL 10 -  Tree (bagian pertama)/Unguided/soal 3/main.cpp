#include <iostream>
#include "bstree.h"
using namespace std;

int main() {

    address root = alokasi(6);
    root->left = alokasi(4);
    root->right = alokasi(7);

    root->left->left = alokasi(2);
    root->left->right = alokasi(5);

    root->left->left->left = alokasi(1);
    root->left->left->right = alokasi(3);

    cout << "pre-order  : ";
    PreOrder(root);
    cout << endl;

    cout << "post-order : ";
    PostOrder(root);
    cout << endl;

    return 0;
}
