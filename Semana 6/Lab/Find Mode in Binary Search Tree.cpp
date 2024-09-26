#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void FindMode(unordered_map<int, int>& map, TreeNode* root) {
    if (root == nullptr) return;
    map[root->val]++;
    FindMode(map, root->left);
    FindMode(map, root->right);
}
vector<int> findMode(TreeNode* root) {
    unordered_map<int, int> mapa;
    vector<int> respuesta;
    if (root == nullptr) {
        return respuesta;
    }

    FindMode(mapa, root);
    int max_freq = 0;
    for (auto& pair : mapa) {
        max_freq = max(max_freq, pair.second);
    }
    for (auto& pair : mapa) {
        if (pair.second == max_freq) {
            respuesta.push_back(pair.first);
        }
    }
    return respuesta;
}



int main() {

}