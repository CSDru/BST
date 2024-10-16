//
// Created by Dru on 10/15/2024.
//
#ifndef BST_BST_CPP
#define BST_BST_CPP

#include "BST.h"

template<typename T>
BST<T>::BST() : root(nullptr) {}

template<typename T>
BST<T>::~BST()
{
    clear(root);
}

template<typename T>
void BST<T>::insert(const T &data)
{
    insert(root, data);
}

template<typename T>
bool BST<T>::contains(const T &data)
{
    return contains(root, data);
}

template<typename T>
void BST<T>::remove(const T &data)
{
    root = remove(root, data);
}

template<typename T>
void BST<T>::preOrder() const
{
    preOrder(root);
}

template<typename T>
void BST<T>::inOrder() const
{
    inOrder(root);
}

template<typename T>
void BST<T>::postOrder() const
{
    postOrder(root);
}

template<typename T>
void BST<T>::breadthOrder() const
{
    breadthOrder(root);
}

template<typename T>
void BST<T>::insert(Node<T> *&node, const T &data)
{
    if(!node)
        node = new Node<T>(data);
    else if(data < node->data)
        insert(node->left, data);
    else
        insert(node->right, data);
}

template<typename T>
bool BST<T>::contains(Node<T> *node, const T &data) const
{
    if(!node)
        return false;
    else if(data < node->data)
        return contains(node->left, data);
    else if(data > node->data)
        return contains(node->right, data);
    else
        return true;
}

template<typename T>
Node<T> *BST<T>::remove(Node<T> *node, const T &data)
{
    if(!node)
        return nullptr;

    if(data < node->data)
        node->left = remove(node->left, data);
    else if(data > node->data)
        node->right = remove(node->right, data);
    else
    {
        if(!node->left && !node->right)
        {
            delete node;
            return nullptr;
        }
        else if (!node->left)
        {
            Node<T> *temp = node->right;
            delete node;
            return temp;
        }
        else if (!node->right)
        {
            Node<T>* temp = node->left;
            delete node;
            return temp;
        }

        Node<T>* leastNode = findLeast(node->right);
        node->data = leastNode->data;
        node->right = remove(node->right, leastNode->data);
    }

    return node;
}

template<typename T>
Node<T> *BST<T>::findLeast(Node<T> *node) const
{
//    if(node && node->left)
//        node = findLeast(node->left);
//    return node;
    while(node && node->left)
        node = node->left;
    return node;
}

template<typename T>
void BST<T>::preOrder(Node<T> *node) const
{
    if(!node)
        return;
    std::cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

template<typename T>
void BST<T>::inOrder(Node<T> *node) const
{
    if(!node)
        return;
    inOrder(node->left);
    std::cout << node->data << " ";
    inOrder(node->right);
}

template<typename T>
void BST<T>::postOrder(Node<T> *node) const
{
    if(!node)
        return;
    postOrder(node->left);
    postOrder(node->right);
    std::cout << node->data << " ";
}

template<typename T>
void BST<T>::breadthOrder(Node<T> *node) const
{
    if(!node)
        return;
    std::queue<Node<T>*> Queue;
    Queue.push(node);

    while(!Queue.empty())
    {
        Node<T>* current = Queue.front();
        Queue.pop();
        std::cout << current->data << " ";

        if(current->left)
            Queue.push(current->left);
        if(current->right)
            Queue.push(current->right);
    }
}

template<typename T>
void BST<T>::clear(Node<T> *node)
{
    if(!node)
        return;
    clear(node->left);
    clear(node->right);
    delete node;
}

#endif //BST_BST_CPP