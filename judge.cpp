#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, vector<int>> vecinos;
        vector<int> confiados;
        for (auto i:trust) {
            vecinos[i[0]].push_back(i[1]);
            confiados.push_back(i[1]);
        }
        for (auto k: confiados){
            if(vecinos[k].size()==0) {
                return k;
            }
        }
        return -1;
    }
};