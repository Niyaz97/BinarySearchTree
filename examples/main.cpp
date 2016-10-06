#include <BinarySearchTree.h>
#include <iostream>

int main() {

    BinarySearchTree<int> tree1{ 52,34,87,34,76};
    BinarySearchTree<int> tree2=std::move(tree1);
    std::cout << tree1;
//    std::ofstream file("/ClionProjects/untitled/Test1.txt");
//    file << tree;
//    file.close();
}
