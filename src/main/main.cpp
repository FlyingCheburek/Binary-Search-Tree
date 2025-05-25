#include "binary_search_tree/tree.hpp"

using namespace BSTree;

int main() {
    Tree<int> tree(5);
    tree >> 1 >> 9 >> 2 >> 7 >> 3 >> 6 >> 4 >> 8;
    return 0;
}