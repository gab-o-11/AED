#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
    stack<int> pila;
    int indice2=0;
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        for(int indice=0;indice<=pushed.size();indice++) {
            if (!pila.empty()&&pila.top()==popped[indice2]) {
                pila.pop();
                indice2++;
            }
            if (indice<=pushed.size()-1) {
                pila.push(pushed[indice]);
            }
            for (int i=indice2;i>=0;i--) {
                if(pila.top()==popped[i]) {
                    pila.pop();
                    indice2++;
                }
            }

        }
        if(!pila.empty()) return false;
        return true;
    }
};
int main() {
    vector<int> pusshed;
    vector<int> popped;
    pusshed.push_back(1);
    pusshed.push_back(2);
    pusshed.push_back(3);
    pusshed.push_back(4);
    pusshed.push_back(5);

    popped.push_back(4);
    popped.push_back(3);
    popped.push_back(5);
    popped.push_back(1);
    popped.push_back(2);

    Solution mySolution;
    cout<<mySolution.validateStackSequences(pusshed,popped);
}