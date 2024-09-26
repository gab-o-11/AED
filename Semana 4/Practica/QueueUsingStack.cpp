#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
    stack<int> pila1;
    stack<int> pila2;
public:
    MyQueue() {
    }

    void push(int x) {
        if (pila1.empty()) {
            pila1.push(x);
        }
        else {
            stack<int> temp=pila1;
            while (!temp.empty()) {
                pila2.push(temp.top());
                temp.pop();
            }
            pila2.push(x);
            pila1=temp;
            temp=pila2;
            while (!temp.empty()) {
                pila1.push(temp.top());
                temp.pop();
            }
            pila2=temp;
        }
    }

    int pop() {
        int x=pila1.top();
        pila1.pop();
        return x;
    }

    int peek() {
        return pila1.top();
    }

    bool empty() {
        return pila1.empty();
    }
};


int main() {
    MyQueue myQueue;
    myQueue.push(1); // queue is: [1]
    myQueue.push(2);
    myQueue.push(3);// queue is: [1, 2] (leftmost is front of the queue)
    myQueue.push(4);
    myQueue.push(5);
    myQueue.push(6);

    while (!myQueue.empty()) {
        cout<<myQueue.peek()<<" ";
        myQueue.pop();
    }



}