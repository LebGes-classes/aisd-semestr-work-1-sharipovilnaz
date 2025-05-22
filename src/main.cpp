#include "../include/splay_tree.hpp"
#include <iostream>
using namespace std;

int main() {
    Node* root = nullptr;

    root = insert(root, 15);
    root = insert(root, 443);
    root = insert(root, 1);
    root = insert(root, 19);
    root = insert(root, 40);
    root = insert(root, 34);
    root = insert(root, 520);

    cout << "preOrder: " << endl;
    preOrder(root);
    cout << "\ninOrder: " << endl;
    inOrder(root);

    root = search(root, 50);
    cout << "\nudalenie" << endl;
    root = deleteNode(root, 34);

    cout << "posle udaleniya, inOrder: " << endl;
    inOrder(root);

    return 0;
}