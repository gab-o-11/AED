#include <iostream>
#include <algorithm>

using namespace std;

class AVL {
private:
    int value, depth;
    AVL* left;
    AVL* right;
public:
    AVL():value(0),depth(0),left(nullptr), right(nullptr){}
    AVL(int val):value(val),depth(0),left(nullptr),right(nullptr){}
    int calculateDepth() {
        if (this->left==nullptr&&this->right==nullptr) {
            return 0;
        }
        else {
            int x=0,y=0;
            if (left!=nullptr)
                x=left->calculateDepth();
            if(right!=nullptr)
                y=right->calculateDepth();
            return 1+max(x,y);
        }
    }
    int getBalance() {
        int leftDepth = 0;
        int rightDepth = 0;

        if (left != nullptr) {
            leftDepth = left->calculateDepth();
        }
        if (right != nullptr) {
            rightDepth = right->calculateDepth();
        }
        return leftDepth - rightDepth;
    }

    AVL* rotacionDerecha() {
        AVL* newNode = left;
        left = newNode->right;
        newNode->right = this;
        this->depth = calculateDepth();
        newNode->depth = newNode->calculateDepth();
        return newNode;
    }
    AVL* rotacionIzquierda() {
        AVL* newRoot = right;
        right = newRoot->left;
        newRoot->left = this;
        this->depth = calculateDepth();
        newRoot->depth = newRoot->calculateDepth();
        return newRoot;
    }

    AVL* rotacionIzquierdaDerecha() {
        left = left->rotacionIzquierda();
        return rotacionDerecha();
    }

    AVL* rotacionDerechaIzquierda() {
        right = right->rotacionDerecha();
        return rotacionIzquierda();
    }

    AVL* insert(int val) {
        if (val < this->value) {
            if (this->left == nullptr) {
                this->left = new AVL(val);
            } else {
                this->left = this->left->insert(val);
            }
        } else if (val > this->value) {
            if (this->right == nullptr) {
                this->right = new AVL(val);
            } else {
                this->right = this->right->insert(val);
            }
        } else {
            return this;
        }
        this->depth = calculateDepth();
        int balance = getBalance();
        if (balance > 1 && val < left->value) {
            return rotacionDerecha();
        }
        if (balance < -1 && val > right->value) {
            return rotacionIzquierda();
        }
        if (balance > 1 && val > left->value) {
            return rotacionIzquierdaDerecha();
        }
        if (balance < -1 && val < right->value) {
            return rotacionDerechaIzquierda();
        }
        return this;
    }
    AVL* arreglarBalance() {
        this->depth = calculateDepth();
        int balanceFactor = getBalance();

        if (balanceFactor > 1 && this->left->getBalance() >= 0) {
            return rotacionDerecha();
        }
        if (balanceFactor < -1 && this->right->getBalance() <= 0) {
            return rotacionIzquierda();
        }
        if (balanceFactor > 1 && this->left->getBalance() < 0) {
            left = left->rotacionIzquierda();
            return rotacionDerecha();
        }

        if (balanceFactor < -1 && this->right->getBalance() > 0) {
            right = right->rotacionDerecha();
            return rotacionIzquierda();
        }
        return this;
    }
    AVL* findMin(AVL* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    AVL* remove(int val) {
        if (val < this->value) {
            if (left != nullptr) {
                left = left->remove(val);
            }
        } else if (val > this->value) {
            if (right != nullptr) {
                right = right->remove(val);
            }
        } else {
            if (left == nullptr && right == nullptr) {
                delete this;
                return nullptr;
            } else if (left == nullptr) {
                AVL* temp = right;
                delete this;
                return temp;
            } else if (right == nullptr) {
                AVL* temp = left;
                delete this;
                return temp;
            } else {
                AVL* temp = findMin(right);
                this->value = temp->value;
                right = right->remove(temp->value);
            }
        }
        if (this == nullptr) {
            return nullptr;
        }
        return arreglarBalance();
    }
};
