#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> bigStones;
    for (auto i:stones) {
        if (bigStones.size()==0||bigStones.size()==1) bigStones.push(i);
        else {
            if(bigStones.top()<)
        }
    }
}
