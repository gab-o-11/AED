#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
    stack<int> pila;
public:
    int evalRPN(vector<string>& tokens) {
        for (auto i:tokens) {
            switch (i) {
                case "+":
                    int x=pila.top();
                    pila.pop();
                    x+=pila.top();
                    pila.push(x);
                    break;
                case "-":
                    x=pila.top();
                    pila.pop();
                    x-=pila.top();
                    pila.pop();
                    pila.push(x);
                    break;
                case "*":
                    x=pila.top();
                    pila.pop();
                    x*=pila.top();
                    pila.pop();
                    pila.push(x);
                    break;
                case "/":
                    x=pila.top();
                    pila.pop();
                    x/=pila.top();
                    pila.pop();
                    pila.push(x);
                    break;
                default:
                    pila.push(stoi(i));
            }
        }
        return pila.top();
    }
};

int main() {

}