#ifndef MAIN_BINARYSEARCHTREE_H
#define MAIN_BINARYSEARCHTREE_H


#include <iostream>
#include <fstream>


template <typename T>
class BinarySearchTree {
public:
    class Node{
    public:
        T value_;
        Node* left_;
        Node* right_;
        Node(T value) : value_(value), left_(nullptr), right_(nullptr){}

        ~Node(){
            if(left_)
                delete left_;
            if(right_)
                delete right_;
        }
    };

    Node* root_;
    size_t size_;

    BinarySearchTree() : root_(nullptr), size_(0){};
    BinarySearchTree(const std::initializer_list<T> & list);
    auto size() const noexcept -> size_t;
    auto insert(const T & value) noexcept -> bool;
    auto find(const T & value) const noexcept -> const T*;
    Node* ReturnRoot() const noexcept {return root_;}
    ~BinarySearchTree();
    void direct(Node* node, std::ostream & out) const ;
};

template<typename T>
BinarySearchTree<T>::BinarySearchTree(const std::initializer_list<T> &list): BinarySearchTree() {
    for (auto el : list) { insert(el);}
}

template<typename T>
auto BinarySearchTree<T>::size() const noexcept -> size_t {
    return size_;
}

template<typename T>
auto BinarySearchTree<T>::insert(const T &value) noexcept -> bool{

    if (root_== nullptr) {
        root_ = new Node(value);
        size_++;
        return true;
    }

    Node* node = root_, *parent = nullptr;

    while(node){
        parent=node;
        if (value < parent->value_)
            node = parent->left_;
        else if (value > parent->value_)
            node = parent->right_;
        else
            return false;
    }

    if (value < parent->value_)
        parent->left_ = new Node(value);
    else parent->right_ = new Node(value);
    size_ ++;
    return true;

}

template<typename T>
auto BinarySearchTree<T>::find(const T & value) const noexcept -> const T*{
    Node* node=root_;
    while(node){
        if(value< node->value_)
            node = node->left_;
        else if (value> node->value_)
            node = node->right_;
        else
            return &node->value_;

    }
    return nullptr;
}

template<typename T>
void BinarySearchTree<T>::direct(Node* node, std::ostream & out) const{
    if(!node)
        return;
    out << node->value_<<" ";
    direct(node->left_, out);
    direct(node->right_, out);
}

template <typename T>
std::ostream& operator << (std::ostream& out, const BinarySearchTree<T>& tree) {
    tree.direct(tree.ReturnRoot(),out);
    return out;
}

template <typename T>
std::ofstream& operator << (std::ofstream& fileout, const BinarySearchTree<T>& tree) {
    tree.direct(tree.ReturnRoot(), fileout);
    return fileout;
}

template <typename T>
std::istream& operator >> (std::istream& input, BinarySearchTree<T>& tree) {

    T value;
    while(input >> value)
        tree.insert(value);
    return input;
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    if (root_){
        delete root_;
        size_ = 0;
    }
}

#endif //MAIN_BINARYSEARCHTREE_H
