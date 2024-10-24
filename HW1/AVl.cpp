#include <algorithm>
#include <cstdlib>
#include <vector>

#include "AVl.h"


using namespace std;
// AVLNode

template <typename T>
AVLNode<T>::AVLNode(T value)
    : data(value), left(nullptr), right(nullptr), height(0) {}

// AVLTree

template <typename T>
AVLTree<T>::AVLTree() : root(nullptr) {}

template <typename T>
int AVLTree<T>::height(AVLNode<T>* node) {
      if(node->left==nullptr&&node->right==nullptr){
          return 0;
      }
      else{
          int x=0,y=0;
          if(node->left!=nullptr) x=height(node->left);
          if(node->right!=nullptr) y=height(node->right);
          return 1+max(x,y);
      }

int AVLTree<T>::getBalance(AVLNode<T>* node) {
  int leftDepth=0;
  int rightDepth=0;
  if (node->left!=nullptr) leftDepth=height(node->right);
  if (node->right!=nullptr) rightDepth=height(node->right);
}

template <typename T>
AVLNode<T>* AVLTree<T>::rightRotate(AVLNode<T>* y) {
  AvlNode* temp=y->left;
  y->left=temp->right;
  temp->right=y;
  y->height=height(y);
  temp->height=height(temp);
  return temp;
}

// Rotación izquierda
template <typename T>
AVLNode<T>* AVLTree<T>::leftRotate(AVLNode<T>* x) {
  AvlNode* temp=x->right;
  x->right=temp->left;
  temp->left=x;
  x->height=height(x);
  temp->height=height(temp);
  return temp;
}

template <typename T>
AVLNode<T>* AVLTree<T>::minValueNode(AVLNode<T>* node) {
  while(node->left!=nullptr){
      node=node->left;
  }
  return node;

// Inserción
template <typename T>
   AVLNode<T>* AVLTree<T>::insert(AVLNode<T>* node, T key) {
      if (node == nullptr) {
          return new AVLNode<T>(key);
      }

      if (key < node->data) {
          node->left = insert(node->left, key);
      } else if (key > node->data) {
          node->right = insert(node->right, key);
      } else {
            return node;
          }

          node->height = 1 + max(height(node->left), height(node->right));

          int balance = getBalance(node);

          if (balance > 1 && key < node->left->data) {
            return rightRotate(node);
          }

          if (balance < -1 && key > node->right->data) {
            return leftRotate(node);
          }

          if (balance > 1 && key > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
          }

          if (balance < -1 && key < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
          }

          return node;
        }

// Eliminar un nodo
template <typename T>
AVLNode<T>* AVLTree<T>::remove(AVLNode<T>* root, T key) {
    if (node == nullptr) {
        return node;
    }
    if (key < node->data) {
        node->left = remove(node->left, key);
    } else if (key > node->data) {
        node->right = remove(node->right, key);
    } else {
        if (node->left == nullptr || node->right == nullptr) {
            AVLNode<T>* temp;
            if (node->left != nullptr) {
                temp = node->left;
            } else {
                temp = node->right;
            }
            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            } else {
                *node = *temp;
            }
            delete temp;
        } else {
            AVLNode<T>* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
    }
    if (node == nullptr) {
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && getBalance(node->left) >= 0) {
        return rightRotate(node);
    }
    if (balance < -1 && getBalance(node->right) <= 0) {
        return leftRotate(node);
    }
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

// Búsqueda
template <typename T>
bool AVLTree<T>::search(AVLNode<T>* node, T key) {
  if(node==nullptr) return false;
  if (node->data==key) return true;
    if (key < node->data) {
        return search(node->left, key);
    } else {
        return search(node->right, key);
    }
}

// Recorrido preorder
template <typename T>
void AVLTree<T>::preorder(AVLNode<T>* root, std::vector<T>& ret) {
  if(node!=nullptr){
      ret.pushback(node->data);
      preorder(node->left, ret);
      preorder(node->right, ret);
  }
}

// Recorrido inorder
template <typename T>
void AVLTree<T>::inorder(AVLNode<T>* root, std::vector<T>& ret) {
  // COMPLETE HERE
}

// Recorrido postorder
template <typename T>
void AVLTree<T>::postorder(AVLNode<T>* root, std::vector<T>& ret) {
  // COMPLETE HERE
}

/// Public functions

template <typename T>
void AVLTree<T>::insert(T key) {
  root = insert(root, key);
}

template <typename T>
void AVLTree<T>::remove(T key) {
    root = remove(root, key);
}

template <typename T>
bool AVLTree<T>::search(T key) {
    return search(root, key);
}

template <typename T>
std::vector<T> AVLTree<T>::preorderTraversal() {
   vector<T> recorridoPreorder;
   preorder(root, recorridoPreorder);
   return recorridoPreorder;
}

template <typename T>
std::vector<T> AVLTree<T>::inorderTraversal() {
  // COMPLETE HERE
}

template <typename T>
std::vector<T> AVLTree<T>::postorderTraversal() {
  // COMPLETE HERE
}

template <typename T>
int AVLTree<T>::height() {
  return height(root);
}

template <typename T>
bool AVLTree<T>::isBalanced() {
  	if(node==nullptr) return true;
	int leftDepth=height(root->left);
	int rightDepth=height(root->right);
	if (abs(leftDepth-rightDepth)>1){
		return false;
	}
}