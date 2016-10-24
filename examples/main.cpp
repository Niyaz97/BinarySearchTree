#include "../include/BinarySearchTree.hpp"
#include <iostream>

int main() {
try {
    BinarySearchTree<int> tree1{52, 34, 87, 76};
    BinarySearchTree<int> tree2 = std::move(tree1);
    BinarySearchTree<int> treedel{15, 17, 12, 10, 13, 19, 18, 20};
    BinarySearchTree<int> treecheck{15, 17, 10, 13, 19, 18, 20};
    std::cout << tree1;
    treedel.remove(12);
    std::cout << treedel << std::endl;
    std::cout << treecheck << std::endl;


    BinarySearchTree<int> treedel2{15, 17, 12, 10, 13, 19, 18, 20};
    BinarySearchTree<int> treecheck2{15, 17, 12, 10, 13, 18, 20};
    treedel2.remove(42);
    std::cout << treedel2 << std::endl;
    std::cout << treecheck2;
}
    catch(BinarySearchTree<int>::except& e){
            std::cout<<e.what()<<", "<<e.getParam()<<std::endl;
    }
    
}
