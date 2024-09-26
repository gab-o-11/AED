#include <iostream>
#include <queue>

using namespace std;
class MyStack {
    queue<int> cola1;
    queue<int> cola2;
public:
    MyStack() {}

    void push(int x) {
        if (cola1.empty()) {
            cola1.push(x);
        }
        else {
            queue<int> temp=cola1;
            cola2.push(x);
            while (!temp.empty()) {
                cola2.push(temp.front());
                temp.pop();
            }
            cola1=cola2;
            cola2=temp;
        }
    }

    int pop() {
        int x=cola1.front();
        cola1.pop();
        return x;
    }

    int top() {
        return cola1.front();
    }

    bool empty() {
        return cola1.empty();
    }
};


int main() {
    MyStack myStack;
    myStack.push(1);
    myStack.push(2);
    cout<<myStack.top()<<endl; // return 2
    cout<<myStack.pop()<<endl; // return 2
    cout<<myStack.empty()<<endl; // return False
}