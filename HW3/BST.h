
#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

template <typename T>
struct BST {
    BST* left;
    BST* right;
    T val;

    BST();

    ~BST();

    void insert(T const& value);

    bool search(T const& value) const;

    void remove(T const& value);

    size_t size() const;

    T findMin() const;

    T findMax() const;

    bool isEmpty() const;

    void clear();
};


#endif //BST_H
