//
// Created by Dru on 9/24/2024.
//

#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

template <typename T>

struct Node
{
    T data;
    Node<T> *left = nullptr, *right = nullptr;

    explicit Node(const T& _data) : data(_data) {}

    Node() : data(T()){}
};

#endif //LINKED_LIST_NODE_H
