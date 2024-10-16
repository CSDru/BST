#include <iostream>
#include "BST.h"

int main()
{
    BST<int> bst;

    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(7);

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
    std::cout << "Contains 20: " << (bst.contains(20) ? "Yes" : "No") << std::endl;

    bst.remove(5);
    std::cout << "In-order traversal after removing 5: ";
    bst.inOrder();

    return 0;
}
