
#include "BST.h"
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
BST<T>::BST() {
    val = T();
    right=nullptr;
    left=nullptr;
}

template <typename T>
BST<T>::~BST() {
    clear();
}

template <typename T>
void BST<T>::insert(T const& value) {
    if (val==T()) val=value;
    else {
        if (val>value) {
            if(this->left==nullptr) {
                this->left=new BST<T>();
                this->left->val=value;
            } else {
                this->left->insert(value);
            }
        } else {
            if (val<value) {
                if (this->right==nullptr) {
                    this->right= new BST<T>();
                    this->right->val=value;
                } else {
                    this->right->insert(value);
                }
            }
        }
    }
}

template <typename T>
bool BST<T>::search(T const& value) const {
    if (this->val==value) return true;
    else {
        if (val>value) {
            if (this->left!=nullptr) return this->left->search(value);
        }
        else {
            if (this->right!=nullptr) return this->right->search(value);
        }
    }
    return false;
}

template <typename T>
void BST<T>::remove(T const& value) {
    if (val > value) {
        if (this->left != nullptr) {
            this->left->remove(value);
        }
    }
    else if (val < value) {
        if (this->right != nullptr) {
            this->right->remove(value);
        }
    }
    else {
        if (this->left == nullptr) {
            BST<T>* node = this->right;
            val = this->right->val;
            this->left = this->right->left;
            this->right = this->right->right;
            delete node;
        }
        else if (this->right == nullptr) {
            BST<T>* node = this->left;
            this->val = this->left->val;
            this->right = this->left->right;
            this->left = this->left->left;
            delete node;
        }
        else {
            val = this->right->findMin();
            this->right->remove(val);
        }
    }
}


template <typename T>
size_t BST<T>::size() const {
    size_t n_left=0, n_right=0;
    if (left!=nullptr) n_left=this->left->size();
    if (right!=nullptr) n_right=this->right->size();
    return 1+n_left+n_right;
}

template <typename T>
T BST<T>::findMin() const {
    const BST<T>* node=this;
    while (node->left != nullptr) {
        node = node->left;
    }
    return node->val;
}

template <typename T>
T BST<T>::findMax() const {
    const BST<T>* node=this;
    while (node->right != nullptr) {
        node = node->right;
    }
    return node->val;
}

template <typename T>
bool BST<T>::isEmpty() const {
    return (left == nullptr && right == nullptr && val == T());
}

template <typename T>
void BST<T>::clear() {
    if (this->left != nullptr) {
        this->left->clear();
        delete this->left;
        this->left = nullptr;
    }

    if (this->right != nullptr) {
        this->right->clear();
        delete this->right;
        this->right = nullptr;
    }
}
