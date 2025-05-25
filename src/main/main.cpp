#include "binary_search_tree/tree.hpp"

using namespace BSTree;

int main() {
    Tree<int> tree(5);
    tree.insert(1);
    tree.insert(9);
    tree.insert(2);
    tree.insert(7);
    tree.insert(3);
    tree.insert(6);
    tree.insert(4);
    tree.insert(8);
    std::cout << tree << std::endl;
    return 0;
}