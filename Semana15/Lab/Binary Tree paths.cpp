#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void busqueda(TreeNode* root, vector<string> &ans,string &res) {
    if(root!=nullptr) {
        if (!res.empty()) {
            res+="->";
        }
        res+=to_string(root->val);
        busqueda(root->left,ans,res);
        res="";
        busqueda(root->right,ans,res);
    }
    ans.push_back(res);
}

vector<string> binaryTreePaths(TreeNode* root) {
    string res;
    vector<string> ans;
    busqueda(root,ans,res);

}