#include <iostream>



class binary_search_tree {
private:
    int value;
    binary_search_tree* left;
    binary_search_tree* right;
public:
    binary_search_tree(){value(0),left(nullptr),right(nullptr);}
    binary_search_tree(int v){value(v),left(nullptr),right(nullptr);}
    binary_search_tree(int v, binary_search_tree* x, binary_search_tree* y){value(v),left(x),right(y);}
    void add_node(binary_search_tree* bst,int val) {
        if (val>this->value) {
            if(left==nullptr) {
                this->left=new binary_search_tree(val);
            }
            else add_node(this->left,val);
        }
        if (val<this->value) {
            if(right==nullptr) {
                this->right=new binary_search_tree(val);
            }
            else add_node(this->right,val);
        }
    }
    binary_search_tree* find_min(binary_search_tree* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    binary_search_tree* find_max(binary_search_tree* node) {
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }
    void swap(binary_search_tree* node2) {
        int temp = this->value;
        this->value = node2->value;
        node2->value = temp;
        binary_search_tree* tempLeft = this->left;
        this->left = node2->left;
        node2->left = tempLeft;
        binary_search_tree* tempRight = this->right;
        this->right = node2->right;
        node2->right = tempRight;
    }
    void delete_node(int x,binary_search_tree* parent = nullptr) {
        if (this->value>x) {
            if (this->left != nullptr) {
                this->left->delete_node(x,this);
            }
        }
        else if (this->value<x) {
            if (this->right != nullptr) {
                this->right->delete_node(x,this);
            }
        }
        else {
            if (this->right==nullptr && this->left==nullptr) {
                if (parent != nullptr) {
                    if (parent->left == this) {
                        parent->left = nullptr;
                    } else if (parent->right == this) {
                        parent->right = nullptr;
                    }
                }
                delete this;
            }
            else if (this->right==nullptr) {
                binary_search_tree* temp = this->left;
                this->value = temp->value;
                this->left = temp->left;
                this->right = temp->right;
                delete temp;
            }
            else if (this->left==nullptr) {
                binary_search_tree* temp = this->right;
                this->value = temp->value;
                this->left = temp->left;
                this->right = temp->right;
                delete temp;
            }
            else {
                binary_search_tree* sucesor=find_min(this->right);
                this->value=sucesor->value;
                this->right->delete_node(sucesor->value, this);
            }
        }
    }
    bool find(int v) {
        if (this->value==v) return true;
        else {
            if (v<this->value) {
                if (this->left==nullptr) return false;
                return this->left->find(v);
            }
            if (v>this->value) {
                if (this->right==nullptr) return false;
                return this->right->find(v);
            }
        }
    }
};