#include "../include/BinarySearchTree.hpp"
#include <iostream>

int main() {

    BinarySearchTree<int> tree1{ 52,34,87,76};
    BinarySearchTree<int> tree2=std::move(tree1);
    BinarySearchTree<int> treedel{100,250,400,50,150,600};
   // std::cout << tree1;

    treedel.remove(treedel.root_,600);
    std::cout<<treedel;

//    std::ofstream file("/ClionProjects/untitled/Test1.txt");
//    file << tree;
//    file.close();
}
