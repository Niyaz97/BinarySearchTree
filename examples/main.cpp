#include "../include/BinarySearchTree.h"


int main() {

    BinarySearchTree<int> tree{ 48,26,87,34,76};
    tree.find(48);
    tree.insert(29);
    std::cout << tree;
  //  file << tree;
    
}
