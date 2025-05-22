#ifndef SPLAY_TREE_H
#define SPLAY_TREE_H

#include <iostream> 
using namespace std;

class Node {
public:
    int key;
    Node *left, *right;
    Node(int key) {
        this->key = key;
        left = right = nullptr;
    }
};

Node* createNewNode(int key);
Node* rightRotate(Node* root);
Node* leftRotate(Node* root);
Node* insert(Node* root, int key);
Node* splay(Node* root, int key);
Node* search(Node* root, int key);
Node* deleteNode(Node* root, int key);

void preOrder(Node* root);
void inOrder(Node* root);
void postOrder(Node* root);

#endif