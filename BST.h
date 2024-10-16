//
// Created by Dru on 10/15/2024.
//

#ifndef BST_BST_H
#define BST_BST_H

#include "Node.h"
#include <iostream>
#include <queue>

template <typename T>
class BST
{
public:
    BST();
    ~BST();

    void insert(const T& data);
    bool contains(const T& data);
    void remove(const T& data);
    void preOrder() const;
    void inOrder() const;
    void postOrder() const;
    void breadthOrder() const;

private:
    Node<T>* root;

    void insert(Node<T>*& node, const T& data);
    bool contains(Node<T>* node, const T& data) const;
    Node<T>* remove(Node<T>* node, const T& data);
    Node<T>* findLeast(Node<T>* node) const;
    void preOrder(Node<T>* node) const;
    void inOrder(Node<T>* node) const;
    void postOrder(Node<T>* node) const;
    void breadthOrder(Node<T>* node) const;
    void clear(Node<T>* node);
};

#include "BST.cpp"

#endif //BST_BST_H