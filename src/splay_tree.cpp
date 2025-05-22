#include "../include/splay_tree.hpp"
#include <iostream>
using namespace std;

// создаем новый узел
Node* createNewNode(int key) {
    Node* node = new Node(key);
    return node;
}

// правый поворот
Node* rightRotate(Node* root) {
    Node* left_child = root->left;
    root->left = left_child->right;
    left_child->right = root;
    return left_child;
}

// левый поворот
Node* leftRotate(Node* root) {
    Node* right_child = root->right;
    root->right = right_child->left;
    right_child->left = root;
    return right_child;
}

// splay функция (перестройка дерева)
Node* splay(Node* root, int key) {
    if (root == nullptr || root->key == key)
        return root;

    // ключ в левом поддереве
    if (key < root->key) {
        if (root->left == nullptr)
            return root;
            
        if (key < root->left->key) {
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        }
        else if (key > root->left->key) {
            root->left->right = splay(root->left->right, key);
            if (root->left->right != nullptr)
                root->left = leftRotate(root->left);
        }

        return (root->left == nullptr) ? root : rightRotate(root);
    }
    // ключ в правом поддереве
    else {
        if (root->right == nullptr)
            return root;

        if (key > root->right->key) {
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }
        else if (key < root->right->key) {
            root->right->left = splay(root->right->left, key);
            if (root->right->left != nullptr)
                root->right = rightRotate(root->right);
        }

        return (root->right == nullptr) ? root : leftRotate(root);
    }
}

// вставка
Node* insert(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);

    root = splay(root, key);

    if (root->key == key)
        return root;

    Node* node = new Node(key);

    if (key < root->key) {
        node->right = root;
        node->left = root->left;
        root->left = nullptr;
    } else {
        node->left = root;
        node->right = root->right;
        root->right = nullptr;
    }
    return node;
}

// поиск
Node* search(Node* root, int key) {
    return splay(root, key);
}

// удаление
Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return root;

    root = splay(root, key);

    if (root->key != key)
        return root;

    Node* left_child = root->left;
    Node* right_child = root->right;
    delete root;

    if (left_child == nullptr)
        return right_child;

    left_child = splay(left_child, key);
    left_child->right = right_child;
    return left_child;
}

// обходы дерева
void preOrder(Node* root) {
    if (root == nullptr) return;
    cout << root->key << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root) {
    if (root == nullptr) return;
    inOrder(root->left);
    cout << root->key << " ";
    inOrder(root->right);
}

void postOrder(Node* root) {
    if (root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->key << " ";
}