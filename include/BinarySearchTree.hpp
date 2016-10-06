#ifndef MAIN_BINARYSEARCHTREE_H
#define MAIN_BINARYSEARCHTREE_H


#include <iostream>
#include <fstream>

template <typename T>
class BinarySearchTree;

template <typename T> auto operator >> (std::istream& input, BinarySearchTree<T>& tree) -> std::istream;
template <typename T> auto operator << (std::ofstream& fileout, const BinarySearchTree<T>& tree) -> std::ofstream&;
template <typename T> auto operator >> (std::ifstream& in, BinarySearchTree<T>& tree) -> std::ifstream&;
template <typename T> auto operator << (std::ostream& out, const BinarySearchTree<T>& tree) -> std::ostream&;


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

        auto copy() -> Node*{
            auto nNode = new Node(value_);
            if(left_)
                nNode->left_=left_->copy();
            if(right_)
                nNode->right_=right_->copy();
            return nNode;
        }
    };



    Node* root_;
    size_t size_;

    BinarySearchTree() : root_(nullptr), size_(0){};
    BinarySearchTree(const std::initializer_list<T>& list);
    BinarySearchTree(BinarySearchTree&& rvalue) {
        size_ = rvalue.size_;
        root_ = rvalue.root_;

        rvalue.root_ = nullptr;
    }

    BinarySearchTree(const BinarySearchTree& tree){
        size_=tree.size_;

        root_=tree.root_->copy();
    }

    Node* ReturnRoot() const noexcept {return root_;}
    ~BinarySearchTree();

    auto size() const noexcept -> size_t;
    auto insert(const T& value) noexcept -> bool;
    auto find(const T& value) const noexcept -> const T*;


    void direct(Node* node, std::ostream& out) const ;
    void symmetric(Node* root, std::ostream& out) const;
    auto equal(Node *firstNode, Node *secondTree) const -> bool;

    auto operator = (const BinarySearchTree<T>& tree) -> BinarySearchTree<T>&; //копирование
    auto operator = (BinarySearchTree<T>&& tree) -> BinarySearchTree<T>&;      //перемещение
    auto operator == (const BinarySearchTree& tree) -> bool;

    friend auto operator >> <> (std::istream& input, BinarySearchTree<T>& tree) -> std::istream;
    friend auto operator << <> (std::ofstream& fileout, const BinarySearchTree<T>& tree) -> std::ofstream&;
    friend auto operator >> <> (std::ifstream& in, BinarySearchTree<T>& tree) -> std::ifstream&;
    friend auto operator << <> (std::ostream& out, const BinarySearchTree<T>& tree) -> std::ostream&;

};

template<typename T>
BinarySearchTree<T>::BinarySearchTree(const std::initializer_list<T>& list): BinarySearchTree() {
    for (auto& el : list) { insert(el);}
}

template<typename T>
auto BinarySearchTree<T>::size() const noexcept -> size_t {
    return size_;
}

template<typename T>
auto BinarySearchTree<T>::insert(const T& value) noexcept -> bool{

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
auto BinarySearchTree<T>::find(const T& value) const noexcept -> const T*{
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
void BinarySearchTree<T>::direct(Node* node, std::ostream& out) const{
    if(!node)
        return;
    out << node->value_<<" ";
    direct(node->left_, out);
    direct(node->right_, out);
}


template<typename T>
void BinarySearchTree<T>::symmetric(Node* node, std::ostream& out) const
{
    if (!node)
        return;

    symmetric(node->right_, out);
    out << node->value_ << "  ";
    symmetric(node->left_, out);
}

template<typename T>
std::ostream& operator << (std::ostream& out, const BinarySearchTree<T>& tree) {
    tree.symmetric(tree.ReturnRoot(), out);
    return out;
}

template<typename T>
std::ofstream& operator << (std::ofstream& fileout, const BinarySearchTree<T>& tree) {
    tree.direct(tree.ReturnRoot(), fileout);
    return fileout;
}

template<typename T>
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

template<typename T>
auto BinarySearchTree<T>::equal(Node *fNode, Node *sNode) const -> bool
{
    if (fNode)
        return sNode && fNode->value_ == sNode->value_
               && equal(fNode->left_, sNode->left_) && equal(fNode->right_, sNode->right_);
    else
        return !sNode;
}

template<typename T>
auto BinarySearchTree<T>::operator=(const BinarySearchTree<T> & tree) -> BinarySearchTree<T>&{
    if (this == &tree)
        return *this;
    delete root_;
    this->root_=tree.root_->copy();
    this->size_=tree.size_;
    return *this;
}

template <typename T>
auto BinarySearchTree<T>::operator=(BinarySearchTree<T> && tree) -> BinarySearchTree<T>&{

    if (this == &tree)
        return *this;
    delete root_;
    this->size_= tree.size_;
    this->root_ = tree.root_;
    tree.size_ = 0;
    tree.root_= nullptr;

    return *this;
}

#endif //MAIN_BINARYSEARCHTREE_H
