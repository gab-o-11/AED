#include <iostream>
#include "BST.cpp"

int main() {
    BST<int> t;
    t.insert(4);
    t.insert(2);
    t.insert(5);
    t.insert(3);

    cout<<t.size()<<endl;
    cout<<t.isEmpty()<<endl;
    cout<<t.findMin()<<endl;
    cout<<t.findMax()<<endl;

}