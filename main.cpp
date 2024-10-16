#include <iostream>
#include "BST.h"

int main()
{
    BST<int> bst;

    bst.insert(34);
    bst.insert(86);
    bst.insert(48);
    bst.insert(7);
    bst.insert(54);
    bst.insert(69);
    bst.insert(49);
    bst.insert(87);
    bst.insert(4);
    bst.insert(9);
    bst.insert(1);
    bst.insert(89);

    std::cout << "Pre-order traversal: ";
    bst.preOrder();
    std::cout << std::endl;
    std::cout << "In-order traversal: ";
    bst.inOrder();
    std::cout << std::endl;
    std::cout << "Post-order traversal: ";
    bst.postOrder();
    std::cout << std::endl;
    std::cout << "Breadth-order traversal: ";
    bst.breadthOrder();
    std::cout << std::endl;

    std::cout << "Contains 7: " << (bst.contains(7) ? "Yes" : "No") << std::endl;
    std::cout << "Contains 16: " << (bst.contains(20) ? "Yes" : "No") << std::endl;

    bst.remove(9);
    std::cout << "In-order traversal after removing 9: ";
    bst.inOrder();

    return 0;
}
