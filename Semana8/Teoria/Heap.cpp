#include <iostream>

using namespace std;


class Heap {
private:
    int val;
    Heap* left;
    Heap* right;
public:
    Heap(int x):val(x),left(nullptr),right(nullptr){}
    Heap(int x, Heap* l, Heap* r):val(0),left(l),right(r){}
    Heap* insert(int v,Heap* root) {
        if (root->val==0) {
            root->val=v;
            return root;
        }
        if (root->left==nullptr) {
            root->left=new Heap(v);
            return root;
        }
        if (root->right==nullptr) {
            root->right=new Heap(v);
            return root;
        }
        else {
            insert(v,root->left);

        }
    }
};
